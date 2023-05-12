# x=0
# while x<3:
#     print(x)
#     break
#     x+=1
# else:
#     print("Loop ended normally")

# l=[1,2,-3,-4,5,6,-7]
# i=0
# while i<len(l):
#     if l[i]<0:
#         print(l[i],end=" ")
#     i+=1

# l=[1,2,-3,-4,5,6,-7]
# o=e=0
# for i in l:
#     if i%2==0:
#         e+=1
#     else:
#         o+=1
# print("Even:",e)
# print("Odd:",o)

# l=[1,2,-3,-4,5,6,-7]
# for i in l[:]:
#     if i%2==0:
#         l.remove(i)
# print(l)

# import pandas as pd
 
# students_data={"Name":["Manoj Mallya","Verbal Kint","George Westinghouse"],"Height":["5'8","5'5","6'0"],"Qualification":["B.Tech","MBBS","PhD"]}
# print(students_data)
# print()
# frame=pd.DataFrame.from_dict(students_data)
# print(frame)
# print()
# Address=["Udupi","Chicago","NYC"]
# frame["Location"]=Address
# print(frame)

# import pandas as pd
 
# students_data={"Name":["Manoj Mallya","Verbal Kint","George Westinghouse"],"Height":["5'8","5'5","6'0"],"Qualification":["B.Tech","B.com","PhD"]}
# frame=pd.DataFrame.from_dict(students_data)
# Address=["Udupi","Chicago","NYC"]
# frame.insert(2,"Location",Address)
# print(frame)

# import pandas as pd
 
# df1=pd.DataFrame({"Name":["Ram","Diya","Chandan","James","Alice"]})
# df2=pd.DataFrame({"Maths":[80.0,90.0,77.5,87.5,86.5],
#                   "Physics":[81.0,94.0,74.5,83.0,82.5],
#                   "Chemistry":[91.5,86.5,85.5,90.0,91.0], 
#                   "Biology":[82.5,83.5,84.5,85.0,93.0]})
 
# df_new=pd.concat([df1,df2],axis=1)
# print(df_new)
# df_new["Total"]=df_new[["Maths","Physics","Chemistry","Biology"]].sum(axis=1)
# print(df_new)
# print("Sum of all marks =",df_new["Total"].sum())

import pandas as pd
 
frame=pd.DataFrame({"Name":["Annie","Diya","Charles","James","Emily"],
                    "Quiz_1/10":[8.0,9.0,7.5,8.5,6.5],
                    "In-sem_1/15":[11.0,14.0,14.5,13.0,12.5],
                    "Quiz_2/10":[9.5,6.5,8.5,9.0,9.0],
                    "In-sem_2/15":[12.5,13.5,14.5,15.0,13.0]})
 
print(frame)
frame["Total"]=frame[["Name","Quiz_1/10","In-sem_1/15","Quiz_2/10","In-sem_2/15"]].sum(axis=1)
frame.loc["Mean"]=frame[["Name","Quiz_1/10","In-sem_1/15","Quiz_2/10","In-sem_2/15"]].mean()
print(frame)

