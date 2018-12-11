#include <fstream>

using namespace std;

ifstream in ("rmq.in");
ofstream out ("rmq.out");

const int N = 100005;

int rmq[N][20], log2[N];

int main()
{
    int n, m, i;
    in >> n >> m;
    for(i = 1; i <= n; i++)
        in >> rmq[i][0];
    log2[1] = 0;
    for(i = 2; i <= n; i++)
        log2[i] = log2[i/2] + 1;
    int k;
    for(k = 1; (1<<k) <= n; k++)
        for(i = 1; i + (1<<k) - 1 <= n; i++)
            rmq[i][k] = min(rmq[i][k-1], rmq[i + (1<<(k - 1))][k-1]);

    int x, y;
    for(i = 1; i <= m; i++)
    {
        in >> x >> y;
        k = log2[y - x + 1];
        out << min(rmq[x][k], rmq[y - (1<<k) + 1][k]);
        out <<"\n";
    }

    return 0;
}
