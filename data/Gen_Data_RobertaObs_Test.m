function [] = Gen_Data_RobertaObs_Test()

% Generates the dataset for the FitzHugh-Nagumo benchmarks

NumOfTimePoints = 100;

TimePoints      = zeros(NumOfTimePoints, 2);
TimePoints(:,1) = 0:(10000/(NumOfTimePoints-1)):10000;
TimePoints(:,2) = 0:(10000/(NumOfTimePoints-1)):10000;

% Get solution of ODE
Sol = SBRoberta_Obs(TimePoints(:,1));

TrueData = Sol.reactionvalues;

NumOfReactions = size(TrueData,2);

% Calculate standard deviation of noise to add
NoiseVariance = (0.1*std(TrueData)).^2;

% Add noise to the data
Data = TrueData;

for a = 1:NumOfReactions
    Data(:,a) = Data(:,a) + randn(NumOfTimePoints, 1)*sqrt(NoiseVariance(a));
end

% Save the dataset
save(['./RobertaObs_Test_Data'], 'TimePoints', 'TrueData', 'Data', 'NoiseVariance');


end

