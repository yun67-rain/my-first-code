expences={}

while True:
    while True:
        date=input("日付を入力してください(sで検索,qで終了):")
        if date=="":
            print("未入力です\n")
        else:
            break
    if date=="q":
        break

    if date=="s":
        while True:
            search_date=input("検索したい日付を入力してください(qで終了):")

            if search_date=="q":
                break

            if search_date in expences:
                data=expences[search_date]
                print(f"【検索結果】{search_date}は[{data['category']}]で{data['amount']}円使っています。\n")
            else:
                print("その日のデータは見つかりませんでした\n")
                continue 
        continue   
    
    category=input("カテゴリを入力してください(例:食費、交通費):")

    while True:
        money_str=input("金額を入力してください:")
        try:
            if money_str=="":
                print("未入力です\n")
            else:
                money=int(money_str)
                expences[date]={"amount":money,"category":category}
                break
        except ValueError:
            print("半角数字で入力してください\n")

if date!="s":
    print("\n---家計簿一覧---")
    total=0
    for date,data in expences.items():
        print(f"{date}|カテゴリ:{data['category']}|金額:{data['amount']}円")
        total+=data['amount']

    print("--------------")
    print(f"合計金額:{total}円")