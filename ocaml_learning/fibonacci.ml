let rec fact n=
if n=1||n=2 then 1
else
 fact(n-1)+fact(n-2)
;;