from django.shortcuts import render
from django.http import HttpResponse
def index(request):
    return HttpResponse("<h1>HEY! Welcome to Edureka! </h1>")
