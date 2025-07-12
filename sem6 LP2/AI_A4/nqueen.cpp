#include<iostream>
#include<vector>
using namespace std;

class nqueens
{
    private:
        int n;
    public:
        nqueens(int n)
        {
            this->n=n;
        }
        void solve(vector<string> &board,vector<vector<string>> &ans, int col)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int i=0;i<4;i++)
            {
                if(issafe(board,i,col))
                {
                    board[i][col]='Q';
                    solve(board,ans,col+1);
                    board[i][col]='-';
                }
            }
        }
        bool issafe(vector<string> board, int row, int col)
        {
            for(int i=0;i<n;i++)
            {
                if(board[i][col]=='Q')
                    return false;
            }
            for(int i=0;i<n;i++)
            {
                if(board[row][i]=='Q')
                    return false;
            }
            int i=row;
            int j=col;
            while(i>=0 && j>=0)
            {
                if(board[i][j]=='Q')
                    return false;
                i--;
                j--;
            }
            i=row;
            j=col;
            while(i<n && j>=0)
            {
                if(board[i][j]=='Q')
                    return false;
                i++;
                j--;
            }
            return true;
        }

};

int main()
{
    nqueens nq(4);
    vector <vector <string>> ans;
    vector <string> board(4);
    string s(4,'-');
    for(int i=0;i<4;i++)
    {
        board[i]=s;
    }
    nq.solve(board,ans,0);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}