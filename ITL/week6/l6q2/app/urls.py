from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('firstPage', views.firstPage, name='firstPage'),
    path('secondPage', views.secondPage, name='secondPage')
]