 (*********************************************
 * Id: plum0598
 *
 * This program uses sml to make 4 functions: 
 * sq, sqsum, cycle, and semrev
 *********************************************)

fun sq num = num * num;

fun sqsum [] = 0
   | sqsum (x::xs) = x * x + sqsum xs;

fun cycle (L, 0) = L
   | cycle (nil,_) = nil
   | cycle (x::xs,n) = cycle (xs @ [x],n-1);
   
fun semrev (L, 0) = L
   | semrev (nil,_) = nil
   | semrev (x::xs, n) = semrev (xs,n-1) @ [x];