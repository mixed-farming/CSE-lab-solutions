from django.shortcuts import render
from .forms import Login
def submit(request):
    if request.method =='POST':
        res = Login(request.POST)
        if res.is_valid():
            Username=res.cleaned_data['Username']
            Email=res.cleaned_data['Email']
            ContactNumber=res.cleaned_data['ContactNumber']
    else:
        res=Login()
    context={"Username":Username,"Email":Email,"ContactNumber":ContactNumber}
    return render(request,'result.html',context)
def index(request):
    form = Login(request.POST or None)
    context={'form':form}
    return render(request,'base.html',context)
def success(request):
    return render(request,'result.html')