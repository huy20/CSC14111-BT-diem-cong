#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> count(vector<int> a)
{
    int n = a.size();
    vector<vector<int>> cnt(n+1, vector<int>(3, 0));
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<3;++j)
            cnt[i][j] = cnt[i-1][j];
        cnt[i][a[i-1]]++;
    }
    return cnt;
}

int solution1(vector<int> a)
{
    int n = a.size(), ans = 0;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<i;++j)
        {
            vector<int> cnt(3, 0);
            for (int k=j;k<=i;++k)
            {
                cnt[a[k]]++;
            }
            if (cnt[0] >= 3 || cnt[1] >= 3 || cnt[2] >= 3)
            {
                ans++;
            }
        }
    }
    return ans;
}

int solution2(vector<int> a, vector<vector<int>> cnt)
{
    int ans = 0;
    int n = a.size();
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=i;++j)
        {
            for (int k=0;k<3;++k)
            {
                if (cnt[i][k] - cnt[j-1][k] >= 3)
                {
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}

int solution3(vector<int> a, vector<vector<int>> cnt)
{
    int n = a.size();
    int l = 1, ans = 0;
    for (int r = 1; r <= n; ++r)
    {
        while  ((cnt[r][0] - cnt[l-1][0] >= 3) ||
                (cnt[r][1] - cnt[l-1][1] >= 3) ||
                (cnt[r][2] - cnt[l-1][2] >= 3))
        {
            l++;
        }
        ans += (l-1);
    }

    return ans;
}



int main()
{
    // vector<int> a = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    vector<int> a = {0,1, 2, 2, 2};
    // vector<int> a = {0, 1, 2, 0, 1, 2, 0, 1, 0, 2};
    // vector<int> a = {1, 1, 1, 1};
    vector<vector<int>> cnt = count(a);

    cout << "Solution 1: " << solution1(a) << '\n';
    cout << "Solution 2: " << solution2(a, cnt) << '\n';
    cout << "Solution 3: " << solution3(a, cnt) << '\n';

    return 0;
}