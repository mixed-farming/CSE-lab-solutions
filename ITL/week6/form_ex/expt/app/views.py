from django.shortcuts import render
from . forms import RegForm

def index(request):
    form_object=RegForm(request.POST or None)#instance of the RegForm
    return render(request,'base.html',{'form':form_object})#rendering the request to base.html with key-value pair
