let apply_and_add f a b = (f a)+(f b)
let result = apply_and_add (fun x -> x*x) 3 4
;;