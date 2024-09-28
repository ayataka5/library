## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

## 前提

- `S` : 群における集合 $S$ 
- `inv` : 群における逆元を返す関数
- `op` : 群における二項演算
- `e` : 群における単位元

## 関数

- `UnionFindWithPotential(int N)` : サイズ `N` のポテンシャル付き UnionFind を作成する。 $\Theta(N)$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `S distance(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するとき、その距離を返す。ならし $\Theta(\alpha(N))$ 。
- `void unite(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。ならし $\Theta(\alpha(N))$ 。

## *

実装はほぼ noshi91 さんのライブラリ(CC0 ライセンス)をコピーした。ありがとうございます。 ( union by size + path halving )

参考: [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)<sup>[archive.org](https://web.archive.org/web/20240221140608/https://noshi91.hatenablog.com/entry/2018/05/30/191943)</sup> / [Potentialized Union Find](https://noshi91.github.io/Library/data_structure/potentialized_union_find.cpp)<sup>[archive.org](https://web.archive.org/web/20240928160516/https://noshi91.github.io/Library/data_structure/potentialized_union_find.cpp)</sup>