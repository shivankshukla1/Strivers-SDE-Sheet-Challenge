#include <bits/stdc++.h> 
class disjoinedset{
    vector<int> par, rank;
    public:
    disjoinedset(int n){
        par.resize(n);
        rank.resize(n, 0);
        for(int i =0 ; i < n; i ++){
            par[i] = i;
        }
    }

    int findpar(int n){
        if(par[n] == n){
            return n;
        }
        par[n] = findpar(par[n]);
    }

    void merge(int a, int b){
        a = findpar(a);
        b = findpar(b);

        if(a == b){
            return;
        }
        if(rank[a] < rank[b]){
            par[a] = b;
        }else if(rank[a] > rank[b]){
            par[b] = a;
        }else{
            par[a] = b;
            rank[b] += 1;
        }
    }
};

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second < b.second;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    disjoinedset ds(n + 1);
    vector<pair<pair<int, int>, int>> answer;
    sort(g.begin(), g.end(), cmp);

    for(auto i : g){
        int a = i.first.first;
        int b = i.first.second;
        if(ds.findpar(a) == ds.findpar(b)){
            continue;
        }else{
            answer.push_back(i);
            ds.merge(a, b);
        }
    }


    return answer;
}
