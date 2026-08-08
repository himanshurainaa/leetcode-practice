class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n, m = len(word1), len(word2)
        last = [-1] * (m + 1)
        last[m] = n
        p = n - 1
        for j in range(m - 1, -1, -1):
            while p >= 0 and word1[p] != word2[j]:
                p -= 1
            last[j] = p
            if p >= 0:
                p -= 1

        ans = []
        i = 0
        changed = False
        for j in range(m):
            while i < n:
                if word1[i] == word2[j]:
                    if not changed or i + 1 <= last[j + 1]:
                        ans.append(i)
                        i += 1
                        break
                else:
                    if not changed and i + 1 <= last[j + 1]:
                        changed = True
                        ans.append(i)
                        i += 1
                        break
                i += 1

        return ans if len(ans) == m else []