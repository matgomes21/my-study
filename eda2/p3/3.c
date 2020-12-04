#include<stdio.h>
#include<stdlib.h>

typedef struct{ int v, w; }Edge;
typedef struct graph * Graph;

Graph graph;

struct graph {int V, E, **adj, **tc;};

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

void GRAPHInsertE(Graph G, Edge e, int codigo){
	int v = e.v, w = e.w;
	if(G->adj[v][w] == 0){
        G->E++;
    }
    if(codigo==1){
	    G->adj[v][w] = 1;
    }
    else if(codigo==2){
	    G->adj[v][w] = 1;
	    G->adj[w][v] = 1;
    }
}

void GRAPHtc(Graph G){
    int i,s,t;
    G->tc = MATRIXInit(G->V,G->V,0);
    for(s=0;s<G->V;s++)
        for(t=0;t<G->V;t++)
            G->tc[s][t] = G->adj[s][t];
    for(s=0;s<G->V;s++)G->tc[s][s]=1;
    for(i=0;i<G->V;i++)
        for(s=0;s<G->V;s++)
            if(G->tc[s][i]==1)
                for(t=0;t<G->V;t++)
                    if(G->tc[i][t]==1)
                        G->tc[s][t]=1;
}

int GRAPHreach(Graph G, int s, int t){
    return G->tc[s][t];
}

int main() {
    int v,w,V,codigo,check=1,way1,way2;
    Edge edge;
    scanf("%d",&V);
    graph = GRAPHInit(V);
    do{
        scanf("%d %d %d",&v, &w, &codigo);
        if(v==0&&w==0&&codigo==0)check=0;
        if(codigo>0){
            edge.v=v;
            edge.w=w;
            GRAPHInsertE(graph, edge, codigo);
        }
    }while(check==1);
    GRAPHtc(graph);
    while(scanf("%d %d",&v,&w)!=EOF){
        way1 = GRAPHreach(graph, v, w);
        way2 = GRAPHreach(graph, w, v);
        if(way1&&way2)printf("Ida e Volta\n");
        else if(way1)printf("Apenas Ida\n");
        else if(way2)printf("Apenas Volta\n");
        else if(way1==0&&way2==0) printf("Impossibru\n");
    }
    return 0;
}