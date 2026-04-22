let rec comb (n,m)=
if m=0||n=m then 1
else
 comb(n,m-1) * (n-m+1)/m
;;