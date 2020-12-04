#include<stdio.h>
#include<stdlib.h>

typedef struct{int v; int w;}Edge;
typedef struct graph *Graph;

struct graph {int V; int E; int **adj;};

typedef struct big{
    int cnt, v, j;
}Big;

int *pre, cnt, J, john;
Big big;

Edge EDGE(int v, int w) {
  Edge e;
  e.v = v;
  e.w = w;
  return e;
}

int ** matrixInit(int l, int c){
    int **matrix;
    matrix = malloc(l*sizeof(int *));
    for(int i=0; i<c; i++)
        matrix[i] = malloc(c*sizeof(int));
    
    return matrix;
}

Graph GRAPHInit(int V) {
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = matrixInit(V,V);
    return G;
}

void GRAPHInsertE(Graph G, Edge e) {
    int v = e.v;
    int w = e.w;
    if(G->adj[v][w] == 0)G->E++;
    G->adj[v][w] = 1;
    G->adj[w][v] = 1;
}

void dfsR(Graph G, Edge e){
    int t,w = e.w;
    if(w==J)john=1;
    pre[w] = cnt++;
    
    for(t=0;t<G->V;t++)
        if(G->adj[w][t]!=0)
            if(pre[t]==-1)
                dfsR(G,EDGE(w,t));
}

void GRAPHSearch(Graph G){
    int v;
    for(v=0;v<G->V;v++)pre[v]=-1;
    for(v=0;v<G->V;v++){
        john=0;
        cnt=0;
        if(pre[v]==-1){
            dfsR(G,EDGE(v,v));
            if(v==0){
                big.cnt = cnt;
                big.v = v;
                big.j = john;
            }
            if(v!=0&&cnt>=big.cnt){
                if(cnt==big.cnt){
                    if(john==1){
                        big.cnt = cnt;
                        big.v = v;
                        big.j = john;
                    }
                    else if(big.j==0&&v<big.v){
                        big.cnt = cnt;
                        big.v = v;
                        big.j = john;
                    }
                }
                else{
                    big.cnt = cnt;
                    big.v = v;
                    big.j = john;
                }
            }
        }
    }
}



int main() {
    int V,v,w;

    Graph G;

    scanf("%d %d",&V,&J);

    pre = malloc(V*sizeof(int));
    G = GRAPHInit(V);

    while(scanf("%d",&v)==1){
        scanf("%d",&w);
        GRAPHInsertE(G, EDGE(v,w));
    }

    GRAPHSearch(G);

    if(big.j==1){
        if(big.cnt==1)printf("Fique em casa\n");
        else printf("Bora pra estrada\n");
    }
    else printf("Vamos para %d\n",big.v);

    return 0;
}