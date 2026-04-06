import random

fortunes=["超大吉","大吉","中吉","吉","末吉","凶"]

print("===今日の運勢チェック===")
result=random.choice(fortunes)
print(f"結果は...【{result}】です")

print(f"\n===簡易家計簿===")
items=[]#お金をためていく空のリスト

while True:
    money=int (input("使った金額を入力してください(0で終了):"))
    if money==0:
        break
    items.append(money)

total=sum(items)
if len(items)>0:
    average=total/len(items)
    print(f"本日の合計支出は{total}です")
    print(f"平均金額:{average}")
else:
    print("入力されたデータがありません")    

if result=="凶":
    print("今日は節約しましょう")

print("\n====パスワード強度診断===")
pw=input("設定したいパスワードを入力してください:")

if len(pw)<8:
    print("警告:短すぎます(8文字以上にしてください)")
elif len(pw)>=12:
    print("最強のパスワードです")
elif pw=="12345678" or pw=="password":
    print("警告:予測されやすいパスワードです")
else:
    print("安全なパスワードです")    