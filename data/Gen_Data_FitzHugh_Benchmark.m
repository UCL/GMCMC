function [] = Gen_Data_FitzHugh_Benchmark()

% Generates the dataset for the FitzHugh-Nagumo benchmarks

NumOfTimePoints = 100;

TimePoints      = zeros(NumOfTimePoints, 2);
TimePoints(:,1) = 0:(20/(NumOfTimePoints-1)):20;
TimePoints(:,2) = 0:(20/(NumOfTimePoints-1)):20;

% Get solution of ODE
Sol = SBFitzHughNagumo(TimePoints(:,1));

TrueData = Sol.statevalues;

% Calculate standard deviation of noise to add
NoiseVariance = (0.1*std(TrueData)).^2;

% Add noise to the data
Data = TrueData;

Data(:,1) = Data(:,1) + randn(NumOfTimePoints, 1)*sqrt(NoiseVariance(1));
Data(:,2) = Data(:,2) + randn(NumOfTimePoints, 1)*sqrt(NoiseVariance(2));

% Save the dataset
save(['./FitzHugh_Benchmark_Data'], 'TimePoints', 'TrueData', 'Data', 'NoiseVariance');


end

