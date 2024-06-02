/* 
 * Problem Statement:
 * https://cses.fi/problemset/task/1647
 */

/*
 * Compile on windows powershell:
 * g++ --std=c++2a .\template.cpp -o template.exe
 * 
 * Other cpp standards: c++11, c++14, c++20, etc.
 * 
 * Compile on unix based system terminal:
 * g++ --std=c++2a template.cpp -o template.out
 */

// Include Standard Template Library //
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <fstream>
// #include <cstring>
// #include <unordered_set>
// #include <unordered_map>

// Include All Standard Template Library //
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

// Macro //
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ll,ll>

// Global //


// Functions //


// Main //
int main(int argc, char const *argv[])
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // cout << fixed << setprecision(15);

    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #else
    // online submission
    #endif
    
    /* code */
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &a_i : a)
        cin >> a_i;
    
    vector<pii> b(q);
    for (pii &b_i : b)
        cin >> b_i.X >> b_i.Y;
    
    int m = 1;
    while (m * m < n)
        m++;

    int minimum = INT_MAX;
    vector<int> sqd;
    for (int i = 0; i < n; i++) {
        minimum = min(minimum, a[i]);

        if ((i + 1) % m == 0) {
            sqd.push_back(minimum);
            minimum = INT_MAX;
        }
    }

    if (n % m) sqd.push_back(m);

    for (pii &b_i : b) {
        int ans = INT_MAX;
        
        int st = 0;
        while (st * m < b_i.X - 1) st++;

        int ed = 0;
        while ((ed + 1) * m < b_i.Y - 1) ed++;
        
        for (int i = b_i.X - 1; i < min(b_i.Y, st * m); i++)
            ans = min(ans, a[i]);
        
        for (int i = st; i < ed; i++)
            ans = min(ans, sqd[i]);
        
        for (int i = max(st, ed) * m; i < b_i.Y; i++)
            ans = min(ans, a[i]);
        
        cout << ans << '\n';
    }
    
    return 0;
}
