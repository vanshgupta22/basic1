#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

vector<bool> *vis;
vector<int> *adj;
vector<char> *mat;
int R,C,n;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int sr,sc;              //Source row and column
queue <int > rq,cq;

int move_count=0;
int nodes_left_in_layer=1;
int nodes_in_next_layer=0;
void explore(int row, int col)
{
    for(int i=0;i<4;i++)
    {
        int rr=row+dr[i];
        int cc=col+dc[i];

        if(rr>=R||rr<0)  continue;
        if(cc>=C||cc<0)  continue;
        if(vis[rr][cc])      continue;
        if(mat[rr][cc]=='#')    continue;

        rq.push(rr);    cq.push(cc);
        vis[rr][cc]=true;
        nodes_in_next_layer++;
    }
}

int solve()
{

    int flag=0;
    rq.push(sr);    cq.push(sc);
    vis[sr][sc]=true;
    //deb(sc);
    while (!rq.empty())
    {
        if(mat[rq.front()][cq.front()]=='E')
        {
            flag=1;
            break;
        }
        int row,col;
        row=rq.front();
        col=cq.front();
        rq.pop();   cq.pop();        //Removing the cell that's visited and in front of the queue
        explore(row,col);           //Exploring the neighbours of the visited node
        
        nodes_left_in_layer--;
        if(nodes_left_in_layer==0)      //Checking if all the elements of the current layer are done or not
        {
            nodes_left_in_layer=nodes_in_next_layer;        //Next layer becomes the current layer
            nodes_in_next_layer=0;                          //Initially next layer has no elements
            move_count++;                                   // Move count is increased per layer
        }

    }
    if(flag)    return move_count;
    return -1;
}

int main()
{
    cin>>R>>C;
    mat = new vector<char> [R];
    vis = new vector<bool> [R];
    adj=new vector<int> [R];

    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            char temp;   cin>>temp;
            mat[i].push_back(temp);
            vis[i].push_back(false);
        }
    }
    cin>>sr>>sc;

    cout<<endl;

    cout<<solve()<<endl;
    
}