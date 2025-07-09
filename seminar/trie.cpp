#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
 
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
 
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}
 
bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    int j=0;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
        j=j+1;
    }
    cout<<"No. of comparisons: "<<j<<endl;
    return (pCrawl->isEndOfWord);
}
 
int main()
{
    ifstream fin;
    fin.open("input.txt");
    string key,key1;
    struct TrieNode *root = getNode();
    while(!fin.eof())
    {
        fin>>key;
        insert(root, key);
    } 
    char output[][32] = {" not present in trie", " present in trie"};
    cout<<"Enter word to be searched: ";
    cin>>key1;
    cout<<key1<<output[search(root, key1)]<<endl;
    return 0;
}