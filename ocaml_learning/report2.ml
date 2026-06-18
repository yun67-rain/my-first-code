let rec count_ones n=
if n<0 then failwith "Error"
else
match n with
0 -> 0
|_ -> (n mod 2) + count_ones (n / 2)
;;

let rec power_val n=
 let rec aux count=
  if count = 0 then 1
  else n * aux (count - 1)
in
aux n
;;

let rec power_steps n=
 let rec aux count=
  if count = 0 then 1
  else 1 + aux (count - 1)
 in
 aux n
;;

let rec collatz_steps n=
if n=1 then 0
else if n mod 2 = 0 then
 1 + collatz_steps (n/2)
else
 1 + collatz_steps (3 * n + 1)
;;

let rec collatz_path n=
if n=1 then [1]
else if n mod 2 =0 then
 n :: collatz_path (n/2)
else
 n :: collatz_path (3 * n + 1)
;;