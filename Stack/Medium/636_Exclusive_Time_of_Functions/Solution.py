from typing import List, Tuple


class Solution:
    def getInfo(self, s: str) -> Tuple[int, bool, int]:
        l = s.split(':')

        id_val = int(l[0])
        is_start = l[1][0] == 's'
        time = int(l[2])

        return id_val, is_start, time

    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * n
        st = []

        prev_id, prev_is_start, prev_time = self.getInfo(logs[0])
        st.append(prev_id)
        
        for i in range(1, len(logs)):
            id_val, is_start, time = self.getInfo(logs[i])
            if is_start:
                if st:
                    res[st[-1]] += time - prev_time
                st.append(id_val)
                prev_time = time
            else:
                res[st[-1]] += time  - prev_time + 1
                st.pop()
                prev_time = time + 1

        return res






