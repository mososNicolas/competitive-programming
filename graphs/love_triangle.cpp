/*
 * Problem: 939A Love Triangle
 * Platform: Codeforces (Rating: 800)
 * https://codeforces.com/problemset/problem/939/A
 *
 * Approach:
 * For this problem, I realized this is a special case of a funtional graph,
 * so I used a simple 1D vector instead of an adjacency list (vector of vectos)
 * I simply check if following a chain of 3 steps leads back to the initial node
 * i. Upon further research, I noticed that using 1 based indexing makes graph
 * problems cleaner and less error-prone, so I plan to use it in future
 * problems.
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool ans = false;
    vector<int> air_planes(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> air_planes[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == air_planes[air_planes[air_planes[i] - 1] - 1] - 1) {
            ans = true;
        }
    }
    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
