using namespace std;

int matrix[4][4] = {1, 3, 5, 7,
					4, 7, 11, 13,
					7, 9, 13, 15,
					10, 20, 30, 40};

int queries[3] = {11, 12, 30}

int main(){
	for (int i = 0; i < 3; i++){
		bool isThere = false;
		for (int j = 0; j < 4; j++){
			int L = matrix[j][0];
			int N = matrix[j][3];

			while (!isThere){
				int M = matrix[j][(L+N+1)/2];
				if (queries[i] == M){
					isThere = true;
					break;
				} else if (queries[i] > M){
					L = M;
				} else if (queries[i] < M){
					N = M;
				}

				if (L > N){
					break;
				}
			}
		}
		if (isThere){
			cout << "YES";
		} else{
			cout << "NO";
		}
	}
}