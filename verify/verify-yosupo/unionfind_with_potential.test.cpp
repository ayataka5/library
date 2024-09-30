#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include <bits/stdc++.h>
using namespace std;

#include "../../data-structure/unionfind_with_potential.hpp"

const long long mod = 998244353;

long long op(const long long x, const long long y) { return (x+y)%mod; }
long long e() { return 0LL; }
long long inv(const long long x) { return (mod-x)%mod; }

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFindWithPotential<long long, op, e, inv> UF(N);
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