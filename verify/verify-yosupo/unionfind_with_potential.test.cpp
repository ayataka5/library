#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include <bits/stdc++.h>
using namespace std;

#include "../../data-structure/unionfind_with_potential.hpp"

const long long mod = 998244353;

int main() {
    auto inv = [](const long long x) { return (mod-x)%mod; };
    auto op = [](const long long x, const long long y) { return (x+y)%mod; };
    auto e = []() { return 0LL; };

    int N, Q;
    cin >> N >> Q;
    UnionFindWithPotential<long long, inv, op, e> UF(N);
    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int u, v;
            cin >> u >> v;
            long long x;
            cin >> x;
            if(!UF.same(u, v)) {
                UF.unite(u, v, x);
                cout << 1 << endl;
            }else {
                cout << (UF.distance(u, v) == x) << endl;
            }
        }else {
            int u, v;
            cin >> u >> v;
            if(UF.same(u, v)) {
                cout << UF.distance(u, v) << endl;
            }else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}