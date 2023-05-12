# a=[x for x in input("Enter numbers : ").split()]
# print("Minimum element in the array : ",min(a))

# a=[x for x in input("Enter numbers : ").split()]
# for i in range(0,len(a)-1,1):
#     for j in range(0,len(a)-i-1,1):
#         if(a[j]>a[j+1]):
#             temp=a[j]
#             a[j]=a[j+1]
#             a[j+1]=temp
# print(a)

# print("Enter the dimensions of matrix 1")
# r1=int(input("Row : "))
# c1=int(input("Column : "))
# print("\nEnter the dimensions of matrix 2")
# r2=int(input("Row : "))
# c2=int(input("Column : "))
# if c1!=r2:
#     print("Matrices cannot be multiplied.")
# else:
#     print("Input matrix1 : ")
#     a=[[int(input(f"Enter the value for row {i+1}, column {j+1} : ")) for j in range(c1)] for i in range(r1)]
#     print("Input matrix2 : ")
#     b=[[int(input(f"Enter the value for row {i+1}, column {j+1} : ")) for j in range(c2)] for i in range(r2)]
#     c = [[0 for j in range(c2)] for i in range(r1)]
#     for i in range(0,r1,1):
#         for j in range(0,c2,1):
#             c[i][j]=0
#             for k in range(0,c1,1):
#                 c[i][j]+=(a[i][k]*b[k][j])
#     print(c)
