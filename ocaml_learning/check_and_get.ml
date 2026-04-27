let check_and_get p x =
 if p x then x
 else 0
;;

let result=check_and_get (fun x -> x mod 2=0) 11
;;
