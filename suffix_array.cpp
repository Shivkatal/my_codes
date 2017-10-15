#include <bits/stdc++.h>
#define MAXN 65536
#define MAXLG 17
using namespace std;

string A;

struct entry{
	int nr[2];
	int p;
}L[MAXN];

int P[MAXLG][MAXN];
int stp,cnt;

int cmp(struct entry a, struct entry b){
	return a.nr[0]==b.nr[0]?(a.nr[1]<b.nr[1]?1:0):(a.nr[0]<b.nr[0]);
}

int main(){
	cin>>A;
	int N=A.length();
	for(int i=0;i<N;i++)
		P[0][i]=A[i]-'a';

	for(stp=1, cnt=1;cnt<N; stp++, cnt<<=1){
		for(int i=0;i<N;i++){
			L[i].nr[0]=P[stp-1][i];
			L[i].nr[1]=i+cnt<N? P[stp-1][i+cnt]:-1;
			L[i].p=i;
		}
		sort(L,L+N,cmp);
		for(int i=0;i<N;i++)
			P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1]?P[stp][L[i-1].p]:1;
	}
	for(int i=0;i<A.length();i++)
			cout<<L[i].p<<" "<<i<<endl;
	return 0;
}
