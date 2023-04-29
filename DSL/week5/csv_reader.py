import csv
# reading csv file without using pandas
# Open the CSV file
with open('covid_19_data.csv', newline='') as csvfile:
    # Create a CSV reader object
    reader = csv.reader(csvfile, delimiter=',')

    # Iterate over each row in the CSV file
    for row in reader:
        # Get the country/region and confirmed columns from the row
        country = row[1]
        confirmed = row[7]

        # Print out the country/region and confirmed columns separated by tabs
        print(f'{country}\t{confirmed}')
