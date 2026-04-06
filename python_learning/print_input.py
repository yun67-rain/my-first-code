year_str=input("今は何年ですか？:")
#input関数は必ず文字列になる

current_year=int(year_str)
#数値として計算するために、int型に変換する

remaining_years=2030-current_year

print(f"2030年まで、あと{remaining_years}年ですね！")