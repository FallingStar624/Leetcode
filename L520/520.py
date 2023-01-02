class Solution:
    def __init__(self):
        self.cnt = 0
        self.ans = False

    def capital_check(self, word: str) -> None:
        length = len(word)
        idx = length // 2
        if length == 1:
            self.cnt += word.isupper()
        else:
            self.capital_check(word[:idx])
            self.capital_check(word[idx:])

    def detectCapitalUse(self, word: str) -> bool:
        self.capital_check(word)
        if len(word) == self.cnt:
            self.ans = True
        elif self.cnt == 0:
            self.ans = True
        elif self.cnt == 1 & word[0].isupper():
            self.ans = True
        else:
            self.ans = False
        return self.ans
