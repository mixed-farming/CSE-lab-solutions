n=int(input("Enter number of tuples : "))
a,c=[],[]
for i in range(n):
    b=tuple([int(x) for x in input("Enter the tuple elements : ").split()])
    a.append(b)
for i in a:
    sum=0
    for j in i:
        sum+=j
    c.append(sum)
print(c)