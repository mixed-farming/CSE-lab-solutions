from django.db import models
class Category(models.Model):
    Name = models.CharField(max_length=100,primary_key=True)
    NumberOfVisits = models.IntegerField()
    NumberOfLikes = models.IntegerField()
# Create your models here
class Page(models.Model):
    category = models.CharField(max_length=100)
    title = models.CharField(max_length=100)
    url = models.URLField(primary_key=True)
    view = models.IntegerField()
