from tkinter import*  
base = Tk()  
base.geometry('500x500')  
base.title(" Gym Registration Form")
  
labl_0 = Label(base, text="Registration Form",width=20,font=("bold", 20))
labl_0.place(x=90,y=53)  

labl_1 = Label(base, text="Personal Information",width=30,font=("bold", 15))
labl_1.place(x=90,y=100)

labl_2 = Label(base, text="Username",width=20,font=("bold", 10))
labl_2.place(x=68,y=130)

entry_02 = Entry(base)
entry_02.place(x=240,y=130)
  
labl_3 = Label(base, text="Gender",width=20,font=("bold", 10))  
labl_3.place(x=68,y=160)
Radiobutton(base, text="Male",padx = 5, value=1).place(x=200,y=160)
Radiobutton(base, text="Female",padx = 2, value=2).place(x=280,y=160)
  
labl_4 = Label(base, text="Contact",width=20,font=("bold", 10))
labl_4.place(x=68,y=190)

entry_02 = Entry(base)  
entry_02.place(x=240,y=190)
  
Button(base, text='Submit',width=20,bg='brown',fg='white').place(x=180,y=380)  
# it will be used for displaying the registration form onto the window  
base.mainloop()  
print("Registration form is created seccussfully...")  