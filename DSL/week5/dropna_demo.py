import pandas as pd

# create a DataFrame with missing values
data = {'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Emily'],
        'Age': [25, 28, 32, None, 24],
        'Country': ['USA', None, 'UK', 'Canada', 'USA']}
df = pd.DataFrame(data)

# display the original DataFrame
print(df)

# drop rows with missing values
df = df.dropna()

# display the cleaned DataFrame
print(df)