// 0-1 knapsack using dynamic programming
// 1) bottom up

#include <bits/stdc++.h>
using namespace std;
int dp[101][1001];

class Solution
{
public:
    int knapsack(int W, int wt[], int val[], int n)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }


        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (wt[i - 1] <= j)
                {
                    int choose = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int skip = dp[i - 1][j];
                    dp[i][j] = max(choose, skip);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
    }
};

int main()
{
    int n, W;
    // memset(dp, 0, sizeof(dp));
    cout << "Enter total no. of weights:- ";
    cin >> n;
    cout << "Enter the max weight:-";
    cin >> W;
    int wt[n];
    int val[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and its weight:-";
        cin >> val[i] >> wt[i];
    }

    Solution ob;
    cout << "Max profit:- " << ob.knapsack(W, wt, val, n);
}