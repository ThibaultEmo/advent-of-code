file = open("input.txt", "r")

elves_values = []

current_elf = 0

for line in file:
    if len(line.strip()) == 0:
        elves_values.append(current_elf)
        current_elf = 0
    else:
        current_elf += int(line)

print(max(elves_values))
