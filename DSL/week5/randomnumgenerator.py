import random
numbers = [random.randint(1, 100) for _ in range(1000)]
with open("random.txt", "w") as file:
    for number in numbers:
        file.write(str(number) + "\n")
        