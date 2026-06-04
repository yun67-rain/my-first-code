# 元となるログデータ（サンプル）
raw_logs = [
    "[INFO] System started successfully.",
    "[WARN] Connection timeout, retrying...",
    "[ERROR] database connection failed.",
    "[INFO] User logged in.",
    "[error] critical out of memory execution stopped.",
    "[INFO] Task completed."
]

def filter_errors(log_data):
   for log in log_data:
     print(f"-> 今からこの行をチェックします:{log}")
     if "error" in log.lower():
        yield log.upper()

print("---エラーログの抽出を開始します---")

for check in filter_errors(raw_logs):
   print(check)

print("---抽出が完了しました---")