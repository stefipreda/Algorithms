#include <fstream>
#include <vector>
#include <queue>

using namespace std;
ifstream in ("dijkstra.in");
ofstream out ("dijkstra.out");

const int N =  50005;
const int INF = 1000000000;

struct muchie
{
    int nod, cost;
};
vector <muchie> G[N];
int n, m;
priority_queue <pair <int, int> > heap;
bool luat[N];
int d[N];

int main()
{
    in >> n >> m;
    int i, a, b, c;
    for(i = 1; i <= m; i++)
    {
        in >> a >> b >> c;
        G[a].push_back({b,c});
    }
    d[1] = 0;
    heap.push(make_pair(-d[1], 1));
    for(i = 2; i <= n; i++)
    {
        d[i] = INF;
        heap.push(make_pair(-d[i], i));
    }
    int x, y;
    while(!heap.empty())
    {
        while(!heap.empty() && luat[heap.top().second] )
            heap.pop();
        if(!heap.empty())
        {
            x = heap.top().second;
            luat[x] = true;
            for (int i = 0; i < G[x].size(); i++) {
                y = G[x][i].nod;
                c = G[x][i].cost;
                if (d[x] + c < d[y]) {
                    d[y] = d[x] + c;
                    heap.push(make_pair(-d[y], y));
                }
            }
        }
    }
    for(i = 2; i <= n; i++)
        if(d[i] == INF)
            out << 0 << " ";
        else out << d[i] <<" ";

    return 0;
}
