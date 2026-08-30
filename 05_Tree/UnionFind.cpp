#include<iostream>
using namespace std;
#define MAXSIZE 100
int parent [MAXSIZE];
//并查集就是两个操作，查询两个元素是不是一个集合里面
//把元素并入集合
//用的就是数的双亲表示法

struct node 
{
    int data;

    node *child;
};

void init(int n)
{

    for(int i=0;i<n;i++)
    {
        //初始每一个节点自己都是一个集合，直接让根节点指向自己
        parent[i]=i;


    }

}


int find(int x)
{


    //找的是元素x所在的集合的根节点
    //首先判断x是不是根节点，是的话就直接返回了
    //不是根节点，就指向上一个节点，一层一层向上知道找到根节点
    while(parent[x]!=x)
    {

        x=parent[x];
    }

    return x;
}


void unionset(int x,int y)
{

    //找到x，y的根节点
    int rootx=find(x);
    int rooty=find(y);
    
    if(rootx!=rooty)
    {
        //把y所在的那一颗树直接并入x
        parent[rooty]=rootx;
    }



}

//对union的优化--让树的高度尽可能矮
//再集合并入的时候尽可能让树不要变高--小树并入大树

//这个时候就要让根节点的绝对值表示树的节点总数，把数值小的并入数值大的
//改成负数表示法初始化的时候要把所有的节点初始化为-1，然后判断根节点的逻辑变为x<0
//注意这里传入的必须是根节点不可以是普通节点
void optunion(int rootx,int rooty)
{
    //xy在同一集合直接范围
    if(rootx==rooty)
        return;

    //特别注意负数表示法x>y的话代表x的节点数更少
    //这个时候就要把x并到y
    if(parent[rootx]>parent[rooty])
    {
        //并入之后集合变大
        parent[rooty]=parent[rootx]+parent[rooty];
        
        parent[rootx]=rooty;

    }
    else
    {
        parent[rootx]=parent[rootx]+parent[rooty];

        parent[rooty]=rootx;


    }


}



















//路径压缩版本的find
//就算是优化之后的union，集合变多树的高度仍可能很高
//1-2-3-4-5-6-7  这样子要找7所在的集合就要先找6再一层一层向找
//时间复杂度达到O（n）
//路径压缩就是    这样子以后找这些节点只用向上一次就行了
                 //1
       // 2   3   4   5   6   7                        

//优化之后时间复杂度是o（α），比logn还小增长很缓慢
int ufind(int x)
{
    int root=x;
    //root先保存当前节点。在一路向上最后就是根节点
    while(parent[root]!=root)
    {
        root=parent[root];
    }
//这个循环之后root就是根节点了
    while(x!=root)//x不是根节点
    {
        //保存原来x的节点的根。为了一路上想把路径上所有的都挂到根下面
        int temp =parent[x];
        //把x直接并入根
        parent[x]=root;

        x=temp;
    }

    return root;
}





