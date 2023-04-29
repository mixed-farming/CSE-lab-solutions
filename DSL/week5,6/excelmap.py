import pandas as pd
# German Credit
df = pd.read_excel('german_credit.xlsx')
df = df.dropna()
words1 = list(df['Creditability'].values)
words2 = list(df['CreditAmount'].values)
words3 = list(df['DurationOfCreditInMonths'].values)
for (word1, word2, words3) in zip(words1, words2, words3):
 print(f'{word1} \t {word2} \t {words3}')