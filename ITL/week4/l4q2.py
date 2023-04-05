class finder:
    '''Class to find the sum of pair of elements equal to target.'''
    def __init__(self,a,x):
        self.a=a
        self.x=x
    def find(self):
        for i in range(0,len(self.a)-1):
            for j in range(i+1,len(self.a)):
                if (self.a[i]+self.a[j])==self.x:
                    return f"Sum of numbers at indices {i},{j}"
        return "No solution exists"

a=[int(x) for x in input("Populate the array : ").split()]
x=int(input("Enter the target element : "))
obj=finder(a,x)
print(obj.find())