from django.shortcuts import redirect, render, HttpResponseRedirect
from .models import Category, Product, Customer, Order
from django.views import View
from django.contrib.auth.hashers import make_password, check_password


def carousel(request):
    return render(request,'carousel.html')

class signin(View):
    def get(self,request):
        return render(request,'Sign_Up.html')
    
    def post(self,request):
        postData = request.POST
        name = postData.get('name')
        phone = postData.get('phone')
        email = postData.get('email')
        password = postData.get('password')
        # validation
        value = {
            'name': name,
            'phone': phone,
            'email': email
        }
        error_message = None

        customer = Customer(name=name,
                            phone=phone,
                            email=email,
                            password=password)
        error_message = self.validateCustomer(customer)

        if not error_message:
            customer.password = make_password(customer.password)
            customer.register()
            return redirect('/login')
        else:
            data = {
                'error': error_message,
                'values': value
            }
            return render(request, 'Sign_Up.html', data)
        
    def validateCustomer(self, customer):
        error_message = ""
        if (not customer.name):
            error_message = "Name Required !!"
        elif (not customer.email):
            error_message = "Email Required !!"
        elif (not customer.password):
            error_message = "Enter Password !!"
        elif len(customer.name) < 4:
            error_message = 'Name must be 4 char long or more'
        elif (not customer.phone):
            error_message = 'Phone Number required'
        elif len(customer.phone) < 10:
            error_message = 'Phone Number must be 10 char Long'
        elif len(customer.password) < 6:
            error_message = 'Password must be 6 char long'
        elif customer.isExists():
            error_message = 'Email Address Already Registered..'
        return error_message


class login(View):
    return_url = None
    def get(self , request):
        login.return_url = request.GET.get('return_url')
        return render(request , 'login.html')

    def post(self , request):
        email = request.POST.get('email')
        password = request.POST.get('password')
        customer = Customer.get_customer_by_email(email)
        error_message = None
        if customer:
            flag = check_password(password, customer.password)
            if flag:
                request.session['customer'] = customer.id

                if login.return_url:
                    return HttpResponseRedirect(login.return_url)
                else:
                    login.return_url = None
                    return redirect('/index')
            else:
                error_message = 'Invalid Credentials !!'
        else:
            error_message = 'Invalid Credentials !!'
        return render(request, 'login.html', {'error': error_message})

def logout(request):
    request.session.clear()
    return redirect('/login')

class Index(View):
    def post(self , request):
        product = request.POST.get('product')
        remove = request.POST.get('remove')
        cart = request.session.get('cart')
        if cart:
            quantity = cart.get(product)
            if quantity:
                if remove:
                    if quantity>=1:
                        cart.pop(product)
                else:
                    cart[product]  = quantity+1

            else:
                cart[product] = 1
        else:
            cart = {}
            cart[product] = 1

        request.session['cart'] = cart
        print(cart , request.session['cart'])
        return redirect('/index')
    
    def get(self , request):
        cart = request.session.get('cart')
        if not cart:
            request.session['cart'] = {}
        products = None
        categories = Category.get_all_categories()
        categoryID = request.GET.get('category')
        if categoryID:
            products = Product.get_all_products_by_categoryid(categoryID)
        else:
            products = Product.get_all_products();
        data = {}
        data['products'] = products
        data['categories'] = categories
        return render(request, 'index.html', data)


class Cart(View):
    def get(self , request):
        customer = request.session.get('customer')
        if(customer):
            cart=request.session.get('cart')
            ids = list(cart.keys())
            products = Product.get_products_by_id(ids)
            # data ={}
            # data['products']=products
            return render(request, 'cart.html', {"products" :products})
        else:
            return render(request,'login.html')

class CheckOut(View):
    def post(self, request):
        address = request.POST.get('address')
        phone = request.POST.get('phone')
        customer = request.session.get('customer')
        cart = request.session.get('cart')
        products = Product.get_products_by_id(list(cart.keys()))
        print(address, phone, customer, cart, products)

        for product in products:
            print(cart.get(str(product.id)))
            order = Order(customer=Customer(id=customer),
                          product=product,
                          price=product.price,
                          address=address,
                          phone=phone,
                          quantity=cart.get(str(product.id)))
            order.save()
        request.session['cart'] = {}

        return redirect('/cart')

class OrderView(View):
    def get(self , request ):
        customer = request.session.get('customer')
        if(customer):
            orders = Order.get_orders_by_customer(customer)
            return render(request , 'orders.html'  , {'orders' : orders})
        else:
            return render(request,'login.html')
# Create your views here.
