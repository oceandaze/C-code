#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ListNode
{
	int data;
	struct ListNode *next;

}ListNode;
					
ListNode *CreatHeadNode()
{
	ListNode*node = NULL;
	node = (ListNode*)malloc(sizeof(ListNode));
	if (node==NULL)
	{
		printf("malloc fair");
	}
	memset(node,0,sizeof(ListNode));
	node->next = NULL;
	return node;
}
void InsertHeadData(ListNode*head,  int data)
{
	ListNode*newnode = CreatHeadNode();
	newnode->data = data;
	newnode->next = head->next;
	head->next = newnode;

}
void InsertTailData(ListNode*head,int data)
{
	ListNode*newnode = CreatHeadNode();
	newnode->data = data;
	newnode->next = NULL;
	while (head->next)
	{
		head = head->next;
	}
	head->next = newnode;
}
void PrintNodeData(ListNode*head)
{
	head = head->next;
	while (head)
	{
		printf("%d", head->data);
		head = head->next;
	}
}
void PrintNodeData2(ListNode*head)
{
	//head = head->next;
	while (head)
	{
		printf("%d", head->data);
		head = head->next;
	}
}
void PrintNodeData_CL(ListNode*head)
{
	ListNode*tail = head;
	do 
	{
		printf("%d", tail->data);
		tail = tail->next;
	} while (tail!= head);
}
void DeleteNodeData(ListNode*head,int data)
{
	ListNode*prev = head;
	ListNode*cur = head;
	while (cur->next)
	{
		if (cur->data==data)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
}
void FreeNode(ListNode*head)
{
	ListNode*prev = head->next;
	while (prev)
	{
		free(head);
		head = prev;
		prev = prev->next;
	}
	free(head);
}
int CountNode(ListNode*head)
{
	int cnt = 0;
	while (head->next)
	{
		cnt++;
		head = head->next;
	}
	return cnt;
}
void bubbleSort(ListNode*head)
{
	ListNode*p = NULL;
	ListNode*q = NULL;
	for (p=head->next;p->next!=NULL;p=p->next)
	{
		for (q=head->next;q->next!=NULL;q=q->next)
		{
			if (q->data>q->next->data)
			{
				int t = q->data;
				q->data = q->next->data;
				q->next->data = t;
			}
		}
	}
}
int main1()
{
	ListNode*head = CreatHeadNode();
	int arr[5] = {3,2,5,4,1};
	for (int i=0;i<5;i++)
	{
		InsertHeadData(head, arr[i]);
	}
	bubbleSort(head);
	PrintNodeData(head);
	//int n = CountNode(head);
	//printf("%d",n);
	system("pause");
	return 0;
}

ListNode*CreatSingleList(ListNode*head, char*data,int n)
{
	head = CreatHeadNode();
	head->data = data[0];
	ListNode*p = head;
	for (int i = 1; i < n; i++)
	{
		p->next = CreatHeadNode();
		p = p->next;
		p->data = data[i];
	}
	return head;
}
ListNode* CreatList_CL(ListNode*head, int*data,int n)
{
	head = CreatHeadNode();
	head->data = data[0];
	ListNode *p = head;
	for (int i = 1; i < n; i++)
	{
		p->next = CreatHeadNode();
		p = p->next;
		p->data = data[i];
	}
	p->next = head;
	return head;
}
// ListNode *CreatList(ListNode * head, int *data)
// {
// 	int i = 0;
// 	ListNode *tail = NULL;
// 	for (i = 0; i < 5; i++)
// 	{
// 		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
// 		node->data = data[i];
// 		node->next = NULL;
// 		if (head == NULL)
// 		{
// 			head = node;
// 			tail = head;
// 		}
// 		else
// 		{
// 			tail->next = node;
// 			tail = tail->next;
// 		}
// 	}
// 	tail->next = head;
// 	return head;
// }

ListNode*CreatListconnect(ListNode*head, int*data)
{
	ListNode*q = head;
	while (q->next)
	{
		q = q->next;
	}
	q->next = CreatHeadNode();
	ListNode*p = q->next;
	p->data = data[0];
	for (int i = 1; i < 6; i++)
	{
		p->next = CreatHeadNode();
		p = p->next;
		p->data = data[i];
	}
	return head;
}
void CreatSingleList2(ListNode**head, int*data,int n)
{
	*head=CreatHeadNode();
	ListNode *p = *head;
	p->data = data[0];
	for (int i = 1; i < n; i++)
	{
		p->next = CreatHeadNode();
		p = p->next;
		p->data = data[i];
	}
}
ListNode* ReverseList(ListNode *head)
{
	ListNode *prev = NULL;
	ListNode *cur = NULL;
	ListNode *temp = NULL;
	cur = head;
	while (cur)
	{
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}
	return prev;
}
void KillGame(ListNode*head)
{
	ListNode*tmp = head;
	ListNode*t = NULL;
	while (tmp->next!=tmp)
	{
		tmp = tmp->next->next;
		printf("%d\t", tmp->data);
		tmp->data = tmp->next->data;
		t = tmp->next;
		tmp->next = t->next;
		free(t);
	}
	printf("%d\n", tmp->data);
}

int main()
{
// 	int data[] = {1,2,3,4,5,6};
// 	int n = sizeof(data) / sizeof(data[0]);
	//ListNode*head =NULL ;
	//head = CreatSingleList(head,data,n);//创建链表
	
	//head=ReverseList(head);	//反转链表
	//head = CreatListconnect(head,data);//续接链表
	//CreatSingleList2(&head, data,n);//无返回值链表
	//PrintNodeData2(head); //打印无头链表
// 	for (int i=0;i<=41;i++)
// 		{
// 			data[i] = i+1;
// 		}
	//head = CreatList_CL(head, data,41); //创建环形链表
	//KillGame(head);

	//PrintNodeData_CL(head);//打印环形链表

// 	int data[] = { 1,1,2 };
// 	ListNode*head = CreatHeadNode();
// 	for (int i = 0; i < 3; i++)
// 	{
// 		InsertTailData(head, data[i]);
// 	}
// 	deleteDuplicates(head);
// 	PrintNodeData(head);
	int arr[10] = {166677};
	printf("%d\n",strlen(arr));
	int arr2[10] = { 513};
	printf("%d\n", strlen(arr2));
// 	char arr3[10] = { 510 };
// 	printf("%d\n", strlen(arr3));
// 	char arr4[10] = {513 };
// 	printf("%d\n", strlen(arr4));
	system("pause");
	return 0;
}



