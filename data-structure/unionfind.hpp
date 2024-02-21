#pragma once

struct UnionFind {

protected:
    ::std::vector<int> parent;
    ::std::vector<int> v_size;

public:
    UnionFind(int N) : parent(N, 0), v_size(N, 1) {
        for(int i = 0; i < N; i++) parent[i] = i;
    }

    int size() const { return ::std::size(parent); }

    int find(int x) {
        assert(x < size());
        while(parent[x] != x) {
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }

    bool same(const int x, const int y) {
        assert(x < size()), assert(y < size());
        return (find(x) == find(y));
    }

    int size(const int x) {
        assert(x < size());
        return v_size[find(x)];
    }

    ::std::pair<int, int> unite(int x, int y) {
        assert(x < size()), assert(y < size());
        x = find(x), y = find(y);
        if(x != y) {
            if(v_size[x] < v_size[y]) {
                ::std::swap(x, y);
            }
            v_size[x] += v_size[y];
            parent[y] = x;
        }
        return ::std::make_pair(x, y);
    }
};

/**
 * @brief UnionFind
 * @docs docs/data-structure/unionfind.md
 */