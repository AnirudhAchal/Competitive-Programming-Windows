/*COMPETITIVE PROGRAMMING C++ TEMPLATE */

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <iomanip>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 998244353

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

const int maxN = 1e5;
vector<int> adj[maxN + 1];
vector<int> deg(maxN + 1);

void solve()
{
    int n, m;

    vector<pair<int, int>> E(m);

    for (int i = 0; i < m; i++)
    {
        cin >> E[i].first >> E[i].second;
        adj[E[i].first].push_back(E[i].second);
        adj[E[i].second].push_back(E[i].first);
    }

    for (int i = 1; i <= n; i++)
    {
        deg[i] = (int)adj[i].size();
    }

    ll sadness = 0;

    for (int i = 0; i < m; i++)
    {
        int x = deg[E[i].first];
        int y = deg[E[i].second];

        sadness++;

        sadness += n - x + n - y;

        deg[E[i].first]--;
        deg[E[i].second]--;

        cout << sadness << "\n";

    }



}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    //cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}



