 (*********************************************
 * Id: plum0598
 *
 * This program uses sml to make 5 functions: 
 * reverse, sq, sqsum, cycle, and semrev
 *********************************************)

(*
fun take (n, lst) =
    if n <= 0 then []
    else case lst of
             [] => []
           | x::xs => x :: take(n-1, xs);
           
fun drop 0 lst = lst
  | drop n [] = []
  | drop n (x::xs) = drop (n-1) xs;
*)

(*
fun take (0, _) = []
   | take (_, []) = []
   | take (n, x::xs) = x :: take(n-1, xs);
   
fun drop (0, lst) = lst
   | drop (_, []) = []
   | drop (n, x::xs) = drop(n-1, xs);
*)

fun reverse(nil) = (nil)
   | reverse(x::xs) = reverse(xs) @ [x];

fun sq num = num * num;

fun sqsum [] = 0
   | sqsum (x::xs) = x * x + sqsum xs

fun cycle (lst, n) =
   let
      fun take (_, 0) = []
         | take ([], _) = []
         | take (x::xs, n) = x :: take(xs, n-1)
      
      fun drop (lst, 0) = lst
         | drop ([], _) = []
         | drop (x::xs, n) = drop(xs, n-1)

      
      val revN = take(n, lst)
      val rest = drop(n, lst)
   in
      rest @ revN
   end;

(*
fun semrev (n, lst) =
    let
        val reversed = reverse(take(n, lst))
    in
        lst @ reversed
    end;
*)

fun semrev (lst, n) =
   let
      fun take (_, 0) = []
         | take ([], _) = []
         | take (x::xs, n) = x :: take(xs, n-1)
      
      fun drop (lst, 0) = lst
         | drop ([], _) = []
         | drop (x::xs, n) = drop(xs, n-1)

      
      val revN = reverse(take(n, lst))
      val rest = drop(n, lst)
   in
      rest @ revN
   end;

(*
fun semrev (L: nil, n: int): L =
   let
      val len = length L
      val m = n mod len
   in
      semrev (take m L) @ drop m L
   end;
*)
   
(*
fun semrev (nil,n) = (nil)
   | semrev(x:xs) = 
   
fun member (_,nil) = false
|   member (e,x::xs) =
      if e=x then true else member(e,xs);
   
fun reverse(nil) = (nil)
|   reverse(x::xs) =
        reverse(xs) @ [x];
        
fun merge (nil, ys) = ys
 |   merge (xs, nil) = xs
 |   merge (x::xs, y::ys) =
       if (x  y) then x :: merge(xs, y::ys)
       else y :: merge(x::xs, ys);
       
fun halve nil = (nil, nil)
 |   halve [a] = ([a], nil)
 |   halve (a::b::cs) =
       let
         val (x, y) = halve cs
       in
         (a::x, b::y)
       end;
       
fun mergeSort nil = nil
|   mergeSort [a] = [a]
|   mergeSort theList =
      let
         val (x, y) = halve theList
      in
        merge(mergeSort x, mergeSort y)
      end;
      
fun prod(a:int,b) =
   (print ("Multiplying "
    ^ (Int.toString(a))
      ^ " * "
      ^ (Int.toString(b))
      ^ " = "
      ^ (Int.toString(a*b))
      ^ "\n");
      a*b);
*)
