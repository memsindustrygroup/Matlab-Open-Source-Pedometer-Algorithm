function walkStruct = stepCounter_struct_init
%%% init of stepCounter structure
%
%#codegen
%

% walkStruct
walkStruct.HIthrA = single(2);
walkStruct.LIthrA = single(0.7);
walkStruct.HIthrW = single(1.7);
walkStruct.LIthrW = single(1.07);
walkStruct.timeThr = single(325); % made a single for real time updates
walkStruct.HLI = uint32(0);
walkStruct.HIt = uint32(0);
walkStruct.LIt = uint32(0);
walkStruct.HIcnt = uint32(0);
walkStruct.LIcnt = uint32(0);
walkStruct.Acur = zeros(1,3,'single'); %accel x y z time
walkStruct.AcurRMS = zeros(1,3,'single');
walkStruct.Aprev = zeros(1,3,'single');
walkStruct.AprevRMS = zeros(1,3,'single');
walkStruct.Acurt = uint32(0);
walkStruct.Aprevt = uint32(0);
walkStruct.crossed = uint8(0);
walkStruct.addPoint = int8(0); % 1 to add point, 0 for nothing, -1 to lose point
walkStruct.reset = uint8(0); % end of interval reset flag

walkStruct.aTimeUnroll = uint32(0);
walkStruct.prevTime = uint16(0);
walkStruct.nWrap = uint16(0);

walkStruct.timerOverflow = uint8(0);
walkStruct.counterOverflow = uint8(0);
