from django.shortcuts import render
from .forms import Bill
# Create your views here.
def submit(request):
    Mob_Cost={
        "HP":5000,
        "Nokia":3000,
        "Samsung":10000,
        "Motorola":8000,
        "Apple":20000
    }
    Laptop_Cost={
        "HP":50000,
        "Nokia":3000,
        "Samsung":100000,
        "Motorola":80000,
        "Apple":200000
    }
    CompanyName=''
    Mobile=''
    Laptop=''
    Quantity=''
    Price=0
    if request.method =='POST':
        res= Bill(request.POST)
        if res.is_valid():
            CompanyName=res.cleaned_data['CompanyName']
            Mobile=res.cleaned_data['Mobile']
            Laptop=res.cleaned_data['Laptop']
            Quantity=res.cleaned_data['Quantity']
    else:
        res=Bill()

    if Mobile=='True':
        Price=Price+(Mob_Cost[CompanyName]*Quantity)

    if Laptop=='True':
        Price=Price+(Laptop_Cost[CompanyName]*Quantity)
    context={"CompanyName":CompanyName,"Mobile":Mobile,"Laptop":Laptop,"Quantity":Quantity,"Price":Price}
    return render(request,'result.html',context)

def index(request):
    form = Bill(request.POST or None)
    context={'form':form}
    return render(request,'base.html',context)
def bill(request):
    return render(request,'result.html')