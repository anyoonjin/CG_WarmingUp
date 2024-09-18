#include <iostream>
#include <fstream>		//���� �����
#include <vector>		//vector
#include <string>		//string
#include <sstream>		//stringstream<���鿡 ���� �ɰ���
#include <algorithm>	//sort������
#include <windows.h>	//
#include <cctype>		//toupper������


using namespace std;

void print_sentences(void);
void Alignment_of_sentences(int r_counter);		//��������
void search_big(int c_counter);
void word_reverse_print(int f_counter);			//������� �ܾ�� �Ųٷ� ����ϱ�
void line_reverse_print(int d_counter);			//���� �� �� �Ųٷ� ����ϱ�
void insert_Symbol(int e_counter);				//3���� �� @@ ����
void change_char(int g_counter, char ch_str, char new_str);
void find_word(string f_str);
string to_uppercase(string str);	//���ڿ� �빮�ڷ� �ٲ��ִ� �Լ�

vector<string> file_line[10];

int main() {
	string file_name;
	ifstream readFile;

	char command{};
	int r_counter{};	//�̰� ���߿� �� ���� �� �ϸ� ������...^^
	int c_counter{};
	int f_counter{};
	int d_counter{};
	int e_counter{};
	int g_counter{};

	cout << "���� �̸��� �Է��ϼ���." << endl;
	cin >> file_name;

	readFile.open(file_name);
	if (readFile.is_open())
	{
		int line_counter{};
		// << "����";
		while (!readFile.eof()) {
			string str_line;
			string str_word;
			getline(readFile, str_line);	//�� �� �ޱ�
			cout << str_line << endl;
			stringstream ss(str_line);	//���鿡 ���� �ɰ���
			while (ss >> str_word) {
				file_line[line_counter].push_back(str_word);//vector�� �� =�̷��� ������ �ƴ϶� ()�̷��� �Լ��� �־������
			}
			line_counter++;
		}
		//cout << file_line[0].size() << endl;


		while (true) {	//���� �� �� ������ ���� ����.. �����ѹ�,,
			cout << endl << "��ɾ �Է��ϼ���: " << endl;
			cin >> command;
			switch (command) {
			case 'c':	// c: �빮�ڷ� ���۵Ǵ� �ܾ� �ٸ� ������ ����ϰ�, �� �� �ִ��� ���. �ٽ� ������ ������� ���
			case 'C':
				c_counter++;
				search_big(c_counter);
				break;
			case 'd':	// d: ���� �� �� ��ü�� �Ųٷ� ���. �ٽ� ������ ������� ���.
			case 'D':
				d_counter++;
				line_reverse_print(d_counter);
				break;
			case 'e':
			case 'E':	// e: 3���� �� 2���� @ ���� ����. �ٽ� ������ ������� ���
				e_counter++;
				insert_Symbol(e_counter);
				break;
			case 'f':	// f: ������ �������� ��� �ܾ���� �Ųٷ� ���. �ٽ� ������ ������� ���
			case 'F':
				f_counter++;
				word_reverse_print(f_counter);
				break;
			case 'g':	// g: ���� ������ Ư�� ���ڸ� �ٸ� ���ڷ� �ٲٱ� (�ٲ� ���ڿ� ���Ӱ� �Է��� ���� �Է� ����) �ٽ� ������ ������� ���
			case 'G': {
				g_counter++;
				char change_str, new_str;
				if (g_counter % 2 == 1) {
					cout << "�ٲ� ���ڸ� �Է��ϼ���: " << endl;
					cin >> change_str;
					cout << "���� �Է��� ���ڸ� �Է��ϼ���: " << endl;
					cin >> new_str;

					change_char(g_counter, change_str, new_str);
				}
				else {
					print_sentences();
				}
			}
					break;
			case 'h':	// h: �� ���� �ܾ��� ������ ���
			case 'H':
				for (int i = 0; i < 10; i++) {
					cout << i + 1 << "��° �� �ܾ� ����: " << file_line[i].size() << endl;
				}
				break;
			case 'r':	// r: �� ������ �ܾ��� ������ ���� �������� �� �������� �� ������� �� ��������...
			case 'R':
				r_counter++;
				Alignment_of_sentences(r_counter);
				break;
			case 's':	// s: ��ɾ�� �ܾ �Է��ϸ�, �Է¹��� ������� ��� ����ϸ鼭 �� �ܾ ã�� �ٸ� ������ ����ϰ�, �� �� �ִ����� ����Ͽ� ���(��ҹ��� �������� �ʴ´�)
			case 'S':
			{
				string f_str;
				cout << "ã�� �ܾ �Է��ϼ���: " << endl;
				cin >> f_str;
				find_word(f_str);
			}
				break;
			case 'q':
			case 'Q':
				readFile.close();
				return 0;
				break;
			default:
				break;
			}
		}
	}
	else {
		cout << "���� �б� ����!";
	}
	readFile.close();
}

/*
			//string str_line;
			string str_word;
			//getline(readFile, str_line);	//,
			getline(readFile, str_word, ' ');	//,
			//readFile >> str_word;		//�̷��� �ϸ� ���� �ܾ�� �����.
			//file_line[line_counter].push_back(str_word) ;
			cout << str_word << endl;

			if (str_word.back() == '\n') {		//back() ���ڿ��� ������ ���ڸ� ��ȯ��
				str_word.pop_back();//������ ���� ����. \n���� �뵵
				file_line[line_counter].push_back(str_word);//vector�� �� =�̷��� ������ �ƴ϶� ()�̷��� �Լ��� �־������
				line_counter++;
			}
			else if (str_word.front() == '\n') {
				str_word = str_word.substr(1);  //pop���� �Լ��� ��� ��������. substr(1) ù ��° ���� ������ �κ� ��ȯ
				line_counter++;
				file_line[line_counter].push_back(str_word);//vector�� �� =�̷��� ������ �ƴ϶� ()�̷��� �Լ��� �־������
			}
			else {
				file_line[line_counter].push_back(str_word);
			}

*/

string to_uppercase(string str) {
	string result = str;
	for (int i = 0; i < str.size(); i++) {
		result[i] = toupper(str[i]);
	}
	return result;
}

void print_sentences(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			cout << file_line[i][j] << ' ';
		}
		cout << endl;
	}
}

void Alignment_of_sentences(int r_counter) {
	//int word_c[10][2]{};
	vector<pair<int, int>> word_c;
	vector<string> f_asc[10];	//��������
	vector<string> f_des[10];	//��������

	if (r_counter % 3 == 0) {	//������� ���
		cout << "������ ������� ����մϴ�." << endl;
		print_sentences();
		return;
	}
	for (int i = 0; i < 10; i++) {
		//word_c[i][0] = file_line[i].size();		//�ܾ� ��
		//word_c[i][1] = i;		//���� �ѹ�			//���߹迭��sort�� �Ἥ vector��
		word_c.push_back(make_pair(file_line[i].size(), i));
	}
	if (r_counter % 3 == 1) {	//������������ ����
		int num{};
		sort(word_c.begin(), word_c.end());
		for (int j = 0; j < 10; j++) {
			num = word_c[j].second;		//������������ ���ĵ� �� ��ȣ	 /�ٷ� �־ �������� ���� ���� ���϶��,,
			for (int k = 0; k < file_line[num].size(); k++) {
				f_asc[j].push_back(file_line[num][k]);
			}
		}
		cout << "������ �ܾ��� ������ ���� ������������ ����մϴ�." << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < f_asc[i].size(); j++) {
				cout << f_asc[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else {		//������������ ����
		int num{};
		sort(word_c.begin(), word_c.end(), greater<pair<int, int>>());
		/*	for (int i = 0; i < 10; i++) {
				cout << word_c[i].first << ' ' << word_c[i].second << endl;
			}*/
		cout << "������ �ܾ��� ������ ���� ������������ ����մϴ�." << endl;
		for (int j = 0; j < 10; j++) {
			num = word_c[j].second;		//������������ ���ĵ� �� ��ȣ	 /�ٷ� �־ �������� ���� ���� ���϶��,,
			for (int k = 0; k < file_line[num].size(); k++) {
				f_des[j].push_back(file_line[num][k]);
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < f_des[i].size(); j++) {
				cout << f_des[i][j] << ' ';
			}
			cout << endl;
		}
	}
}
//�����ϱ� ������ �ϳ��� ����� �������� ����ϴ� �� ���ڴ� ����...

void search_big(int c_counter) {
	int num{};

	if (c_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < file_line[i].size(); j++) {
				if (isupper(file_line[i][j][0])) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << file_line[i][j] << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					num++;
				}
				else {
					cout << file_line[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "�빮�ڷ� ���۵Ǵ� �ܾ��� ����: " << num << endl;
	}
	else {
		cout << "������� ����մϴ�." << endl;
		print_sentences();
	}
}

void word_reverse_print(int f_counter) {
	if (f_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < file_line[i].size(); j++) {
				for (int k = file_line[i][j].size() - 1; k >= 0; k--) {
					cout << file_line[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void line_reverse_print(int d_counter) {
	if (d_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = file_line[i].size() - 1; j >= 0; j--) {
				for (int k = file_line[i][j].size() - 1; k >= 0; k--) {
					cout << file_line[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void insert_Symbol(int e_counter) {
	int num{};
	if (e_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
		num = 0;
			for (int j = 0; j < file_line[i].size(); j++) {
				for (int k = 0; k < file_line[i][j].size(); k++) {
					cout << file_line[i][j][k];
					num++;
					if (num == 3) {
						num = 0;
						cout << "@@";
					}
				}
				cout << " ";
				num++;
				if (num == 3) {
					num = 0;
					cout << "@@";
				}
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void change_char(int g_counter, char ch_str, char new_str) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			for (int k = 0; k < file_line[i][j].size(); k++) {
				if (ch_str == file_line[i][j][k]) {
					cout << new_str;
				}
				else {
					cout << file_line[i][j][k];
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}

void find_word(string f_str) {
	int num{};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			if (to_uppercase(f_str) == to_uppercase(file_line[i][j])) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << file_line[i][j] << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				num++;
			}
			else {
				cout << file_line[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "�ܾ��� �� ����: " << num << endl;
}