a=float(input("Enter the first number :"))
b=float(input("Enter the second number :"))
val=int(input("Choose the operation :\n1)Add\t2)Subtract\t3)Multiply\t4)Divide: "))
if val==1:
    print(a," + ",b," = ", a+b)
elif val==2:
    print(a," - ",b," = ", a-b)
elif val==3:
    print(a," * ",b," = ", a*b)
elif val==4:
    print(a," / ",b," = ", a/b)
else:
    print("Invalid input")