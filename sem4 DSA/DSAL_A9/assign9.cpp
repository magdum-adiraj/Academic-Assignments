#include <iostream>
using namespace std;

class heap
{
    public:
    void heapify(int arr[], int n, int i)
    {
	    int largest = i; 
	    int l = 2 * i + 1;
	    int r = 2 * i + 2; 

	    if (l < n && arr[l] > arr[largest])
		    largest = l;

	    if (r < n && arr[r] > arr[largest])
		     largest = r;

	    if (largest != i)
		{
		      swap(arr[i], arr[largest]);
			  heapify(arr, n, largest);
		}
    }
	
	void heapSort(int arr[], int n)
    {
	      for (int i = n / 2 - 1; i >= 0; i--)
		      heapify(arr, n, i);

	      for (int i = n - 1; i > 0; i--)
		    {
	            swap(arr[0], arr[i]);
		  		heapify(arr, i, 0);
			}
    }
	
	void printArray(int arr[], int n)
    {
	    for (int i = 0; i < n; ++i)
	    {
		    cout << arr[i] << " ";
	    }
	    cout << "\n";
    }
};


int main()
    {
        heap h;
        int l,a;
        cout<<"enter the number of elements to be there in a array:";
        cin>>l;
        int arr[l];
        cout<<"enter the elements:";
        for(int i=0;i<l;i++)
        {
            cin>>a;
            arr[i]=a;
        }
    	int n = sizeof(arr) / sizeof(arr[0]);
    
    	h.heapSort(arr, n);
    
    	cout << "Sorted array is \n";
    	h.printArray(arr, n);
    }
