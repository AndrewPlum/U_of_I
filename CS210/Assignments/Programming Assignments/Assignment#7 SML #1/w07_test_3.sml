 (*********************************************
 * Id: plum0598
 *
 * This program uses sml to make 5 functions: 
 * reverse, sq, sqsum, cycle, and semrev
 *********************************************)

(* This first function is used in semrev*)
fun reverse(nil) = (nil)
   | reverse(x::xs) = reverse(xs) @ [x];

fun sq num = num * num;

fun sqsum [] = 0
   | sqsum (x::xs) = x * x + sqsum xs

(*
fun cycle (L, 0) = L
   | cycle (nil,_) = nil
   | cycle (x::xs,n) = cycle (xs @ [x],n-1);
   
fun semrev (L, 0) = L
   | semrev (nil,_) = nil
   | semrev (x::xs, n) = semrev (xs,n-1) @ [x];
*)

(*
fun cycle (lst, n) =
   let
      fun get_back ([], _) = []
         |get_back (x::xs, 0) = xs
         | get_back (x::xs, n) = x :: get_back(xs, n-1) 
      fun get_front (lst, 0) = lst
         | get_front ([], _) = []
         | get_front (x::xs, n) = get_front(xs, n-1)
      val back = get_back(n, lst)
      val front = get_front(n, lst)
   in
      front @ back
   end;

fun semrev (lst, n) =
   let
      fun get_back (x:xs, 0) = xs
         | get_back ([], _) = []
         | get_back (x::xs, n) = x :: get_back(xs, n-1)
      fun get_front (lst, 0) = lst
         | get_front ([], _) = []
         | get_front (x::xs, n) = get_front(xs, n-1)
      val back = reverse(get_back(n, lst))
      val front = get_front(n, lst)
   in
      front @ back
   end;
*)

fun cycle (nil,_) = nil;
   | cycle (x::xs,n) = 
      let
         fun split (x,xs,n) = 
            let 
               val (below,above) = spl
         val (front, back) = split (x,xs,n)