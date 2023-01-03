from typing import List
from collections import deque


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ans = []
        # transpose (to -> from)
        trans = [[] for _ in range(n)]
        for p, c in edges:
            trans[c].append(p)
        for node in range(n):
            visit = set()
            q = deque([node])
            while q:
                curr = q.popleft()
                for anc_node in trans[curr]:
                    if anc_node not in visit and anc_node not in q:
                        visit.add(anc_node)
                        q.append(anc_node)
            ans.append(sorted(list(visit)))
        return ans


