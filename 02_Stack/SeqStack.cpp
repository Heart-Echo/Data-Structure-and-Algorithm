#include<iostream>
using namespace std;
typedef int Elemtype;
#define MAXSIZE 100


//顺序栈的定义
typedef struct
{
    Elemtype data[MAXSIZE];
    int top;


}sqstack;

//初始化
void initstack(sqstack &s)
{


    //初始化栈顶-1
    s.top=-1;

}

bool empty(sqstack s)
{
    if(s.top==-1)
        return true;
    
    else
        return false;

}

bool push(sqstack &s,Elemtype e)
{
    if(s.top==MAXSIZE-1)
        return false;//栈满了
    
    s.top++;
    s.data[s.top]=e;
    return true;
}

bool pop(sqstack &s,Elemtype &e)
{
    if(s.top==-1)
        return false;

    e=s.data[s.top];
    s.top--;
    return true;

}


bool full(sqstack s)
{

    if(s.top==MAXSIZE-1)
        return true;
    return false;
}

bool gettop(sqstack s,Elemtype &e)
{

    if(s.top==-1)
        return false;
    e=s.data[s.top];
    return true;
}
//注意函数类型
int getlength(sqstack s)
{
    return s.top+1;
}
void PrintStack(sqstack S)
{
    for(int i=S.top; i>=0; i--)
    {
        cout << S.data[i] << " ";
    }

    cout << endl;
}

int main()
{
    sqstack s;

    // Initialize
    initstack(s);

    cout << "Initial length: "
         << getlength(s) << endl;


    // Check empty
    if(empty(s))
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;


    // Push
    push(s,985);
    push(s,211);
    push(s,666);

    cout << "After push, length: "
         << getlength(s) << endl;


    // Get top
    Elemtype e;

    if(gettop(s,e))
    {
        cout << "Top element: "
             << e << endl;
    }
    else
    {
        cout << "Stack is empty." << endl;
    }


    // Pop
    if(pop(s,e))
    {
        cout << "Popped element: "
             << e << endl;
    }
    else
    {
        cout << "Stack is empty, cannot pop." << endl;
    }


    // Get top again
    if(gettop(s,e))
    {
        cout << "New top element: "
             << e << endl;
    }


    // Length
    cout << "Current length: "
         << getlength(s) << endl;


    // Check empty again
    if(empty(s))
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;


    // Check full
    if(full(s))
        cout << "Stack is full." << endl;
    else
        cout << "Stack is not full." << endl;


    return 0;
}
