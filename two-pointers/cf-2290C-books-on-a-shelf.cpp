/*
 * Problem: 2290C - books-on-a-shelf
 * Platform: Codeforces (Rating: 800)
 * Link: https://codeforces.com/contest/2290/problem/C
 *
 * Approach: To be honest, this problem took me 4 days. After researching
 * constructive algorithms, without knowing anythin about two-pointers
 * technique, I just spammed nested loops, frequency arrays, and other weird
 * workarounds until discovering two-pointers, from there, it only took a simple
 * while loop handling even and odd iterations to assign the original sorted
 * array to both sides.
 *
 *
 * Time complexity: O(nLogn)
 * Space complexity: O(n)
 */
#include <bits/stdc++.h>
using namespace std;

int check_books(const vector<int> &books, int n) {
    int ans = 0, min = 0, max = 0;
    int half = n / 2;
    if (n == 1)
        return 1;

    for (int i = 0; i < half; i++) {
        if (books[i] > min) {
            ans++;
            min = books[i];
        }
    }
    for (int i = n - 1; i >= half; i--) {
        if (books[i] > max) {
            ans++;
            max = books[i];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> books(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> books[i];
        }

        sort(books.begin(), books.end());
        vector<int> books_ans(n, 0);

        int l = 0, r = n - 1, i = 0;

        while (l <= r) {
            if (i % 2 == 0) {
                books_ans[r] = books[i];
                r--;
            } else {
                books_ans[l] = books[i];
                l++;
            }
            i++;
        }

        int ans = check_books(books_ans, n);
        cout << ans << "\n";

        for (int n : books_ans) {
            cout << n << " ";
        }
        cout << "\n";
    }
    return 0;
}
