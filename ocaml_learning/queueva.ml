exception Empty;;

type 'a stack = 
|Nil
|Cell of 'a * 'a stack
;;

let create () = Nil ;;

let enqueue x q = Cell (x, q);;

let rec front q=
match q with
|Nil -> raise Empty
|Cell(x, Nil) -> x
|Cell(_, xs) -> front xs
;;

let rec dequeue q=
match q with
|Nil -> raise Empty
|Cell(_, Nil) -> Nil
|Cell(x, xs) -> Cell(x, dequeue xs)
;;