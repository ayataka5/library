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
    _deprecated_at_docs: docs/data-struct/unionfind/unionfind.md
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
    \ * @brief UnionFind\n * @docs docs/data-struct/unionfind/unionfind.md\n */\n"
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
    \ UnionFind\n * @docs docs/data-struct/unionfind/unionfind.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind.hpp
  requiredBy: []
  timestamp: '2024-02-21 23:12:11+09:00'
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
