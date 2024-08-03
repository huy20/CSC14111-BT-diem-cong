#include <vector>
#include <iostream>
using namespace std;

int solve(vector<int> a, int m, int k, vector<int> sm)
{
    // dp[i][j] xét tới phẩn tử thứ i và trong mảng con j
    // đáp án dp[n][k]
    // ko lấy a[i]: dp[i][j] = dp[i-1][j]
    // lấy a[i]: dp[i][j] = dp[i-m][j-1] + sum[i-m..i]
    // khởi tạo: dp[i][1] = sum
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i=1;i<=n;++i)
    {
        if (i - m >= 0)
        {
            dp[i][1] = sm[i] - sm[i-m];
        }
    }

    for (int j=1;j<=k;++j)
    {
        for (int i=1;i<=n;++i)
        {
            if (i - m > 0)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + sm[i] - sm[i-m]);
            }
        }
    }
    return dp[n][k];
}

vector<int> sum(vector<int> a)
{
    vector<int> s(a.size()+1, 0);
    for (int i=1;i<=a.size();++i)
        s[i] = s[i-1] + a[i-1];
    return s;
}

int main()
{
    vector<int> a = {5,2,6,3,4};
    int k = 3, m = 1;
    
    vector<int> sm = sum(a);
    int n = a.size();
    cout << solve(a, m, k, sm) << '\n';

    // k = 2, m = 2;
    // cout << solve(a, m, k, sm) << '\n';
    // k = 1, m = 3;
    // cout << solve(a, m, k, sm) << '\n';
    return 0;
}