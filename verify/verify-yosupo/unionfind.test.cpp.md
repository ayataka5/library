---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/verify-yosupo/unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"data-structure/unionfind.hpp\"\n\nstruct UnionFind\
    \ {\n\nprotected:\n    ::std::vector<int> parent;\n    ::std::vector<int> v_size;\n\
    \npublic:\n    UnionFind(int N) : parent(N, 0), v_size(N, 1) {\n        for(int\
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
    \ * @brief UnionFind\n * @docs docs/data-structure/unionfind.md\n */\n#line 7\
    \ \"verify/verify-yosupo/unionfind.test.cpp\"\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    UnionFind uf(N);\n    while(Q--) {\n        int t, u,\
    \ v;\n        cin >> t >> u >> v;\n        if(t == 0) uf.unite(u, v);\n      \
    \  else cout << (uf.same(u, v)) << endl;\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data-structure/unionfind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  while(Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if(t\
    \ == 0) uf.unite(u, v);\n        else cout << (uf.same(u, v)) << endl;\n    }\n\
    \    return 0;\n}"
  dependsOn:
  - data-structure/unionfind.hpp
  isVerificationFile: true
  path: verify/verify-yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 01:40:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo/unionfind.test.cpp
- /verify/verify/verify-yosupo/unionfind.test.cpp.html
title: verify/verify-yosupo/unionfind.test.cpp
---
