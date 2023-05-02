from django.shortcuts import render

def index(request):
    return render(request,'base.html')

def meta(request):
    return render(request,'meta.html')

def publisher(request):
    return render(request,'publisher.html')

def reviews(request):
    return render(request,'reviews.html')