class search():
    def linear_search(self,list1,value,n):
        index=0
        while(index<n):
            if(list1[index]==value):
                print("Roll number found at index ",index," by linear search")
                break
            else:
                index+=1
        if(index==n):
            print("Roll number not found")

    def sentinel_search(self,list1,value):
        if(list1[-1]==value):
            return len(list1)-1
        list1[-1]=value
        index=0
        while(value!=list1[index]):
            index+=1
        if(index<len(list1)-1):
            return index
        else:
            return -1
    
    def binary_search(self,list1,value,low,high):
        list1.sort()
        if((high-low)>1):
            mid=int((high+low)/2)
            if(value<list1[mid]):
                self.binary_search(list1,value,low,mid)
            elif(value>list1[mid]):
                self.binary_search(list1,value,mid,high)
            elif(value==list1[mid]):
                print("Roll number found at index ",mid," of sorted list by binary search")
        else:
            print("Roll number not foound")
    
    def fibonacci_search(self,list1,value,n):
        list1.sort()
        fib2=0
        fib1=1
        fibM=fib2+fib1
        while(fibM<n):
            fib2=fib1
            fib1=fibM
            fibM=fib2+fib1
        offset=-1
        while(fibM>1):
            i=min(offset+fib2,n-1)
            if(list1[i]<value):
                fibM=fib1
                fib1=fib2
                fib2=fibM-fib1
                offset=i
            elif(list1[i]>value):
                fibM=fib2
                fib1=fib1-fib2
                fib2=fibM-fib1
            else:
                return i
        if(fib1 and list1[n-1]==value):
            return n-1
        return -1

s1=search()
n=int(input("Enter the total number of students "))
t1=tuple(map(int,input("Enter the roll numbers").split()))
value=int(input("Enter roll number to be checked "))
flag='y'
while(flag=='y'):
    m=int(input("MAIN MENU \n 1)linear search \n 2)sentinel search \n 3)binary search \n 4)fibonacci search"))
    if(m==1):
        s1.linear_search(list(t1),value,n)
    elif(m==2):
        d=s1.sentinel_search(list(t1),value)
        if(d==-1):
            print("Roll number not found")
        else:
            print("Roll no found at index ",d," by sentinel search")
    elif(m==3):
        s1.binary_search(list(t1),value,0,(n-1))
    elif(m==4):
        ans=s1.fibonacci_search(list(t1),value,n)
        if(ans>=0):
            print("Roll number found at index ",ans,"in the sorted list")
        else:
            print("Roll number not found")
    else:
        print("Enter valid input")
    a=input("Do you want to continue?(y/n)")
    if(a=='y'):
        flag='y'
    else:
        flag='n'
print("Thank you")









