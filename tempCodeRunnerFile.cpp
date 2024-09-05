#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the LCS of two strings X and Y
pair<int, string> lcs(const string &X, const string &Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store lengths of longest common subsequence
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp array
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Length of the LCS
    int lcs_length = dp[m][n];

    // To find the LCS string, backtrack from dp[m][n]
    string lcs_str;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str.push_back(X[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    // The lcs_str will be in reverse order, so reverse it
    reverse(lcs_str.begin(), lcs_str.end());

    return {lcs_length, lcs_str};
}

int main() {
    string X = "ABCD";
    string Y = "BCDE";

    pair<int, string> result = lcs(X, Y);
    int lcs_length = result.first;
    string lcs_str = result.second;

    cout << "Length of LCS: " << lcs_length << endl;
    cout << "LCS: " << lcs_str << endl;

    return 0;
}
