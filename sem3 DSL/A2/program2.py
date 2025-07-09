class sets:
    def que1(self,cricket,badminton):
        ans1=[]
        for i in cricket:
            if i in badminton:
                ans1.append(i)
        return ans1
    def que2(self,cricket,badminton):
        ans2=[]
        for i in cricket:
            if i not in badminton:
                ans2.append(i)
        for i in badminton:
            if i not in cricket:
                ans2.append(i)
        return ans2
    def que3(self,cricket,badminton,football):
        ans3=[]
        for i in football:
            if i not in cricket:
                if i not in badminton:
                    ans3.append(i)
        n=len(ans3)
        return n
    def que4(self,cricket,badminton,football):
        ans4=[]
        list1=cricket+football
        for i in list1:
            if i not in badminton:
                ans4.append(i)
        n=len(ans4)
        return n
s1=sets()
cricket=list(input("Enter the names of students who play cricket ").split())
badminton=list(input("Enter the names of students who play badminton ").split())
football=list(input("Enter the names of students who play football ").split())
print('''1)Find students who play both cricket and badminton \n2)Find students who play either cricket or badminton
3)Find number of students who neither play cricket nor badminton\n4)fFind number of students who play cricket and football 
but not badminton is''')
while (True):
    choice=int(input("Enter choice: "))
    if(choice==1):
        print("Students who play both cricket and badminton are",s1.que1(cricket,badminton))
    elif(choice==2):
        print("Students who either play cricket or badminton are",s1.que2(cricket,badminton))
    elif(choice==3):
        print("Number of students who neither play cricket or badminton are",s1.que3(cricket,badminton,football))
    elif(choice==4):
        print("Number of students who play cricket and football but not badminton are ",s1.que4(cricket,badminton,football))
    else:
        print("Enter correct choice")
    flag=input("Do you want to continue?(y/n)")
    if(flag=='n'):
        break          
