#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>

#include "../../convolution/convolution.hpp"

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector A(N, 0LL), B(M, 0LL);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    vector<long long> P(convolution(A, B));
    for(int i = 0; i < (int)size(P); i++) {
        cout << P[i] << " \n"[i==(int)size(P)-1];
    }
    return 0;
}