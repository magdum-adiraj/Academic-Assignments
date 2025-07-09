##Python proram to implement Quick Sort and display the top 5 scores

class quick_sort:
    def partition(self,arr,low,high):
        pivot=arr[high]
        i=low
        j=high-1
        flag=True
        while(flag):
            while(i<=j and arr[i]<=pivot):
                i=i+1
            while(i<=j and arr[j]>=pivot):
                j=j-1
            if(j<=i):
                flag=False
            else:
                temp=arr[j]
                arr[j]=arr[i]
                arr[i]=temp
        temp=arr[high]
        arr[high]=arr[i]
        arr[i]=temp
        return i

    def quicksort(self,arr,low,high):
        if len(arr)==1:
            return arr
        if low<high:
            pi=self.partition(arr,low,high)
            self.quicksort(arr,low,pi-1)
            self.quicksort(arr,pi+1,high)

obj=quick_sort()
arr=[]
length=int(input("Enter total number of elements: "))
for i in range(0,length):
    print("Enter element ",i+1," : ")
    ele=float(input())
    arr.append(ele)
obj.quicksort(arr,0,length-1)
print("The sorted array is : ",arr)
print("The top 5 percentages are:")
for i in range(1,6):
    print ("#",i,": ",arr[length-i])
print("Thank you!! ")