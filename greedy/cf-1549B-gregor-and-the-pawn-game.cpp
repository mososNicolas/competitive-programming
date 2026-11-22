/*
 * Problem: 1549B - Gregor and the Pawn Game
 * Platform: Codeforces (Rating: 800)
 * https://codeforces.com/problemset/problem/1549/B
 *
 * Approach:
 * To achieve a time complexity of O(n), I use two Strings: enemy_pawn and pawn.
 * I realized that the only thing that matters is the position j of the 1s to
 * calculate the number of pawns reaching the end. Additionally, when a pawn
 * moves diagonally, I repleace the 1s with 2s to handle cases where two
 * diagonal pawns try to cross the same enemy pawn.
 *
 * time complexity: O(n) per test case
 * space complextity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> ans(t, 0);

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string enemy_pawn;
        cin >> enemy_pawn;
        string pawn;
        cin >> pawn;

        int max_test = 0;
        // pawn(n,j)
        // enemy_pawn(0,j)
        for (int j = 0; j < n; j++) {
            if (enemy_pawn[j] == '0' && pawn[j] == '1') {
                max_test++;
            } else {
                if (j != 0 && j != n - 1) {
                    if (pawn[j] == '1') {
                        if (enemy_pawn[j - 1] == '1') {
                            max_test++;
                            enemy_pawn[j - 1] = '2';
                            continue;
                        }
                        if (enemy_pawn[j + 1] == '1') {
                            max_test++;
                            enemy_pawn[j + 1] = '2';
                            continue;
                        }
                    }
                }
                if (j == 0 && pawn[j] == '1' && enemy_pawn[j + 1] == '1') {
                    max_test++;
                    enemy_pawn[j + 1] = '2';
                }
                if (j == n - 1 && pawn[j] == '1' && enemy_pawn[j - 1] == '1') {
                    max_test++;
                    enemy_pawn[j - 1] = '2';
                }
            }
        }
        ans[i] = max_test;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
