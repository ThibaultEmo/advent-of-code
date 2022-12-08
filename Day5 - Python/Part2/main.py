import re

file = open("input.txt", "r")

#a temp array of 9 stacks, we will need to reverse them to get a real stack state to init the stacks (start of file)
temp_stacks = [[],[],[],[],[],[],[],[],[]]


#variable to init the first stacks states (start of file)
first_stack_position, offset_between_letters = 1,4

#array that will stock the stacks after init
stacks = []

init_stack = False

for line in file:
    #.strip() could give empty string need to prevent crash when checking first character
    if (len(line.strip()) > 0):

        # GETTING THE FIRST STACKS STATE
        if (line.strip())[0] == '[':
            for i in range(len(temp_stacks)):
                position = first_stack_position + i * offset_between_letters

                if (position < len(line)):
                    if line[position].isalpha():
                        temp_stacks[i].append(line[position])

        #after getting all infos in the temp_stack we need to reverse each list to have the right stack behavior
        elif not init_stack:
            for i in range(len(temp_stacks)):
                stacks.append(temp_stacks[i][::-1])

            init_stack = True

        #IF ITS AN INSTRUCTION LINE
        elif (line.strip())[0] == 'm':
            #get all the numbers in a line
            numbers_in_string = re.findall(r'\d+', line)

            #the first number will indicate how many crates we have to move, the second one the stack we need to get the crate from, and the third number the stack we need to put the crate on
            number_of_moves, from_stack, to_stack = int(numbers_in_string[0]),int(numbers_in_string[1]) - 1,int(numbers_in_string[2]) - 1

            #to not change the order we still keep the stack system but put the crates in a temp stack that we will destack after so it will be in the same order as the start
            temp_stack = []

            #we take the crates and put them in the temp_stack
            for i in range(number_of_moves):
                #move the crate from the wanted stack to the target stack
                temp_stack.append(stacks[from_stack].pop())

            #we destack the temp_stack in the right stack so the order hasn't been changed
            for i in range(len(temp_stack)):
                stacks[to_stack].append(temp_stack.pop())


#will print all crates on top to get answer in right format
for stack in stacks:
    print(stack.pop(), end='')

