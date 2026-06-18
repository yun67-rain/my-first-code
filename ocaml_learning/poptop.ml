let create () = [];;

let push st x = x :: st;;

let pop st =
match st with
|[] -> raise Empty
|_ :: xs -> xs 
;;

let top st =
match st with
|[] -> raise Empty
|x :: _ -> x
;;