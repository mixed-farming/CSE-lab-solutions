import pandas as pd
# # Heart Disease
# df = pd.read_csv('heart_disease_data.csv')
# df = df.dropna()
# words1 = list(df['age'].values)
# words2 = list(df['chol'].values)
# Covid 19
df = pd.read_csv('covid_19_data.csv')
df = df.dropna()
words1 = list(df['Country/Region'].values)
words2 = list(df['Confirmed'].values)
words3 = list(df['Recovered'].values)
# # Example
# df = pd.read_csv('example.txt', delimiter='\t')
# df.columns = ['date', 'time', 'city', 'type', 'amount', 'payment']
# df = df.dropna()
# words1 = list(df['city'].values)
# words2 = list(df['amount'].values)
# # German Credit
# df = pd.read_csv('german_credit.csv')
# df = df.dropna()
# words1 = list(df['DurationOfCreditInMonths'].values)
# words2 = list(df['CreditAmount'].values)
for (word1, word2, words3) in zip(words1, words2, words3):
    print(f'{word1} \t {word2} \t {words3}')
