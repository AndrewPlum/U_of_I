father(F,Y):- male(F), parent(F,Y).
mother(M,Y):- female(M), parent(M,Y).
grandfather(G,Y):- male(G), father(G,P), parent(P,Y).
grandmother(G,Y):- female(G), mother(G,P), parent(P,Y).
sister(X,Y):- female(X), parent(P,X), parent(P,Y).
brother(X,Y):- male(X), parent(P,X), parent(P,Y).
aunt(A,Y):- parent(P,Y), sister(A,P).
uncle(U,Y):- parent(P,Y), brother(U,P).
ancestor(A,Y):- parent(A,Y). 
ancestor(A,Y):- parent(P,Y), ancestor(A,P).
