#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int k, sum = 0, a[N + 10];

struct Q{
   int l, r, idx;
};
Q *query;
bool compare(Q q1, Q q2){
   if(q1.l / k == q2.l / k){
      return q1.r > q2.r;
   }
   return q1.l / k < q2.l / k;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
     cin.tie(0); 
     #ifndef ONLINE_JUDGE 
     freopen("input.txt","r",stdin); 
     freopen("output.txt","w",stdout); 
     #endif
     auto start=clock();
     int n;
     cin >> n;
     for(int i = 0; i < n; i++){
      cin >> a[i];
     }
     int q;
     cin >> q;
     k = sqrt(n);
     query = new Q[q];
     for(int i = 0; i < q; i++){
      int l, r;
      cin >> l >> r;
      query[i].l = l;
      query[i].r = r;
      query[i].idx = i;
     }
     sort(query, query + q, compare);int L = 0, R = -1, cur_l, cur_r;
     vector<int> ans(q), freq(N * 10);
     for(int i = 0; i < q; i++){
      cur_l = query[i].l, cur_r = query[i].r;
      cur_l--, cur_r--;
      while(R < cur_r){
         freq[a[++R]]++;
         if(freq[a[R]] == 1){
            sum++;
         }
      }
      while(L > cur_l){
         freq[a[--L]]++;
          if(freq[a[L]] == 1){
            sum++;
         }
      }
      while(R > cur_r){
          freq[a[R]]--;
          if(freq[a[R]] == 0){
            sum--;
         }
         R--;
      }
      while(L < cur_l){
           freq[a[L]]--;
          if(freq[a[L]] == 0){
            sum--;
         }
         L++;
      }
      ans[query[i].idx] = sum;
     }
     for(int i =0; i < q; i++){
      cout << ans[i] << '\n';
     }
     cout << '\n';
     cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
     return 0;
}
