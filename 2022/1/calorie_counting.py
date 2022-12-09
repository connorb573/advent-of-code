with open('input.txt') as file:
    lines = file.readlines()

    accumulator = 0
    values=[]

    for line in lines:
        if line.strip():
            line.replace('\n', '')
            accumulator += int(line)
        else:
            values.append(accumulator)
            accumulator = 0

    accumulator = 0
    for x in range(0, 3):
        print(max(values))
        accumulator += max(values)
        values.remove(max(values))

    print(accumulator)