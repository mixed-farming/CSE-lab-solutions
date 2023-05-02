from django.urls import path
from . import views

urlpatterns = [
    path('',views.index,name='index'),
    path('meta',views.meta,name='meta'),
    path('reviews',views.reviews,name='reviews'),
    path('publisher',views.publisher,name='publisher'),
]