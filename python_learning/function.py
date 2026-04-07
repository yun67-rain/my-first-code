def check_password(pw):
    return len(pw)>=8

pw=input("パスワードを入力してください:")
if check_password(pw):
    print("強いパスワードです")
else:
    print("弱いパスワードです") 