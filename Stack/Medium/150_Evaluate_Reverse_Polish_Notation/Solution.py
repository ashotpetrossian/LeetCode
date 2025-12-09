from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: int(a / b)
        }

        st = []
        for oper in tokens:
            if oper not in operations:
                st.append(int(oper))
            else:
                x = st.pop()
                y = st.pop()

                st.append(operations[oper](y, x))

        return st[0]