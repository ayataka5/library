#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include <bits/stdc++.h>

#include "../../data-structure/unionfind_with_potential.hpp"

using namespace std;

long long op(const long long x, const long long y) { return x+y; }
long long e() { return 0LL; }
long long inv(const long long x) { return -x; }

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFindWithPotential<long long, op, e, inv> UF(N);
    while(Q--) {
        int q; cin >> q;
        if(q == 0) {
            int x, y; long long z;
            cin >> x >> y >> z;
            if(!UF.same(x, y)) {
                UF.unite(x, y, z);
            }
        }else {
            int x, y;
            cin >> x >> y;
            if(UF.same(x, y)) {
                cout << UF.distance(x, y) << endl;
            }else {
                cout << '?' << endl;
            }
        }
    }
}