from django import forms
companies =[('HP','HP'), ('Nokia','Nokia'), ('Samsung','Samsung'), ('Motorola','Motorola'), ('Apple','Apple')]
class Bill(forms.Form):
    CompanyName= forms.ChoiceField(widget=forms.RadioSelect,choices=companies)
    Mobile= forms.CharField(widget=forms.CheckboxInput, required=False)
    Laptop= forms.CharField(widget=forms.CheckboxInput, required=False)
    Quantity=forms.IntegerField()