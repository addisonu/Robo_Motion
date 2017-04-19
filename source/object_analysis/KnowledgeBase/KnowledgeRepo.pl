%% AUTHOR: NA
%% DATE: 03/31/17
%% DESC: Collection of axioms about the world
%% FILE: KnowledgeRepo.pl


%% objects can be in 3 space
dynamicState(Y):- xPlane(Y), yPlane(Y), zPlane(Z).

%%objects can move 
dynamicState(Y).

%%objects can be static
staticState(Y).

%%object can change from being static to moving
staticState(Y); dynamicState(Y).

%% objects can change from being moving to static
dynamicState(Y); staticState(Y).

%% Objects can start moving
changeState(Y, startMove).

%% Objects can stop moving
changeState(Y, stopMove).

%% Objects can move at can move in 3 space
movePlane(x, y, z).

%% Objects can move in 360 degrees on each plane
moveAngle(0, 360).

%% Objects can contort their shape
dimension(Y, Xplane, Yplane, Zplane).

%% Some objects are organic
organic(Y).

%% Some objects are inorganic
inorganic(Y).

%% Some objects are synthetic
synthetic(Y).

%% Some objects are natural
natural(Y).

%% Some organic objects are mammals
organic(X):- mammal(Y).

%% Some mammals are humans
mammal(Y):- human(Y).

%% A vehicle is synthetic
synthetic(Y):- vehicle(Y).

%% A vehicle is robust 
robust(Y):- vehicle(Y).

%% Objects may have a rational course
rationalMove(Y).

%% Objects may move irratically
irrationalMove(Y).

%% Objects may be moved by external forces
move(Y):- externalForce(Y); internalForce(Y).

%% Object location may be fixed by external forces
still(Y):- externalForce(Y).

%% Objects may have movement that follows known patterns
predictableMove(Y).

%% Object may have movenment that doesn't follow known patterns
unpredictableMove(Y).

%% 10 is the highest priority
highestPriority(Y):- priority(Y, 10).

%% 1 is the lowest priority
lowestPriority(Y):- priority(Y, 1).

%% 5 is moderate priority
moderatePriority(Y):- priority(Y, 5).

%% 9 is moderate priority
highPriority(Y):- priority(Y, 9).

%% 8 is moderate priority
highPriority(Y):- priority(Y, 8).

%% 7 is moderate priority
mediumPriority(Y):- priority(Y, 7).

%% 6 is moderate priority
mediumPriority(Y):- priority(Y, 6).

%% 4 is moderate priority
lowPriority(Y):- priority(Y, 4).

%% 3 is moderate priority
lowPriority(Y):- priority(Y, 3).

%% 2 is moderate priority
moderatePriority(Y):- priority(Y, 2).

%% A human object as priority 10
highestPriority(Y):- human(Y).

%% Some synthetic objects have priority 10
synthetic(Y):- highestPriority(Y); priority(Y, Z).

%% Active moving objects have priority greater than 5
moderatePriority(Y):- dynamic(Y).
