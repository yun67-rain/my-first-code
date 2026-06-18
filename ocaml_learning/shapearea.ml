type shape =
|Point
|Circle of int
|Rectangle of int * int
|Square of int
;;

let area s =
match s with
|Point -> 0
|Circle r -> r * r * 3
|Rectangle (h, w) -> h * w
|Square len -> len * len
;;