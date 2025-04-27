%  Id: plum0598
%  This program implements an a suduku solver in prolog

/* Define digits used */

d(1).
d(2).
d(3).
d(4).

/* Are list elements different */

different([]).
different([H|T]):-
   \+(member(H, T)), /* Remember \+ is a not */
   different(T).

/* Check if a list contains digits that can be accepted */

check([]).
check([H|T]):-
   d(H),
   check(T).

/* Check if a 2x2 subgrid contains acceptable digits and different elements */

check_subgrid([A,B,C,D]):-
   check([A,B,C,D]),
   different([A,B,C,D]).

/* Main sudoku predicate */

sudoku(Puzzle, Solution):-
   Solution = Puzzle,
   Puzzle = [
      S11,S12,S13,S14,
      S21,S22,S23,S24,
      S31,S32,S33,S34,
      S41,S42,S43,S44
   ],
   /* Check rows */
   check_subgrid([S11,S12,S13,S14]),
   check_subgrid([S21,S22,S23,S24]),
   check_subgrid([S31,S32,S33,S34]),
   check_subgrid([S41,S42,S43,S44]),
   /* Check columns */
   check_subgrid([S11,S21,S31,S41]),
   check_subgrid([S12,S22,S32,S42]),
   check_subgrid([S13,S23,S33,S43]),
   check_subgrid([S14,S24,S34,S44]),
   /* Check 2x2 subgrids */
   check_subgrid([S11,S12,S21,S22]),
   check_subgrid([S13,S14,S23,S24]),
   check_subgrid([S31,S32,S41,S42]),
   check_subgrid([S33,S34,S43,S44]).
