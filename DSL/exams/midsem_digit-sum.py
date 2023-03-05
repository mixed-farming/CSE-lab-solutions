n=int(input("Enter number of tuples : "))
a,c=[],[]
for i in range(n):
    b=tuple([int(x) for x in input("Enter the tuple elements : ").split()])
    a.append(b)
for i in a:
    for j in i:
        sum=0
        while j>0:
            sum+=(j%10)
            j//=10
        c.append(sum)
print(c)