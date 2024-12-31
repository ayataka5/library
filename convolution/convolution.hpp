#pragma once

::std::vector<::std::complex<double>> DFT(::std::vector<::std::complex<double>> A) {
    const int N = ::std::size(A);
    ::std::vector<::std::complex<double>> B(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            B[i] += A[j] * ::std::polar(1.0, 2 * M_PI * i * j / N);
        }
    }
    return B;
};

::std::vector<::std::complex<double>> IDFT(::std::vector<::std::complex<double>> B){
    const int N = ::std::size(B);
    ::std::vector<::std::complex<double>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            A[i] += B[j] * ::std::polar(1.0, -2 * M_PI * i * j / N);
        }
    }
    for(int i = 0; i < N; i++) A[i] /= (double)N;
    return A;
}

::std::vector<::std::complex<double>> FFT(::std::vector<::std::complex<double>> A){
    const int N = ::std::size(A);
    if(N == 1) return A;
    ::std::vector<::std::complex<double>> even(N / 2), odd(N / 2);
    for(int i = 0; i < N / 2; i++){
        even[i] = A[i * 2];
        odd[i] = A[i * 2 + 1];
    }
    even = FFT(even);
    odd = FFT(odd);
    for(int i = 0; i < N / 2; i++){
        odd[i] *= ::std::polar(1.0, 2.0 * M_PI * (double)i / (double)N);
        A[i] = even[i] + odd[i];
        A[N / 2 + i] = even[i] - odd[i];
    }
    return A;
}

::std::vector<::std::complex<double>> IFFT(::std::vector<::std::complex<double>> A){
    auto ifft = [&](auto f, ::std::vector<::std::complex<double>> a) -> ::std::vector<::std::complex<double>> {
        const int n = ::std::size(a);
        if(n == 1) return a;
        ::std::vector<::std::complex<double>> even(n / 2), odd(n / 2);
        for(int i = 0; i < n / 2; i++){
            even[i] = a[i * 2];
            odd[i] = a[i * 2 + 1];
        }
        even = f(f, even);
        odd = f(f, odd);
        for(int i = 0; i < n / 2; i++){
            odd[i] *= ::std::polar(1.0, -2.0 * M_PI * (double)i / (double)n);
            a[i] = even[i] + odd[i];
            a[n / 2 + i] = even[i] - odd[i];
        }
        return a;
    };
    const int N = ::std::size(A);
    A = ifft(ifft, A);
    for(int i = 0; i < N; i++) A[i] /= (double)N;
    return A;
}

::std::vector<::std::complex<double>> convolution_(::std::vector<::std::complex<double>> A, ::std::vector<::std::complex<double>> B) {
    int k = 1;
    while(k < ::std::size(A) + ::std::size(B) - 1) k *= 2;
    const int N = k;
    ::std::vector<::std::complex<double>> C(N), D(N);
    for(int i = 0; i < N; i++) {
        if(i < ::std::size(A)) C[i] = A[i];
        else C[i] = ::std::complex<double>(0, 0);
    }
    for(int i = 0; i < N; i++) {
        if(i < ::std::size(B)) D[i] = B[i];
        else D[i] = ::std::complex<double>(0, 0);
    }
    ::std::vector<::std::complex<double>> E(FFT(C)), F(FFT(D)), G(N);
    for(int i = 0; i < N; i++) {
        G[i] = E[i] * F[i];
    }
    ::std::vector<::std::complex<double>> H(IFFT(G));
    return H;
}


const long long mod998244353 = 998244353;
const int DIVIDE_LIMIT_998244353 = 23;
::std::vector<long long> ROOT_998244353{1, 998244352, 911660635, 372528824, 929031873, 452798380, 922799308, 781712469, 476477967, 166035806, 258648936, 584193783, 63912897, 350007156, 666702199, 968855178, 629671588, 24514907, 996173970, 363395222, 565042129, 733596141, 267099868, 15311432};
::std::vector<long long> inv_ROOT_998244353{1, 998244352, 86583718, 509520358, 337190230, 87557064, 609441965, 135236158, 304459705, 685443576, 381598368, 335559352, 129292727, 358024708, 814576206, 708402881, 283043518, 3707709, 121392023, 704923114, 950391366, 428961804, 382752275, 469870224};

long long ext_gcd(long long a, long long b, long long &x, long long &y) {
    if(b == 0) { x = 1; y = 0; return a; }
    long long q = a/b;
    long long g = ext_gcd(b, a - q * b, x, y);
    long long z = x - q * y;
    x = y; y = z;
    return g;
};

long long modinv(long long a) {
    long long x, y;
    ext_gcd(a, mod998244353, x, y);
    x %= mod998244353;
    if(x < 0) x += mod998244353;
    return x;
};

::std::vector<long long> NTT(::std::vector<long long> A) {
    const int N = ::std::size(A);
    if(N == 1) return A;
    int k = 0, n = N;
    while(1 < n) { n /= 2; k++; }
    ::std::vector<long long> even(N / 2), odd(N / 2);
    for(int i = 0; i < N / 2; i++){
        even[i] = A[i * 2];
        odd[i] = A[i * 2 + 1];
    }
    even = NTT(even);
    odd = NTT(odd);
    long long zeta(1);
    for(int i = 0; i < N / 2; i++){
        odd[i] *= zeta; odd[i] %= mod998244353;
        A[i] = (even[i] + odd[i]) % mod998244353;
        A[N / 2 + i] = (even[i] - odd[i] + mod998244353) % mod998244353;
        zeta *= ROOT_998244353[k]; zeta %= mod998244353;
    }
    return A;
}

::std::vector<long long> INTT(::std::vector<long long> B){
    auto ifft = [&](auto f, ::std::vector<long long> b) -> ::std::vector<long long> {
        const int n = ::std::size(b);
        if(n == 1) return b;
        int k = 0, n2 = n;
        while(1 < n2) { n2 /= 2; k++; }
        ::std::vector<long long> even(n / 2), odd(n / 2);
        for(int i = 0; i < n / 2; i++){
            even[i] = b[i * 2];
            odd[i] = b[i * 2 + 1];
        }
        even = f(f, even);
        odd = f(f, odd);
        long long zeta(1);
        for(int i = 0; i < n / 2; i++){
            odd[i] *= zeta; odd[i] %= mod998244353;
            b[i] = (even[i] + odd[i]) % mod998244353;
            b[n / 2 + i] = (even[i] - odd[i] + mod998244353) % mod998244353;
            zeta *= inv_ROOT_998244353[k]; zeta %= mod998244353;
        }
        return b;
    };
    const int N = ::std::size(B);
    B = ifft(ifft, B);
    for(int i = 0; i < N; i++) { B[i] *= modinv(N); B[i] %= mod998244353; }
    return B;
}

::std::vector<long long> convolution(::std::vector<long long> A, ::std::vector<long long> B) {
    int k = 1;
    while(k < ::std::size(A) + ::std::size(B) - 1) k *= 2;
    const int N = k;
    ::std::vector<long long> C(N, 0LL), D(N, 0LL);
    for(int i = 0; i < (int)::std::size(A); i++) { C[i] = A[i]; }
    for(int i = 0; i < (int)::std::size(B); i++) { D[i] = B[i]; }
    ::std::vector<long long> E(NTT(C)), F(NTT(D)), G(N);
    for(int i = 0; i < N; i++) {
        G[i] = E[i] * F[i] % mod998244353;
    }
    ::std::vector<long long> H(INTT(G));
    return H;
}

/**
 * @brief Convolution mod 998244353
 * @docs docs/convolution/convolution.md
 */