#include <iostream>
using namespace std;

/*
线性表：由n个数据特性相同的元素组成的有限序列
        分为 顺序表、链表
*/

/*
顺序表：用连续的内存单元依次存储各个元素
        逻辑上和物理上都是连续的（数组）
*/
#define MAX 100
typedef int eType;

typedef struct {
    eType data[MAX];
    int length;
} Seq;
void initSeq(Seq* pseq){     //顺序表初始化函数
    pseq -> length = 0;
}
void appSeq(Seq* pseq, eType e){    //顺序表加元素函数
    if(pseq -> length >= MAX){ return; }    //满了就不加了
    pseq -> data[pseq -> length ++] = e;
}
void listSeq(Seq* pseq){    //顺序表遍历函数
    for(int i = 0; i < pseq->length; i++){
        cout << pseq->data[i] << ' ';
    }
    cout << endl;
}
void popSeq(Seq* pseq, eType e, int n){    //顺序表插入函数
    if(n < 0 || n >= pseq->length){ return; }
    for(int i = pseq->length ; i > n; i--){pseq->data[i] = pseq->data[i - 1]; }
    pseq->data[n] = e;
    pseq->length ++;
}
void delSeq_n(Seq* pseq, int n){    //顺序表删除函数(删除指定位置)
    if(n < 0 || n >= pseq->length){ return; }
    for(int i = n; i < pseq->length - 1; i++){pseq->data[i] = pseq->data[i + 1]; }
    pseq->length --;
}
void delSeq_e(Seq* pseq, eType e){    //顺序表删除函数(删除第一个指定元素)
    int n = -1;
    for(int i=0;i<pseq->length;i++){
        if(pseq->data[i] == e){
            n = i;
            break;
        }
    }
    if(n==-1){ return; }
    for(int i=n;i<pseq->length-1;i++){pseq->data[i] = pseq->data[i + 1]; }
    pseq->length --;
}
int findSeq(Seq* pseq, eType e){    //顺序表查找函数(返回第一个下标)
    for(int i=0;i<pseq->length;i++){
        if(pseq->data[i] == e){return i; }
    }
    return -1;
}

int main(){
    Seq list1;
    initSeq(&list1);
    appSeq(&list1, 1);
    appSeq(&list1, 2);
    appSeq(&list1, 3);
    popSeq(&list1, 4, 1);
    listSeq(&list1);
    return 0;
}