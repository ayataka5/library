---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo/unionfind_with_potential.test.cpp
    title: verify/verify-yosupo/unionfind_with_potential.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/unionfind_with_potential.md
    document_title: UnionFind with Potential
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind_with_potential.hpp\"\n\ntemplate<class\
    \ S, auto inv, auto op, auto e> struct UnionFindWithPotential {\n\nprotected:\n\
    \    ::std::vector<int> parent;\n    ::std::vector<int> v_size;\n    ::std::vector<S>\
    \ v_potential;\n\n    void compress(const int v) {\n        if(parent[v] != v)\
    \ {\n            compress(parent[v]);\n            v_potential[v] = op(v_potential[parent[v]],\
    \ v_potential[v]);\n            parent[v] = parent[parent[v]];\n        }else\
    \ { return; }\n    }\n\npublic:\n    UnionFindWithPotential(const int n) : parent(n,\
    \ 0), v_size(n, 1), v_potential(n, e()) {\n        for(int i = 0; i < n; i++)\
    \ parent[i] = i;\n    }\n\n    int size() const { return ::std::size(parent);\
    \ }\n\n    int size(const int x) {\n        assert(x < size());\n        return\
    \ v_size[find(x)];\n    }\n\n    int find(const int x) {\n        assert(x < size());\n\
    \        compress(x);\n        return parent[x];\n    }\n\n    bool same(const\
    \ int x, const int y) {\n        assert(x < size()); assert(y < size());\n   \
    \     return (find(x) == find(y));\n    }\n\n    S potential(const int x) {\n\
    \        assert(x < size());\n        compress(x);\n        return v_potential[x];\n\
    \    }\n\n    S distance(const int x, const int y) {\n        assert(x < size());\
    \ assert(y < size());\n        return op(inv(potential(x)), potential(y));\n \
    \   }\n\n    void unite(int x, int y, S z) {\n        assert(x < size()); assert(y\
    \ < size());\n        assert(!same(x, y));\n\n        if(size(x) < size(y)) {\n\
    \            z = inv(z);\n            ::std::swap(x, y);\n        }\n\n      \
    \  z = op(op(potential(x), z), inv(potential(y)));\n        x = find(x);\n   \
    \     y = find(y);\n        v_size[x] += v_size[y];\n        parent[y] = x;\n\
    \        v_potential[y] = z;\n    }\n};\n\n/**\n * @brief UnionFind with Potential\n\
    \ * @docs docs/data-structure/unionfind_with_potential.md\n */\n"
  code: "#pragma once\n\ntemplate<class S, auto inv, auto op, auto e> struct UnionFindWithPotential\
    \ {\n\nprotected:\n    ::std::vector<int> parent;\n    ::std::vector<int> v_size;\n\
    \    ::std::vector<S> v_potential;\n\n    void compress(const int v) {\n     \
    \   if(parent[v] != v) {\n            compress(parent[v]);\n            v_potential[v]\
    \ = op(v_potential[parent[v]], v_potential[v]);\n            parent[v] = parent[parent[v]];\n\
    \        }else { return; }\n    }\n\npublic:\n    UnionFindWithPotential(const\
    \ int n) : parent(n, 0), v_size(n, 1), v_potential(n, e()) {\n        for(int\
    \ i = 0; i < n; i++) parent[i] = i;\n    }\n\n    int size() const { return ::std::size(parent);\
    \ }\n\n    int size(const int x) {\n        assert(x < size());\n        return\
    \ v_size[find(x)];\n    }\n\n    int find(const int x) {\n        assert(x < size());\n\
    \        compress(x);\n        return parent[x];\n    }\n\n    bool same(const\
    \ int x, const int y) {\n        assert(x < size()); assert(y < size());\n   \
    \     return (find(x) == find(y));\n    }\n\n    S potential(const int x) {\n\
    \        assert(x < size());\n        compress(x);\n        return v_potential[x];\n\
    \    }\n\n    S distance(const int x, const int y) {\n        assert(x < size());\
    \ assert(y < size());\n        return op(inv(potential(x)), potential(y));\n \
    \   }\n\n    void unite(int x, int y, S z) {\n        assert(x < size()); assert(y\
    \ < size());\n        assert(!same(x, y));\n\n        if(size(x) < size(y)) {\n\
    \            z = inv(z);\n            ::std::swap(x, y);\n        }\n\n      \
    \  z = op(op(potential(x), z), inv(potential(y)));\n        x = find(x);\n   \
    \     y = find(y);\n        v_size[x] += v_size[y];\n        parent[y] = x;\n\
    \        v_potential[y] = z;\n    }\n};\n\n/**\n * @brief UnionFind with Potential\n\
    \ * @docs docs/data-structure/unionfind_with_potential.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind_with_potential.hpp
  requiredBy: []
  timestamp: '2024-09-30 14:54:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo/unionfind_with_potential.test.cpp
documentation_of: data-structure/unionfind_with_potential.hpp
layout: document
redirect_from:
- /library/data-structure/unionfind_with_potential.hpp
- /library/data-structure/unionfind_with_potential.hpp.html
title: UnionFind with Potential
---
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