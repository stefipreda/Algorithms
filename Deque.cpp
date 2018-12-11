#include <fstream>

using namespace std;

ifstream in ("deque.in");
ofstream out ("deque.out");

const int N = 5000005;
int a[N], deq[N];

int main()
{
    int n, k, i;
    in >> n >> k;
    for(i = 1; i <= n; i++)
        in >> a[i];
    int p = 1, u = 1;
    long long S = 0;
    deq[1] = 1;
    for(i = 2; i <= n; i++)
    {
        for(int j = u; j >= p; j--)
            if(a[deq[j]] >= a[i])
                u--;
                else break;
        u++;
        deq[u] = i;

        if(deq[p] == i - k)
            p++;
        if(i >= k)
            S += a[deq[p]];
    }
    out << S;

    return 0;
}
