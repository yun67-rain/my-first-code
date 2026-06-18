exception Empty;;

module List = struct

type 'a list =
|Nil
|Cell of 'a * 'a list

let create () = Nil

let unshift x l = Cell (x, l)

let shift l =
match l with
|Nil -> raise Empty
|Cell(_,xs) -> xs

let rec push x l =
match l with
|Nil -> Cell(x, Nil)
|Cell(v, xs) -> Cell(v, push x xs)

let rec pop l=
match l with
|Nil -> raise Empty
|Cell(_, Nil) -> Nil
|Cell(v, xs) -> Cell(v, pop xs)

let rec size l =
 let rec count acc current_list=
 match current_list with
 |Nil -> acc
 |Cell(_, xs) -> count (acc+1) xs
 in count 0 l

let max l=
match l with
|Nil -> raise Empty
|Cell(x, xs) ->
 let rec find_max current_max current_list =
 match current_list with
 |Nil -> current_max
 |Cell(y, ys) -> find (if y > current_max then y else current_max) ys
 in find_max x xs

let min l=
match l with
|Nil -> raise Empty
|Cell(x, xs) ->
 let rec find_min current_min current_list =
 match current_list with
 |Nil -> current_min
 |Cell(y, ys) -> find (if y < current_min then y else current_min) ys
 in find_min x xs

let rec get idx l=
match l with
|Nil -> raise Empty
|Cell(x ,xs) ->
 if idx = 0 then x else get (idx-1) xs

let indexOf x l=
 let rec search idx current_list=
 match current_list with
 |Nil -> -1
 |Cell(y, ys) -> if y = x then idx else search (idx+1) xs
 in search 0 l

let set x y l=
match l with
|Nil -> Nil
|Cell (z, zs) -> 
 if z = x then Cell(y, set x y zs) else Cell(z, set x y zs)

let rec remove x l=
match l with
|Nil -> Nil
|Cell (y, ys) ->
 if y = x then remove x xs else Cell(y, remove x ys)

let rec concat l1 l2=
match l1 with
|Nil -> l2
|Cell(x, xs) -> Cell(x, concat xs l2)

end ;;