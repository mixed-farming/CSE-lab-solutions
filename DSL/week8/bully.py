import sys

initiatorNode = int(sys.argv[1])
noOfNodes = int(sys.argv[2])

def bully_algorithm():
    print("BULLY ALGORITHM SIMULATION\n")
    print(f'Node {initiatorNode} notices the current coordinator {noOfNodes} has failed')
    biggerNodes = []
    for i in range(initiatorNode+1, noOfNodes):
        print(f'{initiatorNode} sends ELECTION message to {i}')
        biggerNodes.append(i)
    for i in biggerNodes:
        print(f'{i} sends OK message to {initiatorNode}')
    while len(biggerNodes) != 1:
        i = biggerNodes[0]
        for j in range(i+1, noOfNodes):
            print(f'{i} sends ELECTION message to {j}')
        for k in range(i+1, noOfNodes):
            print(f'{k} sends OK message to {i}')
        biggerNodes.remove(i)
    newCoordinatorNode = biggerNodes[0]
    for i in range(0, newCoordinatorNode):
        print(f'{newCoordinatorNode} sends COORDINATOR message to {i}')

if __name__ == '__main__':
    bully_algorithm()