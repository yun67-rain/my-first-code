let rec filter_even h =
match h with
[]->[]
h::t->
if h mod 2 =0 then h::filter_even t
else
 filter_even t 
;;