import sys

count = {"even": 0, "odd": 0}
for line in sys.stdin:
    value, key = line.strip().split()
    count[key] += 1

print("Even count:", count["even"])
print("Odd count:", count["odd"])
