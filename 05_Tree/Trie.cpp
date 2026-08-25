#include<iostream>
using namespace std;
typedef int Elemtype;

#define MAXSIZE 100

typedef struct
{
    //顺序存储本质上就是按照满二叉树
    //按照顺序编号存在数组里面
    Elemtype data[MAXSIZE];

    int length;


}sqtree;



void init(sqtree &t)
{
    t.length=0;



}


bool insert(sqtree &t,Elemtype e)
{
    if (t.length>=MAXSIZE)
        return false;



    //数组的下标位当前长度减去一
    t.data[t.length]=e;
    t.length++;
    return true;
}


Elemtype getelem(sqtree t,int i)
{
    if(i<1||i>t.length)
        return false;


    return t.data[i];

}


//寻找父节点
                //                  1
                //         2                3
                //     4     5          6       7
                // 8    9  10 11     12   13  14  15
//父节点就是自己的序号除2
int getparent(int i)
{
    if(i<=1)
        return 0;



    return i/2;
}


int getlchild(sqtree t,int i)
{
    int child=2*i;
    if(child>t.length)
        return 0;


    return child;


}



int getrchild(sqtree t,int i)
{
    int child=2*i+1;
    if(child>t.length) 
        return 0;

    return child;
}


//线序遍历

void porder(sqtree t,int i)
{
    if(i>t.length)
        return;
    
    //先遍历根节点
    cout<<t.data[i]<<" ";
    
    //递归左右孩子
    porder(t,2*i);

    porder(t,2*i+1);


}

void inorder(sqtree t,int i)
{
    if(i>t.length)
        return;
    
    inorder(t,2*i);

    cout<<t.data[i]<<" ";

    inorder(t,2*i+1);
}


void PostOrder(sqtree t, int i)
{
    if(i > t.length)
        return;

    PostOrder(t, 2 * i);

    PostOrder(t, 2 * i + 1);

    cout << t.data[i] << " ";
}


//因为是顺序存储所以层次遍历就是顺序输出数组
void LevelOrder(sqtree t)
{
    for(int i = 1; i <= t.length; i++)
    {
        cout << t.data[i] << " ";
    }

    cout << endl;
}