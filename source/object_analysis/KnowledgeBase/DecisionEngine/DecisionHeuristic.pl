%% AUTHOR: NA
% DATE: 03/29/17
% DESC: A list of guidelines for determining the correct move
% FILE: DecisionHeuristic.pl

%% Object is not flat and is part of ground surface => walkOn
walkOn(X):- \+flat(X), groundSurface(X).

%% Object is not flat and is not part of ground surface => evade
evade(X):- \+flat(X), \+groundSurface(X).

%% Object is flat and is part of ground surface and can support agent weight => walkOn
walkOn(X):- flat(X), groundSurface(X).

%% Object is flat and part of ground surface and can't hold agent weight => evade
evade(X):- flat(X), groundSurface(X), \+holdWeight(X, Agent).

%% Object is not flat and is part of ground surface and can hold agent weight => walkOn
walkOn(X):- \+flat(X), groundSurface(X), holdWeight(X, Agent).

%% Object is not flat and is part of ground surface and can't hold agent weight => evade
evade(X):- \+flat(X), groundSurface(X), \+holdWeight(X, Agent).

%% Object is a wall => evade
evade(X):- wall(X).

%% Object is a closed window => evade
evade(X):- window(X), closed(X).

%% Object is an open window => evade
evade(X):- window(X), opened(X).

%% Object is an open door => walkOn
walkOn(X):- door(X), opened(X).

%% Object is a closed door => evade
evade(X):- door(X), closed(X).

%% Object is moving and passive and is part of ground surface => walkOn
walkOn(X):- moving(X), passive(X), groundSurface(X).

%% Object is moving and is active => evade
evade(X):- moving(X), active(X).

%% There is no ground surface => stop
stop(Agent):- \+groundSurface(X).
