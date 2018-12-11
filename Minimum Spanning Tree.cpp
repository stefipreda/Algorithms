#include <fstream>
#include <algorithm>

using namespace std;

ifstream in ("apm.in");
ofstream out ("apm.out");

const int N = 200005;

int father[N], lev[N];

struct edge
{
    int x, y, c;
};

edge m[2*N], sol[N];

bool cmp (edge a, edge b)
{
    return (a.c < b.c);
}

void Union(int r1, int r2)
{
    if(lev[r1] < lev[r2])
        father[r1] = r2;
    else
        if(lev[r1] > lev[r2])
        father[r2] = r1;
    else
    {
        father[r1] = r2;
        niv[r2] ++;
    }
}

int Find(int x)
{
    int y, root = x;
    while(father[root] != root)
        root = father[root];
    while(father[x] != x)
    {
        y = father[x];
        father[x] = root;
        x = y;
    }
    return root;
}

int main()
{
    int n, edg, i;
    in >> n >> edg;
    for(i = 1; i <= edg; i++)
    {
        in >> m[i].x >> m[i].y >> m[i].c;
    }
    sort(&m[1], &m[edg + 1], cmp);
    for(i = 1; i <= n; i++)
        father[i] = i;
    int ra1, rad2, k = 0, cost = 0;
    for(i = 1; i <= edg; i++)
    {
        rad1 = Find(m[i].x);
        rad2 = Find(m[i].y);
        if(rad1 != rad2)
        {
            k++;
            sol[k] = m[i];
            cost += m[i].c;
            Union(rad1, rad2);
        }
    }
    out << cost <<"\n" << k <<"\n";
    for(i = 1; i <= k; i++)
        out << sol[i].x <<" " << sol[i].y <<"\n";
    return 0;
}
