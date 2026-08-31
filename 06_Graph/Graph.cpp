#include<iostream>
using namespace std;
typedef int Elemtype;

#define MAXSIZE 100

typedef struct
{
    //顶点
    int vertex[MAXSIZE];
    //二位数组存放边
    int edge[MAXSIZE][MAXSIZE];

    int vertextnum;

    int edgenum;
}graph;


void initgraph(graph &G,int n)
{
    G.vertextnum=n;

    G.edgenum=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G.edge[i][j]=0;
        }



    }

}
//添加无向边
void addegde(graph &G,int u,int v)
{   
    G.edge[u][v]=1;
    G.edge[v][u]=1;
    G.edgenum++;

}


//添加有向边
void adde(graph &G,int u,int v)
{
    G.edge[u][v]=1;
    G.edgenum++;
}

//邻接表存储

//三个结构体，一个结构体存边，一个结构体是数组里面存放的数据节点，还有一个结构体是数组，也就是图本身
//边节点
typedef struct Arcnode
{
    Elemtype weight;
    //这条边指向的顶点
    int adjvex;
    struct Arcnode *next;


}Arcnode;

//顶点节点
typedef struct vnode
{

    int vertex;

    Arcnode *firstedge;

}vnode;

//图
typedef struct 
{
    vnode vertex[MAXSIZE];

    int vertexnum;
    int edgenum;
}Agraph;

void init(Agraph &g,int n)
{
    g.edgenum=0;
    g.vertexnum=n;
    for(int i=0;i<n;i++)
    {
        g.vertex[i].vertex=i;
        g.vertex[i].firstedge=NULL;
    }

}

//添加有向边
void addarcnode(Agraph &g,int u,int v,int weight)
{   
    Arcnode *p=(Arcnode*)malloc(sizeof(Arcnode));
    p->adjvex=v;
    p->weight=weight;
    //头插法插入链表
    p->next=g.vertex->firstedge;
    g.vertex[u].firstedge=p;
}


//遍历顶点的邻接点
void bianli(Agraph &g,int n)
{
    Arcnode *p=g.vertex[n].firstedge;

    while(p!=NULL)
    {
        cout<<p->adjvex<< " ";
        p=p->next;
    }
    cout<<endl;

}

