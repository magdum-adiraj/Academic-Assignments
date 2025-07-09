class SortTech:
    def _init_(self):
        self.arr = []
        self.length = 0

    def TakeInput(self):
        self.length = int(input("Enter number of elememts of array : "))
        self.arr=list(map(float,input("Enter the elements : ").split()))

    def bubbleSort(self):
        for i in range(self.length):
            for j in range(self.length - i - 1):
                if self.arr[j] > self.arr[j+1]:
                    temp = self.arr[j]
                    self.arr[j] = self.arr[j+1]
                    self.arr[j+1] = temp

    def selectionSort(self):
        for i in range(self.length):
            min_index = i
            for j in range(min_index + 1, self.length):
                if self.arr[min_index] > self.arr[j]:
                    min_index = j
                    temp = self.arr[i]
                    self.arr[i] = self.arr[min_index]
                    self.arr[min_index] = temp

    def insertionSort(self):
        for i in range(1, self.length):
            current = self.arr[i]
            j = i - 1
            while (j >= 0 and current < self.arr[j]):
                self.arr[j+1] = self.arr[j]
                j = j - 1
                self.arr[j+1] = current

    def shellSort(self):
        n = self.length
        gap = int(n / 2)
        while gap > 0:
            for i in range(gap, n):
                current = self.arr[i]
                j = i
                while (j >= gap and (self.arr[j - gap]) > current):
                    self.arr[j] = self.arr[j - gap]
                    j = j - gap
                self.arr[j] = current
            gap = int(gap / 2)

    def top5(self):
        print("The top 5 percentages are: ")
        print(self.arr[-1:-6:-1])

    def displayArray(self):
        print("The sorted array is: ")
        print(self.arr)

obj = SortTech()
obj.TakeInput()
ch="y"
print("------MENU------")
print("1) Bubble Sort")
print("2) Selection Sort")
print("3) Insertion Sort")
print("4) Shell Sort")
print("5) Top 5 percentages")
while(ch=="y"):
    choice = int(input("Enter your choice: "))
    if choice == 1:
        obj.bubbleSort()
        obj.displayArray()
    elif choice == 2:
        obj.selectionSort()
        obj.displayArray()
    elif choice == 3:
        obj.insertionSort()
        obj.displayArray()
    elif choice == 4:
        obj.shellSort()
        obj.displayArray()
    elif choice == 5:
        obj.top5()
    else:
        print("Invalid choice")
    flag=input("Do you want to continue? (y/n)")
    if(flag=="y"):
        ch="y"
    else:
        ch="n"
print("Thank You")