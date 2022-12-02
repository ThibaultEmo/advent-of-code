file = open("input.txt", "r")

elves_values = []

current_elf = 0

for line in file:
    if len(line.strip()) == 0:
        elves_values.append(current_elf)
        current_elf = 0
    else:
        current_elf += int(line)

elves_values.sort()
print(elves_values)
print(elves_values[-1])
sum = elves_values[-1] + elves_values[-2] + elves_values[-3]
print(sum)