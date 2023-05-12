# nums = input("Enter a list of integers separated by space: ").split()
# nums = [int(num) for num in nums]
# print(nums)

# import pandas as pd
# import numpy as np
# s=pd.Series([3,9,-2,10,5])
# print(s.sum())
# print(s.min())
# print(s.max())

# import pandas as pd
# data = [['Dinesh',10],['Nithya',12],['Raji',13]]
# df = pd.DataFrame(data)
# print(df,"\n")
# df = pd.DataFrame(data,columns=['Name','Age'])
# print(df)

# import pandas as pd
# data = {'Name':['Kavitha', 'Sudha', 'Raju','Vignesh'],'Age':[28,34,29,42]}
# df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
# print(df)

# import pandas as pd
# data = [['Dinesh',10],['Nithya',12],['Raji',13]]
# df = pd.DataFrame(data,columns=['Name','Age'],index=['1)','2)','3)'])
# print(df)

# import pandas as pd
# import numpy as np
# df1=pd.DataFrame({'A':pd.Timestamp('20230211'),'B':np.array([3]*4,dtype='int64'),'C':pd.Categorical(['Male','Female','Male','Female'])})
# print(df1)
# print(df1.shape)
# print(df1.dtypes)
# print(df1.head())
# print(df1.tail())
# print(df1.describe())
# print(df1.T)

import pandas as pd
import numpy as np

dates=pd.date_range('20200226', periods=100)
df = pd.DataFrame(np.random.randn(100,4), index=dates, columns=list('ABCD'))
# print(df)
# print(df.head())
# print(df.tail())
# print(df.index)
# print(df.columns)
# print(df.T)
# print(df.sort_index(axis=0,ascending=True))
# print(df.sort_values(by='B',ascending=False))
# print(df['20200229':'20200310'])
# print(df.iloc[0])
# print(df.iloc[0,:2])
# print(df.iloc[0,0])
# print(df['A'])
# print(df[['A','B']])
# print(df[['A','B']][:5])
# print(df.loc['20200229':'20200310',['A','B']][:5])
# print(df[df.A>0])
# df['F']=np.array("Male")
# print(df)
# df.loc[:,'D']=np.array([5]*len(df))
# df['D']=np.array(5)
# print(df)
# df.drop ('B', axis=1, inplace=True)
# print(df)
# df.drop ('20200604', axis =0, inplace=True)
# print(df)

# Reading a XLSX file format
# G=pd.read_excel('German Credit_for_Week2.xlsx',sheet_name='Sheet1')
# print(G.head())

# Reading a HTML file format
# B = pd.read_html('http://www.fdic.gov/bank/individual/failed/banklist.html')

# Reading a TXT file format
# H = pd.read_table('HR.txt')
# print(H.head())
# f=H['Department'].value_counts()
# print(f)
# print(H[['Department','Age']])








