from django import forms
from django.forms.widgets import EmailInput, PasswordInput

class Login(forms.Form):
    Username = forms.CharField()
    Password = forms.CharField(widget=PasswordInput,required=False)
    Email = forms.CharField(widget=EmailInput,required=False)
    ContactNumber = forms.IntegerField(required=False)