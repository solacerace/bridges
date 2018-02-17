#include<iostream>
#include<stack>

using namespace std;

bool match(char a, char b)
{
	if (a == '(' && b == ')')
		return true;
	if (a == '{' && b == '}')
		return true;
	if (a == '[' && b == ']')
		return true;	
		
	return false;
}

bool validParenthesis(char* s)
{
	stack<char> st;
	int i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			st.push(s[i]);
		
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (st.size() == 0)
				return false;
			char t = st.top();
			if (match(t,s[i]))
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
		i++;
	}
	cout << "st.size=" << st.size() << endl;
	if (st.size() != 0)
	{
		return false;
	}
	
	return true;
}

int main(int argc, char* argv[])
{
	char s[] = "(){{}}";
	bool res = validParenthesis(s);
	if (res)
	cout << "Result=MATCH" <<  endl;
	else
	cout << "Result=NO-MATCH" << endl;
	
	return true;
}


