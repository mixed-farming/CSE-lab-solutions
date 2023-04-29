import fileinput

# Initialize variables
current_country = None
total_confirmed = 0
recovered = 0

# Loop over lines from stdin
for line in fileinput.input():

    # Split the line into key-value pairs
    key, value, extra = line.strip().split('\t')

    # If the key has changed, print out the previous country's total and reset the counter
    if key != current_country and current_country is not None:
        print('{:<15} {:<15} {:<15}'.format(current_country, total_confirmed, recovered))
        total_confirmed = 0
        recovered=0

    # Update the current country and add to the total confirmed cases
    current_country = key
    total_confirmed += int(value)
    recovered += int(extra)

# Print out the final country's total
print('{:<15} {:<15} {:<15}'.format(current_country, total_confirmed, recovered))