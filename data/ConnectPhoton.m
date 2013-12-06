Photonfile = 'WNBG05_500Hz';
SS = who('-file',Photonfile);
load(Photonfile,'L_ph1');

% To see how many L_ph sections there are in the saved data
s_SS = 0;
for s = 1:size(SS,1)
    if size(SS{s},2)>3
        if sum(SS{s}(1:4)=='L_ph')==4
            s_SS = s_SS+1;
        end
    end
end

[NumOfReps, NumOfUnits] = size(L_ph1);

%size_cc = 300; %size of one group of microvilli
PH = zeros(s_SS*NumOfReps, NumOfUnits);
%n_sec = fix(size(L_ph1,2)./size_cc);
%n_rem_col = rem(size(L_ph1,2),size_cc);


for i = 1:s_SS
    eval(['load ' Photonfile ' L_ph' num2str(i) ';']);
    %if n_rem_col~=0
    %    eval(['L_ph' num2str(i) '(:,n_sec*size_cc+1:end)=[];']);
    %end
    eval(['aint = L_ph' num2str(i) ';']);
    PH((i-1)*NumOfReps+1:i*NumOfReps, :) = aint;
    clear aint L_ph*
end

save(Photonfile, 'PH', '-append');