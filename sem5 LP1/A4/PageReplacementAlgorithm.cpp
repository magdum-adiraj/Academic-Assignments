//============================================================================
// Name        : PageReplacementAlgorithm.cpp
// Author      : Atharva Deshmukh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class PageReplacement
{
private:
	int hit;
	int miss;
	int size;
	string str;
	vector<char> cache;
public:
	PageReplacement()
	{
		hit=0;
		miss=0;
		cout<<"Enter the size of cache : ";
		cin>>size;

		for(int i=0;i<size;i++)
		{
			cache.push_back(' ');
		}

		cout<<" Enter the reference string : ";
		cin>>str;
	}

	void displayCache()
	{
		for(int i=0;i<size;i++)
		{
			cout<<cache[i]<<" ";
		}
		cout<<endl;
	}

	void FirstInFirstOut()
	{
		int index=0;
		for(int i=0;i<str.length();i++)
		{
			bool isPresent=false;
			for(int j=0;j<size;j++)
			{
				if(cache[j]==str[i])
				{
					hit++;
					isPresent=true;
					break;
				}
			}

			if(!isPresent)
			{
				cache[index]=str[i];
				index++;
				index=index%size;
				miss++;
			}

			displayCache();
		}

		cout<<" In First-In-First-Out (FIFO) page replacement algorithm for the reference string "<<str<<" the miss count is : "<<miss<<" & hit count is : "<<hit<<endl;
	}

	int predict(int index)
	{
		   int res = -1, farthest = index;
		   for (int i = 0; i < size; i++)
		   {
		      int j;
		      for (j = index; j < str.length(); j++)
		      {
		         if (cache[i] == str[j])
		         {
		            if (farthest < j)
		            {
		               farthest = j;
		               res = i;
		            }
		            break;
		         }
		      }

		      if (j == str.length())
		      {
		         return i;
		      }
		   }

		   return (res == -1) ? 0 : res;
	}

	void OptimalPageReplacement()
	{
		int index=0;
		for(int i=0;i<str.length();i++)
		{
			bool isPresent=false;
			for(int j=0;j<size;j++)
			{
				if(cache[j]==str[i])
				{
					hit++;
					isPresent=true;
					break;
				}
			}


			if(i<size && isPresent==false)
			{
				cache[index]=str[i];
				index++;
				index=index%size;
				miss++;
			}
			else if(isPresent==false)
			{
				index=predict(i+1);
				cache[index]=str[i];
				miss++;
			}

			displayCache();
		}
		cout<<" In Optimal Page Replacement algorithm for the reference string "<<str<<" the miss count is : "<<miss<<" & hit count is : "<<hit<<endl;
	}

	void LeastRecentlyUsed()
	{
		int index=0;
		unordered_map<int,int> indexes;
		for(int i=0;i<str.length();i++)
		{
			bool isPresent=false;
			for(int j=0;j<size;j++)
			{
				if(cache[j]==str[i])
				{
					hit++;
					isPresent=true;
					break;
				}
			}

			if(i<size && isPresent==false)
			{
				cache[index]=str[i];
				index++;
				index=index%size;
				miss++;
			}
			else if(isPresent==false)
			{
				int leastUsedIndex=INT_MAX;
				int cacheEntry=0;
				for(int j=0;j<size;j++)
				{
					if(leastUsedIndex > indexes[cache[j]])
					{
						leastUsedIndex=indexes[cache[j]];
						cacheEntry=cache[j];
					}
				}

				for(int j=0;j<size;j++)
				{
					if(cache[j]==cacheEntry)
					{
						cache[j]=str[i];
					}
				}

				miss++;
			}

			indexes[str[i]]=i;
			displayCache();
		}
		cout<<" In Least Recently Used (LRU) page replacement algorithm for the reference string "<<str<<" the miss count is : "<<miss<<" & hit count is : "<<hit<<endl;
	}

};
int main()
{
	PageReplacement obj;
	int option;
	cout<<" Page Replacement Algorithms are :- "<<endl;
	cout<<" 1. First-In-First-Out (FIFO) "<<endl;
	cout<<" 2. Optimal Page Replacement "<<endl;
	cout<<" 3. Least Recently Used (LRU) "<<endl;
	cout<<" Select anyone Page Replacement algorithm : ";
	cin>>option;
	switch(option)
	{
	case 1:
		obj.FirstInFirstOut();
		break;
	case 2:
		obj.OptimalPageReplacement();
		break;
	case 3:
		obj.LeastRecentlyUsed();
		break;
	}

	return 0;
}
