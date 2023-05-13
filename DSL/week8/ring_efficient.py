noOfNodes = int(input("Enter total no. of nodes: \n"))
initiatorNode = int(input("Enter initiator node: \n"))
crashed = eval(input("Enter list for whether alive(1) or dead(0): \n"))
newCoord = [initiatorNode]
i = initiatorNode + 1

while True:
    if crashed[i] == 1:
        newCoord.append(i)
        print(f"{i} got {newCoord}")
    i = i + 1
    i = i % noOfNodes
    if i == initiatorNode:
        print(f"{i} got {newCoord}")
        break
coordinator = max(newCoord)
print("New coordinator is " + str(coordinator))
for i in range(noOfNodes):
    print(f"{coordinator} sent P{i} OK")
