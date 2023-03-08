// TLE
#include <bits/stdc++.h> // local
using namespace std;     // local

class Solution
{
public:
    bool isSubseq(string str, string target) // is str a subseq of target?
    {
        if (str.size() > target.size())
            return false;
        if (str.size() == target.size())
            return str.compare(target) == 0;
        int pa = 0;
        int pt = -1;
        int sa = str.size();
        int st = target.size();
        while (pa < sa && pt < st)
        {
            pt++;
            if (str[pa] == target[pt])
            {
                pa++;
            }
        }
        if (pa >= sa)
            return true;
        else
            return false;
    }

    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ws = words.size();
        int result = 0;
        for (int i = 0; i < ws; i++)
        {
            if (isSubseq(words[i], s))
                result++;
        }
        return result;
    }
};

// local
int main()
{
    Solution s;
    vector<string> v;
    string str;
    cin >> str;
    string input;
    while (cin >> input)
    {
        v.push_back(input);
    }
    clock_t timeSt = clock();
    printf("%d\n", s.numMatchingSubseq(str, v));
    clock_t timeEnd = clock();
    printf("Time = %.1fms\n", (double)(timeEnd - timeSt) / CLOCKS_PER_SEC / 1000.0);
    return 0;
}
// local