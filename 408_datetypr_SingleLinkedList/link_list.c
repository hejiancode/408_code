#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;	//����Ԫ����������

/*����һ���ṹ��*/
typedef struct Node {
	elemtype data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;

/*����ͷ�ڵ�ĵ�����ĳ�ʼ�������Ķ���*/
int InitList(LinkList* L) {
	(*L) = (LinkList)malloc(sizeof(Node));		//Ϊ����̬����ڵ�

	/*�ж��Ƿ�ɹ����䣬�������һ��ָ��ָ��NULL*/
	if (!L) {
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	else {
		(*L)->next = NULL;
	}
	
	return 0;
}

/*ͷ�巨����һ��������nΪҪ�����Ԫ�ظ���*/
void CreateListHead(LinkList* L) {
	int i, n;
	LinkList p;

	/*��ǰ�洴����������ò����ʡ��
	(*L) = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	*/

	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf_s("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ(��������)(�ÿո����)��");

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		scanf_s("%d", &p->data);
		p->next = (*L)->next;
		(*L)->next = p;
	}
}

/*β�巨����һ��������nΪҪ�����Ԫ�ظ���*/
void CreateListTail(LinkList* L) {
	int i, n;
	LinkList p, r;

	//(*L) = (LinkList)malloc(sizeof(Node));

	/*ָ��ָ��β�ڵ�*/
	r = *L;		
	while (r->next != NULL) {
		r = r ->next;
	}

	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf_s("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ��˳�����룩(�ÿո����)��");

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		scanf_s("%d", &p->data);
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

/*����������*/
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

/*��ѯ��iλ���ϵ�Ԫ��*/
bool Get_Locate_Elem(LinkList* L, int i) {
	LinkList p;
	p = *L;
	int j = 0;
	int flag = 0;
	elemtype e = 0;
	
	/*����������*/
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

	/*����flag�жϲ����Ƿ�ɹ�*/
	if (flag) {
		printf("��ѯ�õ���Ԫ��Ϊ��%d",e);
		return true;
	}
	else {
		return false;
	}
}

/*����Ԫ�ص�λ��*/
bool Get_Elem_Locate(LinkList* L, elemtype e) {
	LinkList p;
	p = *L;
	int flag = 0;
	int count = 0;
		
	while (p != NULL) {
		if (p->data == e) {
			flag = 1;
			printf("��Ԫ�ص�λ���ǣ�%d", count);
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

/*��L�е�i��λ�ò���Ԫ��e*/
bool Insert_Locate_List(LinkList* L, int i, elemtype e) {
	LinkList p, s;
	int j = 1;
	int flag;
	p = *L;

	/*����һ���ڵ�ȥ�洢�������Ԫ��*/
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	/*����������*/
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

	/*����flag�жϲ����Ƿ�ɹ�*/
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

	/*����һ���ڵ�ȥ�洢�������Ԫ��*/
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	/*�������*/
	while (p != NULL) {
		if (p->data == k) {
			s->next = p->next;
			p->next = s;
			flag = 1;
		}
		p = p->next;
	}
	
	/*����flag�жϲ����Ƿ�ɹ�*/
	if (flag) {
		return true;
	}
	else {
		return false;
	}
}

/*ɾ��L�е�i��Ԫ�أ�����e������ֵ*/
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

//����ָ��Ԫ��
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

/*����ָ��λ�õ�Ԫ��*/
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
/*�����������ɾ��*/
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

/*��ӡ��������*/
void ShowList(LinkList* L) {
	LinkList p;
	p = (*L)->next;
	if (p == NULL) {
		printf("����һ��������\n");
	}
	printf("������");
	while (p) {
		printf(" -> %d", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkList* L;

	InitList(&L);	//����һ���յĴ�ͷ���ĵ�����

	int k, i;
	elemtype m,e;

	/*��ʼ����������ز���*/
	/*��֤һֱ����*/
	while (1) {
		printf("��ǰ������");  //չ��������״
		ShowList(&L);
		printf("\n");
		printf("������ĳ���Ϊ%d\n", LengthList(&L));

		/*����չʾ�˵�*/
		printf("\n-----------------------------------------\n");
		printf("         Main Menu         \n");

		printf("    0   ��������      \n\n");

		printf("    1   ����������ͷ�巨����Ԫ��   \n");
		printf("    2   ����������β�巨����Ԫ��   \n\n");

		printf("    3   ����������λ�ò���Ԫ��   \n");
		printf("    4   �����������ض�Ԫ�غ����Ԫ��   \n\n");

		printf("    5   ��ɾ��ɾ��ָ��λ���ϵ�Ԫ��   \n\n");
		
		printf("    6   ���ģ��޸�ָ��Ԫ��   \n");
		printf("    7   ���ģ��޸�ָ��λ�õ�Ԫ��   \n\n");

		printf("    8   ���飩����ָ��λ���ϵ�Ԫ��    \n");
		printf("    9   ���飩����ָ��Ԫ�ص�λ��    \n\n");

		printf("    10   ��������������    \n\n");

		printf("    11  ����   \n");

		printf("------------------------------------\n");

		printf("��������Ҫʵ�ֵĹ��ܵĲ˵���<0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11>:\n");
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
			printf("����������Ҫ�����Ԫ�ص�λ�ã�");
			scanf_s("%d", &m);
			printf("���������������ʲôԪ�أ�");
			scanf_s("%d", &e);

			if (Insert_Locate_List(&L, m, e)) {
				printf("����Ԫ�سɹ���\n");
			}
			else {
				printf("����Ԫ��ʧ�ܣ�\n");
			}

			break;

		case 4:
			printf("����������Ҫ�����Ԫ�ص�ǰһ��Ԫ�أ�");
			scanf_s("%d", &i);
			printf("���������������ʲôԪ�أ�");
			scanf_s("%d", &m);

			if (Insert_Elem_List(&L, i, m)) {
				printf("����Ԫ�سɹ���\n");
			}
			else {
				printf("����Ԫ��ʧ�ܣ�\n");
			}

			break;

		case 5:
			printf("����������ɾ���ڼ���Ԫ�أ�");
			scanf_s("%d",&k);
			if (Delete_locate_List(&L, k, &m)) {
				printf("ɾ��Ԫ�سɹ���\n");
			}
			else {
				printf("ɾ��Ԫ��ʧ�ܣ�\n");
			}
			break;

		case 6:
			printf("��������������Ǹ�Ԫ�أ�");
			scanf_s("%d", &e);
			printf("�������������Ϊʲô��");
			scanf_s("%d", &m);

			if (Alter_Elem(&L, e, m)) {
				printf("����Ԫ�سɹ���\n");
			}
			else {
				printf("����Ԫ��ʧ�ܣ�\n");
			}
			break;
		
		case 7:
			printf("�������������Ԫ�ص�λ�ã�");
			scanf_s("%d", &i);
			printf("�������������Ϊʲô��");
			scanf_s("%d", &m);

			if (Alter_Locate_Elem(&L, i, m)) {
				printf("����Ԫ�سɹ���\n");
			}
			else {
				printf("����Ԫ��ʧ�ܣ�\n");
			}
			break;

		case 8:
			printf("�����������ѯԪ�ص�λ�ã�");
			scanf_s("%d", &i);

			if (Get_Locate_Elem(&L, i)) {
				printf("��ѯ�ɹ���\n");
			}
			else {
				printf("��ѯʧ�ܣ�\n");
			}
			break;

		case 9:
			printf("�����������ѯ��Ԫ�أ�");
			scanf_s("%d", &e);

			if (Get_Elem_Locate(&L, e)) {
				printf("��ѯ�ɹ���\n");
			}
			else {
				printf("��ѯʧ�ܣ�\n");
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
			printf("��������~");
		}
	}
	return 0;
}