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
#include <fstream>

#define all(x) x.begin(), x.end()
#define debug(x) cout << #x << " = " << x << "\n"
#define MOD 1000000007

const long double PI = 3.141592653589793236L;

typedef long long int ll;
typedef long double ld;

using namespace std;

ifstream infile;
ofstream outfile;

// Read input as 'infile >> ' and print to output file as 'outfile >> '

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    infile.open("input.txt");
    outfile.open("output.txt");

    int T = 1;
    infile >> T;
    
    int i = 1;

    while (T--)
    {
        outfile << "Case #" << i++ << ": ";
        solve();
    }

    outfile.close();
    infile.close();

    return 0;
}


