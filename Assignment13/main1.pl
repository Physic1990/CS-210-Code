father(F,Y) :- 
  parent(F,Y).

mother(M,Y) :- 
  parent(M,Y).

grandfather(G,Y) :- 
  father(G,X), parent(X,Y).

grandmother(G,Y) :- 
  mother(G,X), parent(X,Y).

sister(X,Y) :- 
  parent(P,X), parent(P,Y), female(X).

brother(X,Y) :- 
  parent(P,X), parent(P,Y), male(X).

aunt(A,Y) :- 
  sister(A,P), parent(P,Y).

uncle(U,Y) :- 
  brother(U,P), parent(P,Y).

ancestor(A,Y) :- 
  parent(A,Y).

ancestor(A,Y) :- 
  parent(A,X), ancestor(X,Y).
