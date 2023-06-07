#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    int answer = 0;

    unordered_map<char, int> m;
    int l = 0, r = 0;
    while(r < s.size()){
        m[s[r]] += 1;

        while(m[s[r]] > 1){
            m[s[l]] -= 1;
            l += 1;
        }
        answer = max(answer, r - l + 1);

        r += 1;
    }

    return answer;
}