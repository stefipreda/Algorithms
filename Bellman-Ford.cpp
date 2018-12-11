#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream in ("bellmanford.in");
ofstream out ("bellmanford.out");

const int N = 50005;
const int INF = 2000000000;

struct muchie
{
    int nod, cost;
};

vector <muchie> g[N];
queue <int> q;

bool inq[N];
int nrviz[N], d[N];

int main()
{
    int n, m, i;
    in >> n >> m;
    int a, b, c;
    for(i = 1; i <= m; i++)
    {
        in >> a >> b >> c;
        g[a].push_back( {b, c});
    }
    for(i = 1; i <= n; i++)
        d[i] = INF;
    q.push(1);
    d[1] = 0;
    inq[1] = true;
    nrviz[1] = 1;
    int node, vec;
    while( !q.empty() )
    {
        node = q.front();
        q.pop();
        inq[node] = false;
        for(i= 0; i < g[node].size(); i++)
        {
            vec = g[node][i].nod;
            if(d[vec] > d[node] + g[node][i].cost)
            {
                d[vec] = d[node] + g[node][i].cost;
                if(inq[vec] == false)
                {
                    inq[vec] = true;
                    q.push(vec);
                }
                nrviz[vec] ++;
                if(nrviz[vec] > n)
                {
                    out << "Ciclu negativ!";
                    return 0;
                }
            }
        }
    }
    for(i = 2; i <= n; i++)
        out << d[i] <<" ";


    return 0;
}
