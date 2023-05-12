# x=int(input("Enter length : "))
# y=int(input("Enter breadth : "))
# print("Area of rectangle =",x*y)

# x,y=5,7
# print("Before swap : x=",x,"y=",y)
# x,y=y,x
# print("After swap : x=",x,"y=",y)

# num=int(input("Enter a number : "))
# if num%2==0:
#     print("{} is an even number.".format(num))
# else:
#     print("{} is an odd number.".format(num))

# a,b,c=5,5,4
# if a>b and a>c:
#     print("a")
# elif b>c and b>a:
#     print("b")
# elif c>a and c>b:
#     print("c")
# else:
#     print("Large elements are equal")

# list = [11,-21,0,45,66,-93]
# print(list)
# list.append(45)
# print(list)
# list.pop()
# print(list)
# list.insert(0,11)
# print(list)
# del list[4]
# print(list)
# print(list.count(11))
# list.remove(0)
# print(list)
# list.reverse()
# print(list)
# print(len(list))

# t=(1,3,5,7,9,2,4,6,8,10)
# for i in range(len(t)):
#     print(t[i],end=" ")
#     if i==len(t)/2-1:
#         print("\n",end="")

# l=(12,7,38,56,78)
# new_tuple=tuple(x for x in l if x%2==0)
# print(new_tuple)

# l=[11,-21,0,45,66,-93]
# for i in l[:]:
#     if i<0:
#         print(i,end=" ")

# l=[1,-2,3,-4,5,6,7,-8,9]
# pos,neg=0,0
# for i in l[:]:
#     if i>=0:
#         pos+=1
#     else:
#         neg+=1
# print("Positives =",pos)
# print("Negatives =",neg)

l=[1,2,-3,-4,5,6,-7]
for i in l[:]:
    if i%2==0:
        l.remove(i)
print(l)