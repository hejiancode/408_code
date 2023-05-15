#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/*��������ͽڵ�Ľṹ��*/
typedef struct Node   //˫��������ṹ��
{
    int data;           //����
    struct Node* prev;  //ǰ��ָ��
    struct Node* next;  //���ָ��
}Node;

typedef struct DoubleList   //˫������ṹ��
{
    Node* head;     //ͷ���
    Node* tail;     //β���
    size_t size;    //������
}DoubleList;

/*��������ʼ��˫��������*/
Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));   //Ϊ�½ڵ������ڴ�
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/*��ʼ������*/
void init_list(DoubleList* list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/*�ͷ�����*/
void free_list(DoubleList* list)
{
    while (list->size)
    {
        Node* tmp = list->head;
        list->head = list->head->next;
        free(tmp);
        tmp = NULL;
        list->size--;
    }
}

/*��ȡ������*/
size_t get_size(DoubleList* list)
{
    return list->size;
}

//��ȡͷ���
Node* get_head(DoubleList* list)
{
    return list->head;
}

//��ȡβ���
Node* get_tail(DoubleList* list)
{
    return list->tail;
}

//��������
void show_list(DoubleList* list)
{
    Node* node = list->head;
    for (int i = 0; i < list->size; ++i)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

//����һ��ͷ���
void push_head(DoubleList* list, int data)
{
    Node* new_node = create_node(data);

    //����Ϊ��
    if (list->size == 0)
    {
        //����Ľ�����ͷ��㣬Ҳ��β���
        list->head = new_node;
        list->tail = new_node;
    }
    //����Ϊ��
    else
    {
        //���½�������ͨ��ǰ��ָ��prev�ͺ��ָ��next��������
        new_node->next = list->head;
        list->head->prev = new_node;
        //��ͷ����Ϊ�²���Ľ��
        list->head = new_node;
    }
    list->size++;
}

//����һ��β���
void push_tail(DoubleList* list, int data)
{
    Node* new_node = create_node(data);

    //����Ϊ��
    if (list->size == 0)
    {
        //����Ľ�����β��㣬Ҳ��ͷ���
        list->tail = new_node;
        list->head = new_node;
    }
    //����Ϊ��
    else
    {
        //���½�������ͨ��ǰ��ָ��prev�ͺ��ָ��next��������
        list->tail->next = new_node;
        new_node->prev = list->tail;
        //��β����Ϊ�²���Ľ��
        list->tail = new_node;
    }
    list->size++;

}

//����λ�ò�����
bool insert_node(DoubleList* list, int index, int data)
{
    //�����λ�ó�������ķ�Χ
    if (index <0 || index > list->size)
        return false;
    //�����λ���������0����ͬ�ڲ���ͷ���
    if (index == 0)
    {
        push_head(list, data);
        return true;
    }
    //�����λ�������������ĳ��ȣ���ͬ�ڲ���β���
    else if (index == list->size)
    {
        push_tail(list, data);
        return true;
    }

    Node* tmp = NULL;
    //�����λ�����С�ڵ����м�λ�ã��ǲ����λ�ø�����ͷ���
    if (index <= list->size / 2)
    {
        //��ͷ��㿪ʼ��������������ǰһ��λ��
        tmp = list->head;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }
    }
    //�����λ����������м�λ�ã��ǲ����λ�ø�����β���
    else
    {
        //��β��㿪ʼ��ǰ�����������ǰһ��λ��
        tmp = list->tail;
        for (int i = 0; i < list->size - index; ++i)
        {
            tmp = tmp->prev;
        }
    }

    Node* new_node = create_node(data);

    tmp->next->prev = new_node;
    new_node->next = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
    list->size++;
    return true;
}

//ɾ��ͷ���
void del_head(DoubleList* list)
{
    if (list->size == 0)
        return;
    if (list->size == 1)
    {
        free(list->head);//�ͷ��ڴ�
        init_list(list);
        return;
    }

    Node* tmp = list->head;//����ͷ���
    list->head = tmp->next;
    list->head->prev = NULL;

    free(tmp);//�ͷ��ڴ�
    tmp = NULL;
    list->size--;
}

//ɾ��β���
void del_tail(DoubleList* list)
{
    if (list->size == 0)
        return;
    if (list->size == 1)
    {
        free(list->tail);//�ͷ��ڴ�
        init_list(list);
        return;
    }

    Node* tmp = list->tail;//����β���
    list->tail = tmp->prev;
    list->tail->next = NULL;

    free(tmp);//�ͷ��ڴ�
    tmp = NULL;
    list->size--;
}

//ɾ������λ�ý��
bool del_node(DoubleList* list, int index)
{
    //�жϲ����λ���Ƿ񳬳�����ķ�Χ
    if (index < 0 || index > list->size)
        return false;
    //ɾ����λ���������0����ͬ��ɾ��ͷ���
    if (index == 0)
    {
        del_head(list);
        return true;
    }
    //ɾ����λ�������������ĳ��ȣ���ͬ��ɾ��β���
    if (index == list->size)
    {
        del_tail(list);
        return true;
    }

    Node* tmp = NULL;

    //ɾ����λ�����С���м�λ��
    if (index < list->size / 2)
    {
        //��ͷ��㿪ʼ���������ɾ���ĵĽ��
        tmp = list->head;
        for (int i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }
    }
    //ɾ����λ��������ڵ����м�λ��
    else
    {
        //��β��㿪ʼ��ǰ������ɾ���Ľ��
        tmp = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            tmp = tmp->prev;
        }
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    free(tmp);//�ͷ��ڴ�
    tmp = NULL;
    list->size--;
    return true;
}

//��ȡ����λ�ý��
Node* get_node(DoubleList* list, int index)
{
    //�жϲ����λ���Ƿ񳬳�����ķ�Χ
    if (index < 0 || index > list->size)
        return NULL;
    Node* node = NULL;
    //Ŀ�����λ�����С���м�λ��
    if (index < list->size / 2)
    {
        //��ͷ��㿪ʼ���������Ŀ����
        node = list->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
    }
    //Ŀ�����λ��������ڵ����м�λ��
    else
    {
        //��β��㿪ʼ��ǰ������Ŀ����
        node = list->tail;
        for (int i = 0; i < list->size - index - 1; ++i)
        {
            node = node->prev;
        }
    }
    return node;
}

//��ȡ������ָ���������ڵĵ�һ�����
Node* find_data(DoubleList* list, int data)
{
    if (list->size == 0)
        return NULL;
    Node* node = list->head;
    while (node)
    {
        if (node->data == data)
            return node;
        node = node->next;
    }
    return NULL;
}

//�޸�������ָ������ֵ
bool modify_node(DoubleList* list, int index, int data)
{
    Node* node = get_node(list, index);
    if (node)
    {
        node->data = data;
        return true;
    }
    return false;
}

//�޸�������ָ���ĵ�һ������
bool modify_data(DoubleList* list, int data, int val)
{
    Node* node = find_data(list, data);
    if (node)
    {
        node->data = val;
        return true;
    }
    return false;
}

/*�Գ���������в���*/
void test_insert_del_node()   //������ɾ��ʼ�������Ƿ�ɹ�
{
    //Ϊd_list�����ڴ棬���δ���룬����ֶδ���
    DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
    init_list(d_list);//��ʼ������
    printf("insert head and insert tail---------------------------------\n");
    push_head(d_list, 5);
    push_tail(d_list, 15);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("insert nodes at any location---------------------------------\n");
    insert_node(d_list, 0, 1);
    insert_node(d_list, 2, 10);
    insert_node(d_list, 4, 20);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("delete head and delete tail---------------------------------\n");
    del_head(d_list);
    del_tail(d_list);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("delete nodes at any location---------------------------------\n");
    del_node(d_list, 1);
    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));
}

void test_find_node()   //���Բ��Ҳ����Ƿ�ɹ�
{
    //Ϊd_list�����ڴ棬���δ���룬����ֶδ���
    DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
    init_list(d_list);//��ʼ������

    printf("create a test double list----------------------------------\n");
    for (int i = 1; i <= 10; ++i)
    {
        push_tail(d_list, i);
    }

    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("get the node through the index------------------------------\n");
    Node* node = get_node(d_list, 7);
    if (node)
        printf("success, data: %d\n", node->data);
    else
        printf("index out of the range\n");

    node = get_node(d_list, 12);
    if (node)
        printf("success, data: %d\n", node->data);
    else
        printf("index out of the range\n");

    printf("find the node through the data------------------------------\n");
    Node* tmp = find_data(d_list, 5);
    if (tmp)
        printf("success, data: %d\n", tmp->data);
    else
        printf("data not in the list!\n");

    tmp = find_data(d_list, 20);
    if (tmp)
        printf("success, data: %d\n", tmp->data);
    else
        printf("data not in the list!\n");

}

void test_modify_node()   //���Ի�ȡ��Ϣ�����Ƿ�ɹ�
{
    //Ϊd_list�����ڴ棬���δ���룬����ֶδ���
    DoubleList* d_list = (DoubleList*)malloc(sizeof(DoubleList));
    init_list(d_list);//��ʼ������

    printf("create a test double list----------------------------------\n");
    for (int i = 1; i <= 10; ++i)
    {
        push_tail(d_list, i);
    }

    show_list(d_list);
    printf("list length : %zd\n", get_size(d_list));

    printf("modify the node through the index-----------------------------------------------\n");
    bool res = modify_node(d_list, 2, 11);
    if (res)
    {
        printf("modify node success\n");
        show_list(d_list);
        printf("list length : %zd\n", get_size(d_list));
    }
    else
        printf("modify node fail! index out of the range!\n");

    res = modify_node(d_list, 11, 11);
    if (res)
    {
        printf("modify node success\n");
        show_list(d_list);
        printf("list length : %zd\n", get_size(d_list));
    }
    else
        printf("modify node fail: index out of the range!\n");

    printf("modify the node through the data------------------------------\n");
    bool flag = modify_data(d_list, 5, 30);
    if (flag)
    {
        printf("modify data success\n");
        show_list(d_list);
        printf("list length : %zd\n", get_size(d_list));
    }
    else
        printf("modify data fail: data not in the list!!\n");

    flag = modify_data(d_list, 15, 25);
    if (flag)
    {
        printf("modify data success\n");
        show_list(d_list);
        printf("list length : %zd\n", get_size(d_list));
    }
    else
        printf("modify data fail: data not in the list!!\n");
}


int main()
{
    //test_insert_node();
    test_find_node();
    //test_modify_node();
}