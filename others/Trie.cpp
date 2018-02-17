#include<iostream>
#include<limits>
#include<algorithm>
#include<string>
#include<vector>
#include "conio.h"

const int ALPHABET_SIZE = 26;
using namespace std;

struct TrieNode
{
   struct TrieNode* children[ALPHABET_SIZE];
   bool isEndOfWord;
   TrieNode()
   {
       for(int i = 0; i < ALPHABET_SIZE; i++)
       {
            children[i] = NULL;
       }
       isEndOfWord = false;
   }
};


void insert(TrieNode* root, string key)
{
     TrieNode* pCrawl = root;
     for( int i = 0; i < key.size(); ++i)
     {
          int index = key[i] - 'a';
          if (!pCrawl->children[index])
          {
             pCrawl->children[index] = new TrieNode();
          }          
          pCrawl = pCrawl->children[index];
     }     
     
     pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string key)
{
     TrieNode* pCrawl = root;
     for( int i = 0; i < key.size(); ++i)
     {
          int index = key[i] - 'a';
          if (!pCrawl->children[index])
          {
             return false;
          }          
          pCrawl = pCrawl->children[index];
     }     
     return (pCrawl!= NULL) && (pCrawl->isEndOfWord == true);
}


int main(int argc, char* argv[])
{
    string dict[] = {"hello", "how", "what", "why"};
    int size = sizeof(dict)/sizeof(dict[0]);
    //vector<string> dict = {"hello", "how", "what", "why"};
    TrieNode* root = new TrieNode();
    
    for (int i = 0; i < size; ++i)
    {
        insert(root, dict[i]);
    }
    
    search(root, "hello")? cout << "Yes" : cout << "No";
    search(root, "helloa")? cout << "Yes" : cout << "No";
    
    getch();
    return 0;
}



