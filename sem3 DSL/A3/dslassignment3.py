class matrices:
    def __init__(self):
        self.n=0
        self.m=0
        self.a=0
        self.list1=[]
        self.list2=[]
    def getdata(self):
        self.n,self.m=map(int,input("Enter order of matrix ").split())
        for i in range(0,self.n):
            self.list2=[]
            self.list2=list(map(int,input().split()))
            self.list1.append(self.list2)
    def showdata(self):
        for i in range(0,self.n):
            print(self.list1[i])
    def add(self,obj1,obj2):
        self.list1=[]
        if (obj1.n==obj2.n and obj1.m==obj2.m):
            self.n=obj1.n
            self.m=obj1.m
            for i in range(0,obj1.n):
                self.list2=[]
                for j in range(0,obj1.m):
                    self.a=obj1.list1[i][j]+obj2.list1[i][j]
                    self.list2.append(self.a)
                self.list1.append(self.list2)
        else:
            print("Invalid input ")
    def substract(self,obj1,obj2):
        self.list1=[]
        if (obj1.n==obj2.n and obj1.m==obj2.m):
            self.n=obj1.n
            self.m=obj1.m
            for i in range(0,obj1.n):
                self.list2=[]
                for j in range(0,obj1.m):
                    self.a=obj1.list1[i][j]-obj2.list1[i][j]
                    self.list2.append(self.a)
                self.list1.append(self.list2)
        else:
            print("Invalid input ")
    def transpose(self):
        self.list3=[]
        self.list4=[]
        for i in range(0,self.m):
            self.list3=[]
            for j in range(0,self.n):
                self.a=self.list1[j][i]
                self.list3.append(self.a)
            self.list4.append(self.list3)
        for i in range(0,self.m):
            print(self.list4[i])   
    def multiplication(self,obj1,obj2):
        self.list3=[]
        self.list4=[]
        if(obj1.m==obj2.n):
            for i in range(0,obj1.n):
                self.list3=[]
                for j in range(0,obj2.m):
                    self.sum=0
                    for k in range(0,obj1.m):
                        self.sum+=obj1.list1[i][k]*obj2.list1[k][j]
                    self.list3.append(self.sum)
                self.list4.append(self.list3)
            for i in range(0,obj1.n):
                print(self.list4[i]) 
        else:
            print("Invalid input ")
flag1=1
while(flag1==1):
    print("Enter data for matrix 1 ")
    m1=matrices()
    m1.getdata()
    m1.showdata()
    print("Enter data for matrix 2 ")
    m2=matrices()
    m2.getdata()
    m2.showdata()
    flag=1
    print(''' MENU 
    1)Addition of two matrices 
    2)Substraction of two matrices 
    3)Multiplication of two matrices 
    4)Transpose of matrices ''')
    while(flag==1):
        case=int(input("Enter operation"))
        if(case==1):
            m3=matrices()
            m3.add(m1,m2)
            print("The result of addition is")
            m3.showdata() 
        elif(case==2):
            m3=matrices()
            m3.substract(m1,m2)
            print("The result of substraction is")
            m3.showdata()
        elif(case==3):
            m3=matrices()
            print("The result of multiplication is")
            m3.multiplication(m1,m2)
        elif(case==4):
            print("The transpose of matrix 1")
            m1.transpose()
            print("The transpose of matrix 2")
            m2.transpose()
        char1=input("Do you want to continue?(y/n)")
        if(char1=='y'):
            flag=1
        elif(char1=='n'):
            flag=0
        else:
            print("Ïnvalid input")
    char=input("Do you want to change matrices?(y/n)")
    if(char=='y'):
        flag1=1
    else:
        flag1=0