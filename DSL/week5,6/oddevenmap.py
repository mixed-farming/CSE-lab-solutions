import sys

for line in sys.stdin:
    number = int(line.strip())
    if number % 2 == 0:
        print(number, "even")
    else:
        print(number, "odd")
