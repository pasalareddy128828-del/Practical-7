#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);

    // 0 amount ke liye 0 coins chahiye
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = minCoins(coins, amount);

    cout << "Minimum number of coins = " << result << endl;

    return 0;
}
