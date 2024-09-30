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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"verify/verify-yosupo/unionfind_with_potential.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data-structure/unionfind_with_potential.hpp\"\
    \n\ntemplate<class S, S (*op)(S, S), S (*e)(), S (*inv)(S)> struct UnionFindWithPotential\
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
    \ * @docs docs/data-structure/unionfind_with_potential.md\n */\n#line 7 \"verify/verify-yosupo/unionfind_with_potential.test.cpp\"\
    \n\nconst long long mod = 998244353;\n\nlong long op(const long long x, const\
    \ long long y) { return (x+y)%mod; }\nlong long e() { return 0LL; }\nlong long\
    \ inv(const long long x) { return (mod-x)%mod; }\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    UnionFindWithPotential<long long, op, e, inv> UF(N);\n\
    \    while(Q--) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n \
    \           int u, v;\n            cin >> u >> v;\n            long long x;\n\
    \            cin >> x;\n            if(!UF.same(u, v)) {\n                UF.unite(u,\
    \ v, x);\n                cout << 1 << endl;\n            }else {\n          \
    \      cout << (UF.distance(u, v) == x) << endl;\n            }\n        }else\
    \ {\n            int u, v;\n            cin >> u >> v;\n            if(UF.same(u,\
    \ v)) {\n                cout << UF.distance(u, v) << endl;\n            }else\
    \ {\n                cout << -1 << endl;\n            }\n        }\n    }\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data-structure/unionfind_with_potential.hpp\"\
    \n\nconst long long mod = 998244353;\n\nlong long op(const long long x, const\
    \ long long y) { return (x+y)%mod; }\nlong long e() { return 0LL; }\nlong long\
    \ inv(const long long x) { return (mod-x)%mod; }\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    UnionFindWithPotential<long long, op, e, inv> UF(N);\n\
    \    while(Q--) {\n        int t;\n        cin >> t;\n        if(t == 0) {\n \
    \           int u, v;\n            cin >> u >> v;\n            long long x;\n\
    \            cin >> x;\n            if(!UF.same(u, v)) {\n                UF.unite(u,\
    \ v, x);\n                cout << 1 << endl;\n            }else {\n          \
    \      cout << (UF.distance(u, v) == x) << endl;\n            }\n        }else\
    \ {\n            int u, v;\n            cin >> u >> v;\n            if(UF.same(u,\
    \ v)) {\n                cout << UF.distance(u, v) << endl;\n            }else\
    \ {\n                cout << -1 << endl;\n            }\n        }\n    }\n  \
    \  return 0;\n}"
  dependsOn:
  - data-structure/unionfind_with_potential.hpp
  isVerificationFile: true
  path: verify/verify-yosupo/unionfind_with_potential.test.cpp
  requiredBy: []
  timestamp: '2024-09-30 15:33:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo/unionfind_with_potential.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo/unionfind_with_potential.test.cpp
- /verify/verify/verify-yosupo/unionfind_with_potential.test.cpp.html
title: verify/verify-yosupo/unionfind_with_potential.test.cpp
---
