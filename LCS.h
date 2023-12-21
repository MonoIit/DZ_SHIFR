#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <cmath>

std::vector<std::vector<int>> fillMatrix(std::string& s1, std::string& s2)
{
    int m = s1.length(), n = s2.length();
    std::vector<std::vector<int>> dp;
    for (int i = 0; i < m+1; i++)
    {
        std::vector<int> per;
        for (int j = 0; j < n+1; j++)
        {
            per.push_back(0);
        }
        dp.push_back(per);
    }

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp;
}

std::vector<std::string> Combinations(std::string q)
{
    std::vector<std::string> res;
    std::bitset<20> b;
    int count = 0;
    for (int i = 0; i < pow(2, q.size()); ++i)
    {
        std::string posl;
        for (int x = 0; x < 20; x++)
        {
            if (b[x] == 1)
            {
                posl += q[x];
            }
        }
        count++;
        res.push_back(posl);
        for (int j = 0; j < 20; j++)
        {
            if (b[j] == 1)
            {
                b[j].flip();
            }
            else
            {
                b[j].flip();
                break;
            }
        }
    }
    return res;
}

std::string naive(std::string& s1, std::string& s2)
{
    std::vector<std::string> ex1 = Combinations(s1);
    std::vector<std::string> ex2 = Combinations(s2);
    if (ex1.size() > ex2.size())
    {
        std::vector<std::string> per;
        per = ex1;
        ex1 = ex2;
        ex2 = per;
    }
    std::string res;
    int max = 0;
    for (std::string i : ex1)
    {
        for (std::string j : ex2)
        {
            if (i == j && i.length() > max)
            {
                max = i.length();
                res = i;
            }
        }
    }
    return res;
}

std::string lcs(std::string& s1, std::string& s2)
{
    if (s1.length() < s2.length())
    {
        std::string per;
        per = s1;
        s1 = s2;
        s2 = per;
    }
    std::vector<std::vector<int>> L = fillMatrix(s1, s2);
    std::string word;
    int x = s1.length()-1, y = s2.length()-1;
    while (x >= 0 && y >= 0)
    {
        if (s1[x] == s2[y])
        {
            word.push_back(s1[x]);
            x--;
            y--;
        }
        else if (L[x-1][y] > L[x][y-1])
            x--;
        else
            y--;
    }
    reverse(word.begin(), word.end());
    return word;
}