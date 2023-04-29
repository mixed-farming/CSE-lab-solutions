import fileinput#or import sys

creditability = None
count=0
totalcredit=0
totalcreditmonths=0


print('{:<15}{:<15}{:<15}{:<15}'.format('Creditability','Count','AvgCredit','AvgCreditMonths'))
for line in fileinput.input():#or sys.stdin:
    key, value, extra = line.strip().split('\t')

    if key != creditability and creditability is not None:
        print('{:<15}{:<15}{:<15}{:<15}'.format(creditability,count,totalcredit//count,totalcreditmonths//count))
        creditability=key
        totalcredit=int(value)
        totalcreditmonths=int(extra)
        count=1

    count+=1
    creditability=key
    totalcredit += int(value)
    totalcreditmonths += int(extra)

print('{:<15}{:<15}{:<15}{:<15}'.format(creditability,count,totalcredit//count,totalcreditmonths//count))