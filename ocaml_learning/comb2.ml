let rec comb2 (n,m)=
if m=0||n=m then 1
else
 comb2(n-1,m)+comb2(n-1,m-1)
;;