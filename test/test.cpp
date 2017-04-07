// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<malloc.h>
#include <string>
#include <iostream>
#include<stack>
using namespace  std;
struct ListNode
{
int data;
ListNode *next;
};
void printReverse(ListNode *head)
{
ListNode *p;
p = head;
	if(head == NULL)
	return;
std::stack<ListNode*>nodes;
	while(p)  //入栈
	{
		nodes.push(p);
		p = p->next;
	}   
	while(!nodes.empty())  //出栈
	{
		p =  nodes.top();
		printf("%d\n",p->data);
		nodes.pop();
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	//新建链表
	ListNode *head,*temp,*p;
	head  =(ListNode*) malloc(sizeof(ListNode));
	head->next = NULL;
	for(int i =0;i<5;i++)
	{
		temp =(ListNode*) malloc(sizeof(ListNode));
		temp->data = i;
		temp->next = NULL;
		if(i == 0)
		{
			head = temp;
			p = head;
		}
		else
		{
			
			p->next = temp;
			p = p->next;
		}
	      
	}
	printReverse(head);
	//释放链表
	p = head;
	while(p != NULL)
	{
	temp = p->next;
	free(p);
	p = temp;
	

	}

	system("pause");
	return 0;
}

