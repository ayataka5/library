## 概要

通常の [UnionFind](unionfind.md) に加え、ポテンシャルを扱えます。なお、対象となる代数的構造における、単位元と逆元を要求します。

## 引数

- `S` : 対象となるものの集合。
- `op` : 二項演算 $S \times S \rightarrow S$ (ここでは記号として $\star$ と記す)。ここで結合法則、 $\forall x, y, z; \, x \star (y \star z) = (x \star y) \star z$ を満たす。
- `e` : 単位元 $e \in S$ 。$\forall x; \, x \star e = e \star x = x$ を満たす。
- `inv`: 逆元 $S \rightarrow S$ (ここでは記号として $x^{-1}$ と記す)。$\forall x; \, x \star x^{-1} = x^{-1} \star x = e$ を満たす。

## 関数

- `UnionFindWithPotential(int N)` : サイズ `N` のポテンシャル付き UnionFind を作成する。 $\Theta(N)$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `S potantial(int x)` : 要素 `x` のポテンシャルを返す。ならし $\Theta(\alpha(N))$ 。
- `S distance(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するとき、その距離を返す。ならし $\Theta(\alpha(N))$ 。
- `void unite(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。ならし $\Theta(\alpha(N))$ 。

(ここで $\alpha(N)$ はアッカーマン関数の逆関数。)

## *

実装はほぼ noshi91 さんのライブラリ(CC0 ライセンス)をコピーした。ありがとうございます。 ( union by size + path halving )

参考: [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)<sup>[archive.org](https://web.archive.org/web/20240221140608/https://noshi91.hatenablog.com/entry/2018/05/30/191943)</sup> / [Potentialized Union Find](https://noshi91.github.io/Library/data_structure/potentialized_union_find.cpp)<sup>[archive.org](https://web.archive.org/web/20240928160516/https://noshi91.github.io/Library/data_structure/potentialized_union_find.cpp)</sup>