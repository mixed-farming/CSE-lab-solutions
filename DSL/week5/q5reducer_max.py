import fileinput

max_country = None
max_value = 0
recoveries = 0 

current_country = None
current_value = 0
current_recoveries = 0

for line in fileinput.input():
    # Split the line into key-value pairs
    key, value, extra = line.strip().split('\t')

    # If we've moved on to a new country, check if the previous country had the max value
    if key != current_country:
        if current_value > max_value:
            max_country = current_country
            max_value = current_value
            recoveries = current_recoveries

        current_country = key
        current_value = int(value)
        current_recoveries = int(extra)
    else:
        current_value += int(value)
        current_recoveries += int(extra)

# Check the final country as well
if current_value > max_value:
    max_country = current_country
    max_value = current_value
    recoveries = current_recoveries

# Print out the max country and its value
print(f'{max_country}\t{max_value}\t{recoveries}')
