exception Empty;;

let create () = [];;

let enqueue x q = x :: q;;

let rec front q =
match q with
|[] -> raise Empty
|[x] -> x
|_ :: xs -> front xs
;;

let rec dequeue q =
match q with
|[] -> raise Empty
|[_] -> []
|_ :: xs -> x :: dequeue xs
;;