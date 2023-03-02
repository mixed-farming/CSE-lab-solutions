def isPalindrome(j):
    k=str(j)
    return k==k[::-1]
    # for i in range(0,len(k)//2,1): #trivial approach
    #     if k[i]!=k[len(k)-i-1]:
    #         return 0        
    # return 1

a=[(121,23,34),(45,67,303)]
b=[]
for i in a:
    for j in i:
        if isPalindrome(j)==1:
            b.append(j)
print(b)