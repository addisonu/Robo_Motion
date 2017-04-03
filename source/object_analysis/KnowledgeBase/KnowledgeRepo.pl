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
changeState(Y)

%% Objects can stop moving


%% Objects can move at can move in 3 space


%% Objects can move in 360 degrees on each plane


%% Objects can contort their shape


%% Objects can be static

%% Objects can be dynamic

%% Some objects are organic


%% Some objects are inorganic

%% Some objects are synthetic

%% Some objects are natural

%% Some organic objects are mammals

%% Some mammals are humans



%% Objects may have a rational course

%% Objects may move irratically

%% Objects may be moved by external forces

%% Object location may be fixed by external forces

%% Objects may have movement that follows known patterns

%% Object may have movenment that doesn't follow known patterns


%% 10 is the highest priority

%% 1 is the lowest priority

%% A human object as priority 10

%% Some synthetic objects have priority 10

%% Active moving objects have priority greater than 5
