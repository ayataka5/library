---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj/aoj-dsl-1-a.test.cpp
    title: verify/verify-aoj/aoj-dsl-1-a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/unionfind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind.hpp\"\n\nstruct UnionFind {\n\n\
    protected:\n    ::std::vector<int> parent;\n    ::std::vector<int> v_size;\n\n\
    public:\n    UnionFind(int N) : parent(N, 0), v_size(N, 1) {\n        for(int\
    \ i = 0; i < N; i++) parent[i] = i;\n    }\n\n    int size() const { return ::std::size(parent);\
    \ }\n\n    int find(int x) {\n        assert(x < size());\n        while(parent[x]\
    \ != x) {\n            x = parent[x] = parent[parent[x]];\n        }\n       \
    \ return x;\n    }\n\n    bool same(const int x, const int y) {\n        assert(x\
    \ < size()), assert(y < size());\n        return (find(x) == find(y));\n    }\n\
    \n    int size(const int x) {\n        assert(x < size());\n        return v_size[find(x)];\n\
    \    }\n\n    ::std::pair<int, int> unite(int x, int y) {\n        assert(x <\
    \ size()), assert(y < size());\n        x = find(x), y = find(y);\n        if(x\
    \ != y) {\n            if(v_size[x] < v_size[y]) {\n                ::std::swap(x,\
    \ y);\n            }\n            v_size[x] += v_size[y];\n            parent[y]\
    \ = x;\n        }\n        return ::std::make_pair(x, y);\n    }\n};\n\n/**\n\
    \ * @brief UnionFind\n * @docs docs/data-structure/unionfind.md\n */\n"
  code: "#pragma once\n\nstruct UnionFind {\n\nprotected:\n    ::std::vector<int>\
    \ parent;\n    ::std::vector<int> v_size;\n\npublic:\n    UnionFind(int N) : parent(N,\
    \ 0), v_size(N, 1) {\n        for(int i = 0; i < N; i++) parent[i] = i;\n    }\n\
    \n    int size() const { return ::std::size(parent); }\n\n    int find(int x)\
    \ {\n        assert(x < size());\n        while(parent[x] != x) {\n          \
    \  x = parent[x] = parent[parent[x]];\n        }\n        return x;\n    }\n\n\
    \    bool same(const int x, const int y) {\n        assert(x < size()), assert(y\
    \ < size());\n        return (find(x) == find(y));\n    }\n\n    int size(const\
    \ int x) {\n        assert(x < size());\n        return v_size[find(x)];\n   \
    \ }\n\n    ::std::pair<int, int> unite(int x, int y) {\n        assert(x < size()),\
    \ assert(y < size());\n        x = find(x), y = find(y);\n        if(x != y) {\n\
    \            if(v_size[x] < v_size[y]) {\n                ::std::swap(x, y);\n\
    \            }\n            v_size[x] += v_size[y];\n            parent[y] = x;\n\
    \        }\n        return ::std::make_pair(x, y);\n    }\n};\n\n/**\n * @brief\
    \ UnionFind\n * @docs docs/data-structure/unionfind.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind.hpp
  requiredBy: []
  timestamp: '2024-02-21 23:31:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj/aoj-dsl-1-a.test.cpp
documentation_of: data-structure/unionfind.hpp
layout: document
redirect_from:
- /library/data-structure/unionfind.hpp
- /library/data-structure/unionfind.hpp.html
title: UnionFind
---
## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

- `UnionFind(int N)` : サイズ `N` の UnionFind を作成する。 $\Theta(N)$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `pair<int, int> unite(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。併合後の根とそうでない方の pair を返す。ならし $\Theta(\alpha(N))$ 。

## *

実装は noshi91 さんのものに寄せた。 ( union by size + path halving )

参考: [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)<sup>[archive.org](https://web.archive.org/web/20240221140608/https://noshi91.hatenablog.com/entry/2018/05/30/191943)</sup>