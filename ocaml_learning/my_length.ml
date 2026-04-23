let rec my_length l = 
match l with
 []->0
 h :: t -> 1 + my_length t
;;