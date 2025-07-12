#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class fit
{

public:
    int bsize[60];
    int psize[50];
    int m, n;

    void firstfit()
    {
        int allo[n];
        memset(allo, -1, sizeof(allo));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (bsize[j] >= psize[i])
                {
                    allo[i] = j;
                    bsize[j] -= psize[i];
                    break;
                }
            }
        }

        cout << "\n Process num \t Process size \t Block Number \n ";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t" << psize[i] << "\t\t";
            if (allo[i] != -1)
                cout << allo[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }

    void nextfit()
    {
        int j = 0;
        int allo[n];
        memset(allo, -1, sizeof(allo));
        for (int i = 0; i < n; i++)
        {
            int ct = 0;
            while (j < m)
            {
                if (ct == m)
                {
                    break;
                }
                
                else
                {
                    ct++;
                    if (bsize[j] >= psize[i])
                    {
                        allo[i] = j;
                        bsize[j] -= psize[i];
                        break;
                    }
                }
                j = (j + 1) % m;
            }
        }

        cout << "\n Process num \t Process size \t Block Number \n ";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t" << psize[i] << "\t\t";
            if (allo[i] != -1)
                cout << allo[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }

    void bestfit()
    {
        int allo[n];
        memset(allo, -1, sizeof(allo));
        for (int i = 0; i < n; i++)
        {
            int bestIdx = -1;
            for (int j = 0; j < m; j++)
            {
                if (bsize[j] >= psize[i])
                {
                    if (bestIdx == -1)
                        bestIdx = j;
                    else if (bsize[bestIdx] > bsize[j])
                        bestIdx = j;
                }
            }
            if (bestIdx != -1)
            {
                allo[i] = bestIdx;
                bsize[bestIdx] -= psize[i];
            }
        }

        cout << "\nProcess No.\tProcess Size\tBlock no.\n";
        for (int i = 0; i < n; i++)
        {
            cout << " " << i + 1 << "\t\t" << psize[i] << "\t\t";
            if (allo[i] != -1)
                cout << allo[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }

    void worstfit()
    {
        int allo[n];
        memset(allo, -1, sizeof(allo));
        for (int i = 0; i < n; i++)
        {
            int wstIdx = -1;
            for (int j = 0; j < m; j++)
            {
                if (bsize[j] >= psize[i])
                {
                    if (wstIdx == -1)
                        wstIdx = j;
                    else if (bsize[wstIdx] < bsize[j])
                        wstIdx = j;
                }
            }
            if (wstIdx != -1)
            {
                allo[i] = wstIdx;
                bsize[wstIdx] -= psize[i];
            }
        }

        cout << "\nProcess No.\tProcess Size\tBlock no.\n";
        for (int i = 0; i < n; i++)
        {
            cout << "   " << i + 1 << "\t\t" << psize[i] << "\t\t";
            if (allo[i] != -1)
                cout << allo[i] + 1;
            else
                cout << "Not Allocated";
            cout << endl;
        }
    }

    void input()
    {
        cout << "Enter number of blocks: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Enter block size: ";
            cin >> bsize[i];
        }

        cout << "Enter number of processes: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter process size: ";
            cin >> psize[i];
        }
    }
};

int main()
{
    int c;
    fit f;

    cout << "1. First Fit " << endl;
    cout << "2. Next Fit " << endl;
    cout << "3. Best Fit " << endl;
    cout << "4. Worst Fit " << endl;
    cout << "5. Exit " << endl;
    cout << "Enter your choice: ";
    cin >> c;

    switch (c)
    {
    case 1:
        f.input();
        f.firstfit();
        break;

    case 2:
        f.input();
        f.nextfit();
        break;

    case 3:
        f.input();
        f.bestfit();
        break;

    case 4:
        f.input();
        f.worstfit();
        break;

    case 5:
        cout << "Wrong Choice, please enter a valid choice. ";
        break;
    }
    return 0;
}