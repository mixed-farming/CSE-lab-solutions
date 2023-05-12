import pandas as pd
df=pd.read_csv('countries_exam.csv')
df=df.dropna()
words1=list(df['country'].values)
words2=list(df['population'].values)
words3=list(df['lifeExpectancy'].values)
for (word1,word2,word3) in zip(words1,words2,words3):
    print(f"{word1}\t{word2}\t{word3}")