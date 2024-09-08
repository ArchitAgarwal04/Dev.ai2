#include<bits/stdc++.h>
using namespace std;
#define int long long
int power(int A,int expo)
{	if (expo == 0)
		return 1;
	int res = power(A, expo / 2);
	if (expo % 2) return res * res * A;
	else return res * res;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int fact(int x){
    if(x==1 || x==0) return 1;
    return (x*fact(x-1));
}
const int M = 1e9 + 7;
int modExp(int b, int e, int m) {
    int r = 1;
    while (e > 0) {
        if (e & 1) {
            r = (r * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return r;
}
int inverse(int x, int m) {
    return modExp(x, m - 2, m);
}
int calcP(int s, int sq, int n) {
    int P = (1LL * s * s % M - sq + M) % M;
    P = (P * inverse(2, M)) % M;
    return P;
}
int calcQ(int n) {
    return (1LL * n * (n - 1) / 2) % M;
}
int computeRes(const vector<int>& a, int n) {
    int s = 0, sq = 0;
    for (int i = 0; i < n; ++i) {
        s = (s + a[i]) % M;
        sq = (sq + 1LL * a[i] * a[i] % M) % M;
    }

    int P = calcP(s, sq, n);
    int Q = calcQ(n);
    int val = inverse(Q, M);

    return (P * val) % M;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    cout << computeRes(a, n) << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}