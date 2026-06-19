module Queue : sig
 exception Empty
 type 'a queue 

 val create : unit -> 'a queue
 val enqueue : 'a queue -> 'a -> 'a queue
 val dequeue : 'a queue -> 'a queue
 val peek : 'a queue -> 'a
end = struct
 exception Empty
 type 'a queue =Q of 'a list

 let create () = Q []

 let enqueue (Q l) a=
 let rec last list =
  match list with
  |[] -> [a]
  | x :: xs -> x :: last xs
 in Q (last l)

 let dequeue (Q l)=
 match l with
 |[] -> raise Empty
 |x :: xs -> Q xs

 let peek (Q l)=
 match l with 
 |[] -> raise Empty
 |x :: _ -> x 
end ;;