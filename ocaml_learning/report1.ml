let rec checkl a x=
match x with
 [] -> false
|h :: t -> 
 if h = a then true
 else checkl a t
;;

let rec dellt n x=
match x with 
[] -> []
|h :: t ->
  if n=0 then x
  else if n<0 then failwith "Error"
  else dellt (n-1) t
;;

let rec dellt2 a x=
match x with
[] -> []
|h :: t ->
 if a=1 then t
 else h :: dellt2 (a-1) t
;;

let rec posl n x=
match x with
[] -> failwith "Not Exist..."
|h :: t ->
 if n=1 then h
 else if n<1 then failwith "Not Exist..."
 else posl (n-1) t
;;

let rec add2list x=
match x with 
[] -> []
|h1 :: h2 :: t -> (h1+h2) :: add2list(h2 :: t)
|_ -> []
;;

let rec mullist x y=
match (x,y) with
(h1 :: t1, h2 :: t2) -> (h1 * h2) :: mullist t1 t2
|_ -> []
;;

let rec chglist (a,b) x=
match x with
[] -> []
|h :: t ->
 if h=a then b :: chglist (a,b) t
 else h :: chglist (a,b) t
;;

let rec replicate n a=
if n=0 then []
else a :: replicate (n-1) a
;;

let rec inslist n a x=
if n<1 then failwith "Error"
else match x with
[] -> [a]
|h :: t ->
 if n=1 then a :: x
 else h :: inslist (n-1) a t
;;

let rec merge x y=
match (x,y) with
([],[]) -> []
|([],y) -> y
|(x,[]) -> x
|(h1 :: t1,h2 :: t2)->
 h1 :: h2 :: merge t1 t2
;;

let rec inside_length x=
match x with
[] -> 0
|h ::t ->
 (List.length h)+inside_length t
;;

let rec concat x=
match x with
[] -> []
|h :: t ->
 h @ concat t
;;

let rec assoc a x=
match x with
[] -> failwith "Not found..."
|(key,value) :: t ->
 if key=a then value
 else assoc a t
;;

let rec minimum x=
match x with
[] -> failwith "Error"
|[h] -> h
|h :: t ->
 let m = minimum t in
 if h<m then h
 else m
;;

let rec extract f x=
match x with
[] -> []
|h :: t ->
 if f h then h :: extract f t
 else extract f t
;;

let rec index x a=
match x with
[] -> failwith "Not found"
|h :: t ->
 if h=a then 0
 else 1+ index t a
;;

let rec numOfRotes (m,n)=
if m=0 || n=0 then 1
else numOfRotes(m-1,n) + numOfRotes(m,n-1)
;;

let rec mem a x=
match x with
[] -> false
|h :: t -> if h = a then true else mem a t
;;

let rec inter x y=
match x with 
[] -> []
|h :: t ->
 if mem h y then h :: inter t y
 else inter t y
;;

let rec union x y=
match y with
[] -> x
|h :: t ->
 if mem h x then union x t
 else h :: union x t
;;

let rec diff x y=
match x with
[] -> []
|h :: t ->
 if mem h y then diff t y
 else h :: diff t y
;;