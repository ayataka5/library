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