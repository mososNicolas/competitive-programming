/*
 * Problem: 1676A Lucky?
 * Platform: Codeforces (Rating: 800)
 * https://codeforces.com/problemset/problem/1676/A
 *
 * Approach:
 * Direct comparison of the sum of the first characters against the last three.
 *
 * Time complexity: O(1) per test case
 * Space complexity: O(1)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        string tic;
        cin >> tic;

        int last = tic[0] + tic[1] + tic[2];
        int from = tic[3] + tic[4] + tic[5];

        if (last == from) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
