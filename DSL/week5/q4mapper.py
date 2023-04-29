import pandas as pd
# Heart Disease
df = pd.read_csv('heart_disease_data.csv') 
df = df.dropna()
words = list(df['age'].values)
def main(separator=' --> '):
    for word in words:
        print('%s%s%d' % (word, separator, 1))
if __name__ == "__main__":
 main()