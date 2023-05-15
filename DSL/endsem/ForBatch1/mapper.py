import pandas as pd
df=pd.read_csv('exam_score.csv')
df=df.dropna()
words1=list(df['group'].values)#group A, group B, ... group E
words2=list(df['category'].values)#male or female
words3=list(df['math score'].values)#score in maths
for (word1,word2,word3) in zip(words1,words2,words3):#sort based on group values to return to highest scorer in maths in both categories of all groups
    print(f"{word1}\t{word2}\t{word3}")