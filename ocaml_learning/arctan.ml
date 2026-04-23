let arctan1 n=
let rec plus k=
 if k<0 then 0.0
 else minus k+. 1.0/.(float_of_int(4*k+1))
and minus k=
 plus(k-1)-. 1.0/.(float_of_int(4*k+3))
in 
 plus n
;;