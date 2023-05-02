from django import forms

class RegForm(forms.Form):
    title=forms.CharField()
    description=forms.CharField()
    views=forms.IntegerField()
    available=forms.BooleanField(required=False)