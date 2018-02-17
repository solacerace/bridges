#include<iostream>
using namespace std;

struct NODE
{
	NODE(int d, NODE* n): data(d), next(n)
	{
	}
	int data;
	NODE* next;
};


NODE* insert(NODE* head, int data)
{
	NODE* newNode = new NODE(data, NULL);
	// If head is NULL
	if (head == NULL)
	{
		return newNode;
	}
	NODE* cur = head;
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = newNode;
	return head;
}


NODE* reverse(NODE* head)
{
	if (head == NULL)
	{
		return NULL;
	}
	
	// Get the prev, cur and next element
	NODE* prev = NULL;
	NODE* cur = head;
	NODE* next = head->next;
	
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	
	return prev;
	
}

void print(NODE* head)
{
	
	NODE* cur = head;
	while(cur != NULL)
	{
		cout << cur->data << endl;
		cur = cur->next;		
	}
	
}

int main(int argc, char* argv[])
{
	NODE* head = NULL;
	for (int i = 0; i < 10; ++i)
	{
		cout << "Insert="<< i << endl;
	
		head = insert(head, i+10);
	}
	
	print(head);
	head = reverse(head);
	cout << "Reverse" << endl;
	print(head);
	
	return 0;	
}


