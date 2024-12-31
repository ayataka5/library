---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo/convolution.test.cpp
    title: verify/verify-yosupo/convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/convolution/convolution.md
    document_title: Convolution mod 998244353
    links: []
  bundledCode: "#line 2 \"convolution/convolution.hpp\"\n\n::std::vector<::std::complex<double>>\
    \ DFT(::std::vector<::std::complex<double>> A) {\n    const int N = ::std::size(A);\n\
    \    ::std::vector<::std::complex<double>> B(N);\n    for(int i = 0; i < N; i++)\
    \ {\n        for(int j = 0; j < N; j++) {\n            B[i] += A[j] * ::std::polar(1.0,\
    \ 2 * M_PI * i * j / N);\n        }\n    }\n    return B;\n};\n\n::std::vector<::std::complex<double>>\
    \ IDFT(::std::vector<::std::complex<double>> B){\n    const int N = ::std::size(B);\n\
    \    ::std::vector<::std::complex<double>> A(N);\n    for(int i = 0; i < N; i++)\
    \ {\n        for(int j = 0; j < N; j++){\n            A[i] += B[j] * ::std::polar(1.0,\
    \ -2 * M_PI * i * j / N);\n        }\n    }\n    for(int i = 0; i < N; i++) A[i]\
    \ /= (double)N;\n    return A;\n}\n\n::std::vector<::std::complex<double>> FFT(::std::vector<::std::complex<double>>\
    \ A){\n    const int N = ::std::size(A);\n    if(N == 1) return A;\n    ::std::vector<::std::complex<double>>\
    \ even(N / 2), odd(N / 2);\n    for(int i = 0; i < N / 2; i++){\n        even[i]\
    \ = A[i * 2];\n        odd[i] = A[i * 2 + 1];\n    }\n    even = FFT(even);\n\
    \    odd = FFT(odd);\n    for(int i = 0; i < N / 2; i++){\n        odd[i] *= ::std::polar(1.0,\
    \ 2.0 * M_PI * (double)i / (double)N);\n        A[i] = even[i] + odd[i];\n   \
    \     A[N / 2 + i] = even[i] - odd[i];\n    }\n    return A;\n}\n\n::std::vector<::std::complex<double>>\
    \ IFFT(::std::vector<::std::complex<double>> A){\n    auto ifft = [&](auto f,\
    \ ::std::vector<::std::complex<double>> a) -> ::std::vector<::std::complex<double>>\
    \ {\n        const int n = ::std::size(a);\n        if(n == 1) return a;\n   \
    \     ::std::vector<::std::complex<double>> even(n / 2), odd(n / 2);\n       \
    \ for(int i = 0; i < n / 2; i++){\n            even[i] = a[i * 2];\n         \
    \   odd[i] = a[i * 2 + 1];\n        }\n        even = f(f, even);\n        odd\
    \ = f(f, odd);\n        for(int i = 0; i < n / 2; i++){\n            odd[i] *=\
    \ ::std::polar(1.0, -2.0 * M_PI * (double)i / (double)n);\n            a[i] =\
    \ even[i] + odd[i];\n            a[n / 2 + i] = even[i] - odd[i];\n        }\n\
    \        return a;\n    };\n    const int N = ::std::size(A);\n    A = ifft(ifft,\
    \ A);\n    for(int i = 0; i < N; i++) A[i] /= (double)N;\n    return A;\n}\n\n\
    ::std::vector<::std::complex<double>> convolution_(::std::vector<::std::complex<double>>\
    \ A, ::std::vector<::std::complex<double>> B) {\n    int k = 1;\n    while(k <\
    \ ::std::size(A) + ::std::size(B) - 1) k *= 2;\n    const int N = k;\n    ::std::vector<::std::complex<double>>\
    \ C(N), D(N);\n    for(int i = 0; i < N; i++) {\n        if(i < ::std::size(A))\
    \ C[i] = A[i];\n        else C[i] = ::std::complex<double>(0, 0);\n    }\n   \
    \ for(int i = 0; i < N; i++) {\n        if(i < ::std::size(B)) D[i] = B[i];\n\
    \        else D[i] = ::std::complex<double>(0, 0);\n    }\n    ::std::vector<::std::complex<double>>\
    \ E(FFT(C)), F(FFT(D)), G(N);\n    for(int i = 0; i < N; i++) {\n        G[i]\
    \ = E[i] * F[i];\n    }\n    ::std::vector<::std::complex<double>> H(IFFT(G));\n\
    \    return H;\n}\n\n\nconst long long mod998244353 = 998244353;\nconst int DIVIDE_LIMIT_998244353\
    \ = 23;\n::std::vector<long long> ROOT_998244353{1, 998244352, 911660635, 372528824,\
    \ 929031873, 452798380, 922799308, 781712469, 476477967, 166035806, 258648936,\
    \ 584193783, 63912897, 350007156, 666702199, 968855178, 629671588, 24514907, 996173970,\
    \ 363395222, 565042129, 733596141, 267099868, 15311432};\n::std::vector<long long>\
    \ inv_ROOT_998244353{1, 998244352, 86583718, 509520358, 337190230, 87557064, 609441965,\
    \ 135236158, 304459705, 685443576, 381598368, 335559352, 129292727, 358024708,\
    \ 814576206, 708402881, 283043518, 3707709, 121392023, 704923114, 950391366, 428961804,\
    \ 382752275, 469870224};\n\nlong long ext_gcd(long long a, long long b, long long\
    \ &x, long long &y) {\n    if(b == 0) { x = 1; y = 0; return a; }\n    long long\
    \ q = a/b;\n    long long g = ext_gcd(b, a - q * b, x, y);\n    long long z =\
    \ x - q * y;\n    x = y; y = z;\n    return g;\n};\n\nlong long modinv(long long\
    \ a) {\n    long long x, y;\n    ext_gcd(a, mod998244353, x, y);\n    x %= mod998244353;\n\
    \    if(x < 0) x += mod998244353;\n    return x;\n};\n\n::std::vector<long long>\
    \ NTT(::std::vector<long long> A) {\n    const int N = ::std::size(A);\n    if(N\
    \ == 1) return A;\n    int k = 0, n = N;\n    while(1 < n) { n /= 2; k++; }\n\
    \    ::std::vector<long long> even(N / 2), odd(N / 2);\n    for(int i = 0; i <\
    \ N / 2; i++){\n        even[i] = A[i * 2];\n        odd[i] = A[i * 2 + 1];\n\
    \    }\n    even = NTT(even);\n    odd = NTT(odd);\n    long long zeta(1);\n \
    \   for(int i = 0; i < N / 2; i++){\n        odd[i] *= zeta; odd[i] %= mod998244353;\n\
    \        A[i] = (even[i] + odd[i]) % mod998244353;\n        A[N / 2 + i] = (even[i]\
    \ - odd[i] + mod998244353) % mod998244353;\n        zeta *= ROOT_998244353[k];\
    \ zeta %= mod998244353;\n    }\n    return A;\n}\n\n::std::vector<long long> INTT(::std::vector<long\
    \ long> B){\n    auto ifft = [&](auto f, ::std::vector<long long> b) -> ::std::vector<long\
    \ long> {\n        const int n = ::std::size(b);\n        if(n == 1) return b;\n\
    \        int k = 0, n2 = n;\n        while(1 < n2) { n2 /= 2; k++; }\n       \
    \ ::std::vector<long long> even(n / 2), odd(n / 2);\n        for(int i = 0; i\
    \ < n / 2; i++){\n            even[i] = b[i * 2];\n            odd[i] = b[i *\
    \ 2 + 1];\n        }\n        even = f(f, even);\n        odd = f(f, odd);\n \
    \       long long zeta(1);\n        for(int i = 0; i < n / 2; i++){\n        \
    \    odd[i] *= zeta; odd[i] %= mod998244353;\n            b[i] = (even[i] + odd[i])\
    \ % mod998244353;\n            b[n / 2 + i] = (even[i] - odd[i] + mod998244353)\
    \ % mod998244353;\n            zeta *= inv_ROOT_998244353[k]; zeta %= mod998244353;\n\
    \        }\n        return b;\n    };\n    const int N = ::std::size(B);\n   \
    \ B = ifft(ifft, B);\n    for(int i = 0; i < N; i++) { B[i] *= modinv(N); B[i]\
    \ %= mod998244353; }\n    return B;\n}\n\n::std::vector<long long> convolution(::std::vector<long\
    \ long> A, ::std::vector<long long> B) {\n    int k = 1;\n    while(k < ::std::size(A)\
    \ + ::std::size(B) - 1) k *= 2;\n    const int N = k;\n    ::std::vector<long\
    \ long> C(N, 0LL), D(N, 0LL);\n    for(int i = 0; i < (int)::std::size(A); i++)\
    \ { C[i] = A[i]; }\n    for(int i = 0; i < (int)::std::size(B); i++) { D[i] =\
    \ B[i]; }\n    ::std::vector<long long> E(NTT(C)), F(NTT(D)), G(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        G[i] = E[i] * F[i] % mod998244353;\n    }\n  \
    \  ::std::vector<long long> H(INTT(G));\n    return H;\n}\n\n/**\n * @brief Convolution\
    \ mod 998244353\n * @docs docs/convolution/convolution.md\n */\n"
  code: "#pragma once\n\n::std::vector<::std::complex<double>> DFT(::std::vector<::std::complex<double>>\
    \ A) {\n    const int N = ::std::size(A);\n    ::std::vector<::std::complex<double>>\
    \ B(N);\n    for(int i = 0; i < N; i++) {\n        for(int j = 0; j < N; j++)\
    \ {\n            B[i] += A[j] * ::std::polar(1.0, 2 * M_PI * i * j / N);\n   \
    \     }\n    }\n    return B;\n};\n\n::std::vector<::std::complex<double>> IDFT(::std::vector<::std::complex<double>>\
    \ B){\n    const int N = ::std::size(B);\n    ::std::vector<::std::complex<double>>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        for(int j = 0; j < N; j++){\n\
    \            A[i] += B[j] * ::std::polar(1.0, -2 * M_PI * i * j / N);\n      \
    \  }\n    }\n    for(int i = 0; i < N; i++) A[i] /= (double)N;\n    return A;\n\
    }\n\n::std::vector<::std::complex<double>> FFT(::std::vector<::std::complex<double>>\
    \ A){\n    const int N = ::std::size(A);\n    if(N == 1) return A;\n    ::std::vector<::std::complex<double>>\
    \ even(N / 2), odd(N / 2);\n    for(int i = 0; i < N / 2; i++){\n        even[i]\
    \ = A[i * 2];\n        odd[i] = A[i * 2 + 1];\n    }\n    even = FFT(even);\n\
    \    odd = FFT(odd);\n    for(int i = 0; i < N / 2; i++){\n        odd[i] *= ::std::polar(1.0,\
    \ 2.0 * M_PI * (double)i / (double)N);\n        A[i] = even[i] + odd[i];\n   \
    \     A[N / 2 + i] = even[i] - odd[i];\n    }\n    return A;\n}\n\n::std::vector<::std::complex<double>>\
    \ IFFT(::std::vector<::std::complex<double>> A){\n    auto ifft = [&](auto f,\
    \ ::std::vector<::std::complex<double>> a) -> ::std::vector<::std::complex<double>>\
    \ {\n        const int n = ::std::size(a);\n        if(n == 1) return a;\n   \
    \     ::std::vector<::std::complex<double>> even(n / 2), odd(n / 2);\n       \
    \ for(int i = 0; i < n / 2; i++){\n            even[i] = a[i * 2];\n         \
    \   odd[i] = a[i * 2 + 1];\n        }\n        even = f(f, even);\n        odd\
    \ = f(f, odd);\n        for(int i = 0; i < n / 2; i++){\n            odd[i] *=\
    \ ::std::polar(1.0, -2.0 * M_PI * (double)i / (double)n);\n            a[i] =\
    \ even[i] + odd[i];\n            a[n / 2 + i] = even[i] - odd[i];\n        }\n\
    \        return a;\n    };\n    const int N = ::std::size(A);\n    A = ifft(ifft,\
    \ A);\n    for(int i = 0; i < N; i++) A[i] /= (double)N;\n    return A;\n}\n\n\
    ::std::vector<::std::complex<double>> convolution_(::std::vector<::std::complex<double>>\
    \ A, ::std::vector<::std::complex<double>> B) {\n    int k = 1;\n    while(k <\
    \ ::std::size(A) + ::std::size(B) - 1) k *= 2;\n    const int N = k;\n    ::std::vector<::std::complex<double>>\
    \ C(N), D(N);\n    for(int i = 0; i < N; i++) {\n        if(i < ::std::size(A))\
    \ C[i] = A[i];\n        else C[i] = ::std::complex<double>(0, 0);\n    }\n   \
    \ for(int i = 0; i < N; i++) {\n        if(i < ::std::size(B)) D[i] = B[i];\n\
    \        else D[i] = ::std::complex<double>(0, 0);\n    }\n    ::std::vector<::std::complex<double>>\
    \ E(FFT(C)), F(FFT(D)), G(N);\n    for(int i = 0; i < N; i++) {\n        G[i]\
    \ = E[i] * F[i];\n    }\n    ::std::vector<::std::complex<double>> H(IFFT(G));\n\
    \    return H;\n}\n\n\nconst long long mod998244353 = 998244353;\nconst int DIVIDE_LIMIT_998244353\
    \ = 23;\n::std::vector<long long> ROOT_998244353{1, 998244352, 911660635, 372528824,\
    \ 929031873, 452798380, 922799308, 781712469, 476477967, 166035806, 258648936,\
    \ 584193783, 63912897, 350007156, 666702199, 968855178, 629671588, 24514907, 996173970,\
    \ 363395222, 565042129, 733596141, 267099868, 15311432};\n::std::vector<long long>\
    \ inv_ROOT_998244353{1, 998244352, 86583718, 509520358, 337190230, 87557064, 609441965,\
    \ 135236158, 304459705, 685443576, 381598368, 335559352, 129292727, 358024708,\
    \ 814576206, 708402881, 283043518, 3707709, 121392023, 704923114, 950391366, 428961804,\
    \ 382752275, 469870224};\n\nlong long ext_gcd(long long a, long long b, long long\
    \ &x, long long &y) {\n    if(b == 0) { x = 1; y = 0; return a; }\n    long long\
    \ q = a/b;\n    long long g = ext_gcd(b, a - q * b, x, y);\n    long long z =\
    \ x - q * y;\n    x = y; y = z;\n    return g;\n};\n\nlong long modinv(long long\
    \ a) {\n    long long x, y;\n    ext_gcd(a, mod998244353, x, y);\n    x %= mod998244353;\n\
    \    if(x < 0) x += mod998244353;\n    return x;\n};\n\n::std::vector<long long>\
    \ NTT(::std::vector<long long> A) {\n    const int N = ::std::size(A);\n    if(N\
    \ == 1) return A;\n    int k = 0, n = N;\n    while(1 < n) { n /= 2; k++; }\n\
    \    ::std::vector<long long> even(N / 2), odd(N / 2);\n    for(int i = 0; i <\
    \ N / 2; i++){\n        even[i] = A[i * 2];\n        odd[i] = A[i * 2 + 1];\n\
    \    }\n    even = NTT(even);\n    odd = NTT(odd);\n    long long zeta(1);\n \
    \   for(int i = 0; i < N / 2; i++){\n        odd[i] *= zeta; odd[i] %= mod998244353;\n\
    \        A[i] = (even[i] + odd[i]) % mod998244353;\n        A[N / 2 + i] = (even[i]\
    \ - odd[i] + mod998244353) % mod998244353;\n        zeta *= ROOT_998244353[k];\
    \ zeta %= mod998244353;\n    }\n    return A;\n}\n\n::std::vector<long long> INTT(::std::vector<long\
    \ long> B){\n    auto ifft = [&](auto f, ::std::vector<long long> b) -> ::std::vector<long\
    \ long> {\n        const int n = ::std::size(b);\n        if(n == 1) return b;\n\
    \        int k = 0, n2 = n;\n        while(1 < n2) { n2 /= 2; k++; }\n       \
    \ ::std::vector<long long> even(n / 2), odd(n / 2);\n        for(int i = 0; i\
    \ < n / 2; i++){\n            even[i] = b[i * 2];\n            odd[i] = b[i *\
    \ 2 + 1];\n        }\n        even = f(f, even);\n        odd = f(f, odd);\n \
    \       long long zeta(1);\n        for(int i = 0; i < n / 2; i++){\n        \
    \    odd[i] *= zeta; odd[i] %= mod998244353;\n            b[i] = (even[i] + odd[i])\
    \ % mod998244353;\n            b[n / 2 + i] = (even[i] - odd[i] + mod998244353)\
    \ % mod998244353;\n            zeta *= inv_ROOT_998244353[k]; zeta %= mod998244353;\n\
    \        }\n        return b;\n    };\n    const int N = ::std::size(B);\n   \
    \ B = ifft(ifft, B);\n    for(int i = 0; i < N; i++) { B[i] *= modinv(N); B[i]\
    \ %= mod998244353; }\n    return B;\n}\n\n::std::vector<long long> convolution(::std::vector<long\
    \ long> A, ::std::vector<long long> B) {\n    int k = 1;\n    while(k < ::std::size(A)\
    \ + ::std::size(B) - 1) k *= 2;\n    const int N = k;\n    ::std::vector<long\
    \ long> C(N, 0LL), D(N, 0LL);\n    for(int i = 0; i < (int)::std::size(A); i++)\
    \ { C[i] = A[i]; }\n    for(int i = 0; i < (int)::std::size(B); i++) { D[i] =\
    \ B[i]; }\n    ::std::vector<long long> E(NTT(C)), F(NTT(D)), G(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        G[i] = E[i] * F[i] % mod998244353;\n    }\n  \
    \  ::std::vector<long long> H(INTT(G));\n    return H;\n}\n\n/**\n * @brief Convolution\
    \ mod 998244353\n * @docs docs/convolution/convolution.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: convolution/convolution.hpp
  requiredBy: []
  timestamp: '2024-12-31 21:04:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo/convolution.test.cpp
documentation_of: convolution/convolution.hpp
layout: document
redirect_from:
- /library/convolution/convolution.hpp
- /library/convolution/convolution.hpp.html
title: Convolution mod 998244353
---
## 概要

Cooley-Tukey FFT(fast Fourier transform, 高速フーリエ変換) とその逆変換と NTT(Numeric Theory Translation, 数論変換) を用いてふたつの数列の畳み込みを高速に行う。

- `convolution(vector<complex<double>> A, vector<complex<double>> B)` : ふたつの数列 `A`, `B` の畳み込みの結果の数列 `C` を返す。 `C` のサイズ `N` は $|A| + |B| - 1$ を 2 冪に切り上げたもの。

また、実装されている以下の関数らに直接アクセスすることは推奨されない。
- `FFT(int N)` : サイズ `N` の数列を FFT する。精度は `double` に依存している。この時、 `N` は 2 冪でなければならない。計算量は $\Theta(N\ \mathrm{log}\ N)$ となる。
- `IFFT(int N)` : サイズ `N` の数列を IFFT(inverse fast Fourier transform) する。精度は `double` に依存している。この時、 `N` は 2 冪でなければならない。計算量は $\Theta(N\ \mathrm{log}\ N)$ となる。
- `DFT(int N)` : サイズ `N` の数列を DFT(discrete Fourier transform) する。精度は `double` に依存している。この時、 `N` は 2 冪でなくてもよい。計算量は $\Theta(N^2)$ となる。
- `IDFT(int N)` : サイズ `N` の数列を IDFT(inverse discrete Fourier transform) する。精度は `double` に依存している。この時、 `N` は 2 冪でなくてもよい。計算量は $\Theta(N^2)$ となる。

## *

参考: [【競プロer向け】FFT を習得しよう！](https://trap.jp/post/1386/)<sup>[archive.org](https://web.archive.org/web/20241231061337/https://trap.jp/post/1386/)</sup>