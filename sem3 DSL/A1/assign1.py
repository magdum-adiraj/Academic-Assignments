class string_assign:
    def que1(self,list1):
        max=0
        char=[]
        max=len(list1[0])
        for i in range(0,len(list1)):
            if(len(list1[i])>max):
                max=len(list1[i])
        for j in range(len(list1)-1,-1,-1):
            if(len(list1[j])==max):
                char.append(list1[j])
        print("1)Word with longest length is ",char,"\n")
    def que2(self,list1):
        frequency=0
        i=0
        char=input("Enter word to be checked ")
        for i in range (0,len(list1)):
            if(list1[i]==char):
                frequency+=1
        if(frequency==0):
            print("Word not found. Enter valid word")
            self.que2(list1)
        else:            
            print("2)The frequency of ",char,"is",frequency,"\n")
    def que3(self,string):
        reverse_string=string[::-1]
        if(string==reverse_string):
            print("3)It is palindrome \n")
        else:
            print("3)It is not palindrome \n") 
    def que4(self,string):
        sub_string=input("Enter the substring ")
        if sub_string in string:
            print("4)The starting index of sub string is",string.index(sub_string),"\n")   
        else:
            print("Enter valid sub string ")
            self.que4(string)
    def que5(self,list1):
        for i in range(0,len(list1)):
            m=0
            m=list1.count(list1[i])
            print("The occurance of ",list1[i]," is ",m,"\t")    
string=input("Enter the string: ")
list1=list(string.split())
s1=string_assign()
print(''' MAIN MENU \n 1)To find word with longest length \n 2)To check frequency of word in the string \n 3)To check if the string is palindrome
 \n 4)To check the index of substring \n 5)To find occurance of each word ''')
while (True):
    choice=int(input("Enter choice: "))
    if(choice==1):
        print(s1.que1(list1))
    elif(choice==2):
        print(s1.que2(list1))
    elif(choice==3):
        print(s1.que3(string))
    elif(choice==4):
        print(s1.que4(string))
    elif(choice==5):
        print(s1.que5(list1))
    else:
        print("Enter correct choice")
    flag=input("Do you want to continue?(y/n)")
    if(flag=='n'):
        print("Thank you ")
        break     