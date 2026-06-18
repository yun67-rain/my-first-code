module Queue = struct
 exception Empty
 
 type 'a queue = 'a list

 let create () = []
 
 let enqueue x q = x :: q

 let rec front q =
 match q with
 |[] -> raise Empty
 |[x] -> x
 |_ :: xs -> front xs

 let rec dequeue q =
 match q with
 |[] -> raise Empty
 |[_] -> []
 |x :: xs -> x :: dequeue xs
 
end ;;