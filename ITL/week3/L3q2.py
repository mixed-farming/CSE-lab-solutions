input_file=open("temp.txt",'r')
output_file=open("output.txt",'w')

content=input_file.read()

reversed_content=content[::-1]

output_file.write(reversed_content)

print('Reverse filling process completed')