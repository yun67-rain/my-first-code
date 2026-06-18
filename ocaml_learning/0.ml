(*
引数で渡すリストの中に同じ要素が複数含まれていなければtrueを返し，他の場合falseを返す関数distinctを定義しなさい．

例：
# distinct;;
- : 'a list -> bool = <fun>
# distinct [];;
- : bool = true
# distinct [11; 2; 2; 3; 3; 4];;
- : bool = false
# distinct [1; 2; 3; 4];;
- : bool = true
# distinct ["aa"; "aaa"; "bbb"; "ccc"];;
- : bool = true
*)

(* 目的：受け取ったリストの中に同じ要素が複数含まれていなければ true を、含まれていれば false を返す *)
(* distinct : 'a list -> bool *)

(* データ定義：
   'a list は以下のいずれかの形：
   - [] : 空リスト
   - first :: rest : 先頭の要素が first で、残りのリストが rest
*)

(* 補助関数のヘッダと目的 *)
(* 目的：リストの中に要素 x と同じものが含まれているかを判定する *)
(* member : 'a -> 'a list -> bool *)
let rec member x lst = 
match lst with
| [] -> false
| first :: rest -> 
 if first = x then true 
 else member x rest
;;

(* 本体 *)
let rec distinct lst=
match lst with
|[] -> true
|first :: rest ->
 if member first rest then false
 else distinct rest
;;

(* テスト *)
let test1 = distinct [] = true
let test2 = distinct [11; 2; 2; 3; 3; 4] = false
let test3 = distinct [1; 2; 3; 4] = true
let test4 = distinct ["aa"; "aaa"; "bbb"; "ccc"] = true