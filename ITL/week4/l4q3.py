class power:
    '''Class to calculate the power of a number.'''
    result=1
    def __init__(self,a,m):
        self.a=a
        self.m=m
    def calculate(self):
        for i in range(m):
            self.result*=self.a
        return self.result

a=int(input("Enter the base number : "))
m=int(input("Enter the index : "))
obj=power(a,m)
print(f"{a} to the power {m} = ",obj.calculate())