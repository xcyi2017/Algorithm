/*
 * 数据结构
 *      1, 线性结构
 *              （1）顺序表
 *                      借助数据元素在存储器中的相对位置来表示数据元素的逻辑关系
 *              （2）链表 单链表 双向链表 单向循环链表 双向循环链表
 *              （3）如何在工程中和内核中使用链表
 *      2. 树形结构
 *      3. 网状结构
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_LIST_LENGTH 8
#define INIT_LIST_LENGTH_INC 3

typedef struct
{
    int userId;
    char userName[10];
    char userMail[20];
    int userGrade;
} ElemType_T;

typedef struct
{
    ElemType_T *base;
    int list_total_length;
    int list_current_length;
} SeqList_T;

// 增加表长度
int __seqListInc(SeqList_T *seqList)
{
    ElemType_T *newBase = (ElemType_T *) realloc(seqList->base, sizeof(ElemType_T) * (seqList->list_current_length +
                          INIT_LIST_LENGTH_INC));
    if (newBase == NULL)
    {
        printf("realloc memory error ...... \n");
        return 0;
    }

    seqList->base = newBase;
    seqList->list_total_length += INIT_LIST_LENGTH_INC;
    return 1;
}

// 初始化顺序表
void InitSeqList(SeqList_T *seqList)
{
    // 开辟内存空间
    seqList->base = (ElemType_T *)malloc(sizeof(ElemType_T) * INIT_LIST_LENGTH);
    if (seqList->base == NULL)
    {
        printf("malloc memory error ....... \n");
        return;
    }

    seqList->list_total_length = INIT_LIST_LENGTH; // 8
    seqList->list_current_length = 0;
}

// 尾部插入数据
void insert_back(SeqList_T *seqList, ElemType_T *elem_tmp)
{
    printf("user infor: userName = %s userMail = %s userGrade = %d \n",
           elem_tmp->userName, elem_tmp->userMail, elem_tmp->userGrade);
    // 判断顺序表是否满
    if (seqList->list_total_length == seqList->list_current_length)
    {
        if (__seqListInc(seqList) == 0)
        {
            printf("SeqList is Full ....... \n");
            return;
        }
    }

    memcpy((seqList->base + seqList->list_current_length)->userName, elem_tmp->userName, 10);
    memcpy((seqList->base + seqList->list_current_length)->userMail, elem_tmp->userMail, 20);
    (seqList->base + seqList->list_current_length)->userGrade = elem_tmp->userGrade;
    (seqList->base + seqList->list_current_length)->userId = seqList->list_current_length;

    seqList->list_current_length++;
}

void insert_front(SeqList_T *seqList, ElemType_T *elem_tmp)
{
    int i = 0;
    printf("user infor: userName = %s userMail = %s userGrade = %d \n",
           elem_tmp->userName, elem_tmp->userMail, elem_tmp->userGrade);
    // 判断顺序表是否满
    if (seqList->list_total_length == seqList->list_current_length)
    {
        if (__seqListInc(seqList) == 0)
        {
            printf("SeqList is Full ....... \n");
            return;
        }
    }

    // 移动数据
    for (i = seqList->list_current_length; i > 0; i--)
    {
        memcpy(seqList->base + i, seqList->base + i - 1, sizeof(ElemType_T));
        (seqList->base + i)->userId++;
    }

    memcpy(seqList->base->userName, elem_tmp->userName, 10); // 数组不能给数组赋值，指针不能给数组赋值
    memcpy(seqList->base->userMail, elem_tmp->userMail, 20);
    seqList->base->userGrade = elem_tmp->userGrade;
    seqList->base->userId = 0;

    seqList->list_current_length++;
}

void delete_back(SeqList_T *seqList)
{
    if (seqList->list_current_length == 0)
    {
        return;
    }

    seqList->list_current_length--;
}

void delete_front(SeqList_T *seqList)
{
    int i = 0;
    if (seqList->list_current_length == 0)
    {
        return;
    }
    for (i = 0; i < seqList->list_current_length - 1; i++)
    {
        memcpy(seqList->base + i, seqList->base + i + 1, sizeof(ElemType_T));
        (seqList->base + i)->userId--;
    }
    seqList->list_current_length--;
}



void insert_pos(SeqList_T *seqList, ElemType_T *elem_tmp, int position)
{
    int i = 0;
    // 判断顺序表是否满
    if (seqList->list_total_length == seqList->list_current_length)
    {
        if (__seqListInc(seqList) == 0)
        {
            printf("SeqList is Full ....... \n");
            return;
        }
    }
    // 判断插入位置的合法性
    if (seqList->list_current_length < position || position < 0)
    {
        printf("insert pos error .......... \n");
        return;
    }
    // 移动数据
    for (i = seqList->list_current_length; i > position; i--)
    {
        memcpy(seqList->base + i, seqList->base + i - 1, sizeof(ElemType_T));
        (seqList->base + i)->userId++;
    }

    memcpy((seqList->base + position)->userName, elem_tmp->userName, 10);
    memcpy((seqList->base + position)->userMail, elem_tmp->userMail, 20);
    (seqList->base + position)->userGrade = elem_tmp->userGrade;
    (seqList->base + position)->userId = position;

    seqList->list_current_length++;
}

void delete_pos(SeqList_T *seqList, int position)
{
    int i = 0;
    if (seqList->list_current_length == 0)
    {
        return;
    }
    // 判断删除数据位置的合法性
    if (position < 0 || position >= seqList->list_current_length)
    {
        printf("input delete position error .......\n");
        return;
    }

    for (i = position; i < seqList->list_current_length - 1; i++)
    {
        memcpy(seqList->base + i, seqList->base + i + 1, sizeof(ElemType_T));
        (seqList->base + i)->userId--;
    }
    seqList->list_current_length--;
}

void modify_pos(SeqList_T *seqList, ElemType_T *elem_tmp, int position)
{
    if (seqList->list_current_length == 0)
    {
        return;
    }
    // 判断修改数据位置的合法性
    if (position < 0 || position >= seqList->list_current_length)
    {
        printf("input modify position error .......\n");
        return;
    }

    memcpy((seqList->base + position)->userName, elem_tmp->userName, 10);
    memcpy((seqList->base + position)->userMail, elem_tmp->userMail, 20);
    (seqList->base + position)->userGrade = elem_tmp->userGrade;
    (seqList->base + position)->userId = position;
}

void find(SeqList_T *seqList, int position)
{
    if (seqList->list_current_length == 0)
    {
        return;
    }
    // 判断查找的下标值是否合法
    if (position < 0 || position >= seqList->list_current_length)
    {
        printf("input find position error .........\n");
        return;
    }
    printf("find user infor: userName = %s userMail = %s userGrade = %d \n",
           (seqList->base + position)->userName,
           (seqList->base + position)->userMail,
           (seqList->base + position)->userGrade);
}

void length(SeqList_T *seqList)
{
    printf("seqList total length = %d current length = %d \n",
           seqList->list_total_length,
           seqList->list_current_length);
}


void clear(SeqList_T *seqList)
{
    seqList->list_current_length = 0;
}

void destroy(SeqList_T *seqList)
{
    free(seqList->base);
    seqList->list_current_length = 0;
}

void sort(SeqList_T *seqList)
{
    // 使用冒泡排序法
    int i = 0;
    int j = 0;
    ElemType_T elem_tmp;
    // 循环总次数 循环次数 = 元素个数 - 1
    for (i = 0; i < seqList->list_current_length - 1; i ++)
    {
        for (j = i; j < seqList->list_current_length - i - 1; j ++)
        {
            if ((seqList->base + j)->userGrade > (seqList->base + j + 1) -> userGrade) 
            {
                memcpy(&elem_tmp, seqList->base + j, sizeof(ElemType_T));
                memcpy(seqList->base + j, seqList->base + j + 1, sizeof(ElemType_T));
                memcpy(seqList->base + j + 1, &elem_tmp, sizeof(ElemType_T));
            }
            
        }        
    }
}


void reverse(SeqList_T *seqList)
{
    int i = 0;
    int offset1 = 0;
    int offset2 = seqList->list_current_length - 1;

    ElemType_T elem_tmp;

    while (offset1 < offset2)
    {
        memcpy(&elem_tmp, seqList->base + offset2, sizeof(ElemType_T));
        memcpy(seqList->base + offset2, seqList->base + offset1, sizeof(ElemType_T));
        memcpy(seqList->base + offset1, &elem_tmp, sizeof(ElemType_T));

        offset1 ++;
        offset2 --;
    }

    for (i = 0; i < seqList->list_current_length; i ++)
    {
        (seqList->base + i) -> userId = i;
    }
}

void test(SeqList_T *seqList)
{
    ElemType_T elem_tmp;
    memcpy(elem_tmp.userName, "yhf", strlen("yhf\n"));
    memcpy(elem_tmp.userMail, "yhf@qq.com", strlen("yhf@qq.com\n"));
    elem_tmp.userGrade = 100;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "wwj", strlen("wwj\n"));
    memcpy(elem_tmp.userMail, "wwj@qq.com", strlen("wwj@qq.com\n"));
    elem_tmp.userGrade = 200;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "zhangsan", strlen("zhangsan\n"));
    memcpy(elem_tmp.userMail, "zhangsan@qq.com", strlen("zhangsan@qq.com\n"));
    elem_tmp.userGrade = 300;
    insert_back(seqList, &elem_tmp);
}


void __test1(SeqList_T *seqList)
{
    ElemType_T elem_tmp;
    memcpy(elem_tmp.userName, "yhf", strlen("yhf\n"));
    memcpy(elem_tmp.userMail, "yhf@qq.com", strlen("yhf@qq.com\n"));
    elem_tmp.userGrade = 1;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "wwj", strlen("wwj\n"));
    memcpy(elem_tmp.userMail, "wwj@qq.com", strlen("wwj@qq.com\n"));
    elem_tmp.userGrade = 3;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "zhangsan", strlen("zhangsan\n"));
    memcpy(elem_tmp.userMail, "zhangsan@qq.com", strlen("zhangsan@qq.com\n"));
    elem_tmp.userGrade = 5;
    insert_back(seqList, &elem_tmp);

}


void __test2(SeqList_T *seqList)
{
    ElemType_T elem_tmp;
    memcpy(elem_tmp.userName, "yhf", strlen("yhf\n"));
    memcpy(elem_tmp.userMail, "yhf@qq.com", strlen("yhf@qq.com\n"));
    elem_tmp.userGrade = 2;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "wwj", strlen("wwj\n"));
    memcpy(elem_tmp.userMail, "wwj@qq.com", strlen("wwj@qq.com\n"));
    elem_tmp.userGrade = 4;

    insert_back(seqList, &elem_tmp);

    memcpy(elem_tmp.userName, "zhangsan", strlen("zhangsan\n"));
    memcpy(elem_tmp.userMail, "zhangsan@qq.com", strlen("zhangsan@qq.com\n"));
    elem_tmp.userGrade = 6;
    insert_back(seqList, &elem_tmp);

}


void show_list(SeqList_T *seqList)
{
    int i = 0;
    ElemType_T *elem_tmp = NULL;
    printf("---------------------------------------------\n");
    printf("| User information table                    |\n");
    printf("---------------------------------------------\n");
    printf("|  userId | userName | userMail | userGrade |\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < seqList->list_current_length; i++)
    {
        elem_tmp = seqList->base + i;
        printf("|%8d|%12s|%12s|%8d|\n", elem_tmp->userId, elem_tmp->userName, elem_tmp->userMail,
               elem_tmp->userGrade);
    }
    printf("---------------------------------------------\n");
}

int main()
{
    int i = 0;
    SeqList_T seqList1, seqList2, mergeSeqList;

    InitSeqList(&seqList1);
    InitSeqList(&seqList2);
    InitSeqList(&mergeSeqList);

    __test1(&seqList1);
    __test2(&seqList2);

    show_list(&seqList1);
    show_list(&seqList2);
    
    for (i = 0; i < seqList1.list_current_length; i++)
    {
        insert_back(&mergeSeqList, seqList1.base + i);
    }

    for (i = 0; i < seqList2.list_current_length; i++)
    {
        insert_back(&mergeSeqList, seqList2.base + i);
    }
    sort(&mergeSeqList);
    show_list(&mergeSeqList);

    return 0;
}

/*
int main(int argc, char* argv[])
{

    SeqList_T seqList; // 实例化 顺序表
    InitSeqList(&seqList);
    int operation = 1;
    int position = 0;
    ElemType_T elem_tmp; // 临时存储用户信息
    while (operation)
    {
        printf("- --------------------------------------\n");
        printf("|  SeqList Operation :                 |\n");
        printf("----------------------------------------\n");
        printf("| (1)  insert_back  (2)  insert_front  |\n");
        printf("| (3)  delete_back  (4)  delete_front  |\n");
        printf("| (5)  insert_pos   (6)  delete_pos    |\n");
        printf("| (7)  modify_pos   (8)  show_list     |\n");
        printf("| (9)  find         (10) length        |\n");
        printf("| (11) clear        (12) destroy       |\n");
        printf("| (13) sort         (14) reverse       |\n");
        printf("| (0)               (15) test          |\n");
        printf("----------------------------------------\n");
        printf("Please input your operation : >");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            printf("Please input user infor:1)userName 2)userMail 3)userGrade (back insert).\n");
            scanf("%s %s %d", elem_tmp.userName, elem_tmp.userMail, &elem_tmp.userGrade);
            insert_back(&seqList, &elem_tmp);
            break;
        case 2:
            printf("Please input user infor:1)userName 2)userMail 3)userGrade (front insert).\n");
            scanf("%s %s %d", elem_tmp.userName, elem_tmp.userMail, &elem_tmp.userGrade);
            insert_front(&seqList, &elem_tmp);
            break;
        case 3:
            delete_back(&seqList);
            break;
        case 4:
            delete_front(&seqList);
            break;
        case 5:
            printf("please input insert position : >\n");
            scanf("%d", &position);
            printf("Please input user infor:1)userName 2)userMail 3)userGrade (pos insert).\n");
            scanf("%s %s %d", elem_tmp.userName, elem_tmp.userMail, &elem_tmp.userGrade);
            insert_pos(&seqList, &elem_tmp, position);
            break;
        case 6:
            printf("please input delete position : >\n");
            scanf("%d", &position);
            delete_pos(&seqList, position);
            break;
        case 7:
            printf("please input modif position : >\n");
            scanf("%d", &position);
            printf("Please input user infor:1)userName 2)userMail 3)userGrade (pos modify).\n");
            scanf("%s %s %d", elem_tmp.userName, elem_tmp.userMail, &elem_tmp.userGrade);
            modify_pos(&seqList, &elem_tmp, position);
            break;
        case 8:
            show_list(&seqList);
            break;
        case 9:
            printf("please input insert position : >\n");
            scanf("%d", &position);
            find(&seqList, position);
            break;
        case 10:
            length(&seqList);
            break;
        case 11:
            clear(&seqList);
            break;
        // case 12:
        //     destroy(&seqList);
        //     break;
        case 13:
            sort(&seqList);
            break;
        case 14:
            reverse(&seqList);
            break;
        case 15:
            test(&seqList);
            break;
        default:
            printf("Please input 0-14\n");
        }
    }
    destroy(&seqList);
    return 0;
    
}
*/

