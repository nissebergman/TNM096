act(go(X,Y),
[shakey(S), floor(F), on(S,F), in(S,X),connected(X,Y) ],
[in(S,X)],
[in(S,Y)]
).

act(push(B,X,Y),
[shakey(S), floor(F), box(B), on(S,F), connected(X,Y), in(S,X), in(B,X)],
[in(B,X), in(S,X)],
[in(B,Y), in(S,Y)]
).

act(climbUp(B),[shakey(S), box(B), floor(F), room(R), on(S,F), in(B,R), in(S,R)],
[on(S,F)],
[on(S,B)]
).

act(climbDown(B), [shakey(S), box(B), floor(F), on(S,B)],
[on(S,B)],
[on(S,F)]
).

act(turnOn(L), [shakey(S), box(B), light(L), on(S,B), lightPos(L,false)],
[lightPos(L,false)],
[lightsPos(L,true)]
).

act(turnOff(L), [shakey(S), box(B), light(L), on(S,B), lightPos(L,true)],
[lightPos(L,true)],
[lightPos(L,false)]
).

goal_state(
[      in(s,room1),
       lightPos(light1, false),
       in(box2, room2)
]).

initial_state(

     [      %Initial shakey
            shakey(s),
            in(s, room3),
            on(s, floor),
            
            %Rooms
            room(room1),
            room(room2),
            room(room3),
            room(room4),
            connected(room1, corridor),
            connected(room2, corridor),
            connected(room3, corridor),
            connected(room4, corridor),
            connected(corridor, room1),
            connected(corridor, room2),
            connected(corridor, room3),
            connected(corridor, room4),
            
            %Boxes
            box(box1),
            box(box2),
            box(box3),
            box(box4),
            in(box1, room1),
            in(box2, room1),
            in(box3, room1),
            in(box4, room1),
            
            %Lights
            light(light1),
            light(light2),
            light(light3),
            light(light4),
            in(light1, room1),
            in(light2, room2),
            in(light3, room3),
            in(light4, room4),
            lightPos(light1, true),
            lightPos(light2, false),
            lightPos(light3, false),
            lightPos(light4, true)

     ]).
