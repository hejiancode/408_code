#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;	//定义元素数据类型

/*定义一个结构体*/
typedef struct Node {
	elemtype data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

/*带有头节点的单链表的初始化函数的定义*/
int InitList(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(Node));		//为链表动态分配节点

	/*判断是否成功分配，并将最后一个指针指向NULL*/
	if (!L) {
		printf("分配内存失败！\n");
		exit(0);
	}
	else {
		(*L)->next = NULL;
	}
	
	return 0;
}

/*头插法创建一个单链表，n为要插入的元素个数*/
void CreateListHead(LinkList* L) {
	int i, n;
	LinkList p;

	/*若前面创建过链表，则该步骤可省略
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	*/

	printf("请输入您要插入元素的个数：");
	scanf_s("%d", &n);
	printf("请输入你要插入的元素值(倒序输入)(用空格隔开)：");

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		scanf_s("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/*尾插法创建一个单链表，n为要插入的元素个数*/
void CreateListTail(LinkList* L) {
	int i, n;
	LinkList p, r;

	//(*L) = (LinkList)malloc(sizeof(Node));

	/*指针指向尾节点*/
	r = *L;		
	while (r->next != NULL) {
		r = r ->next;
	}

	printf("请输入您要插入元素的个数：");
	scanf_s("%d", &n);
	printf("请输入你要插入的元素值（顺序输入）(用空格隔开)：");

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

/*计算链表长度*/
int LengthList(LinkList* L) {
	int length = 0;
	LinkList p;
	p = (*L)->next;
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}

/*查询第i位置上的元素*/
bool Get_Locate_Elem(LinkList* L, int i) {
	LinkList p;
	p = *L;
	int j = 0;
	int flag = 0;
	elemtype e = 0;
	
	/*具体插入操作*/
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (j == i) {
		flag = 1;
		e = p->data;
	}
	else {
		flag = 0;
	}

	/*根据flag判断操作是否成功*/
	if (flag) {
		printf("查询得到的元素为：%d",e);
		return true;
	}
	else {
		return false;
	}
}

/*查找元素的位置*/
bool Get_Elem_Locate(LinkList* L, elemtype e) {
	LinkList p;
	p = *L;
	int flag = 0;
	int count = 0;
		
	while (p != NULL) {
		if (p->data == e) {
			flag = 1;
			printf("该元素的位置是：%d", count);
		}
		p = p->next;
		count++;
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

/*在L中第i个位置插入元素e*/
bool Insert_Locate_List(LinkList* L, int i, elemtype e) {
	LinkList p, s;
	int j = 1;
	int flag;
	p = *L;

	/*申请一个节点去存储待插入的元素*/
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	/*具体插入操作*/
	while (p != NULL && j < i) {
		p = p->next;
		j++;
		}
	if (j == i) {
		flag = 1;
		s->next = p->next;
		p->next = s;
	}
	else {
		flag = 0;
	}

	/*根据flag判断操作是否成功*/
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}


bool Insert_Elem_List(LinkList* L, elemtype k, elemtype e) {
	LinkList p, s;
	int flag = 0;
	p = *L;

	/*申请一个节点去存储待插入的元素*/
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	/*具体操作*/
	while (p != NULL) {
		if (p->data == k) {
			s->next = p->next;
			p->next = s;
			flag = 1;
		}
		p = p->next;
	}
	
	/*根据flag判断操作是否成功*/
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

/*删除L中第i个元素，并用e返回其值*/
bool Delete_locate_List(LinkList* L, int i, elemtype* e) {
	LinkList p, q;
	int j = 1;
	p = *L;

	while (p->next && j < i) {
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) {
		return false;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return true;
}

//更改指定元素
bool Alter_Elem(LinkList* L,elemtype e, elemtype m) {
	LinkList p;
	int flag = 0;

	p = (*L)->next;
	while (p != NULL) {
		if (p->data == e) {
			p->data = m;
			flag = 1;
		}
		p = p->next;
	}
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

/*更改指定位置的元素*/
bool Alter_Locate_Elem(LinkList* L, int i, elemtype m) {
	int flag = 0;
	int j = 0;
	LinkList p;
	p = (*L);

		while (p != NULL && j <= i) {
			p = p->next;
			j++;

			if (j == i) {
				p->data = m;
				flag = 1;
			}	
		}	
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}
/*单链表的整表删除*/
int ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return 0;
}

/*打印整个链表*/
void ShowList(LinkList* L) {
	LinkList p;
	p = (*L)->next;
	if (p == NULL) {
		printf("这是一个空链表！\n");
	}
	printf("单链表");
	while (p) {
		printf(" -> %d", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList* L;

	InitList(&L);	//创建一个空的带头结点的单链表

	int k, i;
	elemtype m,e;

	/*开始进行链表相关操作*/
	/*保证一直进行*/
	while (1) {
		printf("当前的链表：");  //展现链表现状
		ShowList(&L);
		printf("\n");
		printf("单链表的长度为%d\n", LengthList(&L));

		/*功能展示菜单*/
		printf("\n-----------------------------------------\n");
		printf("         Main Menu         \n");

		printf("    0   结束程序      \n\n");

		printf("    1   （创）采用头插法插入元素   \n");
		printf("    2   （创）采用尾插法插入元素   \n\n");

		printf("    3   （增）基于位置插入元素   \n");
		printf("    4   （增）基于特定元素后插入元素   \n\n");

		printf("    5   （删）删除指定位置上的元素   \n\n");
		
		printf("    6   （改）修改指定元素   \n");
		printf("    7   （改）修改指定位置的元素   \n\n");

		printf("    8   （查）查找指定位置上的元素    \n");
		printf("    9   （查）查找指定元素的位置    \n\n");

		printf("    10   销毁整个单链表    \n\n");

		printf("    11  清屏   \n");

		printf("------------------------------------\n");

		printf("请输入你要实现的功能的菜单号<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>:\n");
		scanf_s("%d", &i);

		switch (i) {
		case 0:
			exit(0);
			break;

		case 1:
			CreateListHead(&L);
			break;
		
		case 2:
			CreateListTail(&L);
			break;

		case 3:
			printf("请输入你想要插入的元素的位置：");
			scanf_s("%d", &m);
			printf("请输入你想更插入什么元素：");
			scanf_s("%d", &e);

			if (Insert_Locate_List(&L, m, e)) {
				printf("插入元素成功！\n");
			}
			else {
				printf("插入元素失败！\n");
			}

			break;

		case 4:
			printf("请输入你想要插入的元素的前一个元素：");
			scanf_s("%d", &i);
			printf("请输入你想更插入什么元素：");
			scanf_s("%d", &m);

			if (Insert_Elem_List(&L, i, m)) {
				printf("插入元素成功！\n");
			}
			else {
				printf("插入元素失败！\n");
			}

			break;

		case 5:
			printf("请输入你想删除第几个元素：");
			scanf_s("%d",&k);
			if (Delete_locate_List(&L, k, &m)) {
				printf("删除元素成功！\n");
			}
			else {
				printf("删除元素失败！\n");
			}
			break;

		case 6:
			printf("请输入你想更改那个元素：");
			scanf_s("%d", &e);
			printf("请输入你想更改为什么：");
			scanf_s("%d", &m);

			if (Alter_Elem(&L, e, m)) {
				printf("更改元素成功！\n");
			}
			else {
				printf("更改元素失败！\n");
			}
			break;
		
		case 7:
			printf("请输入你想更改元素的位置：");
			scanf_s("%d", &i);
			printf("请输入你想更改为什么：");
			scanf_s("%d", &m);

			if (Alter_Locate_Elem(&L, i, m)) {
				printf("更改元素成功！\n");
			}
			else {
				printf("更改元素失败！\n");
			}
			break;

		case 8:
			printf("请输入你想查询元素的位置：");
			scanf_s("%d", &i);

			if (Get_Locate_Elem(&L, i)) {
				printf("查询成功！\n");
			}
			else {
				printf("查询失败！\n");
			}
			break;

		case 9:
			printf("请输入你想查询的元素：");
			scanf_s("%d", &e);

			if (Get_Elem_Locate(&L, e)) {
				printf("查询成功！\n");
			}
			else {
				printf("查询失败！\n");
			}
			break;

		case 10:
			ClearList(&L);
			system("pause");
			break;

		case 11:
			system("cls");
			break;

		default:
			printf("操作有误~");
		}
	}
	return 0;
}