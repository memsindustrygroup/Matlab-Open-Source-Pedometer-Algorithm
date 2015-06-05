function walkStruct = walkAlg3(walkStruct,accDataIn,aRMSin,tDataIn,whichThr)
%%% walking algorithm. 
% Performs step counting primarily targeted for the wrist mounting, uses
% maximum observed value for each. Could also be used for accel radii.
% Inputs: 
% walkStruct = holds all persistent varibles as well as thresholds, see
% stepCounter_struct_init for definitions.
% accDataIn = accel data inputs, x, y, z; can be lowpass filtered
% if desired.
% aRMSin = moving average or rms data, subtracted from data. Can input
% zeros, or input RMS data as desired, will require different thresholds.
% tDataIn = time data, in milliseconds, relative timing between points is
% all that matters, but must be unwrapped before input to this function.
% whichThr = allows user to store two sets of thresholds and switch with
% this value. Example, could use different thresholds for 0 aRMSin vs moving
% standard deviation for aRMSin and switch depending on if data available.
%
%#codegen
%

% choose a thershold setting 
% two threshold settings per to denote high acceleration or low
% acceleration amplitudes
if whichThr == 2
    LIth = walkStruct.LIthrA;
    HIth = walkStruct.HIthrA;
else
    LIth = walkStruct.LIthrW;
    HIth = walkStruct.HIthrW;
end
walkStruct.addPoint = int8(0);

    if max(abs(accDataIn-aRMSin))>LIth % check if data has crossed minimum threshold
        if ~walkStruct.crossed % when it crosses a threshold incremement steps
            walkStruct.HLI = walkStruct.HLI + uint32(1); % step count
            walkStruct.crossed = uint8(1);
        end
        % if newest point is highest current point for this crossing, save
        % it as the current peak data point
        if max(abs(accDataIn-aRMSin)) > max(abs(walkStruct.Acur-walkStruct.AcurRMS))
            walkStruct.Acur = accDataIn;
            walkStruct.AcurRMS = aRMSin;
            walkStruct.Acurt = tDataIn;% time and value
        end
    else
        if walkStruct.crossed % once data crosses back under threshold, perform calculations and determine step type
            walkStruct.addPoint = int8(1);
            if max(abs(walkStruct.Acur-walkStruct.AcurRMS)) > HIth
                % high impact point classification
                walkStruct.HIcnt = walkStruct.HIcnt + uint32(1);
                walkStruct.HIt = walkStruct.HIt + uint32(1);
            else
                % low impact point classification
                walkStruct.LIcnt = walkStruct.LIcnt + uint32(1);
                walkStruct.LIt = walkStruct.LIt + uint32(1);
            end
            
            if walkStruct.HLI > 1 
                % remove data points that are too close together in time
                if abs(walkStruct.Acurt-walkStruct.Aprevt) < walkStruct.timeThr
                    walkStruct.HLI = walkStruct.HLI - uint32(1);
                    walkStruct.addPoint = int8(-1);
                    if max(abs(walkStruct.Aprev-walkStruct.AprevRMS)) > max(abs(walkStruct.Acur-walkStruct.AcurRMS))
                        if max(abs(walkStruct.Acur-walkStruct.AcurRMS)) > HIth
                            walkStruct.HIcnt = walkStruct.HIcnt - uint32(1);
                            walkStruct.HIt = walkStruct.HIt - uint32(1);
                        else
                            walkStruct.LIcnt = walkStruct.LIcnt - uint32(1);
                            walkStruct.LIt = walkStruct.LIt - uint32(1);
                        end
                        walkStruct.Acur = walkStruct.Aprev;
                        walkStruct.AcurRMS = walkStruct.AprevRMS;
                        walkStruct.Acurt = walkStruct.Aprevt;
                    else
                        if max(abs(walkStruct.Aprev-walkStruct.AprevRMS)) > HIth
                            walkStruct.HIcnt = walkStruct.HIcnt - uint32(1);
                            walkStruct.HIt = walkStruct.HIt - uint32(1);
                        else
                            walkStruct.LIcnt = walkStruct.LIcnt - uint32(1);
                            walkStruct.LIt = walkStruct.LIt - uint32(1);
                        end
                    end
                end
            end
            % set the current point as the previous point, and reset the
            % current point for new steps.
            walkStruct.Aprev = walkStruct.Acur;
            walkStruct.AprevRMS = walkStruct.AcurRMS;
            walkStruct.Aprevt = walkStruct.Acurt;
            walkStruct.Acur = zeros(size(walkStruct.Acur),'single');
            walkStruct.AcurRMS = zeros(size(walkStruct.AcurRMS),'single');
            walkStruct.Acurt = uint32(0);
            walkStruct.crossed = uint8(0);
        end
    end
% end