module Vector = struct 

exception Empty

let vempty () = []

let rec at idx v=
match v with
|[] -> raise Empty
|x :: xs ->
 if idx = 0 then x else at (idx-1) xs

let vector l = l

let vlength v =
 let rec count acc current_list=
 match current_list with
 |[] -> acc
 |_ :: xs -> count (acc+1) xs
 in count 0 v 

let vshow v =
 let rec print_list current_list=
 match current_list with
 |[] -> ()
 |x :: xs ->
  print_int x ; print_string "," ; print_list xs
 in print_list v 

let isvempty v=
match v with
|[] -> true
|_ -> false
end ;;