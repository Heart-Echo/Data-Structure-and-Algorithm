#include<iostream>
using namespace std;
#define MAXSIZE 100


typedef struct arcnode
{
    int adjvex;

    int weight;

    struct arcnode*next;



}arcnode;


typedef struct vnode
{
    char vertex;

    arcnode*first;


}vnode;

typedef struct arcgraph
{
    vnode graph[MAXSIZE];

    int vertexnum;
    int edgenum;


}arcgraph;

bool visited[MAXSIZE]={false};

void dfs(arcgraph &g,int v)
{
    //输出顶点v
    cout<<g.graph[v].vertex;

    visited[v]=true;
    //用一个临时指针指向第一条边
    //之后只用移动临时指针，和链表遍历的思想一致

    arcnode*p=g.graph[v].first;
    //p不为空就是判断v是不是连接着有边
    while(p!=NULL)
    {

        //递归实现dfs

        if(!visited[p->adjvex])
        {
            dfs(g,p->adjvex);

        }
        //指向下一个边
        p=p->next;
    }


}



//为了防止有非连通分量，要对所有顶点都dfs一次

void ans(arcgraph g)
{
    for(int i=0;i<g.vertexnum;i++)
    {

        if(visited[i]!=true)
        {
            dfs(g,i);
        }



    }



}