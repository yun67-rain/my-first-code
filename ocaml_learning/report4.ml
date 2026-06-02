let rec exchange_pass_c x=
match x with
|[] -> ([], false, 0)
|[a] -> ([a],false, 0)
|h1 :: h2 :: t ->
 if h1 > h2 then 
 let (rest,_, count)=exchange_pass_c(h1 :: t) in
 (h2 :: rest, true, count+1)
 else 
 let(rest,judge, count)=exchange_pass_c (h2 :: t) in
 (h1 :: rest, judge, count+1)
;; 

let rec exchange_sort_c x=
let (next,judge, count1)=exchange_pass_c x in
if judge then 
 let (final_list, count2) = exchange_sort_c next in
 (final_list, count1 + count2)
else (next, count1)
;;

let rec select_min_c x=
match x with
|[] -> failwith "empty list"
|[a] -> (a, [], 0)
|h :: t ->
 let (min_val, rest, count)=select_min_c t in
 if h<min_val then
 (h, t, count+1)
 else
 (min_val, h :: rest, count+1)
;;

let rec selection_sort_c x=
match x with
|[] -> ([], 0)
|_->
 let (min_val, rest, count1) = select_min_c x in
 let (sorted_rest, count2) = selection_sort_c rest in
 (min_val :: sorted_rest, count1 + count2)
;;

let rec insert_c a x=
match x with
|[] -> ([a], 0)
|h :: t ->
 if a <= h then (a :: h :: t, 1)
 else
 let (inserted_list, count) = insert_c a t in
  (h :: inserted_list, count + 1)
;;

let rec insertion_sort_c x=
match x with
|[] -> ([], 0)
|h :: t -> 
 let (sorted_tail, count1) = insertion_sort_c t in
 let(final_list, count2) = insert_c h sorted_tail in
 (final_list, count1 + count2)
;;

let rec split x=
match x with
|[] -> ([],[])
|[x] -> ([x],[])
| x :: y :: z ->
 let (left, right) =split z in
 (x :: left, y :: right)
;;

let rec merge_c x y=
match x,y with
|[],_ -> (y, 0)
|_,[] -> (x, 0)
| xh :: xt, yh ::yt ->
 if xh <= yh then
  let (merge_rest, count) = merge_c xt y in
  (xh :: merge_rest, count+1)
 else
  let (merge_rest, count) = merge_c x yt in
  (yh :: merge_rest, count+1)
;;

let rec merge_sort_c x=
match x with
|[] -> ([], 0)
|[a] -> ([a], 0)
|_ ->
 let (left, right) = split x in
 let (sorted_left, count1) = merge_sort_c left in
 let (sorted_right, count2) = merge_sort_c right in
 let (final_list, count3) = merge_c sorted_left sorted_right in
 (final_list, count1 + count2 + count3)
;;

let rec partition_c pivot x=
match x with
|[] -> ([], [], 0)
|h :: t ->
 let (small, big, count) = partition_c pivot t in
 if h <= pivot then
 (h :: small, big, count+1)
 else
 (small, h :: big, count+1)
;;

let rec quick_sort_c x=
match x with
|[] -> ([], 0)
|pivot :: t ->
 let (small, big, count1) = partition_c pivot t in
 let (sorted_small, count2) = quick_sort_c small in
 let (sorted_big, count3) =quick_sort_c big in
 (sorted_small @ (pivot :: sorted_big), count1 + count2 + count3)
;;