#Checking strength of the password
s=input("Enter password : ")
if len(s)<6 or len(s)>20:
    print("Not strong")
else:
    has_upper=False
    has_lower=False
    has_number=False
    for i in s:
        if i.isupper():
            has_upper=True
        if i.islower():
            has_lower=True
        if i.isnumeric():
            has_number=True
    if not has_number or not has_lower or not has_upper:
        print("Not strong")
    else:
        print("Strong")