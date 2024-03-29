#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"

#include <bits/stdc++.h>

#include "../../data-structure/unionfind.hpp"

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    while(Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) uf.unite(u, v);
        else cout << (uf.same(u, v) ? 1 : 0) << endl;
    }
    return 0;
}