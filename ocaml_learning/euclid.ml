let rec eu (a,b)=
 if a mod b =0 then b
 else
  let r= a mod b in
  eu(b,r)
;;