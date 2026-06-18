(*
第１引数にリストlst，第２引数に整数nを渡し，lstのn番目の要素を取り除いたリストを返す関数rmnthを定義しなさい．最初の要素は0番目とする．

例：
# rmnth;;
- : 'a list -> int -> 'a list = <fun>
# rmnth [1; 2; 3] 0;;
- : int list = [2; 3]
# rmnth ['a'; 'b'; 'c'; 'd'] 2;;
- : char list = ['a'; 'b'; 'd']
# rmnth ["aa"; "bb"] 2;;
- : string list = ["aa"; "bb"]
*)

(* 目的：リスト lst の n 番目の要素を取り除いたリストを返す。最初の要素は 0 番目とする。 *)
(* 指定された位置がリストの長さ以上の場合は、元のリストをそのまま返す。 *)
(* rmnth : 'a list -> int -> 'a list *)

(* データ定義：
   'a list は以下のいずれかの形：
   - [] : 空リスト
   - first :: rest : 先頭の要素が first で、残りのリストが rest
*)

(* 本体 *)
let rec rmnth lst n = 
match lst with
|[] -> []  
|first :: rest -> 
 if n = 0 then rest 
 else first :: rmnth rest (n - 1)
;;

(* テスト *)
let test1 = rmnth [] 0 = []
let test2 = rmnth [1; 2; 3] 0 = [2; 3]
let test3 = rmnth ['a'; 'b'; 'c'; 'd'] 2 = ['a'; 'b'; 'd']
let test4 = rmnth ["aa"; "bb"] 2 = ["aa"; "bb"]