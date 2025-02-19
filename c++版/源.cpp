#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void clear_ui(void);
void clear_input(void);
void ui0(void);
void ui1(void);
void ui2(void);
void ui3(void);
void ui4(void);
void ui_end(void);
void select_0(void);
void select_1(void);
void select_way(void);
bool judge_yn(string);
void new_student(void);
void find_clas(void);
void find_term(void);
float judge_score(string);
void delet(long long int,int);

void clear_ui(void){//�����Ļ
	system("cls");
}

void clear_input(void) {//�������������
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//�����γ�ģ��
struct clas {
	float score =  -1;
	bool pass = (score >= 60);
	void update_score() {		//����һ�������� ����pass
		pass = score >= 60;
	}
};

//����ѧ��ģ��
struct students {
	string name;//��һ6:�ߵ���ѧ����ѧ�������Ϣ���ۣ���ѧ��ְҵ���Ĺ滮��c���Գ�����ƣ���ѧ����������������ѧӢ��
	string sex;//���5�����Դ�����Java������ƣ����ݽṹ���㷨����ѧ�������������
	long long int number = 0;//����4�������̣���������ԭ�����������ϵͳ�����簲ȫ����
	int old = 0;//����3��������Ӧ�ÿ�����Ƕ��ʽϵͳ������ʵϰ
	int cla_num = 0;		//�γ���
	float sum = 0;
	clas a[18];
	void newsum(void) {	//ˢ���ܷ�
		sum = 0;
		for (int i = 0; i < cla_num; i++) {
			sum += a[i].score;
		}
	}
	void newscore(void) {
		for (int i = 0; i < cla_num; i++) {
			a[i].update_score();
		}
	}
};

void show_student(students);		//����ģ�嵼�º��õĺ���
bool compare(students, students);
students find_name();
students find_number();

students show_list(void);
list<students> student;//ȫ���б������ѧ������
vector<students> goal; //����������ѧ��(�ų����)
vector<list<students>::iterator> address_goal;//����������ѧ��
string classs[18] = { "�ߵ���ѧ","��ѧ�������Ϣ����","��ѧ��ְҵ���Ĺ滮","c���Գ������","��ѧ������������","��ѧӢ��", "���Դ���","Java�������","���ݽṹ���㷨","��ѧ����","���������","������","��������ԭ��","���������ϵͳ","���簲ȫ����","������Ӧ�ÿ���","Ƕ��ʽϵͳ","����ʵϰ" };

//��y/n�������ж�
bool judge_yn(string a) {
	cout << a;
	char f;
	cin >> f;
	clear_input();
	cout << endl;
	while (f != 'y' && f != 'n') {
		cout << "�밴��ʽ��д!" << endl;
		cout << a;
		cin >> f;
		clear_input();
		cout << endl;
	}
	return f == 'y';
}

//�Գɼ�����
float judge_score(string a){
	float score;
	cout << "��¼��" << a << "�ɼ���  ";
	cin >> score;
	clear_input();
	while (score < 0 || score > 100) {
		cout << "�������Ϸ�������������" << endl;
		cout << "��¼��" << a << "�ɼ���  ";
		cin >> score;
		clear_input();
	}
	return score;
}

//չʾѧ������
void show_student(students a) {
	cout << "1.���֣�" << a.name << endl;
	cout << "2.ѧ�ţ�" << a.number << endl;
	cout << "3.�Ա�" << a.sex << endl;
	cout << "4.�꼶��" << a.old << endl;
	cout << "�ɼ���" << endl;
	for (int i = 0; i < a.cla_num; i++) {
		cout << i + 5 << "." << classs[i] << ":  " << a.a[i].score;
		if (!a.a[i].pass) {
			cout << "(������)";
		}
		cout << endl;
	}
	cout << "================================================" << endl;
}

//��������----ui_end
void ui_end(void) {
	clear_ui();
	cout << "==============================================================" << endl;
	cout << "�����Ѱ�ȫ�˳�����л�´�ʹ��:)" << endl;
	cout << "��������ر�" << endl;
	getchar();
	exit(0);
}

//������------ui0
void ui0(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "========================================================================" << endl << endl;
	cout << "1.����ϵͳ" << endl;
	cout << "2.ɾ��ϵͳ" << endl;
	cout << "3.�޸�ϵͳ" << endl;
	cout << "4.��ѯϵͳ" << endl << endl;
	cout << "5.�ر�" << endl;
	cout << endl << endl;
	cout << "��ѡ�����(�������)��  ";
	select_0();
}

//�ж�ui0�����룻
void select_0(void) {
	int select;
	while (1) {
		char a;
		cin >> a;
		clear_input();
		if ('1' <= a && a <= '5') {
			select = (int)(a - '0');
			break;
		}
		else {
			cout << "����Ƿ�!����������!(����س������)" << endl;
			getchar();
			clear_ui();
			ui0();
		}
	}
	switch (select) { //ת����ҳ��
	case 1:ui1(); break;
	case 2:ui3(); break;
	case 3:ui2(); break;
	case 4:ui4(); break;
	case 5:ui_end(); break;
	}
}

//�½�����----ui1
void ui1(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ����ϵͳ" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.������ѧ��" << endl;
	cout << "2.����������" << endl;
	cout << endl << endl;
	cout << "��ѡ�����(�������)��  ";
	select_1();
}

//�ж�----ui1
void select_1(void) {
	int select;
	cin >> select;
	clear_input();
	while (select != 1 && select != 2) {
		cout << "����Ƿ�!����������!(����س������)" << endl;
		getchar();
		clear_ui();
		ui1();
	}
	if (select == 1) {
		new_student();
	}
	else {
		ui0();
	}
}

//�½�ѧ��
void new_student(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ������ѧ��" << endl;
	cout << "===========================================================================" << endl << endl;

	students stu2; //��ʱ����
			
	//¼������
	cout << "��������ѧ��������";
	cin >> stu2.name;
	cout << endl;

	//¼���Ա�
	cout << "��������ѧ���Ա�(���С���Ů��)��  ";
	cin >> stu2.sex;
	clear_input();
	cout << endl;
	while (stu2.sex != "��" && stu2.sex != "Ů") {
		cout << "�汾���ͣ������������Ա�" << endl << endl;
		cout << "��������ѧ���Ա�(���С���Ů��)��  ";
		cin >> stu2.sex;
		clear_input();
		cout << endl;
	}

	//¼��ѧ��
	while (1) {
		cout << "������ѧ�ţ�  ";
		cin >> stu2.number;
		int k = 0;
		list<students>::iterator p;
		for (p = student.begin(); p != student.end(); p++) {
			if (p->number == stu2.number) {
				cout << "ѧ�����ظ�������������" << endl;
				k = 1;
				break;
			}
		}
		if(k == 1){
			continue;
		}
		break;
	}
	clear_input();
	cout << endl;

	//¼������
	cout << "�������꼶(1~4)��  ";
	cin >> stu2.old;
	clear_input();
	while (stu2.old > 4 || stu2.old < 1) {
		cout << "���꼶�����ڣ�����������!" << endl;
		cout << "�������꼶(1~4)��  ";
		cin >> stu2.old;
		clear_input();
		cout << endl;
	}

	//¼��γ���
	switch (stu2.old){
	case 1:stu2.cla_num = 6; break;
	case 2:stu2.cla_num = 11; break;
	case 3:stu2.cla_num = 15; break;
	case 4:stu2.cla_num = 18; break;
	}

	//¼��ɼ�
	float ee;
	for (int i = 0; i < stu2.cla_num; i++) {
		ee = judge_score(classs[i]);
		stu2.a[i].score =ee;
	}
	stu2.newscore();


	//¼���ܷ�
	stu2.newsum();

	//ȷ�ϻ���
	clear_ui();
	cout << "                   ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ������ѧ��" << endl;
	cout << "===========================================================================" << endl;
	cout << "��ȷ��¼����Ϣ" << endl << endl;
	cout << "================================================" << endl;
	show_student(stu2);
		
	if (judge_yn("�Ƿ���(y / n)��")) {
		student.push_back(stu2);	//д��Ŀǰѧ����

		ofstream student_write("students.txt",ios::app);	//����д����,д���ļ�
		student_write << stu2.name  << " " << stu2.sex << " " << stu2.number << " " << stu2.old << " " << stu2.cla_num << " " << stu2.sum << "  ";
		for (int i = 0; i < stu2.cla_num; i++) {
			student_write << stu2.a[i].score << " ";
		}
		student_write << endl;
		student_write.close();

		cout << "����ɹ���\n����س��󷵻�������" << endl;
		getchar();
		ui0();
	}
	else {
		cout << "¼��ȡ��������س������" << endl;
		getchar();
		ui1();
	}
}

//�޸Ľ���----ui2
void ui2(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               �޸�ϵͳ" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.����" << endl;
	cout << "2.ѧ��" << endl << endl;
	cout << "3.�˳�" << endl << endl;
	cout << "��ѡ���ѯ��ʽ��  ";
	int select;
	bool show = false;
	cin >> select;
	clear_input();
	while (select > 3 || select < 1) {
		cout << "�ò��������ڣ����������룡" << endl;
		cout << "��ѡ���ѯ��ʽ��  ";
		cin >> select;
		clear_input();
	}
	switch (select) {
	case 1:delet(find_name().number, 0); ui0;;
	case 2:delet(find_number().number, 0); ui0;
	case 3:ui0();
	}
}

//ɾ������----ui3
void ui3(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ɾ��ϵͳ" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.����" << endl;
	cout << "2.ѧ��" << endl << endl;
	cout << "3.�˳�" << endl << endl;
	cout << "��ѡ���ѯ��ʽ��  ";
	int select;
	bool show = false;
	cin >> select;
	clear_input();
	while (select > 3 || select < 1) {
		cout << "�ò��������ڣ����������룡" << endl;
		cout << "��ѡ���ѯ��ʽ��  ";
		cin >> select;
		clear_input();
	}
	switch (select) {
	case 1:delet(find_name().number, 1); ui0; break;
	case 2:delet(find_number().number, 1); ui0; break;
	case 3:ui0(); break;
	}
}

//��ѧ��ɾ��/�޸�Ԫ��
void delet(long long int number,int k) 
{	//k = 1:ɾ��,k = 0���޸�
	auto it = find_if(student.begin(), student.end(), [number](const students& s) {
		return s.number == number;
		});
	//����ѧ���Ƿ���ͬ������ͬ����ɾ���ģ���ֲĩβ;
	if (k == 1) {
		cout << endl;
		show_student(*it);
		if (judge_yn("�Ƿ�ȷ��ɾ��(y/n)���ò��������棡   ")) {
			student.erase(it);	//ɾ��
		}
	}
	else {
		show_student(*it);
		cout << "��ѡ��Ҫ�޸ĵ���  ";
		int select;
		cin >> select;
		clear_input();
		while (select < 0 || select >(*it).cla_num + 4) {
			cout << "���������ڣ�\n��ѡ��Ҫ�޸ĵ���  ";
			cin >> select;
			clear_input();
		}
		cout << endl;
		if (select == 1) {
			//¼������
			cout << "���޸�ѧ��������";
			cin >> (*it).name;
			cout << endl;
		}
		else if (select == 2) {
			//¼��ѧ��
			long long int y;
			while (1) {
				cout << "���޸�ѧ�ţ�  ";
				cin >> y;
				int k = 0;
				list<students>::iterator p;
				for (p = student.begin(); p != student.end(); p++) {
					if (p->number == y ) {
						cout << "ѧ�����ظ�������������" << endl;
						k = 1;
						break;
					}
				}
				if (k == 1) {
					continue;
				}
				break;
			}
			(*it).number = y;
			clear_input();
			cout << endl;
		}
		else if (select == 3) {
			//¼���Ա�
			cout << "���޸�ѧ���Ա�(���С���Ů��)��  ";
			cin >> (*it).sex;
			clear_input();
			cout << endl;
			while ((*it).sex != "��" && (*it).sex != "Ů") {
				cout << "�汾���ͣ������������Ա�" << endl << endl;
				cout << "��������ѧ���Ա�(���С���Ů��)��  ";
				cin >> (*it).sex;
				clear_input();
				cout << endl;
			}
		}
		else if (select == 4) {
			//¼������
			cout << "���޸��꼶(1~4)��  ";
			cin >> (*it).old;
			clear_input();
			while ((*it).old > 4 || (*it).old < 1) {
				cout << "���꼶�����ڣ�����������!" << endl;
				cout << "���޸��꼶(1~4)��  ";
				cin >> (*it).old;
				clear_input();
				cout << endl;
			}
			//�޸Ŀγ���
			switch ((*it).old) {
			case 1:(*it).cla_num = 6; break;
			case 2:(*it).cla_num = 11; break;
			case 3:(*it).cla_num = 15; break;
			case 4:(*it).cla_num = 18; break;
			}
		}
		if (select > 3) {
			//¼��ɼ�
			float ee;
			for (int i = 0; i < (*it).cla_num; i++) {
				if (i + 5 == select || (*it).a[i].score == -1) {
					ee = judge_score(classs[i]);
					(*it).a[i].score = ee;
				}
			}
			(*it).newscore();
			//¼���ܷ�
			(*it).newsum();
		}
		//ȷ�ϻ���
		cout << "================================================" << endl;
		cout << "��ȷ���޸���Ϣ" << endl << endl;
		show_student(*it);

		if (judge_yn("�Ƿ���(y / n)��")) {
			cout << "����ɹ���" << endl;
		}
		else {
			cout << "�޸�ȡ��" << endl;
			cout << "�������������ҳ��" << endl;
			getchar();
			ui0();
		}
	}
	ofstream file;				//��ʼ����������
	file.open("students.txt");
	if (!file.is_open()) {
		cout << "���棡���ļ���ʧ�ܣ�����������дȨ�ޣ���" << endl;//�ж϶�ȡ�������
		cout << "��������˳�����" << endl;
		getchar();
		exit(1);
	}
	list<students>::iterator p;			//������������
	for (p = student.begin(); p != student.end(); p++) {
		file << (*p).name << " " << (*p).sex << " " << (*p).number << " " << (*p).old << " " << (*p).cla_num << " " << (*p).sum << "  ";
		for (int i = 0; i < (*p).cla_num; i++) {
			file << (*p).a[i].score << " ";
		}
		file << endl;
	}
	cout << "�������������ҳ��" << endl;
	getchar();
	file.close();
	ui0();
}

//���ҽ���----ui4
void ui4(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ����ϵͳ" << endl;
	cout << "===========================================================================" << endl << endl;
	if (student.empty()) {
		cout << "ѧ������Ϊ�գ��뵼����ѯ!" << endl << endl;
		cout << "���س����������˵�" << endl;
		getchar();
		ui0();
	}
	select_way();
}

//ѡ����ҷ�ʽ
void select_way() {
	cout << "1.����" << endl;
	cout << "2.ѧ��" << endl;
	cout << "3.ѧ��" << endl;
	cout << "4.ѧ��" << endl;
	cout << "5.�ܷ�(���꼶)" << endl;
	cout << "6.չʾȫ����Ϣ" << endl << endl;
	cout << "7.������ҳ��" << endl << endl;
	cout << "��ѡ����ҷ�ʽ��";
	int select;
	bool show = true;
	cin >> select;
	clear_input();
	while (select < 1 || select > 7) {
		cout << "�����Ƿ���" << endl;
		cout << "������ѡ����ҷ�ʽ��  ";
		cin >> select;
		clear_input();
	}
	cout << "================================================" << endl;
	switch (select) {
	case 1: {
		show_student(find_name());
		cout << "���س�������";
		getchar();
		address_goal.clear();
		goal.clear();
		ui4();
	}break;
	case 2: {
		show_student(find_number());
		cout << "���س�������";
		address_goal.clear();
		goal.clear();
		getchar();
		ui4();
	} break;
	case 3: find_clas(); ui4();	break;
	case 4: find_term(); ui4(); break;
	case 5: {
		vector<students> term[4];
		list<students>::iterator p;
		for (p = student.begin(); p != student.end(); p++) {	//��ѧ������
			if (p->old == 1) {
				term[0].push_back(*p);
			}
			else if (p->old == 2) {
				term[1].push_back(*p);
			}
			else if (p->old == 3) {
				term[2].push_back(*p);
			}
			else {
				term[3].push_back(*p);
			}
		}
		int u;
		int t;
		for (u = 0; u < 4; u++) {
			cout << "================================================" << endl;
			switch (u) {
			case 0: cout << "��һ��" << endl << endl; break;
			case 1: cout << "�����" << endl << endl; break;
			case 2: cout << "������" << endl << endl; break;
			case 3: cout << "���ģ�" << endl << endl; break;
			}
			if (term[u].size()) {
				sort(term[u].begin(), term[u].end(), compare);
				for (int t = 0; t < term[u].size(); t++) {
					cout << t + 1 << "." << term[u].at(t).name << term[u].at(t).number << "��" << term[u].at(t).sum << endl;
				}
			}
			else {
				cout << "���꼶δ¼��ѧ����" << endl;
			}
		}
		cout << "================================================" << endl << endl;
		cout << "���س�������" << endl;
		getchar();
		clear_input();
		ui4();
	}
	case 6: {
		list<students>::iterator p;
		cout << "================================================" << endl;
		for (p = student.begin(); p != student.end(); p++) {
			show_student(*p);
		}
		cout << "�����������" << endl;
		getchar();
		clear_input();
	}; ui4(); break;
	case 7: ui0();
	}
}

//���ֽܷ���Ƚ�
bool compare(students a, students b) {
	return a.sum > b.sum;
}

//���������в�ѯ
students find_name()  {
	string name;
	cout << "������������  ";
	cin >> name;
	clear_input();
	cout << endl;
	list<students>::iterator p;
	for (p = student.begin(); p != student.end(); p++) {
		if (p->name == name) {
			goal.push_back(*p);
			address_goal.push_back(p);
		}
	}
	return show_list();
}

//��ѧ�Ž��в�ѯ
students find_number() {
	long long int number;
	cout << "������ѧ�ţ�  ";
	cin >> number;
	clear_input();
	cout << endl;
	list<students>::iterator p;
	for (p = student.begin(); p != student.end(); p++) {
		if (p->number == number) {
			goal.push_back(*p);
			address_goal.push_back(p);
		}
	}
	return show_list();
}

//��ѧ�ƽ��в�ѯ
void find_clas(void) {
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ����ϵͳ" << endl;
	cout << "===========================================================================" << endl;
	cout << "��һ��" << endl;
	cout << "1.�ߵ���ѧ" << endl;
	cout << "2.��ѧ�������Ϣ����" << endl;
	cout << "4.c���Գ������" << endl;
	cout << "5.��ѧ������������" << endl;
	cout << "6.��ѧӢ��" << endl << endl;
	cout << "�����" << endl;
	cout << "7.���Դ���" << endl;
	cout << "8.Java�������" << endl;
	cout << "9.���ݽṹ���㷨" << endl;
	cout << "10.��ѧ����" << endl;
	cout << "11.���������" << endl << endl;
	cout << "������" << endl;
	cout << "12.������" << endl;
	cout << "13.��������ԭ��" << endl;
	cout << "14.���������ϵͳ" << endl;
	cout << "15.���簲ȫ����" << endl << endl;
	cout << "���ģ�" << endl;
	cout << "16.������Ӧ�ÿ���" << endl;
	cout << "17.Ƕ��ʽϵͳ" << endl;
	cout << "18.����ʵϰ" << endl << endl << endl;
	cout << "��ѡ��γ�(�������)��  ";
	int select1;
	cin >> select1;
	clear_input();
	while (select1 < 0 || select1 > 18) {
		cout << "�γ̲����ڣ����������룡" << endl;
		cout << "��ѡ��γ�(�������)��  ";
		cin >> select1;
		clear_input();
	}
	int i =select1 - 1;
	clear_ui();
	cout << "                     ѧ������ϵͳ�ڲ�����v0.1����ҵ�棩" << endl;
	cout << "                               ����ϵͳ" << endl;
	cout << "===========================================================================" << endl;
	cout << "��ǰѡ�� " << classs[i] << endl << endl;
	cout << "1.չʾ��������" << endl;
	cout << "2.�Ե�ǰ��������ѧ��" << endl;
	cout << "3.�鿴�ֶ�����" << endl << endl;
	cout << "4.�������˵�" << endl << endl;
	cout << "��ѡ�������  ";
	int select;
	cin >> select;
	clear_input();
	cout << endl;
	while (select < 1 || select > 4) {
		cout << "���������ڣ����������룡" << endl;
		cout << "��ѡ�������  ";
		cin >> select;
		clear_input();
		cout << endl;
	}
	switch (select) {
	case 1: {
		vector<students>::iterator p;
		list<students>::iterator x;
		float sum = 0;//ѧ�Ƴɼ���
		vector<students> /*��Чѧ������*/copy,/*��ͷ�ѧ��*/min,/*��߷�ѧ��*/max,/*����ѧ��*/pass,/*������ѧ��*/unpass;

		for (x = student.begin(); x != student.end(); x++) {	//������Ч��ѧ��
			if (x->a[i].score != -1) {
				copy.push_back(*x);
				sum += x->a[i].score;
			}
		}
		if (copy.empty()) {
			cout << "��δ��ѧ����óɼ���\n\n�س��󷵻�������";
			getchar();
			clear_input();
			ui0();
		}
		sum = sum / copy.size();//��ʱsum = ƽ���ɼ�
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//��������ѧ��
			return a.a[i].score > b.a[i].score;
			});//Lambda���ʽ������粶��i�������ж�https://www.bilibili.com/video/BV1fG41157Ew/?spm_id_from=333.337.search-card.all.click&vd_source=1599b1fe085b1fbd7be552c71b77fe79

		float max_score, min_score;
		max_score = copy.at(0).a[i].score;
		min_score = copy.at(copy.size() - 1).a[i].score;
		for (p = copy.begin(); p != copy.end(); p++) {		//���ദ��ѧ��
			if (p->a[i].score == max_score) {
				max.push_back(*p);
			}
			if (p->a[i].score == min_score) {
				min.push_back(*p);
			}
			if (p->a[i].score >= 60) {
				pass.push_back(*p);
			}
			if (p->a[i].score < 60) {
				unpass.push_back(*p);
			}
		}
		cout << "ƽ���ɼ���  " << sum << endl;
		cout << "�����ʣ�  " << (float(pass.size()) / copy.size()) * 100 << "%(����" << pass.size() << "������" << unpass.size() << ")" << endl;
		cout << "================================================" << endl;
		cout << "��߷֣�  " << max_score << "(��" << max.size() << "��)" << endl << endl;
		for (int j = 0; j < max.size(); j++) {
			cout << j + 1 << "." <<max.at(j).name << "��" << max.at(j).number << endl;
		}
		cout << "================================================" << endl;
		cout << "��ͷ֣�  " << min_score << "(��" << min.size() << "��)" << endl << endl;
		for (int j = 0; j < min.size(); j++) {
			cout << j + 1 << "." << min.at(j).name <<  "��" << min.at(j).number << endl;
		}
		cout << "================================================" << endl;
		cout << "����(" << "��" << pass.size() << "��)" << endl << endl;
		for (int j = 0; j < pass.size(); j++) {
			cout << j + 1 << "." << pass.at(j).name << "��" << pass.at(j).number << "��  " << pass.at(j).a[i].score << endl;
		}
		cout << "================================================" << endl;
		cout << "������(" << "��" << unpass.size() << "��)" << endl << endl;
		for (int j = 0; j < unpass.size(); j++) {
			cout << j + 1 <<  "." <<unpass.at(j).name << "��" << unpass.at(j).number << "��  " << unpass.at(j).a[i].score << endl;
		}
		cout << "================================================" << endl;
	}; break;

	case 2: {							//дcase��ִ֤���˳�ʱ�������㣬���´�����
		vector<students>::iterator p;
		list<students>::iterator x;
		float sum = 0;//ѧ�Ƴɼ���
		vector<students> /*��Чѧ������*/copy;

		for (x = student.begin(); x != student.end(); x++) {	//������Ч��ѧ��
			if (x->a[i].score != -1) {
				copy.push_back(*x);
			}
		}
		if (copy.empty()) {
			cout << "��δ��ѧ����óɼ���\n\n�س��󷵻�������";
			getchar();
			clear_input();
			ui0();
		}
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//��������ѧ��
			return a.a[i].score > b.a[i].score;
			});
		int j = 1;
		for (p = copy.begin(); p != copy.end(); p++, j++) {
			cout << j << "." << p->name << p->number << ":" << p->a[i].score << endl;
		}
	}; break;
	case 3: {
		vector<students>::iterator p;
		list<students>::iterator x;
		vector<students> /*��Чѧ������*/copy;
		int stunum[10] = { 0 };

		for (x = student.begin(); x != student.end(); x++) {	//������Ч��ѧ��
			if (x->a[i].score != -1) {
				copy.push_back(*x);
			}
		}
		if (copy.empty()) {
			cout << "��δ��ѧ����óɼ���\n\n�س��󷵻�������";
			getchar();
			clear_input();
			ui0();
		}
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//��������ѧ��
			return a.a[i].score > b.a[i].score;
			});
		for (p = copy.begin(); p != copy.end(); p++) {
			if (p->a[i].score >= 90) {
				stunum[9]++;
			}
			else if (p->a[i].score >= 80) {
				stunum[8]++;
			}
			else if (p->a[i].score >= 70) {
				stunum[7]++;
			}
			else if (p->a[i].score >= 60) {
				stunum[6]++;
			}
			else if (p->a[i].score >= 50) {
				stunum[5]++;
			}
			else if (p->a[i].score >= 40) {
				stunum[4]++;
			}
			else if (p->a[i].score >= 30) {
				stunum[3]++;
			}
			else if (p->a[i].score >= 20) {
				stunum[2]++;
			}
			else if (p->a[i].score >= 10) {
				stunum[1]++;
			}
			else{
				stunum[0]++;
			}
		}
		cout << 100 << "~" << 90 << ":" << stunum[9] << endl;
		for (int j = 8; j > 0; j--) {
			cout << " " << (j + 1) * 10 << "~" << j * 10 << ":" << stunum[j] << endl;
		}
		cout << " " << 10 << "~" << 0 << " :" << stunum[0] << endl;
	}; break;
	case 4: {
		ui0();
	}
	}
	cout << "�밴�س�������" << endl;
	getchar();
}

//��ѧ�ڽ��в�ѯ
void find_term(void){
	int old;
	cout << "������ѧ�꣺  ";
	cin >> old;
	clear_input();
	cout << endl;
	list<students>::iterator p;
	for (p = student.begin(); p != student.end(); p++) {	//������Ч����
		if (p->old == old) {
			goal.push_back(*p);
			address_goal.push_back(p);
		}
	}
	show_student(show_list());
	cout << "���س�������";
	getchar();
	address_goal.clear();
	address_goal.resize(0);
	goal.clear();
	goal.resize(0);
	ui4();
}

//չʾ���,չʾgoal����ѡ��
students show_list() {
	cout << "================================================" << endl;
	if (goal.empty()) {
		cout << "δ��ѯ�������Ϣ\n\n���س�������������" << endl;
		getchar();
		ui0();
	}
	else {
		vector<students>::iterator p;
		int i = 0;
		for (p = goal.begin(),i = 1; p < goal.end(); p++,i++) {
			cout << i << ".  " << "������" << p->name << "  " << "ѧ�ţ�" << p -> number << endl;
		}
		cout << "================================================" << endl << endl;
		cout << "��ѡ��ѧ�����:  ";
		int select;
		cin >> select;
		clear_input();
		while (select < 0 || select > goal.size()) {
			cout << "����Ƿ�!����������!(����س������)" << endl;
			cin >> select;
		}
		cout << "================================================" << endl;
		goal.clear();
		goal.resize(0);
		students a = *(address_goal[select - 1]);
		address_goal.clear();
		address_goal.resize(0);
		return a;
	}
}

//¼�����ݣ��������
int main(void) {
	ifstream student_read;
	student_read.open("students.txt");	//������ȡ��

	if (!student_read.is_open()) {
		cout << "���棡���ļ���ʧ�ܣ�����������дȨ�ޣ���" << endl;//�ж϶�ȡ�������
		cout << "��������˳�����" << endl;
		getchar();
		return 1;
	}
	string stu, a;
	while (getline(student_read, stu)) {
		if (stu.size() == 0) {		//����(��ɾ��),o����;
			continue;
		}
		students std1;		//������ʱѧ����Ϣ
		istringstream iss(stu);	//��ÿ�����ݣ�ÿ��ѧ�������δ���
		iss >> std1.name >> std1.sex >> std1.number >> std1.old >> std1.cla_num >> std1.sum;
		int i = 0;
		while (iss >> std1.a[i].score) {//¼��ÿ�Ƴɼ�
			i++;
		}
		std1.newscore();
		student.push_back(std1);
	}
	student_read.close();
	ui0();
	return 0;
}
