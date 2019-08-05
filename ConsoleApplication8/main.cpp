#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int count;
int min_g = 999999;
int visit[100001] = { 0 };
queue<int> q;

int go(int a, int count) {
	visit[a] = 1;
	q.push(a);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		if (a == K)
			return visit[a]-1;
		if (a-1>=0 && visit[a - 1] == 0) {
			q.push(a - 1);
			visit[a - 1] = visit[a] + 1;
		}
		if (a+1<=100000 && visit[a + 1] == 0) {
			q.push(a + 1);
			visit[a + 1] = visit[a] + 1;
		}
		if (a * 2 <= 100000 && visit[a * 2] == 0) {
			q.push(a * 2);
			visit[a * 2] = visit[a] + 1;
		}
	}
}

int main() {
	cin >> N >> K;
	min_g = min(min_g, go(N, 0));
	cout << min_g << endl;
	return 0;
}