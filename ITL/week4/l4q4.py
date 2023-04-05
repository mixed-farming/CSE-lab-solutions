class capitalize:
    '''Class modifies the input string to upper case.'''
    def get_string(self):
        self.str = input("Enter a string : ")
    def print_string(self):
        print(self.str.upper())

obj=capitalize()
obj.get_string()
obj.print_string()
