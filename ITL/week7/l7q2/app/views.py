from django.shortcuts import render
from .models import Works,Lives
from .forms import Employee,Company
# Create your views here.
def home(request):
    return render(request,'base.html')

def portal(request):
    form = Employee()
    form1 = Employee(request.POST)
    if form1.is_valid():
        name = form1.cleaned_data['name']
        company = form1.cleaned_data['company']
        salary = form1.cleaned_data['salary']
        street = form1.cleaned_data['street']
        city = form1.cleaned_data['city']
        Works.objects.create(name=name,company=company,salary=salary)
        Lives.objects.create(name=name,street=street,city=city)
    return render(request,'add.html',{"form":form})

def search(request):
    form1 = Company(request.POST)
    if form1.is_valid():
        company = form1.cleaned_data["company"]
        employa = Works.objects.filter(company=company)
        employees = Lives.objects.filter(name__in=[e.name for e in employa])
        return render(request, "search.html", {"form": form1, "employees": employees})
    else:
        form1 = Company()
    return render(request, "search.html", {"form": form1})

