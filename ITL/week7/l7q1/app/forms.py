from django import forms
class CategoryForm(forms.Form):
    Name = forms.CharField(max_length=100)
    NumberOfVisits = forms.IntegerField()
    NumberOfLikes = forms.IntegerField()

class PageForm(forms.Form):
    category = forms.CharField(max_length=100)
    title = forms.CharField(max_length=100)
    url = forms.URLField()
    view = forms.IntegerField()
