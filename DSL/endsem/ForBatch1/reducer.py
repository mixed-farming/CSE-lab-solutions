import fileinput
curr=None
category=None
max_math_male=-1
max_math_female=-1
for line in fileinput.input():
    group,gender,score= line.strip().split('\t')
    if curr and curr!=group:
        print('Group : ',group)
        print('Highest math scorer among males : ',max_math_male)
        print('Highest math scorer among females : ',max_math_female,'\n')
        max_math_male=-1
        max_math_female=-1
    curr=group
    category=gender
    score=int(score)
    if category=='male' and score>max_math_male:
        max_math_male=score
    elif category=='female' and score>max_math_female:
        max_math_female=score
print('Group : ',group)#to print the highest scorers of last group
print('Highest math scorer among males : ',max_math_male)
print('Highest math scorer among females : ',max_math_female)
