---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind_with_potential.hpp
    title: UnionFind with Potential
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"verify/verify-aoj/aoj-dsl-1-b.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"data-structure/unionfind_with_potential.hpp\"\n\
    \ntemplate<class S, S (*op)(S, S), S (*e)(), S (*inv)(S)> struct UnionFindWithPotential\
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
    \ * @docs docs/data-structure/unionfind_with_potential.md\n */\n#line 6 \"verify/verify-aoj/aoj-dsl-1-b.test.cpp\"\
    \n\nusing namespace std;\n\nlong long op(const long long x, const long long y)\
    \ { return x+y; }\nlong long e() { return 0LL; }\nlong long inv(const long long\
    \ x) { return -x; }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFindWithPotential<long\
    \ long, op, e, inv> UF(N);\n    while(Q--) {\n        int q; cin >> q;\n     \
    \   if(q == 0) {\n            int x, y; long long z;\n            cin >> x >>\
    \ y >> z;\n            if(!UF.same(x, y)) {\n                UF.unite(x, y, z);\n\
    \            }\n        }else {\n            int x, y;\n            cin >> x >>\
    \ y;\n            if(UF.same(x, y)) {\n                cout << UF.distance(x,\
    \ y) << endl;\n            }else {\n                cout << '?' << endl;\n   \
    \         }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/unionfind_with_potential.hpp\"\
    \n\nusing namespace std;\n\nlong long op(const long long x, const long long y)\
    \ { return x+y; }\nlong long e() { return 0LL; }\nlong long inv(const long long\
    \ x) { return -x; }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFindWithPotential<long\
    \ long, op, e, inv> UF(N);\n    while(Q--) {\n        int q; cin >> q;\n     \
    \   if(q == 0) {\n            int x, y; long long z;\n            cin >> x >>\
    \ y >> z;\n            if(!UF.same(x, y)) {\n                UF.unite(x, y, z);\n\
    \            }\n        }else {\n            int x, y;\n            cin >> x >>\
    \ y;\n            if(UF.same(x, y)) {\n                cout << UF.distance(x,\
    \ y) << endl;\n            }else {\n                cout << '?' << endl;\n   \
    \         }\n        }\n    }\n}"
  dependsOn:
  - data-structure/unionfind_with_potential.hpp
  isVerificationFile: true
  path: verify/verify-aoj/aoj-dsl-1-b.test.cpp
  requiredBy: []
  timestamp: '2024-09-30 15:33:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj/aoj-dsl-1-b.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj/aoj-dsl-1-b.test.cpp
- /verify/verify/verify-aoj/aoj-dsl-1-b.test.cpp.html
title: verify/verify-aoj/aoj-dsl-1-b.test.cpp
---
