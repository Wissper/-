#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    //连通分支数
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        //让更小的集加入更大的集
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = find(x);
        y = find(y);
        return x == y;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int num = connections.size();
        if(num < n-1) return -1;
        UnionFind uf(n);
        for(int i=0; i<num; i++){
            uf.unite(connections[i][0], connections[i][1]);
        }
        return uf.setCount - 1;
    }
};
