#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arrayA, vector<int> arrayB) {
	vector<int> answer;
	sort(arrayA.begin(), arrayA.end());
	sort(arrayB.begin(), arrayB.end());
	vector<int> v;
	vector<int> check(arrayA.size() + arrayB.size()+1,0);

	int size_of_inter=0;
	int size_of_coml;
	
	for (int i = 0; i < arrayA.size(); i++) {
		if (check[arrayA[i]] == 0) {
			v.push_back(arrayA[i]);
			check[arrayA[i]] = 1;
		}
	}

	for (int i = 0; i < arrayB.size(); i++) {
		if (check[arrayB[i]] == 0) {
			v.push_back(arrayB[i]);
			check[arrayB[i]] = 1;
		}
	}

	size_of_coml = v.size();

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < arrayB.size(); j++) {
			if (v[i] == arrayB[j]) {
				size_of_coml--;
				size_of_inter++;
			}
		}
	}

	cout << "합집합 size: "<<v.size() << "\n";
	cout << "차집합 size: "<<size_of_coml << "\n";
	cout << "교집합 size: "<<size_of_inter << "\n";
	
	return answer;
}

int main(void) {
	// this is a test case..
	vector<int> arrayA{ 1, 2, 3, 2 };
	vector<int> arrayB{ 1,6,7 };

	solution(arrayA, arrayB);
}