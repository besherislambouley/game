/*
 * we keep an array no[i][j] the number of times we have said no between pair i,j before 
 * as long as no[i][j] < sz[i]*sz[j]-1 ( notice if we say no now then it would be impossible to reach from i to j ) , so we say yes
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
#include "game.h"
int n ;
int p[1509] , sz [1509] ;
int no[1509][1509] ;
int get ( int node ) {
        if ( p [node] == node ) return node ;
        return p [node] = get ( p [node] ) ;
}
int merge ( int a , int b ) {
        if ( a == b ) return 0 ;
        if ( no [a][b] < sz [a] * sz[b] - 1 ) return 0 ;
        if ( sz[a] > sz[b] ) swap ( a , b ) ;
        for ( int i = 0 ; i < n ; i ++ ) {
                no [i][b] += no[a][i] ;
                no [b][i] += no[a][i] ;
        }
        sz[b] += sz[a] ;
        p [a] = b ;
        return 1 ;
}
void initialize(int N) {
  		n = N ;
        for ( int i = 0 ; i < n ; i ++ ) {
                p[i] = i , sz[i] = 1 ;
        }
}
int hasEdge(int u, int v) {
        u = get ( u ) , v = get ( v ) ;
        if ( merge ( u , v ) ) return 1 ;
        no [u][v] ++ ;
        no [v][u] ++ ;
        return 0;
}
