from collections import Counter

with open('inputs/input01') as input_file:
    inputs = input_file.read()

up_down_count = Counter(inputs)
up = up_down_count['(']
down = up_down_count[')']

current_floor = up - down
print(f'The instructions take Santa to floor no. {current_floor}!')
# The instructions take Santa to floor no. 74!

current_floor = 0
for pos, direction in enumerate(inputs):
    if direction == '(':
        current_floor += 1
    if direction == ')':
        current_floor -= 1
    if current_floor == -1:
        first_time_in_basement = pos + 1
        break

print(f'The first instruction for which Santa ends up in the basement is {first_time_in_basement}!')
# The first instruction for which Santa ends up in the basement is 1795!
