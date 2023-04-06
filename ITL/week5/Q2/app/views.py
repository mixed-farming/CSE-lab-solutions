from django.shortcuts import render 
from django.http import HttpResponse 
import datetime as dt


# Create your views here. 
def home(request): 
    return render(request,'base.html') 
def select(request): 
    current_year = dt.datetime.now().year
    doj = request.GET['doj'] 
    year= int(doj[:4]) 
    years_since_joining = current_year - year
    if years_since_joining>=5: 
        n1 = "Congratulations... \nYou are eligible for promotion." 
    else: 
        n1 = "Sorry... \nYou are not eligible for promotion." 
    return render(request,'result.html',{"selection":n1}) 
