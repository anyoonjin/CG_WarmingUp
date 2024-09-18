#include<iostream>
#include<random>	//c++에선 random헤더 사용./c에선 srand 사용
#include<algorithm>

using namespace std;
random_device rd;		//시드값 얻기 위한 random_device 생성
mt19937 gen(rd());		//random_device를 통해 난수 생성 엔진을 초기화
uniform_int_distribution<int>dis3(0, 2);		//0부터 2까지 균등하게 나타나는 난수열 생성 위해 균등 분포 정의
uniform_int_distribution<int>dis2(0, 1);
uniform_int_distribution<int>dis = dis3;

int procession1[4][4]{}, procession2[4][4]{};

void make_procession(int procession[][4]);		//행렬 만들기
void Mul_procession(int procession1[][4], int procession2[][4]);
void add_procession(int procession1[][4], int procession2[][4]);
void sub_procession(int procession1[][4], int procession2[][4]);
void mul_num_procession(int procession[][4], int num);
int determinant2x2(int arr_00, int arr_01, int arr_10, int arr_11);		//행렬식 구하기
int determinant3x3(int arr_00, int arr_01, int arr_02, int arr_10, int arr_11, int arr_12, int arr_20, int arr_21, int arr_22);
int determinant4x4(int arr[][4]);
void Transposed_matrix(int procession[][4]);	//전치행렬
void even_number(int e_counter, int procession[][4]);	//한 번 누르면 짝수, 또 누르면 홀수,, 다시 누르면 정상

int main() {

	make_procession(procession1);
	cout << endl;
	make_procession(procession2);

	char command{};
	int e_counter{};

	while (true) {	//숫자 될 수 있으면 적지 말기.. 매직넘버,,
		cout << endl << "명령어를 입력하세요: " << endl;
		cin >> command;

		switch (command) {
		case 'm':
		case 'M':
			cout << "행렬의 곱: " << endl;
			Mul_procession(procession1, procession2);
			break;
		case 'a':
		case 'A':
			cout << "행렬의 덧셈: " << endl;
			add_procession(procession1, procession2);
			break;
		case 'd':
		case 'D':
			cout << "행렬의 뺄셈: " << endl;
			sub_procession(procession1, procession2);
			break;
		case 'r':
		case 'R':
			cout << "첫번째 행렬의 행렬식 값: " << determinant4x4(procession1) << endl;
			cout << "두번째 행렬의 행렬식 값: " << determinant4x4(procession2);
			break;
		case 't':
		case 'T':	//전치행렬과 그 행렬식의 값
			cout << "첫번째 행렬을 정치행렬 했습니다.: " << endl;
			Transposed_matrix(procession1);
			cout << endl << "두번째 행렬을 정치행렬 했습니다.: " << endl;
			Transposed_matrix(procession2);

			cout << "첫번째 행렬의 행렬식 값: " << determinant4x4(procession1) << endl;
			cout << "두번째 행렬의 행렬식 값: " << determinant4x4(procession2);
			break;
		case 'e':
		case 'E':
			e_counter++;
			even_number(e_counter, procession1);
			cout << endl;
			even_number(e_counter, procession2);
			break;
		case 's':
		case 'S':
			cout << "행렬의 값을 새로 랜덤하게 설정합니다." << endl;
			make_procession(procession1);
			cout << endl;
			make_procession(procession2);
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			//원래 행렬에 곱한 값이 유지되어야 하나?

			int num = command - '0';	//이렇게 하면 문자를 숫자로 바꿀 수 있음
			mul_num_procession(procession1, num);
			cout << endl;
			mul_num_procession(procession2, num);
		}
		break;
		case 'q':
		case 'Q':
			return 0;
			break;
		default:
			break;
		}
	}

}

void make_procession(int procession[][4]) {		//행렬 만들기
	int counter_2{};	//행렬 안의 2 카운터
	//int procession[4][4]{};
	dis = dis3;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			procession[i][j] = dis(gen);
			if (procession[i][j] == 2) {
				counter_2++;
			}
			if (counter_2 == 2) {
				dis = dis2;
			}
			cout << procession[i][j] << ' ';
		}
		cout << endl;
	}
}

void Mul_procession(int procession1[][4], int procession2[][4]) {
	int mul_p[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			mul_p[i][j] = procession1[i][0] * procession2[0][j] +
				procession1[i][1] * procession2[1][j] +
				procession1[i][2] * procession2[2][j] +
				procession1[i][3] * procession2[3][j];

			cout << mul_p[i][j] << ' ';

		}
		cout << endl;
	}
}

void add_procession(int procession1[][4], int procession2[][4]) {
	int add_p[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			add_p[i][j] = procession1[i][j] + procession2[i][j];

			cout << add_p[i][j] << ' ';

		}
		cout << endl;
	}
}

void sub_procession(int procession1[][4], int procession2[][4]) {
	int sub_p[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			sub_p[i][j] = procession1[i][j] - procession2[i][j];

			cout << sub_p[i][j] << ' ';

		}
		cout << endl;
	}

}

void mul_num_procession(int procession[][4], int num) {
	int mul_p[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			procession[i][j] = procession[i][j] * num;

			cout << procession[i][j] << ' ';

		}
		cout << endl;
	}
}

int determinant2x2(int arr_00, int arr_01, int arr_10, int arr_11) {

	return arr_00 * arr_11 - arr_01 * arr_10;
}

int determinant3x3(int arr_00, int arr_01, int arr_02, int arr_10, int arr_11, int arr_12, int arr_20, int arr_21, int arr_22) {
	int num = arr_00 * determinant2x2(arr_11, arr_12, arr_21, arr_22) - arr_01 * determinant2x2(arr_10, arr_12, arr_20, arr_22)
		+ arr_02 * determinant2x2(arr_10, arr_11, arr_20, arr_21);
	return num;
}

int determinant4x4(int arr[][4]) {
	int num = arr[0][0] * determinant3x3(arr[1][1], arr[1][2], arr[1][3], arr[2][1], arr[2][2], arr[2][3], arr[3][1], arr[3][2], arr[3][3])
		- arr[1][0] * determinant3x3(arr[0][1], arr[0][2], arr[0][3], arr[2][1], arr[2][2], arr[2][3], arr[3][1], arr[3][2], arr[3][3])
		+ arr[2][0] * determinant3x3(arr[0][1], arr[0][2], arr[0][3], arr[1][1], arr[1][2], arr[1][3], arr[3][1], arr[3][2], arr[3][3])
		- arr[3][0] * determinant3x3(arr[0][1], arr[0][2], arr[0][3], arr[1][1], arr[1][2], arr[1][3], arr[2][1], arr[2][2], arr[2][3]);
	return num;
}

void Transposed_matrix(int procession[][4]) {
	for (int i = 1; i < 4; i++) {
		swap(procession[i][0], procession[0][i]);
	}
	for (int i = 2; i < 4; i++) {
		swap(procession[i][1], procession[1][i]);
	}
	swap(procession[3][2], procession[2][3]);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << procession[i][j] << ' ';
		}
		cout << endl;
	}
}

void even_number(int e_counter, int procession[][4]) {
	int num{};
	if (e_counter % 3 == 0) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << procession[i][j] << ' ';
			}
			cout << endl;
		}

		return;
	}
	else if (e_counter % 3 == 1) {
		num = 0;
		cout << "행렬의 값 중 짝수만 출력합니다." << endl;
	}
	else {
		cout << "행렬의 값 중 홀수만 출력합니다." << endl;
		num = 1;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (procession[i][j] % 2 == num) {
				cout << procession[i][j] << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
}