let rec sum_n n =
if n=0 then 0
else n + sum_n(n-1)
;;