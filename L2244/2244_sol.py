class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        freqs = Counter(tasks)
        res = 0
        for task, freq in freqs.items():
            if freq == 1:
                return -1
            res += (freq + 2) // 3
        return res

            
