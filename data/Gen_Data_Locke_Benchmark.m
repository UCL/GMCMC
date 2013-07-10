function [] = Gen_Data_Locke_Benchmark()

% Generates the dataset for the FitzHugh-Nagumo benchmarks

NumOfTimePoints = 100;

TimePoints      = zeros(NumOfTimePoints, 2);
TimePoints(:,1) = 0:(48/(NumOfTimePoints-1)):48;
TimePoints(:,2) = 0:(48/(NumOfTimePoints-1)):48;

% Get solution of ODE
Sol = SBLocke_2005a_Full(TimePoints(:,1));

TrueData = Sol.statevalues;

% Calculate standard deviation of noise to add
NoiseVariance = (0.1*std(TrueData)).^2;

% Add noise to the data
Data = TrueData;

for a = 1:6
    Data(:,a) = Data(:,a) + randn(NumOfTimePoints, 1)*sqrt(NoiseVariance(a));
end

% Save the dataset
save(['./Locke_Benchmark_Data'], 'TimePoints', 'TrueData', 'Data', 'NoiseVariance');


end

