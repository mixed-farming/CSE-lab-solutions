# Prompt user for input file name
filename = input("Enter the name of the input file: ")

# Open the file
with open(filename) as f:
    # Initialize variables to count the number of lines and the sum of the CGPA values
    count = 0
    total_cgpa = 0
    
    # Iterate over each line in the file
    for line in f:
        # Check if the line starts with "CGPA"
        if line.startswith("CGPA"):
            # Split the line into words and extract the CGPA value
            words = line.split()
            cgpa = float(words[1])
            
            # Add the CGPA value to the total and increment the count
            total_cgpa += cgpa
            count += 1
    
    # Calculate the average CGPA
    if count > 0:
        average_cgpa = total_cgpa / count
        print("The average CGPA is:", average_cgpa)
    else:
        print("No CGPA values found in the file.")
