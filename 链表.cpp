#include <iostream>
using namespace std;

/*
链表：存储单元内存不连续，逻辑上是连续的
        由一组任意存储的结点组成
        每个结点包含数据域（存放数据）和指针域（存放指向下一节点的指针）

结构：
    头节点*next -> [结点1]
                   数据域
                   *next -> [结点2]
                            数据域
                            *next -> [结点3]
                                     数据域
                                     *next -> ... -> [结点n]
                                                     数据域
                                                     *next -> NULL
*/
#define MAX 100
typedef int eType;

typedef struct {
    eType data; //数据域
    Node* next;//指向下一节点的指针
} Node;

Node* initLink(){//链表初始化函数
    Node* head = new Node;    //创建头结点
    head->next = NULL;        //头结点指针域置空
    return head;
}

void apphead(Node* pl, eType e){//头插法加节点
    Node* pnew = new Node;    //创建新结点

    pnew->data = e;           //数据域赋值
    pnew->next = pl->next;    //新结点指针域指向原头结点的下一个结点
    
    pl->next = pnew;          //头结点指针域指向新结点（不能颠倒）
}
void list(Node* pl){//遍历链表
    for(Node* p = pl;p!=NULL;p=p->next){cout << p->data << " "; }
    cout << endl;
}

void apptail(Node*pl , eType e){//尾插法加节点
    Node*pnew = new Node;

    pnew->data = e;
    pnew->next = NULL;
    
    Node* p = pl;
    for(;p->next!=NULL;p=p->next);
    p->next = pnew;
}