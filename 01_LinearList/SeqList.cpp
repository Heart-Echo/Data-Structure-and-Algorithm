#include<iostream>
using namespace std;

#define Maxsize 100
//typedef 用来给一个已有的类型起一个新的名字
//现在是int，以后如果是别的例如char,float不需要改代码
typedef int Elemtype ;

//给结构体取名字叫Sqlist
typedef struct
{
    int length;
    Elemtype data[Maxsize];
}Sqlist;
//初始化，顺序表变了，要&
void initlist(Sqlist &L)
{
    L.length=0;
}
//按照位置插入

//对于&，不加&叫做值传递，不会修改内存里面的数据，最终传出来的是一个复制品

//加了&叫做引用传递，最终会修改内存的值



//插入，顺序表变了，所以要&
bool insert(Sqlist &L,int i,Elemtype e)
{
    if(i>L.length+1||i<1)
        return false; 
    if(L.length>=Maxsize)
        return false;
   for(int j=L.length;j>=i;j--)
   {
    L.data[j]=L.data[j-1];
   }
   L.data[i-1]=e;
   L.length++;
   return true;
   //插入一个之后变长别忘了
}



//要&
bool sqdelete(Sqlist &L,int i,Elemtype &e)
{
    if(i<1||i>L.length)
        return false;
    
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
    {
        L.data[j-1]=L.data[j];

    }
    L.length--;
    return true;
}
//按位查找，仅仅只是遍历了，顺序表本身没变，不用&
bool getelem(Sqlist L,int i,Elemtype &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    return true;

}
//按值查找,返回的是位置注意与数组下标对应
//只是遍历表没变，不用&
int locateElem(Sqlist L,Elemtype e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i]==e)            //注意这里是逻辑运算==不是=赋值
            return i+1;
    }
    return 0;
}

void printlist(Sqlist &L)
{
    for(int i=0;i<L.length;i++)
    {

        cout<<L.data[i]<<" ";
    }
    cout <<endl;
}

int main()
{
    Sqlist L;
    initlist (L);
    insert(L,1,985);
    insert(L,2,211);
    insert(L,3,666);
    printlist(L);
    Elemtype x;//这里的x是作为一个临时变量用来接收删除的元素
    sqdelete(L,2,x);

    cout << "Delete" << x << endl;
    printlist(L);
    insert(L,3,666);
    printlist(L);
    getelem(L,1,x);
    cout<<x<<endl;
}





