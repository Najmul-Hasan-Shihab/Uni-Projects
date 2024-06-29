#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Graph{

public:
    int V;
    vector<vector<int> > adjacent;
    int* no_of_adjacent;


///Functions==
public:
    Graph(int V);
    void addedge(int v, int w);
    vector<int> show_adjacents(int V);
};
