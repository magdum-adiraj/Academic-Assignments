from django.urls import path
from .middlewares.auth import auth_middleware
from . import views

urlpatterns = [
    path('',views.carousel,name="Welcome"),
    path('signin',views.signin.as_view(),name="Signin"),
    path('login',views.login.as_view(),name="Login"),
    path('logout',views.logout,name="Logout"),
    path('index',views.Index.as_view(),name="Home"),
    path('cart',views.Cart.as_view(),name="Cart"),
    path('checkout',views.CheckOut.as_view(),name="CheckOut"),
    path('orders',auth_middleware(views.OrderView.as_view()),name="Orders")
]