from django.shortcuts import render, redirect
from .forms import SubjectForm

def index(request):
    form = SubjectForm()
    return render(request, 'firstPage.html', {'form': form})

def firstPage(request):
    if request.method == 'POST':
        form = SubjectForm(request.POST)
        if form.is_valid():
            Name = form.cleaned_data['Name']
            RollNo = form.cleaned_data['RollNo']
            Subject = form.cleaned_data['Subject']
            request.session['Name'] = Name
            request.session['RollNo'] = RollNo
            request.session['Subject'] = Subject
            return redirect('secondPage')
    else:
        form = SubjectForm()
    return render(request, 'firstPage.html', {'form': form})
    
def secondPage(request):
    Name = request.session['Name']
    RollNo = request.session['RollNo']
    Subject = request.session['Subject']
    context = {'Name': Name, 'RollNo': RollNo, 'Subject': Subject}
    return render(request, 'secondPage.html', context)