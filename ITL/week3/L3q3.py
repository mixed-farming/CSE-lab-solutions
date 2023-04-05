def bin_recurse(a,low,high,x):
    if low<=high:
        mid=(low+high)//2
        if a[mid]==x:
            return mid
        elif a[mid]>x:
            return bin_recurse(a,low,mid-1,x)
        else:
            return bin_recurse(a,mid+1,high,x)
    else:
        return -1
    

a=[int(x) for x in input("Populate the array in ascending order : ").split()]
key=int(input("Enter the key element : "))
result=bin_recurse(a,0,len(a)-1,key)
if result==-1:
    print("Element not found.")
else:
    print("Element found at index:",result)