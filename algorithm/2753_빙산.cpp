#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int time=0;

vector<vector<int>> ice(301, vector<int>(301,0));
bool visited[301][301];

struct op {
	int x;
	int y;
};

void bfs(op start) {
	queue<op> q;
	q.push(start);
	visited[start.x][start.y] = true;

	while (!q.empty()) {
		op ma = q.front();
		q.pop();
		//cout << ma.x << ", " << ma.y<<"\n";

		op nw;

		if (ice[ma.x - 1][ma.y]>0) {
			nw.x = ma.x - 1;
			nw.y = ma.y;

			if (!visited[nw.x][nw.y]) {
				q.push(nw);
				visited[nw.x][nw.y] = true;
			}
		}
		if (ice[ma.x + 1][ma.y] > 0) {
			nw.x = ma.x + 1;
			nw.y = ma.y;
			
			if (!visited[nw.x][nw.y]) {
				q.push(nw);
				visited[nw.x][nw.y] = true;
			}
		}
	    if (ice[ma.x][ma.y+1] > 0) {
			nw.x = ma.x;
			nw.y = ma.y+1;
			
			if (!visited[nw.x][nw.y]) {
				q.push(nw);
				visited[nw.x][nw.y] = true;
			}
		}
		if (ice[ma.x][ma.y-1] > 0) {
			nw.x = ma.x;
			nw.y = ma.y-1;
			
			if (!visited[nw.x][nw.y]) {
				q.push(nw);
				visited[nw.x][nw.y] = true;
			}
		}
	}
	//group++;
	return;
}

void year_past() {
	vector<vector<int>> ice2 = ice;

	// 1년이 지난 후의 빙산..
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (ice2[i][j] > 0) {
				int bye = 0;

				if (ice2[i - 1][j] == 0)
					bye++;
				if (ice2[i + 1][j] == 0)
					bye++;
				if (ice2[i][j+1] == 0)
					bye++;
				if (ice2[i][j-1] == 0)
					bye++;

				if (ice2[i][j] - bye < 0)
					ice[i][j] = 0;
				else
					ice[i][j] = ice2[i][j]-bye;

			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ice[i][j] << " ";
		}
		cout << "\n";
	}
	*/
}


int main(void) {
	cin >> n >> m;

	op start; // 빙산 시작 지점

	int group=0;

	start.x = 0;
	start.y = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
			visited[i][j] = false;

			if (ice[i][j] > 0 && start.x==0 && start.y==0 ) {
				start.x = i;
				start.y = j;
			}
		}
	}
	
	if (start.x == 0 && start.y == 0) {
		cout << 0 << "\n";
		return 0;
	}
	else {
		while (true) {
			op wat;
			wat.x = 0;
			wat.y = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < m; j++) {
					if (ice[i][j] > 0 && visited[i][j] == false) {
						//cout << i << ", " << j << "\n";
						wat.x = i;
						wat.y = j;
						bfs(wat);
						group++;
					}
				}
			}

			if (wat.x == 0 && wat.y == 0) {
				cout << 0 << "\n";
				return 0;
			}else if (group < 2) {
				time++;
				year_past();
				group = 0;
				memset(visited, false, sizeof(visited));
				continue;
			}
			else {
				break;
			}
		}
	}

	cout << time << "\n";
	return 0;
}