## 概要

Cooley-Tukey FFT(fast Fourier transform, 高速フーリエ変換) とその逆変換と NTT(Numeric Theory Translation, 数論変換) を用いてふたつの数列の畳み込みを高速に行う。

- `convolution(vector<long long> A, vector<long long> B)` : ふたつの数列 `A`, `B` の畳み込みの結果の数列 `C` を返す。 `C` のサイズ `N` は $|A| + |B| - 1$ を 2 冪に切り上げたもの。また、 mod998244353 の結果を返す。

## *

任意mod, 非再帰化 などまだ最適化、高速化の余地はある。

参考:

[【競プロer向け】FFT を習得しよう！](https://trap.jp/post/1386/)<sup>[archive.org](https://web.archive.org/web/20241231061337/https://trap.jp/post/1386/)</sup>

[NTT(数論変換)のやさしい解説](https://sen-comp.hatenablog.com/entry/2021/02/06/180310)<sup>[archive.org](https://web.archive.org/web/20241231235330/https://sen-comp.hatenablog.com/entry/2021/02/06/180310)</sup>