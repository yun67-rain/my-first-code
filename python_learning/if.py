password=input("パスワードを入力してください:")

if password=="python123":
    print("ログイン成功")
elif password=="":
    print("パスワードを入力してください")
else:
    print("パスワードが違います")