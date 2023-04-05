# a=[int(x) for x in input("Enter numbers : ").split()]
# print("Minimum element in the array :",min(a))

#bubble sort
# a=[int(x) for x in input("Enter numbers : ").split()]
# for i in range(0,len(a)-1,1):
#     for j in range(0,len(a)-i-1,1):
#         if(a[j]>a[j+1]):
#             temp=a[j]
#             a[j]=a[j+1]
#             a[j+1]=temp
# print(a)

#selection sort
# A = [64, 25, 12, 22, 11]
# for i in range(len(A)):
#     # Find the minimum element in remaining 
#     # unsorted array
#     min_idx = i
#     for j in range(i+1, len(A)):
#         if A[min_idx] > A[j]:
#             min_idx = j      
#     # Swap the found minimum element with 
#     # the first element        
#     A[i], A[min_idx] = A[min_idx], A[i]
# print ("Sorted array")
# for i in range(len(A)):
#     print("%d" %A[i],end=" ")

#matrix multiplication
print("Enter the dimensions of matrix 1")
r1=int(input("Row : "))
c1=int(input("Column : "))
print("\nEnter the dimensions of matrix 2")
r2=int(input("Row : "))
c2=int(input("Column : "))
if c1!=r2:
    print("Matrices cannot be multiplied.")
else:
    print("Input matrix1 : ")
    a=[[int(input(f"Enter the value for row {i+1}, column {j+1} : ")) for j in range(c1)] for i in range(r1)]
    print("Input matrix2 : ")
    b=[[int(input(f"Enter the value for row {i+1}, column {j+1} : ")) for j in range(c2)] for i in range(r2)]
    c = [[0 for j in range(c2)] for i in range(r1)]
    for i in range(0,r1,1):
        for j in range(0,c2,1):
            c[i][j]=0
            for k in range(0,c1,1):
                c[i][j]+=(a[i][k]*b[k][j])
    print(c)

# Increment chars of a string(done using ascii value approach)
# a="manoj"
# b=""
# for i in a:
#     b+=chr(ord(i)+1)
# print(b)

#Reversing a number
# def reverse(num):
#     rev = 0
#     while num > 0:
#         rev = (rev * 10) + num%10
#         num = num // 10
#     return rev
# print(f'reverse the number of {reverse(12345)}')
# # OR
# num = 12345
# print(str(num)[::-1])



