expences={}

while True:
    while True:
        date=input("日付を入力してください(sで検索,qで終了):")
        if date=="":
            print("未入力です")
        else:
            break
    if date=="q":
        break

    if date=="s":
        search_date=input("検索したい日付を入力してください:")

        if search_date in expences:
            data=expences[search_date]
            print(f"【検索結果】{search_date}は[{data['category']}]で{data['amount']}円使っています。")
        else:
            print("その日のデータは見つかりませんでした")
            continue    
    while True:
        money_str=input("金額を入力してください")
        try:
            if money=="":
                print("未入力です")
            else:
                money=int()
                expences[date]=money
                break
        except ValueError:
            print("半角数字で入力してください")


print("---家計簿一覧---")
for date,money in expences.items():
    print(f"{date}:{money}円")

total=sum(expences.values())
print(f"合計金額:{total}円")