function [walkStruct] = aTimeUnroll2(atime,resolution,walkStruct)
%#codegen
if walkStruct.prevTime > atime %if previosu time is greater than current time, then increase count to note wrap
    % assumes no packets lost, and updates within 2 seconds of each other..
    walkStruct.nWrap = walkStruct.nWrap + uint16(1);
end
% set in milliseconds for best storage method
walkStruct.aTimeUnroll = uint32((single(walkStruct.nWrap)*65535+single(atime))*resolution*1000); % wrap corrected time scaled in milli seconds

if walkStruct.aTimeUnroll > 4294967294 % max uint32 #
    walkStruct.nWrap = uint16(0);
    walkStruct.timerOverflow = uint8(1); % sets overflow flag to 1
else
    walkStruct.timerOverflow = uint8(0); % resets wrapper back to 0
end

walkStruct.prevTime = atime;