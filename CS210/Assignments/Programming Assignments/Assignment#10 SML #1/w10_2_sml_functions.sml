 (*********************************************
 * Id: plum0598
 *
 * This program uses sml to make 2 functions: 
 * member and split
 *********************************************)

(*
fun sq num = num * num;

fun sqsum [] = 0
   | sqsum (x::xs) = x * x + sqsum xs

fun cycle (L, 0) = L
   | cycle (nil,_) = nil
   | cycle (x::xs,n) = cycle (xs @ [x],n-1);
   
fun semrev (L, 0) = L
   | semrev (nil,_) = nil
   | semrev (x::xs, n) = semrev (xs,n-1) @ [x];
   
fun cycle (nil,_) = nil;
   | cycle (x::xs,n) = 
      let
         fun split (x,xs,n) = 
            let 
               val (below,above) = spl
         val (front, back) = split (x,xs,n)
*)

fun member (_,nil) = false
   | member (e,x::xs) = if e=x then true else member(e,xs);
   
fun split (pivot, nil) = (nil, nil)
   (*
   | split (nil, first::rest) = (nil, first::rest)
   *)
   | split (pivot, first::rest) =
      let
         val (small, large) = split (pivot, rest)
      in
         if first < pivot
            then (first::small, large)
            else (small, first::large)
      end;
