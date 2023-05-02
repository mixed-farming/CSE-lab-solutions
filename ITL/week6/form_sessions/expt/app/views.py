from django.shortcuts import render
from .forms import LoginForm
from django.shortcuts import HttpResponse

def formView(request):
    if request.session.has_key('username'):
        username = request.session['username']
        return render(request, 'loggedin.html', {"username" : username})
    else:
        return render(request, 'base.html', { })
    
def login(request):
    username = 'not logged in'
    if request.method == 'POST':
        MyLoginForm = LoginForm(request.POST)
        if MyLoginForm.is_valid():
            username = MyLoginForm.cleaned_data['username']
            request.session['username'] = username
    else:
        MyLoginForm = LoginForm()
    return render(request, 'loggedin.html', {"username" : username})

def logout(request):
    try:
        del request.session['username']
    except:
        pass
    return HttpResponse("<strong>You are logged out.</strong>")
