from django.db import models

class Publisher(models.Model):
    name = models.CharField(max_length=100)
    street = models.CharField(max_length=200)
    city = models.CharField(max_length=50)
    state = models.CharField(max_length=50)
    country = models.CharField(max_length=50)
    site = models.URLField()

class Author(models.Model):
    fname = models.CharField(max_length=100)
    lname = models.CharField(max_length=100)
    em = models.EmailField()

class Book(models.Model):
    title = models.CharField(max_length=200)
    pdate = models.DateField()
    authors = models.CharField(max_length=200, default='Manoj')
    publisher = models.CharField(max_length=200, default="NA")
