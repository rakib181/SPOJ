#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> g[N];
vector<int> dist(N, 0);
vector<bool> vis(N, false);

long long binPow(long long a, long long b, long long mod){
     long long ans = 1;
     while(b){
        if(b & 1) ans = ans * a % mod;
         a = a * a % mod;
         b >>= 1;
     }
     return ans;
}

bool compositeness(long long a, long long d, long long s, long long n){
    long long x = binPow(a, d, n);
    if(x == 1 || x == n - 1)return false;

    for(int i = 0; i < s; i++){
        x = x * x % n;
        if(x == n - 1)return false;
    }
    return true;
}

bool isPrime(long long n, int iter = 5){
    if(n < 4)return n == 2 || n == 3;
    long long d = n - 1, s = 0;
    while(!(d & 1)){
        s++;
        d >>= 1;
    }
    for(int i = 0; i <= iter; i++){
        long long a = 2 + rand() % (n - 3);
        if(compositeness(a, d, s, n)){
             return false;
        }
    }
    return true;
}

bool isValid(int a, int b){
    int cnt = 0;
    while(a > 0){
        if((a % 10) != (b % 10))cnt++;
        a /= 10, b /= 10;
        if(cnt > 1)return false;
    }
    return true;
}

int32_t main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0); 
      #ifndef ONLINE_JUDGE 
      freopen("input.txt","r",stdin); 
      freopen("output.txt","w",stdout); 
      #endif
      auto start=clock();
      int tt;
      cin >> tt;
      while(tt--){
      int a, b;
      cin >> a >> b;
      vector<int> primes;
      for(int i = 1000; i <= 9999; i++){
          g[i].clear(), dist[i] = 0, vis[i] = false;
      }
      for(int i = 1000; i <= 9999; i++){
          if(isPrime(i))primes.push_back(i);
      }
      for(int i = 0; i < primes.size(); i++){
        for(int j = i + 1; j < primes.size(); j++){
                if(isValid(primes[i], primes[j])){
                    g[primes[i]].push_back(primes[j]);
                    g[primes[j]].push_back(primes[i]);
            }
        }
      }
      queue<int> q;
      q.push(a);
      dist[a] = 0;
      vis[a] = true;
      while(!q.empty()){
        int cur = q.front();
        q.pop();
         for(auto x : g[cur]){
        if(!vis[x]){
            vis[x] = true;
            dist[x] = dist[cur] + 1;
            q.push(x);
        }
         }
      }
      cout << dist[b] << '\n';
  }
      cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
      return 0;
}
