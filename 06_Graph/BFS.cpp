#include<iostream>
using namespace std;
//广度优先搜索   类似于树的层序遍历
#include<queue>
//需要一个辅助队列


#define MAXSIZE 100

typedef struct Arcnode
{
    int vertex;

    int weight;


    struct Arcnode*next;
}Arcnode;

typedef struct vnode
{
    int data;

    Arcnode *firstedge;

}vnode;


typedef struct graph
{
    int vertexnum;
    int edgenum;

    vnode graph[MAXSIZE];


};
//需要一个辅助的数组来记录顶点是否被访问过
bool visited[MAXSIZE];


void BFS(graph &g,int start)
{
    //创建辅助队列
    queue<int> q;

    visited[start]=true;

    cout<<start<<" ";

    q.push(start);

while(q.empty()!=NULL)
{
    //队头元素
    int u=q.front();
    //队头出队
    q.pop();
    //u就是当前正在处理的节点
    //找到u的邻接表
    //让p指向第一条边
    Arcnode* p=g.graph[u].firstedge;

    //相当于链表的遍历
    while(p!=NULL)
    {
        //u这个顶点连着的边的另一边的节点
        int v=p->vertex;
        //防止循环访问
        if(visited[v]!=NULL)
        {
            //标记为已经访问了
            visited[v]=true;

             cout<<v<<" ";
        //顺着链表向下
            q.push(v);
        }

// vertex[0]
//     |
//   first
//     ↓
// ┌─────────────┐
// │ adjvex = 1  │
// │ next ────────┼────┐
// └─────────────┘    ↓
//               ┌─────────────┐
//               │ adjvex = 2  │
//               │ next ────────┼────┐
//               └─────────────┘    ↓
//                             ┌─────────────┐
//                             │ adjvex = 3  │
//                             │ next = NULL │
//                             └─────────────┘
        
        //指向下一条边
    p=p->next;

    }
 
}



}
//为了防止有非连通分量
void BFStraverse(graph &g)
{
    for(int i=0;i<g.vertexnum;i++)
    {

        visited[i]=false;
    }

    for(int i=0;i<g.vertexnum;i++)
    {
        if(!visited[i])
        {
            //对每一个没有访问的顶点BFS
            BFS(g,i);


        }
        

    }


}