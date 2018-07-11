#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}

void reversewords(char* str)
{
    size_t N = strlen(str);
    reverse(&str[0], &str[N]);
    cout << "str=" << str << endl;

    size_t s = 0, l = 0;
    while ( l < N)
    {
        while (str[l] != ' ' && str[l] != '\0')
            l++;

        reverse(&str[s], &str[l]);
        cout << "str=" << str << endl;
        s = ++l;
    }

}


int  maxSequence(vector<int>& a)
{
    long cs = a[0], ms = a[0];

    for (int i = 1; i < a.size(); ++i)
    {
        cs = max(cs + a[i], a[i]);
        ms = max(ms, cs);
    }
    return ms;
}


int  profitLoss(vector<int>& a)
{
    int gm = a[0], mp=0;
    for (int i = 1; i < a.size(); ++i)
    {
        gm = min(gm, a[i]);
        mp = max(mp, a[i] - gm);
    }
    return mp;
}


void rotateArray(vector<int>& a, int L)
{
    //I = 3 5 8 2 4 6
    //O = 4 6 3 5 8 2
    
    // 642853
    reverse(a.begin(), a.end());
    // 
    reverse(a.begin(), a.begin()+L);
    reverse(a.begin()+L, a.end());
}


int lengthOfLW(const char* str)
{
    int N = strlen(str);
    int l = N;
    //Find the position of last word.
    while (l > 0 && str[l] != ' ')
        l--;
    return (N - l-1);
}

bool validatePar(const string& str)
{
    stack<int> s;
    auto fun = [](char c, char st) 
        { 
            if (c == ']' && st == '[') return true;
            if (c == '}' && st == '{') return true; 
            if (c == ')' && st == '(') return true;
            return false;
    };

    for (auto&& c : str)
    {
        if (c == '[' || c == '{' || c == '(')
        {
            s.push(c);
        }
        else
        {
            if (s.size() > 0 && fun(c, s.top()))
                s.pop();
            else
                return false;
        }
    }
    if (s.size() != 0)
        return false;
    return true;
}


struct Node
{
    Node(int value) : value(value), next(NULL) {}
    int value;
    Node* next;
};

Node* insert(Node* head, int val)
{
    if (head == NULL)
        return new Node(val);

    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

Node* merge(Node* l1, Node* l2)
{
    Node* dummyHead = new Node(0);
    Node *p = dummyHead;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->value < l2->value)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    if (l1 != NULL) p->next = l1;
    if (l2 != NULL) p->next = l2;

    return dummyHead->next;
}


/*
hihow
01234

*/

bool WordBreak(const string& s, set<string>& d)
{
    for (int i = 0; i < s.size(); i++)
    {
        string iw = s.substr(0, i + 1);
        if (d.find(iw) != d.end())
        {
            std::cout << iw.c_str() << '\t'; 
            string nw = s.substr(i + 1, s.size() - (i + 1));
            if (i+1 == s.size() || WordBreak(nw, d))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    set<string> d = { "love", "is", "no", "now", "where", "here" };
    string s("loveisnowhere");
    if (WordBreak(s, d))
        cout << "Pass";
    else
        cout << "Fail";
    return 0;

    char str[100] = "HOW ARE YOU";
    reversewords(str);
    cout << "str=" << str << endl;

    vector<int> v = {5, 3, -9, 12, 21, -5};
    long ms = maxSequence(v);
    cout << "ms=" << ms << endl;

    vector<int> a = { 3, 5, 8, 2, 24 };
    int mp = profitLoss(a);
    cout << "mp=" << mp << endl;

    rotateArray(a, 2);
    for_each(a.begin(), a.end(), [](int& v) {cout << v << " "; });

    cout << "lengthOfLW=" << lengthOfLW("how are you") << endl;
    bool res = validatePar("({[]})");
    cout << "res=" << validatePar("({[]})") << endl;
    cout << "res=" << validatePar("[({[]})") << endl;

    Node* l1 = NULL;
    for (auto&& i : vector<int>({20,12,8,4,1}))
        l1 = insert(l1, i);
    print(l1);

    Node* l2 = NULL;
    for (auto&& i : vector<int>({ 30,22,18,14,11 }))
        l2 = insert(l2, i);
    print(l2);

    Node* l3 = merge(l1, l2);
   print(l3);

   set<string> ss = {"love", "is", "no", "now", "where", "here" };

   for_each(ss.begin(), ss.end(), [](const string& word)
   { 
       cout << word.c_str() << " ";
   }
   );

    return 1;
}

