from django import forms
class car(forms.Form):
    manufacturer = forms.ChoiceField(choices=[("BMW","bmw"),("Benz","benz"),("Suzuki","suzuki")],label="Manufacturer")
    model = forms.CharField(label="Model")
