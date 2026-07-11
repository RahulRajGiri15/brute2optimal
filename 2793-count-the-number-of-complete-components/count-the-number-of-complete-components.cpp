class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (size[u] < size[v])
            swap(u, v);

        parent[v] = u;
        size[u] += size[v];
    }

    int getSize(int u) {
        return size[find(u)];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU d(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {
            d.unite(e[0], e[1]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[d.find(i)].push_back(i);

        int ans = mp.size();

        for (auto &it : mp) {
            int sz = d.getSize(it.first);

            bool complete = true;

            for (int node : it.second) {
                if (degree[node] != sz - 1) {
                    complete = false;
                    break;
                }
            }

            if (!complete)
                ans--;
        }

        return ans;
    }
};