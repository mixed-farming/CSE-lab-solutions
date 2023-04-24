from django import forms
from django.forms.fields import CharField, IntegerField

subjects = [
    ('Maths', 'Maths'),
    ('Physics', 'Physics'),
    ('Chemistry', 'Chemistry'),
    ('Biology', 'Biology'),
]
class SubjectForm(forms.Form):
    Name = CharField()
    RollNo = IntegerField()
    Subject = CharField(label='Select subject.', widget=forms.Select(choices=subjects))