import os #ファイルがあるかチェックするもの

expences={}

if os.path.exisits("kakeibo.txt"):
    with open("kakeibo.txt","r",encoding="utf-8")as f:
        for line in f:
            data_list=line.strip().split(",")

            if len(data_list)==3:
                date=data_list[0]
                category=data_list[1]
                money=int(data_list[2])
                expences[date]={"amount":money,"category":category}
                print("データを読み込みました!")

while True:
    while True:
        date=input("日付を入力してください(cで集計,sで検索,qで終了):")
        if date=="":
            print("未入力です\n")
        else:
            break
    if date=="q":
        break

    if date=="c":
        while True:
            target=input("集計したいカテゴリを入力してください(qで終了):")
            cat_total=0

            if target=='q':
                break

            for date,data in expences.items():
                if data["category"]==target:
                    cat_total+=data["amount"]
            print(f"{target}の合計は{cat_total}円です\n")
            continue
        continue

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

if date=="q":
    print("\n---家計簿一覧---")
    total=0
    for date,data in expences.items():
        print(f"{date}|カテゴリ:{data['category']}|金額:{data['amount']}円")
        total+=data['amount']

    print("--------------")
    print(f"合計金額:{total}円")

    with open("kakeibo.txt","w",encoding="utf-8")as f:
        for date,data in expences.items():
            f.write(f"{date},{data['category']},{data['amount']}\n")
    print("ファイルを保存しました!")
