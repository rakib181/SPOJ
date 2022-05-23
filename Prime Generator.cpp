#include<bits/stdc++.h>
using namespace std;
const int N=1e6+15;
vector<int>v;
bool prime[N+1];
vector<int>GenPrime;

void sieve(){
    for(int i=4;i<=N;i+=2)prime[i]=1;
      for(int i=2;i*i<=N;i++){
         if(!prime[i]){
            GenPrime.push_back(i);
            for(int j=i*i;j<=N;j+=i+i){
               prime[j]=1;
            }
         }
      }
}
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
    auto st=clock();
    sieve();
    int t;
    cin>>t;
    while(t--){
      int n,m;
      cin>>n>>m;
    vector<int>ar(m-n+1,0);

      for(auto p:GenPrime){
         if(p*p>m){
            break;
         }
         
         int start=(n/p)*p;
         if(p>n && p<=m){
            start=2*p;
         }
         for(int j=start;j<=m;j+=p){
            if(j<n){
               continue;
            }
            ar[j-n]=1;
         }
      }
      for(int i=n;i<=m;i++){
         if(ar[i-n]==0 && i!=1){
            cout<<i<<endl;
         }
      }
      cout<<endl;
    }
   cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
