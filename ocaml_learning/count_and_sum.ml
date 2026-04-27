let rec count_and_sum l=
match l with
[] -> (0,0)
h ::t ->
 let (c,s)=count_and_sum t in
 (c+1,s+h)
;;