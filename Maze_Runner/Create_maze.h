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

#include "Create_graph.h"

using namespace std;

class Maze{

public:
    Graph* maze_graph;
    int HEIGHT;
    int WIDTH;
    int no_of_vertices;
    int *spanning_tree;
    int **cells;

///Funtions==
public:
    Maze(int w, int h);
    void initialize();
    void maze_DFS();
    void draw_maze();
    int unvisited_nb(bool* visit,vector<int> adj_list);
};
