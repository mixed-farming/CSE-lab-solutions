class py_solution:
    '''Conversion from Arabic to Roman numericals.'''
    def int_to_Roman(self, num):
        
        val = [
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4,
            1
        ]
        syb = [
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV",
            "I"
        ]
        roman_num = ''
        i = 0
        while num > 0:
            count = num // val[i]
            roman_num += syb[i] * count
            num -= val[i] * count
            i += 1
        return roman_num

 

calculate = py_solution()
print(py_solution.__doc__)
print(calculate.int_to_Roman(1))
print(calculate.int_to_Roman(888))