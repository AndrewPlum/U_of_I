/*********************************************
 * Id: plum0598
 *
 * This program creates a family tree using prolog
 *********************************************/

% father rule - F is the father of Y if F is male and is a parent of Y
father(F, Y) :- male(F), parent(F, Y).

% mother rule - M is the mother of Y if M is female and is a parent of Y
mother(M, Y) :- female(M), parent(M, Y).

% grandfather rule - G is the grandfather of Y if G is male and is a parent of Y's parent
grandfather(G, Y) :- male(G), parent(G, P), parent(P, Y).

% grandmother rule - G is the grandmother of Y if G is female and is a parent of Y's parent
grandmother(G, Y) :- female(G), parent(G, P), parent(P, Y).

% sister rule - X is the sister of Y if X is female, X and Y have the same parents, and X is not Y
sister(X, Y) :- female(X), parent(P, X), parent(P, Y), X \= Y.

% brother rule - X is the brother of Y if X is male, X and Y have the same parents, and X is not Y
brother(X, Y) :- male(X), parent(P, X), parent(P, Y), X \= Y.

% aunt rule - A is the aunt of Y if A is female, A is a sibling of Y's parent, and A is not the mother of Y
aunt(A, Y) :- female(A), parent(P, Y), sibling(A, P), \+ mother(A, Y).

% uncle rule - U is the uncle of Y if U is male, U is a sibling of Y's parent, and U is not the father of Y
uncle(U, Y) :- male(U), parent(P, Y), sibling(U, P), \+ father(U, Y).

% ancestor rule - A is an ancestor of Y if A is a parent of Y or A is an ancestor of Y's parent
ancestor(A, Y) :- parent(A, Y).
ancestor(A, Y) :- parent(P, Y), ancestor(A, P).
