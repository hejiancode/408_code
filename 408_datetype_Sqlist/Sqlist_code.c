#include<stdio.h>
#include<stdlib.h>

//�����Ĵ�С
#define MaxSize 20
//��typedef ��int���������ΪElemType����˼�Ǳ���Ԫ�ص�type
typedef int ElemType;

//˳���ṹ���壬�����˱�ĳ��Ⱥ�һ������
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//����˳����ʼ������
int Init_SeqList(SeqList* L)
{
    L->length = 0;     //���ó���Ϊ0���ձ�

    return 1;
}

//�������ĳ��Ԫ��λ�õĺ���
int Elem_Locate_SeqList(SeqList* L, int x)
{
    int i = 0;

    /*��ͷ��ʼ���ɨ��Ƚ�*/
    for (i = 0; i < L->length && L->elem[i] != x; i++) {
    }
    /* while(i<L->length&&L->elem[i]!=x)
         i++;*/

    /*ɨ������󣬸���������лظ�*/
    if (i >= L->length) {   //δ�ҵ�Ҫ���ҵ�Ԫ��
        printf("˳����в����ڸ�Ԫ�أ�\n");
        return 0;
    }
    else {   //�ҵ�Ҫ���ҵ�Ԫ�أ���������λ�ã���Ϊ�������飬���Է��ص�����Ӧ�ü�1��
        return i + 1;
    }
}

Locate_Elem_SeqList(SeqList* L, int x) {
    if (x < 1 && x > L->length) {
        printf("����λ������");
    }
    else {
        printf("��λ����Ԫ��Ϊ��%d", L->elem[x - 1]);
    }
}
//�������˳���ĺ������ڵ�i��Ԫ��֮ǰ����x
//ע�⣺���û���˵��1��������ĵ�0��
int Insert_SeqList(SeqList* L, int i, int x)
{
    int j;
    //printf("MaxSize\n");
    //printf("%d",MaxSize);
    //printf("%d",L.length);
    if (L->length >= MaxSize)
    {
        printf("˳����������޷����в��������");
        return 0;
    }
    else if (i <= 0 || i > L->length + 1)
    {
        printf("�����λ�ò���ȷ��");
        return 0;
    }
    /*�����һ��Ԫ�ؿ�ʼ��һ��һ����������һλ����Ҫ�����Ԫ�������ռ�*/
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    //�ڵ�i��Ԫ��֮ǰ������ǰѴ�i��ʼ��Ԫ�������ƣ�Ȼ��ֵ����i��Ԫ�أ��������о���i-1��
    L->elem[i - 1] = x;
    L->length++; //������֮�����鳤��+1
    return 1;
}

//����ɾ��˳���Ԫ�غ�����ɾ����i��Ԫ��
int Delete_Locate_Elem_SeqList(SeqList* L, int i){
    int j;
    if ((i < 1) || (i > L->length)){//�Ͳ�����һ�����ж�����
        printf("ɾ��λ�ò���ȷ��");
        return 0;
    }
    //ɾ����i��Ԫ�ؾ��Ǵӵ�i��Ԫ�ؿ�ʼһ��һ���شӺ���ǰ����
    for (j = i; j < L->length; j++){
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;   //���鳤��-1
    return 1;
}

//����ɾ��˳���Ԫ�غ�����ɾ��ָ����Ԫ��
int Delete_Elem_SeqList(SeqList* L, int i){
    int flag = 0;
    for (int j = 0; j < L->length; j++) {
        if (i == L->elem[j]) {
            for (int y = j; y < L->length; y++) {
                L->elem[y] = L->elem[y + 1];
            }
            L->length--;
            flag = 1;
        }
    }
    return flag;
}

//�޸�ָ����Ԫ��
int Alter_Elem(SeqList* L, ElemType x, ElemType e) {
    int flag = 0;
    int a;
    for (int j = 0; j < L->length; j++) {
        if (x = L->elem[j]) {
            e = L->elem[j];
            flag = 1;
        }
    }
    return flag;
}

//�޸�ָ��λ���ϵ�Ԫ��
int Alter_Locate_Elem(SeqList* L, int locate, ElemType e) {
    if ((locate < 1) || (locate > L->length)) {
        printf("�޸�λ�ò���ȷ��");
        return 0;
    }
    else {
        L->elem[locate-1] = e;
        printf("�޸ĳɹ���");
    }
}
//������ʾ���Ա�ĺ���
int Display_SeqList(SeqList* L)
{
    /*�ѵ�ǰ˳����ӡ����*/
    for (int i = 0; i < L->length; i++){
        printf("%d", L->elem[i]);
    }

    return 1;
}

int main()
{
    SeqList L;  //����һ��˳���ṹ�����
    ElemType e, x;
    int i = 1, k, j;

    /*��ʼ��˳���*/
    Init_SeqList(&L);
    
    /*Ϊ˳�������7��Ԫ��*/
    printf("please input seven data\n");
    for (int a = 1; a <= 7; a++) {
        scanf_s("%d", &e);
        Insert_SeqList(&L, a, e);
    }
    
    /*��ʼ����˳�����ز���*/
    while (i)   //��֤һֱ����
    {
        printf("��ǰ��˳���");  //չ��˳�����״
        Display_SeqList(&L);

        /*����չʾ�˵�*/
        printf("\n-----------------------------------------\n");
        printf("         Main Menu         \n");

        printf("    0   ��������      \n");

        printf("    1   ����������Ԫ�ص�ָ��λ��   \n");

        printf("    2   ��ɾ��ɾ��ָ��λ���ϵ�Ԫ��   \n");
        printf("    3   ��ɾ��ɾ��ָ��Ԫ��   \n");

        printf("    4   ���ģ��޸�ָ��Ԫ��   \n");
        printf("    5   ���ģ��޸�ָ��λ�õ�Ԫ��   \n");

        printf("    6   ���飩����ָ��λ���ϵ�Ԫ��    \n");
        printf("    7   ���飩����ָ��Ԫ�ص�λ��    \n");

        printf("    8   ����   \n");

        printf("------------------------------------\n");

        printf("��������Ҫʵ�ֵĹ��ܵĲ˵���<0, 1, 2, 3, 4, 5, 6, 7, 8>:\n");
        scanf_s("%d", &i);
        switch (i)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("���������Ԫ��λ�ã�");
            scanf_s("%d", &k);
            printf("���������Ԫ��ֵ��");
            scanf_s("%d", &x);
            j = Insert_SeqList(&L, k, x);
            if (j != 0)
            {
                printf("����Ԫ�غ�˳���");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;

        case 2:
            printf("������ɾ��Ԫ��λ�ã�");
            scanf_s("%d", &k);
            j = Delete_Locate_Elem_SeqList(&L, k);
            if (j != 0)
            {
                printf("ɾ��Ԫ�غ�˳���");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;

        case 3:
            printf("������ɾ����Ԫ�أ�");
            scanf_s("%d", &k);
            if (Delete_Elem_SeqList(&L, k)) {
                printf("ɾ��Ԫ�سɹ���");
            }
            else {
                printf("�ڵ�ǰ����δ�ҵ�Ҫɾ����Ԫ��");
            }
            break;
        
        case 4:
            printf("���������ʲôԪ�أ�");
            scanf_s("%d", &x);
            printf("���������ΪʲôԪ�أ�");
            scanf_s("%d", &e);

            if (Alter_Locate_Elem(&L, x, e)) {
                printf("����Ԫ�سɹ���");
            }
            else {
                printf("�ڵ�ǰ����δ�ҵ�Ҫ���ĵ�Ԫ��");
            }
            break;

        case 5:
            printf("�������޸ĵ�Ԫ��λ�ã�");
            scanf_s("%d", &k);
            printf("���������ΪʲôԪ�أ�");
            scanf_s("%d", &e);
            Alter_Locate_Elem(&L, k, e);
            break;

        case 6:
            printf("��������ҵ�λ�ã�");
            scanf_s("%d", &x);
            printf("\n");
            Locate_Elem_SeqList(&L, x);
            printf("\n\n");
            break;

        case 7:
            printf("���������Ԫ�أ�");
            scanf_s("%d", &x);
            printf("\n");
            j = Elem_Locate_SeqList(&L, x);
            if (j != 0)//�ҵ�Ԫ�ط��ص���i+1,���Կ���ǰ�溯��
            {
                printf("ָ��Ԫ��λ���� %d\n", j);
            }
            printf("\n\n");
            break;

        case 8:
            system("cls");
            break;
        
        default:
            printf("��������~");
        }
    }
    return 0;
}