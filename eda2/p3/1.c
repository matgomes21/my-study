#include<stdio.h>
#include<stdlib.h>

typedef struct{ int v, w; }Edge;
typedef struct graph * Graph;

int *pre, cnt=0, conexos=0;

Graph graph;

struct graph { 
    int V, E;
    int **adj;
};

int ** MATRIXInit(int l, int c, int p){
    int **matrix;
    matrix = malloc(l*sizeof(int *));
    for(int i=0;i<l;i++){
        matrix[i] = malloc(c*sizeof(int));
    }
    return matrix;
}

Graph GRAPHInit(int V){
	Graph G = malloc(sizeof(*G));
	G-> V = V; G->E = 0;
	G-> adj = MATRIXInit(V,V,0);
	return G;
}

void GRAPHInsertE(Graph G, Edge e){
	int v = e.v, w = e.w;
	if(G->adj[v][w] == 0)G->E++;
	G->adj[v][w] = 1;
	G->adj[w][v] = 1;
}

void dfsR(Graph G, Edge e) {
    int t, w = e.w;
    Edge edge;
    pre[w] = cnt++;
    
    for(t=0; t<G->V; t++)
        if(G->adj[w][t] != 0)
            if(pre[t] == -1){
                edge.v = w;
                edge.w = t;
                dfsR(G,edge);
            }
}

void GRAPHSearch(Graph G) {
    int v;
    Edge edge;
    cnt = 0;
    for(v=0; v<G->V; v++)
      pre[v] = -1;
    for(v=0; v<G->V; v++)
        if(pre[v] == -1){
            edge.v=v;
            edge.w=v;
            dfsr(G, edge);
            conexos++;
        }
}

int main() {
    int v,w,V;
    Edge edge;
    scanf("%d",&V);
    pre = malloc(V*sizeof(int));
    graph = GRAPHInit(V);
    while(scanf("%d %d",&v,&w)!=EOF){
        edge.v = v;
        edge.w = w;
        GRAPHInsertE(graph, edge);
    }
    GRAPHSearch(graph);
    printf("%d\n",conexos);

    return 0;
}