# counter = 100 # An integer assignment
# miles = 1000.0 # A floating point
# name = "John" # A string
# print (counter)
# print (miles)
# print (name)

# a = 5 # integer assignment
# b= 4.56 #floating point assignment
# #mathematical operations with scalar variables
# print (5*a) # would give the result 25
# print (a/2) # would give the result 2.5print(a**2), is the power (squaring operation) would give the result 25

# str = 'Hello World!'
# print (str) # Prints complete string
# print (str[0]) # Prints first character of the string
# print (str[2:5]) # Prints characters starting from 3rd to 5th
# print (str[2:]) # Prints string starting from 3rd character
# print (str * 2) # Prints string two times
# print (str + "TEST") # Prints concatenated string

# var1 = 'Hello World!'
# print ("Updated String :", var1[:6] + 'Python')

# print( "My name is %s and weight is %d kg!" % ('Abay', 55))

# str = "this is string example wow!!!"
# print (str.capitalize())

# str = "this is string example ... wow!!!"
# print(str.count('s'))
# print(str.find('example'))

# str = "THIS IS STRING EXAMPLE ... WOW!!!"
# print (str.lower())

# str = "this is string example ... wow!!! this is really string"
# print (str.replace(" is ", " was "))

# str = "this is string example ... wow!!!"
# print (str.swapcase())

# str = "this is string example ... wow!!!"
# print (str.title())

# list = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
# tinylist = [123, 'john']
# print (list) # Prints complete list
# print (list[0]) # Prints first element of the list
# print (list[1:3]) # Prints elements starting from 2nd till 3rd
# print (list[2:]) # Prints elements starting from 3rd element
# print (tinylist * 2) # Prints list two times
# print (list + tinylist) # Prints concatenated lists

# list = ['physics', 'chemistry', 1997, 2000]
# list.append('maths')
# del list[2]
# print(list)
# print('physics' in list)
# print(len(list))
# list.pop()
# list.insert (2, 'maths')
# list.remove('chemistry')
# list.reverse()
# print(list)

# num=float(input('Enter a number:'))
# if num>0:
#     print('pos number')
# elif num==0:
#     print('zero')
# else:
#     print('Neg number')

# x=float(input('Enter a number:'))
# if x<10:
# print('smaller')
# if x>20:
# print('bigger')
# print('Finished')

# # initialize the variable
# i=1
# n=5
# # while loop from i = 1 to 5
# while i <= n:
# print(i)
# i=i+1

# from math import *
# import numpy as np
# x= [9, 41, 12, 3, 74, 15]
# y=np.zeros(len(x))
# for i in range(len(x)):
#     if x[i]>20:
#         y[i]=x[i]
# print(y)

# x= [9, 41, 12, 3, 74, 15]
# count=sum=avg=0
# for i in x:
#     count=count+1
#     sum=sum+i
# avg=sum/count
# print(count)
# print(sum)
# print(avg)

# x=int(input('Enter a number:'))
# for i in range(1,x+1):
#     if x%i ==0:
#         print(i)

# x= [9, 41, 12, 3, 74, 15]
# for i in x:
#     if i>20:
#         print (i)

# sum = 0
# while True:
#     num = int(input("Enter a number (0 to stop): "))
#     if num == 0:
#         break
#     sum += num
# print("The sum is:", sum)