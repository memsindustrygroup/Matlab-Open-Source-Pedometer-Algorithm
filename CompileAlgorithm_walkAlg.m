%emlc CompileAlgorithm -eg {[0 0 0]',[0 0 0]',[0 0 0]',0}  -c -report -T rtw:lib


% Switch to current directory & restore default path
p = mfilename('fullpath');
[pathstr, name, ext] = fileparts(p)
cd(pathstr)
restoredefaultpath
% warning on

close all
clear all

commandwindow

fprintf('\nGenerating AutoCode...\n')
warning off


walkStruct = stepCounter_struct_init;

% load 'SPwrap_sample_data.mat'; % load sample data variables
% addpath('EMmatlab/em_overrides_direct'); % only add this path

%%% real time workshop config object
% rtwcfg = emlcoder.RTWConfig;
% rtwcfg = emlcoder.RTWConfig('ert'); % Engineering Laptop ert setting
cfg = coder.config('lib');
% cfg = coder.config('lib','ecoder',false);
% rtwcfg.ObjectivePriorities = 'Efficiency';
cfg.FilePartitionMethod = 'MapMFileToCFile'; % MapMFileToCFile or SingleFile
cfg.CCompilerOptimization = 'Off';
cfg.EnableVariableSizing = true;
cfg.InlineThreshold = int32(0);
cfg.HardwareImplementation.ProdHWDeviceType = 'ARM Compatible->ARM Cortex';
cfg.HardwareImplementation.TargetHWDeviceType = 'ARM Compatible->ARM Cortex';
cfg.GenCodeOnly = true;

% set to tool chain configuration - to remove code gen warning
cfg.GenerateMakefile = true;
cfg.MakeCommand = 'make_rtw';
cfg.TemplateMakefile = 'default_tmf';
cfg.CCompilerOptimization = 'Off';

accDataIn = zeros(1,3,'single');
aRMSin = zeros(1,3,'single');
tDataIn = uint32(0);
whichThr = single(0);
resolution = single(1/32000);
atime = uint16(0);


codegen  walkAlg3 -args {walkStruct,accDataIn,aRMSin,tDataIn,whichThr} ...
         stepCounter_struct_init -args {} ...
         aTimeUnroll2 -args {atime,resolution,walkStruct}...
         -config cfg -c -report



% codegen App_Tracker -args {kSet,m,w,mtracker,walkStruct,steptrack,steptrack0,steptrack1,steptrackOut} -config cfg -c -report
% % codegen  SPAlgorithm_wrap1 -args {m,m2,magdef,accdef,gyrodef,kSet,mcalSet,w,k1,dataOut,mcalOut,mcalSIHI_in,gbias_in}  -config cfg -c -report


     
     
fprintf('\nCode Generation Complete!\n')



