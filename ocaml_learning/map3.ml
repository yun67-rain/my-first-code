let map3 f a b c =[f a;f b; f c]
let result = map3 (fun x -> x+100) 10 20 30
;;