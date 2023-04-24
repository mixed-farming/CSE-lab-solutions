from django.shortcuts import render
from .forms import AuthorForm,PublisherForm,BookForm,AuthorSearch,PublisherSearch,BookSearch
from .models import Author,Publisher,Book
# Create your views here.
def index(request):
    return render(request,'base.html')

def publisherEntry(request):
    form = PublisherForm()
    form1 = PublisherForm(request.POST)
    if form1.is_valid():
        name = form1.cleaned_data["name"]
        street = form1.cleaned_data["street"]
        city = form1.cleaned_data["city"]
        state = form1.cleaned_data["state"]
        country = form1.cleaned_data["country"]
        site = form1.cleaned_data["site"]
        Publisher.objects.create(name = name,street = street,city = city,state = state,country = country,site = site)
    return render(request,'registerP.html',{"form":form})

def authorEntry(request):
    form = AuthorForm()
    form1 = AuthorForm(request.POST)
    if form1.is_valid():
        fname = form1.cleaned_data["fname"]
        lname = form1.cleaned_data["lname"]
        email = form1.cleaned_data["email"]
        Author.objects.create(fname = fname,lname = lname,em = email)
    return render(request,'registerA.html',{"form":form})

def bookEntry(request):
    form = BookForm()
    form1 = BookForm(request.POST)
    if form1.is_valid():
        a = form1.cleaned_data
        title = a["title"]
        pdate = a["pdate"]
        pname = a["pname"]
        anames = a["anames"].split()
        print(anames)
        publisher = Publisher.objects.get(name = pname)
        authors = []
        book = Book(title = title,pdate = pdate,publisher = publisher)
        book.save()
        for i in anames:
            a = Author.objects.get(fname = i)
            book.authors.add(a)
        book.save()
    return render(request,'registerB.html',{"form":form})

def searchBook(request):
    form = BookSearch()
    form1 = BookSearch(request.POST)
    if form1.is_valid():
        title = form1.cleaned_data["title"]
        book = Book.objects.get(title = title)
        return render(request,'searchB.html',{"form":form1,"book":book})
    return render(request,'searchB.html',{"form":form})

def searchAuthor(request):
    form = AuthorSearch()
    form1 = AuthorSearch(request.POST)
    if form1.is_valid():
        fname = form1.cleaned_data["fname"]
        author = Author.objects.get(fname = fname)
        return render(request,'searchA.html',{"form":form1,"author":author})
    return render(request,'searchA.html',{"form":form})

def searchPublisher(request):
    form = PublisherSearch()
    form1 = PublisherSearch(request.POST)
    if form1.is_valid():
        name = form1.cleaned_data["name"]
        publisher = Publisher.objects.get(name = name)
        return render(request,'searchP.html',{"form":form1,"publisher":publisher})
    return render(request,'searchP.html',{"form":form})