% Function to process a matlab data file and run it through the walking
% algorithm
clear all;close all

addpath('Data')

[FileName,PathName] = uigetfile({'Data/;*.mat;*.csv;*.xlsx'},'Choose Sentral Log File');
disp(FileName)

newResP = 0;resampledHtData = newResP; %initialize in case file doesn't have said data
trueSteps = 0;startTime = 1;endTime = 0;
titles = [FileName];

if FileName(end) == 't' % process .mat file

    load([PathName FileName])

    resultData = data_rec.dataSimRec.data_result_ay;

    timeAy = resultData(:,1); % in seconds
    accelAy = resultData(:,5:7);
    listValues = zeros(size(timeAy));
    j = 1;
    listValues(j) = 1;
    % remove repeated samples
    for i = 2:length(listValues)
        if all(accelAy(i,:) == accelAy(i-1,:))

        else
            listValues(j) = i;
            j = j + 1;
        end
    end
    % basic values
    listValues = listValues(1:(j-1));
    time = uint32(timeAy(listValues)*1000); % scale to milliseconds
    acal = accelAy(listValues,:);% scaled in g's
    filetype = 1;
elseif FileName(end) == 'x' || FileName(end) == 'v'
    [rawData,header] = xlsread(FileName);
    whichInds = rawData(:,4) == 1;
    aDataRaw = rawData(whichInds,[1 5 6 7]);
    acal = aDataRaw(:,2:4)/9.81;%convert m/s2 to g's
    tRaw = aDataRaw(:,1);
    t2 = tRaw - tRaw(1,:); % time from zero in counts
    time = t2/10^6; % go from picoseconds to microseconds
    filetype = 2;
    ssts = find(rawData(:,4) == 104);
    tts = rawData(:,4) == 103;
    try
       trueSteps = rawData(tts,8);
       if length(trueSteps) > 1
           trueSteps = max(trueSteps);
       end
    catch;end
    try
        indices = find(aDataRaw(:,1) <= rawData(ssts(1),1));
        startTime = indices(end);
        if isempty(startTime);startTime=0;end
    catch;end
    try
        indices = find(aDataRaw(:,1) >= rawData(ssts(2),1));
        endTime = indices(1);
        if isempty(endTime);startTime=0;end
    catch;end

else
    disp('Invalid file selected. Exiting.')
    filetype = 0;
    return
end

aR = sqrt(acal(:,1).^2 + acal(:,2).^2 + acal(:,3).^2); %accel radius in g's

walkStruct = stepCounter_struct_init;
walkStruct.LIthrW = single(1.03); % change important threshold if needed

for k = 1:length(time)
    % run with accel data
    walkStruct = walkAlg3(walkStruct,acal(k,:),[0 0 0],time(k),1);
    
    % run with accel radius
%     walkStruct = walkAlg3(walkStruct,aR(k,:),0,time(k),1); 
end

stepcount= sprintf('detected steps = %d',walkStruct.HLI);

disp('Total number of steps detected')
disp(walkStruct.HLI)

figure(1);plot(time/1000,acal);legend('Accel X','Accel Y', 'Accel Z', 'Location','Best');title(titles,'Interpreter','none');text(2,.75,stepcount);ylabel('g-force');xlabel('seconds');



figure(2);plot(time/1000,aR);title(titles,'Interpreter','none');legend('Accel Radius','Location','Best');ylabel('3-Axis Root-Sum-Square (g-force)');text(3,.75,stepcount);xlabel('seconds');