class Song:
    def __init__(self, title, duration):
        self.title=title
        self.duration=duration

    def __str__(self):
        second=self.duration%60
        minute=self.duration//60
        return f"[{self.title}]({minute}分{second}秒)"

    def __lt__(self, other):
        return self.duration < other.duration

# --- 動作確認用のメイン処理 ---
# プレイリスト（曲のリスト）
playlist = [
    Song("Roundabout", 504),
    Song("Walk Like an Egyptian", 204),
    Song("Modern Crusaders", 164)
]

print("--- ソート前 ---")
for song in playlist:
    print(song)

# 大小関係 (__lt__) を定義したことで、そのまま sort() が使えるようになります
playlist.sort()

print("\n--- 再生時間が短い順にソート後 ---")
for song in playlist:
    print(song)
