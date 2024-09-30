#pragma once

template<class S, auto inv, auto op, auto e> struct UnionFindWithPotential {

protected:
    ::std::vector<int> parent;
    ::std::vector<int> v_size;
    ::std::vector<S> v_potential;

    void compress(const int v) {
        if(parent[v] != v) {
            compress(parent[v]);
            v_potential[v] = op(v_potential[parent[v]], v_potential[v]);
            parent[v] = parent[parent[v]];
        }else { return; }
    }

public:
    UnionFindWithPotential(const int n) : parent(n, 0), v_size(n, 1), v_potential(n, e()) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int size() const { return ::std::size(parent); }

    int find(const int x) {
        assert(x < size());
        compress(x);
        return parent[x];
    }

    S potential(const int x) {
        assert(x < size());
        compress(x);
        return v_potential[x];
    }

    bool same(const int x, const int y) {
        assert(x < size()); assert(y < size());
        return (find(x) == find(y));
    }

    S distance(const int x, const int y) {
        assert(x < size()); assert(y < size());
        return op(inv(potential(x)), potential(y));
    }

    int size(const int x) {
        assert(x < size());
        return v_size[find(x)];
    }

    void unite(int x, int y, S z) {
        assert(x < size()); assert(y < size());
        assert(!same(x, y));

        if(size(x) < size(y)) {
            z = inv(z);
            ::std::swap(x, y);
        }

        z = op(op(potential(x), z), inv(potential(y)));
        x = find(x);
        y = find(y);
        v_size[x] += v_size[y];
        parent[y] = x;
        v_potential[y] = z;
    }
};

/**
 * @brief UnionFind with Potential
 * @docs docs/data-structure/unionfind_with_potential.md
 */