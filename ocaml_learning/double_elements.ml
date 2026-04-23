let rec double_elements l =
match l with
 [] -> []
 h :: t -> h*2 :: double_elements t
;;