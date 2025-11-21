#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct edge{
	int u, v;
	int w;
};
const int maxx = 1000;
int n, m;
int parent[maxx], size[maxx];
vector<edge> canh;
void make_set(){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}
int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}
bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(size[a] < size[b]) swap(a, b);
	parent[b] = a;
	size[a] + size[b];
	return true;
}
void input(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		edge e;
		edge e = edge(x, y, w);
		e.u = x;
		e.v = y;
		e.w = w;
		canh.push_back(e);
	}
}
void kruskal(){
	vector<edge> mst;
	int d = 0; 
	sort(canh.begin(), canh.end(), cmp);
	for(int i = 0; i < m; i++){
		if(mst.size() == n - 1) break;
		edge e = canh[i];
		if(Union(e.u, e.v)){
			mst.push_back(e);
			d += e.w;
		}
	}
	if(mst.size() != n - 1){
		cout << "Do thi khong lien thong";
	}
	else{
		cout << "MST = " << d << endl;
		for(auto it : mst){
			cout << it.u << " " << it.v << " " << it.w << endl;
		}
	}
}
int main() {
	input();
	make_set();
	kruskal();
	return 0;
}

