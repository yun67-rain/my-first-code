let h = 0.0001;;
let eps = 0.00001;;
let dx = 0.5;;

let diff_forward f x =
(f(x +. h) -. f x) /. h
;;

let diff_central f x =
(f(x +. h) -. f(x -. h)) /. (2.0 *. h)
;;

let rec ext f x0 =
  let df = diff_central f x0 in
  
  if abs_float df < eps then
    (x0, f x0)
  else
    let f_prime x = diff_central f x in
    let ddf = diff_central f_prime x0 in
    
    let x_next = x0 -. (df /. ddf) in
    ext f x_next
;;

let area_rectangle f x dx_val = 
  (f x) *. dx_val
;;

let area_trapezoid f x dx_val = 
  ((f x +. f (x +. dx_val)) /. 2.0) *. dx_val
;;

let area_simpson f x dx_val =
  let mid = x +. (dx_val /. 2.0) in
  ((f x +. 4.0 *. f mid +. f (x +. dx_val)) /. 6.0) *. dx_val
;;

let rec integral area_func f a b =
  if a >= b then 0.0
  else area_func f a dx +. integral area_func f (a +. dx) b
;;