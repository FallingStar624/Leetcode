from typing import List
import heapq
from heapq import heapify


class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        rnd, flag = 0, True
        cnt = dict()
        # refer for min round
        min_rnd = [0 for _ in range(100001)]
        min_rnd[1], min_rnd[2], min_rnd[3] = 1, 1, 1
        for i in range(4, 100001):
            min_rnd[i] = min(min_rnd[i-2], min_rnd[i-3]) + 1
        # heap setting
        heap = []
        heapify(heap)
        for task in tasks:
            if cnt.get(task):
                cnt[task] += 1
            else:
                cnt[task] = 1
        for k, v in cnt.items():
            heapq.heappush(heap, (-v, k))
        # complete tasks
        while flag and len(heap):
            top = heapq.heappop(heap)
            top_cnt = -top[0]
            if top_cnt == 1:
                flag = False
            else:
                rnd += min_rnd[top_cnt]
                top_cnt = 0
            if top_cnt:
                heapq.heappush(heap, (-top_cnt, top[1]))

        # empty check
        if len(heap) > 0:
            rnd = -1
        return rnd


