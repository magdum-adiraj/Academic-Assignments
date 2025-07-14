#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

class Graph
{
    private:
        int V;
        vector<vector<int>> adj;

    public:
        Graph(int v)
        {
            this->V=v;
            adj.resize(V);
        }

        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void parallelBFS(int start)
        {
            vector<bool> visited(adj.size(),false);
            visited[start]=true;
            queue<int> q;
            q.push(start);
            while(!q.empty())
            {
                int u;
    #pragma omp parallel shared(q,visited)
                {
    #pragma omp single
                    {
                        u=q.front();
                        q.pop();
                        cout<<u<<" ";
                    }
                    if(adj[u].size()!=0)
                    {
    #pragma omp for
                            for(int i=0;i<=adj[u].size()-1;++i)
                            {
                                if(!visited[adj[u][i]])
                                {
    #pragma omp critical
                                    {
                                        q.push(adj[u][i]);
                                        visited[adj[u][i]]=true;
                                    }
                                }
                            }
                    }
                }
            }

        }
};

template <typename T>
T parallelMin(const vector<T> &arr){
    T result=arr[0];
    #pragma omp parallel for reduction(min:result)
    for(int i=0;i<arr.size();i++)
    {
        result=min(result,arr[i]);
    }
    return result;
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.parallelBFS(0);
    return 0;
}