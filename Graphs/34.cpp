// Disjoint Set Union Data Structure (DSU)
 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
using namespace std;

class DisJointSet
{
public:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindUpar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        return parent[node] = FindUpar(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }
        if (rank[uu] < rank[uv])
        {
            parent[uu] = uv;
        }
        else if (rank[uu] > rank[uv])
        {
            parent[uv] = uu;
        }
        else
        {
            parent[uv] = uu;
            rank[uu]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int uu = FindUpar(u);
        int uv = FindUpar(v);

        if (uu == uv)
        {
            return;
        }

        if (size[uu] < size[uv])
        {
            parent[uu] = uv;
            size[uv] += size[uu];
        }
        else
        {
            parent[uv] = uu;
            size[uu] += size[uv];
        }
    }
};



class DSU
{
public:
    vector<int> par;
    vector<int> rank;
    vector<int> size;

    DSU(int n)
    {
        par.resize(n);
        for(int i=0; i<n; i++)
        {
            par[i] = i;
        }
        rank.resize(n,0);
        size.resize(n,1);
    }

    int FindUpar(int node)
    {
        if(par[node]==node)
        {
            return node;
        }

        return par[node] =  FindUpar(par[node]);
    }

    void UnionByRank(int a, int b)
    {
        int ulpa = FindUpar(a);
        int ulpb = FindUpar(b);

        if(rank[ulpa]==rank[ulpb])
        {
            rank[ulpa]++;
            par[ulpb] = ulpa;
        }
        else if(rank[ulpa]>rank[ulpb])
        {
            par[ulpb] = ulpa;
        }
        else 
        {
            par[ulpa] = ulpb;
        }
    }

    void UnionBySize(int a, int b)
    {
        int ulpa = FindUpar(a);
        int ulpb = FindUpar(b);

        if(size[ulpa]<size[ulpb])
        {
            size[ulpb]+= size[ulpa];
            par[ulpa] = ulpb;
        }
        else 
        {
            size[ulpa]+= size[ulpb];
            par[ulpb] = ulpa;
        }
    }
};