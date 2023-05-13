#include<stdio.h>
#include<stdlib.h>

//定义表的大小
#define MaxSize 20
//用typedef 给int定义个名字为ElemType，意思是表中元素的type
typedef int ElemType;

//顺序表结构定义，包括了表的长度和一个数组
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//定义顺序表初始化函数
int Init_SeqList(SeqList* L)
{
    L->length = 0;     //设置长度为0，空表

    return 1;
}

//定义查找某个元素位置的函数
int Elem_Locate_SeqList(SeqList* L, int x)
{
    int i = 0;

    /*从头开始逐个扫描比较*/
    for (i = 0; i < L->length && L->elem[i] != x; i++) {
    }
    /* while(i<L->length&&L->elem[i]!=x)
         i++;*/

    /*扫描结束后，根据情况进行回复*/
    if (i >= L->length) {   //未找到要查找的元素
        printf("顺序表中不存在该元素！\n");
        return 0;
    }
    else {   //找到要查找的元素，返回它的位置（因为这是数组，所以返回的序数应该加1）
        return i + 1;
    }
}

Locate_Elem_SeqList(SeqList* L, int x) {
    if (x < 1 && x > L->length) {
        printf("输入位置有误");
    }
    else {
        printf("该位置上元素为：%d", L->elem[x - 1]);
    }
}
//定义插入顺序表的函数：在第i个元素之前插入x
//注意：对用户来说第1个是数组的第0个
int Insert_SeqList(SeqList* L, int i, int x)
{
    int j;
    //printf("MaxSize\n");
    //printf("%d",MaxSize);
    //printf("%d",L.length);
    if (L->length >= MaxSize)
    {
        printf("顺序表已满，无法进行插入操作！");
        return 0;
    }
    else if (i <= 0 || i > L->length + 1)
    {
        printf("插入的位置不正确！");
        return 0;
    }
    /*从最后一个元素开始，一个一个地往后移一位，给要插入的元素留出空间*/
    for (j = L->length - 1; j >= i - 1; j--)
    {
        L->elem[j + 1] = L->elem[j];
    }
    //在第i个元素之前插入就是把从i开始的元素往后移，然后赋值给第i个元素，在数组中就是i-1了
    L->elem[i - 1] = x;
    L->length++; //插入完之后数组长度+1
    return 1;
}

//定义删除顺序表元素函数，删除第i个元素
int Delete_Locate_Elem_SeqList(SeqList* L, int i){
    int j;
    if ((i < 1) || (i > L->length)){//和插入是一样的判断条件
        printf("删除位置不正确！");
        return 0;
    }
    //删除第i个元素就是从第i个元素开始一个一个地从后向前覆盖
    for (j = i; j < L->length; j++){
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;   //数组长度-1
    return 1;
}

//定义删除顺序表元素函数，删除指定的元素
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

//修改指定的元素
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

//修改指定位置上的元素
int Alter_Locate_Elem(SeqList* L, int locate, ElemType e) {
    if ((locate < 1) || (locate > L->length)) {
        printf("修改位置不正确！");
        return 0;
    }
    else {
        L->elem[locate-1] = e;
        printf("修改成功！");
    }
}
//定义显示线性表的函数
int Display_SeqList(SeqList* L)
{
    /*把当前顺序表打印出来*/
    for (int i = 0; i < L->length; i++){
        printf("%d", L->elem[i]);
    }

    return 1;
}

int main()
{
    SeqList L;  //定义一个顺序表结构体变量
    ElemType e, x;
    int i = 1, k, j;

    /*初始化顺序表*/
    Init_SeqList(&L);
    
    /*为顺表表输入7个元素*/
    printf("please input seven data\n");
    for (int a = 1; a <= 7; a++) {
        scanf_s("%d", &e);
        Insert_SeqList(&L, a, e);
    }
    
    /*开始进行顺序表相关操作*/
    while (i)   //保证一直进行
    {
        printf("当前的顺序表：");  //展现顺序表现状
        Display_SeqList(&L);

        /*功能展示菜单*/
        printf("\n-----------------------------------------\n");
        printf("         Main Menu         \n");

        printf("    0   结束程序      \n");

        printf("    1   （增）插入元素到指定位置   \n");

        printf("    2   （删）删除指定位置上的元素   \n");
        printf("    3   （删）删除指定元素   \n");

        printf("    4   （改）修改指定元素   \n");
        printf("    5   （改）修改指定位置的元素   \n");

        printf("    6   （查）查找指定位置上的元素    \n");
        printf("    7   （查）查找指定元素的位置    \n");

        printf("    8   清屏   \n");

        printf("------------------------------------\n");

        printf("请输入你要实现的功能的菜单号<0, 1, 2, 3, 4, 5, 6, 7, 8>:\n");
        scanf_s("%d", &i);
        switch (i)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printf("请输入插入元素位置：");
            scanf_s("%d", &k);
            printf("请输入插入元素值：");
            scanf_s("%d", &x);
            j = Insert_SeqList(&L, k, x);
            if (j != 0)
            {
                printf("插入元素后顺序表：");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;

        case 2:
            printf("请输入删除元素位置：");
            scanf_s("%d", &k);
            j = Delete_Locate_Elem_SeqList(&L, k);
            if (j != 0)
            {
                printf("删除元素后顺序表：");
                Display_SeqList(&L);
                printf("\n");
            }
            printf("\n\n");
            break;

        case 3:
            printf("请输入删除的元素：");
            scanf_s("%d", &k);
            if (Delete_Elem_SeqList(&L, k)) {
                printf("删除元素成功。");
            }
            else {
                printf("在当前表中未找到要删除的元素");
            }
            break;
        
        case 4:
            printf("请输入更改什么元素：");
            scanf_s("%d", &x);
            printf("请输入更改为什么元素：");
            scanf_s("%d", &e);

            if (Alter_Locate_Elem(&L, x, e)) {
                printf("更改元素成功。");
            }
            else {
                printf("在当前表中未找到要更改的元素");
            }
            break;

        case 5:
            printf("请输入修改的元素位置：");
            scanf_s("%d", &k);
            printf("请输入更改为什么元素：");
            scanf_s("%d", &e);
            Alter_Locate_Elem(&L, k, e);
            break;

        case 6:
            printf("请输入查找的位置：");
            scanf_s("%d", &x);
            printf("\n");
            Locate_Elem_SeqList(&L, x);
            printf("\n\n");
            break;

        case 7:
            printf("请输入查找元素：");
            scanf_s("%d", &x);
            printf("\n");
            j = Elem_Locate_SeqList(&L, x);
            if (j != 0)//找到元素返回的是i+1,可以看看前面函数
            {
                printf("指定元素位置是 %d\n", j);
            }
            printf("\n\n");
            break;

        case 8:
            system("cls");
            break;
        
        default:
            printf("操作有误~");
        }
    }
    return 0;
}