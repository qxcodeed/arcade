from typing import List
import random

def fit(line: List[str], index: int, value: int, prox: int): 
    left = line[max(0, index - prox) : index]
    right = line[index + 1: min(index + prox + 1, len(line))]
    return str(value) not in (left + right)

def find_next(line: List[str], index):
    return "".join(line).find(".", index + 1)

def solver(line: List[str], index: int, lim: int, prox: int, rand: bool = False, first = True) -> List[str]:
    if(index == -1):
        # print("".join(line))
        return ["".join(line)]
    answers = []
    space = random.sample(range(lim + 1), lim + 1) if rand else range(lim + 1)
    for v in space:
        if fit(line, index, v, prox):
            line[index] = str(v)
            #print("".join(line))
            new_index = find_next(line, index)
            answers += solver(line, new_index, lim, prox, rand, first)
            if first and len(answers) == 1:
                return answers
            #    return True
    line[index] = "."
    #print("".join(line))
    return answers


def generate(lim, prox, size):
    line = ["." for _ in range(size)]
    answers = solver(line, 0, lim, prox, True, True)
    return answers[0]

def destroy(line, lim, prox):
    for _ in range(100):
        line2 = [v for v in line]
        pos = random.randint(0, len(line) - 1)
        line2[pos] = "."
        backup = [v for v in line2]
        answers = solver(backup, 0, lim, prox, False, False)
        #print(len(answers))
        if len(answers) == 1:
            line = [v for v in line2]
    return line

code = generate(3, 3, 7)
print(code)
line = destroy([c for c in code], 3, 3)
print(line)
exit(1)

line = input()
line = [c for c in line]
prox = int(input())

for lim in range(1, 10):
    answers = solver(line, 0, lim, prox)
    if len(answers) > 0:
        print(lim)
        print("\n".join(answers))
        break

