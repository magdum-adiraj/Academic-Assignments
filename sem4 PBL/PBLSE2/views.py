from django.shortcuts import render,redirect
from django.contrib.auth.models import User, auth
from django.contrib import messages

def home(request):
    return render(request, 'index.html')

def about(request):
    return render(request, 'about.html')

def contact(request):
    return render(request, 'contact.html')

def calorie(request):
    return render(request, 'CalorieCounterF.html')

def bmi(request):
    return render(request, 'BMI.html')

def signup(request):
    if request.method == 'POST':
        username = request.POST['username']
        email = request.POST['email']
        password1 = request.POST['password1']
        password2 = request.POST['password2']

        if User.objects.filter(username=username).exists():
            messages.info(request, 'Take another username')
            return render(request, 'signup.html')
        elif User.objects.filter(email=email).exists():
            messages.info(request, 'Take another email')
            return render(request, 'signup.html')
        elif (password1 != password2):
            messages.info(request, 'Password not matching')
            return render(request, 'signup.html')
        else:
            user = User.objects.create_user(username=username, password=password1, email=email)
            user.save()
        return render(request, 'index.html')
    else:
        return render(request, 'signup.html')

def login(request):
    if request.method == 'POST':
        username = request.POST['username']
        password = request.POST['password']
        user = auth.authenticate(username=username, password=password)
        if user is not None:
            auth.login(request, user)
            return render(request, 'index.html')
        else:
            messages.info(request, 'Invalid Credentials')
            return render(request, 'login.html')

    else:
        return render(request, 'login.html')

def logout(request):
    auth.logout(request);
    return render(request, 'index.html')
