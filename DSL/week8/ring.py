import sys

processes = []
num_processes = 0
election_initiator = -1

def parse_arguments():
    global num_processes, election_initiator
    if len(sys.argv) != 3:
        print("Usage: python3 ring_algorithm.py <number of processes> <election initiator>")
        sys.exit(1)
    election_initiator = int(sys.argv[1])
    num_processes = int(sys.argv[2])

def initialise_processes():
    global processes #processes is a list with each element being a dictionary with two keys: id and active
    for i in range(num_processes):
        processes.append({"id": i, "active": True})

def election():
    # Fail the process with maximum ID
    max_id = fetch_maximum()
    processes[max_id]["active"] = False
    print("Process", processes[max_id]["id"], "fails")
    # Begin election process
    current = election_initiator
    next = (current + 1) % num_processes
    print("Election initiated by Process", current)
    while True:
        if processes[next]["active"]:
            print("Process", processes[current]["id"], "passes Election (", processes[current]["id"], ") to", processes[next]["id"])
            current = next
        next = (next + 1) % num_processes
        if next == election_initiator:
            print("Process", processes[current]["id"], "passes Election (", processes[current]["id"], ") to", processes[next]["id"])
            break
    # Identify new coordinator
    coord = fetch_maximum()
    print("Process", processes[coord]["id"], "becomes coordinator")
    # Send Coordinator message to all active processes
    for i in range(0, coord):
        print(f'{coord} sends COORDINATOR message to {i}')
    # current = coord
    # next = (current + 1) % num_processes
    # while True:
    #     if processes[next]["active"]:
    #         print("Process", processes[current]["id"], "passes Coordinator (", processes[coord]["id"], ") message to process", processes[next]["id"])
    #         current = next
    #     next = (next + 1) % num_processes
    #     if next == coord:
    #         print("Process", processes[current]["id"], "passes Coordinator (", processes[coord]["id"], ") message to process", processes[next]["id"])
    #         print("End of Election")
    #         break

def fetch_maximum():
    max_id = -1
    max_index = -1
    for i in range(num_processes):
        if processes[i]["active"] and processes[i]["id"] > max_id:
            max_id = processes[i]["id"]
            max_index = i
    return max_index

# Main function to start the algorithm
parse_arguments()
initialise_processes()
election()