import fileinput
curr=None
maxPop=-22
lifeExp=-22
for line in fileinput.input():
    country,pop,exp= line.strip().split('\t')
    if curr and curr!=country:
        print("%s\t%s\t%s"%(curr,maxPop,lifeExp))
        maxPop=-1
        lifeExp=-1
    curr=country
    if int(pop)>maxPop:
        maxPop=int(pop)
        lifeExp=float(exp)
if curr: 
    print("%s\t%s\t%s"%(curr,maxPop,lifeExp))