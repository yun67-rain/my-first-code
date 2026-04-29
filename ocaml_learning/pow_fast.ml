let rec pow_fast(x,n)=
if n=0 then 1.0
else if n mod 2 =0 then pow_fast(x*.x,n/2)
else x*.pow_fast(x,n-1)
;;