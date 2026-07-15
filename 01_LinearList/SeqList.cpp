#include<iostream>
using namespace std;

#define Maxsize 100
typedef int Elemtype ;
typedef struct
{
    int length;
    Elemtype data[Maxsize];
}Sqlist;

void initlist(Sqlist &L)
{
    L.length=0;
}
//按照位置插入
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
//按位查找
bool getelem(Sqlist &L,int i,Elemtype &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    return true;

}
//按值查找,返回的是位置注意与数组下标对应
int locateElem(Sqlist &L,Elemtype e)
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





