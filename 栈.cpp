#include <iostream>
using namespace std;

/*
栈：后进先出。类似摞盘子
一种特殊的线性表，只能对最后一个元素（栈顶）进行插入删除操作

c++中应有专门的库函数<stack>：
stack<元素类型> 栈名;       //创建栈
栈名.push(元素);            //入栈
栈名.pop();                 //出栈
栈名.top()                  //栈顶元素
*/

#define MAX 100
#define eType int

typedef struct {
    eType data[MAX];
    int top = -1;        //栈顶。默认-1
} Stack;

void initSta(Stack* psta){  //栈初始化
    psta ->top = -1;        //按习惯第一个元素"下标"为0
}

bool isFull(Stack* psta){       //判断是否满栈
    if(psta->top == MAX-1){return true;}
    return false;
}

bool isNone(Stack* psta){       //判断是否空栈
    if(psta->top == -1){return true; }
    return false;
}

void push(Stack* psta, eType n){    //栈顶压入新元素
    if(!isFull(psta)){psta -> data[psta -> ++top] = n; }
}

void pop(Stack* psta){  //出栈
    if(!isNone(psta)){psta->top --; }
}

eType getTop(Stack* psta){      //获取栈顶元素
    if(!isNone(psta)){return psta -> data[psta -> top]; }
    return eType(-1);
}

int main(){
    struct Stack sta;
    push(&sta,3);
    push(&sta,6);
    cout << getTop(&sta) << endl;
    pop(&sta);
    cout << getTop(&sta) << endl;
    
    return 0;
}