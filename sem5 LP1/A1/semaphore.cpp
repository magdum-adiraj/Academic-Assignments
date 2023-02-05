#include <iostream>
using namespace std;
class Array
{
public:
    int mutex = 0; // 0 unlocked
    int count = 2; // 1 read 0 write
    int arr[5];
    int ele;
    int user_read = 0;
    int user_write = 1;
    int f;

    void write()
    {
        int i;
        count = 0;
        cout << "\nEnter the index: ";
        cin >> i;
        cout << "\nEnter the element: ";
        cin >> ele;
        arr[i] = ele;
        cout << "\nARRAY LOCKED FOR WRITING";
        mutex = 1;
    }
    void read()
    {
        int i;
        count = 1;
        cout << "\nEnter index: ";
        cin >> i;
        cout << arr[i];
        cout << "\nARRAY LOCKED FOR READING";
        mutex = 1;
    }
    void leaveread()
    {
        if (user_read == 0)
        {
            cout << "ARRAY UNLOCKED FROM READING";
            mutex = 0;
        }
        else
        {
            --user_read;
            cout << "\nThere are still " << user_read +1<< " reading the array";
        }
    }

    void leavewrite()
    {
        if (user_write == 0)
        {
            cout << "ARRAY UNLOCKED FROM WRITING";
            mutex = 0;
        }
        else
        {
            --user_write;
            cout << "\nThere are still " << user_write+1 << " writing the array";
        }
    }
};

int main()
{
    Array a;
    int ans, func;
    char n = 'y';
   while (n == 'y')
    {
        cout << "\n1. Read\n2.Write \n3.Exit Read\n4.Exit Write\n5.Exit";
        cin >> ans;
        if (ans == 1 && a.count == 0)
        {
            cout << "\nARRAY IS BEING WRITTEN CANNOT ACCESS";
            cout << "\n1. Read\n2.Write \n3.Exit Read\n4.Exit Write\n5.Exit";
            cin >> ans;
        }
        if (ans == 2 && a.count == 1)
        {
            cout << "\nARRAY IS BEING READ CANNOT ACCESS";
            cout << "\n1. Read\n2.Write \n3.Exit Read\n4.Exit Write\n5.Exit";
            cin >> ans;
        }

        switch (ans)

        {
        case 1:
            cout << "\n1.Mutex \n2.Semaphore";
            cin >> func;
            if (func == 1)
            {
                if (a.count != 0 && a.mutex == 0)
                    a.read();
                else if (a.count == 1 && a.mutex == 1)
                    cout << "\nTHE ARRAY IS BEING READ NOW CANNOT BE ACCESSED SINCE MUTEX";
                else if (a.count == 0)
                    cout << "\nARRAY IS BEING WRITTEN CANNOT ACCESS";
            }
            else
            {
                if (a.count != 0 && a.mutex == 0)
                    a.read();
                else if (a.count == 1 && a.mutex == 1)
                {
                    ++a.user_read;
                    a.read();
                    cout << "\nThere are " << a.user_read+1 << " users reading the array now";
                }
                else if (a.count == 0)
                    cout << "\nARRAY IS BEING WRITTEN CANNOT ACCESS";
            }
            cout << "\nAllow more users?";
            cin >> n;
            break;

        case 2:
            cout << "\n1.Mutex \n2.Semaphore";
            cin >> func;
            if (func == 1)
            {
                if (a.count != 1 && a.mutex == 0)
                    a.write();
                else if (a.count == 0 && a.mutex == 1)
                    cout << "\nTHE ARRAY IS BEING READ NOW CANNOT BE ACCESSED SINCE MUTEX";
                else if (a.count == 1)
                    cout << "\nARRAY IS BEING READ CANNOT ACCESS";
            }
       else
            {
                if (a.count != 1 && a.mutex == 0)
                    a.write();
                else if (a.count == 0 && a.mutex == 1)
                {
                    ++a.user_write;
                    a.write();
                    cout << "\nThere are " << a.user_write << " users writing the array now";
                }
                else if (a.count == 1)
                    cout << "\nARRAY IS BEING READ CANNOT ACCESS";
            }
            cout << "\nAllow more users?";
            cin >> n;
            break;

        case 3:
            a.leaveread();
            cout << "\nAllow more users?";
            cin >> n;
            break;
        case 4:
            a.leavewrite();
            cout << "\nAllow more users?";
            cin >> n;
            break;
        case 5:
            exit(0);
        }
    }
return 0;
}
 
 
 
