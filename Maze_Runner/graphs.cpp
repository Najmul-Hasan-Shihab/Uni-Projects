#include "Create_graph.h"


///Initialize==
Graph::Graph(int v)
{
    V=v;
    no_of_adjacent=new int[V];
    adjacent.resize(V, vector<int>(V,0));
    for(int i=0; i<V; i++)
    {
        adjacent[i].resize(V);
        no_of_adjacent[i]=0;
    }
}


///Add edge==
void Graph::addedge(int v, int w)
{
    vector<int> temp=adjacent[v];
    int cnt=no_of_adjacent[v];
    for(int i=0; i<cnt; i++)
    {
        if(w==temp[i]) return;
    }
    no_of_adjacent[v]++;
    adjacent[v][no_of_adjacent[v]-1]=w;
}


///Show adjacents==
vector<int> Graph::show_adjacents(int V)
{
    vector<int> tempo=adjacent[V];
    tempo.erase(tempo.begin()+no_of_adjacent[V], tempo.begin()+tempo.size());
    return tempo;
}
