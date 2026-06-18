(*
以下の仕様を満たす関数combineを定義しなさい．リストの要素数が異なる場合は，要素数の少ない方に合わせてよい．
combine [a1; ...; an] [b1; ...; bn] = [(a1,b1); ...; (an,bn)]

例：
# combine;;
- : 'a list -> 'b list -> ('a * 'b) list = <fun>
# combine [1; 2; 3] ['a'; 'b'; 'c'];;
- : (int * char) list = [(1, 'a'); (2, 'b'); (3, 'c')]
# combine [1; 2] ["aa"; "bb"; "cc"];;
- : (int * char) list = [(1, "aa"); (2, "bb")]
*)

(* 目的：2つのリストを受け取り、対応する要素をペアにしたリストを返す。 *)
(* 要素数が異なる場合は、少ない方に合わせる。 *)
(* combine : 'a list -> 'b list -> ('a * 'b) list *)

(* データ定義：
   'a list と 'b list の組は以下のいずれかの形：
   - ([], _) : 少なくとも左側が空リスト
   - (_, []) : 少なくとも右側が空リスト
   - (xh :: xt, yh :: yt) : 両方とも空でないリスト（xh, yh は先頭の要素、xt, yt は残りのリスト）
*)

(* テスト *)
let test1 = combine [] [] = []
let test2 = combine [1; 2; 3] ['a'; 'b'; 'c'] = [(1, 'a'); (2, 'b'); (3, 'c')]
let test3 = combine [1; 2] ["aa"; "bb"; "cc"] = [(1, "aa"); (2, "bb")]
let test4 = combine [1; 2; 3] ["aa"; "bb"] = [(1, "aa"); (2, "bb")]

let rec combine x y = 
match (x, y) with
  | (xh :: xt, yh :: yt) -> (xh, yh) :: combine xt yt
  | _ -> []  (* 片方でも空リストになったら終了 *)
;;