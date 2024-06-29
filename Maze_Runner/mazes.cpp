#include "Create_maze.h"


///Maze constructor==
Maze::Maze(int w, int h)
{
    WIDTH=w;
    HEIGHT=h;
    maze_graph=new Graph(w*h);
    no_of_vertices=HEIGHT*WIDTH;
    spanning_tree=new int[no_of_vertices];
    cells=new int*[HEIGHT];

    initialize();
    maze_DFS();

    for(int i=0; i<HEIGHT; i++)
    {
        cells[i]=new int[WIDTH];
        for(int column=0; column<WIDTH; column++) cells[i][column]=0xF; //1111
    }
    draw_maze();
}

///Initialize the maze==
void Maze::initialize()
{
	for(int row = 0;row<HEIGHT;row++)
    {
		for(int col = 0;col<WIDTH;col++)
		{
			int v = row*WIDTH+col;
			if(row>0)
			{
				int v_top = (row-1)*WIDTH+(col);
				maze_graph->addedge(v,v_top);
				maze_graph->addedge(v_top,v);
			}
			if(col>0)
			{
				int v_left = row*WIDTH+(col-1);
				maze_graph->addedge(v,v_left);
				maze_graph->addedge(v_left,v);
			}
			if(row<HEIGHT-1)
			{
				int v_bottom = (row+1)*WIDTH+(col);
				maze_graph->addedge(v,v_bottom);
				maze_graph->addedge(v_bottom,v);

			}
			if(col<WIDTH-1)
            {
				int v_right = (row)*WIDTH+(col+1);
				maze_graph->addedge(v,v_right);
				maze_graph->addedge(v_right,v);
			}
		}
	}
	int v_temp = (0+1)*WIDTH+(0);
	maze_graph->addedge(0,v_temp);
	maze_graph->addedge(v_temp,0);
	v_temp = (0)*WIDTH+(0+1);
	maze_graph->addedge(0,v_temp);
	maze_graph->addedge(v_temp,0);
}

///DepthFirstSearch==
void Maze::maze_DFS()
{
	int s_v = 0;
	stack<int> temp;
	int no_of_vertex = no_of_vertices;
	bool visited[no_of_vertex];
	int visitCount = 1;
	int i;
	for(i = 0;i<no_of_vertex;i++) visited[i] = false;

	visited[s_v] = true;
	spanning_tree[s_v] = -1;
	while(visitCount<no_of_vertex)
    {
		vector<int> adj_list = maze_graph->show_adjacents(s_v);
		random_shuffle ( adj_list.begin(), adj_list.end() );
		int adj_count = maze_graph->no_of_adjacent[s_v];
		int next_cell = unvisited_nb(visited,adj_list);
		if(next_cell!=-9)
        {
			int w = next_cell;
			visited[w] = true;
			spanning_tree[w] = s_v;
			temp.push(w);
			s_v = w;
			visitCount++;
		}
		else
        {
			if(!temp.empty())
			{
				s_v = temp.top();
				temp.pop();
			}
		}
	}
}

///Check Unvisited Neighbour==
int Maze::unvisited_nb(bool* visited,vector<int> adj_list)
{
	int s = adj_list.size();

	set<int> rand_set;
	while(rand_set.size()<s)
    {
		int r = rand()%s;
		rand_set.insert(r);
		if(!visited[adj_list[r]]) return adj_list[r];
	}
	return -9;
}

///Draw the maze==
void Maze::draw_maze()
{
	int v,r0,c0,v0;
	int RIGHT = 1;  /// 0001    1 = wall, 0 = path
	int UP = 2;     /// 0010
	int LEFT = 4;   /// 0100
	int DOWN = 8;   /// 1000
	for(int row = 0;row<HEIGHT;row++)
    {
		for(int col = 0;col<WIDTH;col++)
		{
			v = row*WIDTH+col;
			int w = spanning_tree[v]; // cell connected to 'v'
			if(w>=0)
            {
				r0 = w/WIDTH;
				c0 = w%WIDTH;
			}
			v0 = r0*WIDTH+c0;
			if(col+1==c0)
			{
				cells[row][col] &= ~RIGHT;
				cells[r0][c0] &= ~LEFT;
			}
			if(row+1==r0)
			{
				cells[row][col] &= ~DOWN;
				cells[r0][c0] &= ~UP;
			}
			if(row-1==r0)
			{
				cells[row][col] &= ~UP;
				cells[r0][c0] &= ~DOWN;
			}
			if(col-1==c0)
			{
				cells[row][col] &= ~LEFT;
				cells[r0][c0] &= ~RIGHT;
			}
		}
	}

	cells[0][0] &= ~LEFT;
	cells[HEIGHT-1][WIDTH-1] &= ~RIGHT;
}
