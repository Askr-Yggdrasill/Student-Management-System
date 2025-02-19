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

void clear_ui(void){//清空屏幕
	system("cls");
}

void clear_input(void) {//清空输入流缓冲
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//创建课程模板
struct clas {
	float score =  -1;
	bool pass = (score >= 60);
	void update_score() {		//创建一个方法， 更新pass
		pass = score >= 60;
	}
};

//创建学生模板
struct students {
	string name;//大一6:高等数学，大学计算机信息导论，大学生职业生涯规划，c语言程序设计，大学生心理健康教育，大学英语
	string sex;//大二5：线性代数，Java程序设计，数据结构与算法，大学物理，计算机网络
	long long int number = 0;//大三4，网络编程，计算机组成原理，计算机操作系统，网络安全技术
	int old = 0;//大四3：互联网应用开发，嵌入式系统，生产实习
	int cla_num = 0;		//课程数
	float sum = 0;
	clas a[18];
	void newsum(void) {	//刷新总分
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

void show_student(students);		//运用模板导致后置的函数
bool compare(students, students);
students find_name();
students find_number();

students show_list(void);
list<students> student;//全局列表存所有学生数据
vector<students> goal; //存搜索到的学生(排除多个)
vector<list<students>::iterator> address_goal;//存搜索到的学生
string classs[18] = { "高等数学","大学计算机信息导论","大学生职业生涯规划","c语言程序设计","大学生心理健康教育","大学英语", "线性代数","Java程序设计","数据结构与算法","大学物理","计算机网络","网络编程","计算机组成原理","计算机操作系统","网络安全技术","互联网应用开发","嵌入式系统","生产实习" };

//对y/n类输入判断
bool judge_yn(string a) {
	cout << a;
	char f;
	cin >> f;
	clear_input();
	cout << endl;
	while (f != 'y' && f != 'n') {
		cout << "请按格式填写!" << endl;
		cout << a;
		cin >> f;
		clear_input();
		cout << endl;
	}
	return f == 'y';
}

//对成绩输入
float judge_score(string a){
	float score;
	cout << "请录入" << a << "成绩：  ";
	cin >> score;
	clear_input();
	while (score < 0 || score > 100) {
		cout << "分数不合法！请重新输入" << endl;
		cout << "请录入" << a << "成绩：  ";
		cin >> score;
		clear_input();
	}
	return score;
}

//展示学生数据
void show_student(students a) {
	cout << "1.名字：" << a.name << endl;
	cout << "2.学号：" << a.number << endl;
	cout << "3.性别：" << a.sex << endl;
	cout << "4.年级：" << a.old << endl;
	cout << "成绩：" << endl;
	for (int i = 0; i < a.cla_num; i++) {
		cout << i + 5 << "." << classs[i] << ":  " << a.a[i].score;
		if (!a.a[i].pass) {
			cout << "(不及格)";
		}
		cout << endl;
	}
	cout << "================================================" << endl;
}

//结束画面----ui_end
void ui_end(void) {
	clear_ui();
	cout << "==============================================================" << endl;
	cout << "程序已安全退出，感谢下次使用:)" << endl;
	cout << "按任意键关闭" << endl;
	getchar();
	exit(0);
}

//主界面------ui0
void ui0(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "========================================================================" << endl << endl;
	cout << "1.导入系统" << endl;
	cout << "2.删除系统" << endl;
	cout << "3.修改系统" << endl;
	cout << "4.查询系统" << endl << endl;
	cout << "5.关闭" << endl;
	cout << endl << endl;
	cout << "请选择操作(输入序号)：  ";
	select_0();
}

//判断ui0的输入；
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
			cout << "输入非法!请重新输入!(输入回车后继续)" << endl;
			getchar();
			clear_ui();
			ui0();
		}
	}
	switch (select) { //转跳子页面
	case 1:ui1(); break;
	case 2:ui3(); break;
	case 3:ui2(); break;
	case 4:ui4(); break;
	case 5:ui_end(); break;
	}
}

//新建界面----ui1
void ui1(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               导入系统" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.导入新学生" << endl;
	cout << "2.返回主界面" << endl;
	cout << endl << endl;
	cout << "请选择操作(输入序号)：  ";
	select_1();
}

//判断----ui1
void select_1(void) {
	int select;
	cin >> select;
	clear_input();
	while (select != 1 && select != 2) {
		cout << "输入非法!请重新输入!(输入回车后继续)" << endl;
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

//新建学生
void new_student(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               导入新学生" << endl;
	cout << "===========================================================================" << endl << endl;

	students stu2; //临时数据
			
	//录入名字
	cout << "请输入新学生姓名：";
	cin >> stu2.name;
	cout << endl;

	//录入性别
	cout << "请输入新学生性别(“男”或“女”)：  ";
	cin >> stu2.sex;
	clear_input();
	cout << endl;
	while (stu2.sex != "男" && stu2.sex != "女") {
		cout << "版本过低，不接受其他性别" << endl << endl;
		cout << "请输入新学生性别(“男”或“女”)：  ";
		cin >> stu2.sex;
		clear_input();
		cout << endl;
	}

	//录入学号
	while (1) {
		cout << "请输入学号：  ";
		cin >> stu2.number;
		int k = 0;
		list<students>::iterator p;
		for (p = student.begin(); p != student.end(); p++) {
			if (p->number == stu2.number) {
				cout << "学号已重复！请重新输入" << endl;
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

	//录入年龄
	cout << "请输入年级(1~4)：  ";
	cin >> stu2.old;
	clear_input();
	while (stu2.old > 4 || stu2.old < 1) {
		cout << "该年级不存在！请重新输入!" << endl;
		cout << "请输入年级(1~4)：  ";
		cin >> stu2.old;
		clear_input();
		cout << endl;
	}

	//录入课程数
	switch (stu2.old){
	case 1:stu2.cla_num = 6; break;
	case 2:stu2.cla_num = 11; break;
	case 3:stu2.cla_num = 15; break;
	case 4:stu2.cla_num = 18; break;
	}

	//录入成绩
	float ee;
	for (int i = 0; i < stu2.cla_num; i++) {
		ee = judge_score(classs[i]);
		stu2.a[i].score =ee;
	}
	stu2.newscore();


	//录入总分
	stu2.newsum();

	//确认环节
	clear_ui();
	cout << "                   学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               导入新学生" << endl;
	cout << "===========================================================================" << endl;
	cout << "请确认录入信息" << endl << endl;
	cout << "================================================" << endl;
	show_student(stu2);
		
	if (judge_yn("是否导入(y / n)？")) {
		student.push_back(stu2);	//写入目前学生链

		ofstream student_write("students.txt",ios::app);	//创建写入流,写入文件
		student_write << stu2.name  << " " << stu2.sex << " " << stu2.number << " " << stu2.old << " " << stu2.cla_num << " " << stu2.sum << "  ";
		for (int i = 0; i < stu2.cla_num; i++) {
			student_write << stu2.a[i].score << " ";
		}
		student_write << endl;
		student_write.close();

		cout << "导入成功！\n输入回车后返回主界面" << endl;
		getchar();
		ui0();
	}
	else {
		cout << "录入取消，输入回车后继续" << endl;
		getchar();
		ui1();
	}
}

//修改界面----ui2
void ui2(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               修改系统" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.姓名" << endl;
	cout << "2.学号" << endl << endl;
	cout << "3.退出" << endl << endl;
	cout << "请选择查询方式：  ";
	int select;
	bool show = false;
	cin >> select;
	clear_input();
	while (select > 3 || select < 1) {
		cout << "该操作不存在，请重新输入！" << endl;
		cout << "请选择查询方式：  ";
		cin >> select;
		clear_input();
	}
	switch (select) {
	case 1:delet(find_name().number, 0); ui0;;
	case 2:delet(find_number().number, 0); ui0;
	case 3:ui0();
	}
}

//删除界面----ui3
void ui3(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               删除系统" << endl;
	cout << "===========================================================================" << endl << endl;
	cout << "1.姓名" << endl;
	cout << "2.学号" << endl << endl;
	cout << "3.退出" << endl << endl;
	cout << "请选择查询方式：  ";
	int select;
	bool show = false;
	cin >> select;
	clear_input();
	while (select > 3 || select < 1) {
		cout << "该操作不存在，请重新输入！" << endl;
		cout << "请选择查询方式：  ";
		cin >> select;
		clear_input();
	}
	switch (select) {
	case 1:delet(find_name().number, 1); ui0; break;
	case 2:delet(find_number().number, 1); ui0; break;
	case 3:ui0(); break;
	}
}

//以学号删除/修改元素
void delet(long long int number,int k) 
{	//k = 1:删除,k = 0：修改
	auto it = find_if(student.begin(), student.end(), [number](const students& s) {
		return s.number == number;
		});
	//按照学号是否相同，将相同（待删除的）移植末尾;
	if (k == 1) {
		cout << endl;
		show_student(*it);
		if (judge_yn("是否确认删除(y/n)？该操作不可逆！   ")) {
			student.erase(it);	//删除
		}
	}
	else {
		show_student(*it);
		cout << "请选择要修改的项  ";
		int select;
		cin >> select;
		clear_input();
		while (select < 0 || select >(*it).cla_num + 4) {
			cout << "操作不存在！\n请选择要修改的项  ";
			cin >> select;
			clear_input();
		}
		cout << endl;
		if (select == 1) {
			//录入名字
			cout << "请修改学生姓名：";
			cin >> (*it).name;
			cout << endl;
		}
		else if (select == 2) {
			//录入学号
			long long int y;
			while (1) {
				cout << "请修改学号：  ";
				cin >> y;
				int k = 0;
				list<students>::iterator p;
				for (p = student.begin(); p != student.end(); p++) {
					if (p->number == y ) {
						cout << "学号已重复！请重新输入" << endl;
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
			//录入性别
			cout << "请修改学生性别(“男”或“女”)：  ";
			cin >> (*it).sex;
			clear_input();
			cout << endl;
			while ((*it).sex != "男" && (*it).sex != "女") {
				cout << "版本过低，不接受其他性别" << endl << endl;
				cout << "请输入新学生性别(“男”或“女”)：  ";
				cin >> (*it).sex;
				clear_input();
				cout << endl;
			}
		}
		else if (select == 4) {
			//录入年龄
			cout << "请修改年级(1~4)：  ";
			cin >> (*it).old;
			clear_input();
			while ((*it).old > 4 || (*it).old < 1) {
				cout << "该年级不存在！请重新输入!" << endl;
				cout << "请修改年级(1~4)：  ";
				cin >> (*it).old;
				clear_input();
				cout << endl;
			}
			//修改课程数
			switch ((*it).old) {
			case 1:(*it).cla_num = 6; break;
			case 2:(*it).cla_num = 11; break;
			case 3:(*it).cla_num = 15; break;
			case 4:(*it).cla_num = 18; break;
			}
		}
		if (select > 3) {
			//录入成绩
			float ee;
			for (int i = 0; i < (*it).cla_num; i++) {
				if (i + 5 == select || (*it).a[i].score == -1) {
					ee = judge_score(classs[i]);
					(*it).a[i].score = ee;
				}
			}
			(*it).newscore();
			//录入总分
			(*it).newsum();
		}
		//确认环节
		cout << "================================================" << endl;
		cout << "请确认修改信息" << endl << endl;
		show_student(*it);

		if (judge_yn("是否导入(y / n)？")) {
			cout << "导入成功！" << endl;
		}
		else {
			cout << "修改取消" << endl;
			cout << "按任意键返回主页面" << endl;
			getchar();
			ui0();
		}
	}
	ofstream file;				//开始创建输入流
	file.open("students.txt");
	if (!file.is_open()) {
		cout << "警告！！文件打开失败！！请检查程序读写权限！！" << endl;//判断读取操作结果
		cout << "按任意键退出程序" << endl;
		getchar();
		exit(1);
	}
	list<students>::iterator p;			//重新整个导入
	for (p = student.begin(); p != student.end(); p++) {
		file << (*p).name << " " << (*p).sex << " " << (*p).number << " " << (*p).old << " " << (*p).cla_num << " " << (*p).sum << "  ";
		for (int i = 0; i < (*p).cla_num; i++) {
			file << (*p).a[i].score << " ";
		}
		file << endl;
	}
	cout << "按任意键返回主页面" << endl;
	getchar();
	file.close();
	ui0();
}

//查找界面----ui4
void ui4(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               查找系统" << endl;
	cout << "===========================================================================" << endl << endl;
	if (student.empty()) {
		cout << "学生数据为空，请导入后查询!" << endl << endl;
		cout << "按回车键返回主菜单" << endl;
		getchar();
		ui0();
	}
	select_way();
}

//选择查找方式
void select_way() {
	cout << "1.姓名" << endl;
	cout << "2.学号" << endl;
	cout << "3.学科" << endl;
	cout << "4.学年" << endl;
	cout << "5.总分(分年级)" << endl;
	cout << "6.展示全部信息" << endl << endl;
	cout << "7.返回主页面" << endl << endl;
	cout << "请选择查找方式：";
	int select;
	bool show = true;
	cin >> select;
	clear_input();
	while (select < 1 || select > 7) {
		cout << "操作非法！" << endl;
		cout << "请重新选择查找方式：  ";
		cin >> select;
		clear_input();
	}
	cout << "================================================" << endl;
	switch (select) {
	case 1: {
		show_student(find_name());
		cout << "按回车键返回";
		getchar();
		address_goal.clear();
		goal.clear();
		ui4();
	}break;
	case 2: {
		show_student(find_number());
		cout << "按回车键返回";
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
		for (p = student.begin(); p != student.end(); p++) {	//按学年分类好
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
			case 0: cout << "大一：" << endl << endl; break;
			case 1: cout << "大二：" << endl << endl; break;
			case 2: cout << "大三：" << endl << endl; break;
			case 3: cout << "大四：" << endl << endl; break;
			}
			if (term[u].size()) {
				sort(term[u].begin(), term[u].end(), compare);
				for (int t = 0; t < term[u].size(); t++) {
					cout << t + 1 << "." << term[u].at(t).name << term[u].at(t).number << "：" << term[u].at(t).sum << endl;
				}
			}
			else {
				cout << "该年级未录入学生！" << endl;
			}
		}
		cout << "================================================" << endl << endl;
		cout << "按回车键返回" << endl;
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
		cout << "按任意键返回" << endl;
		getchar();
		clear_input();
	}; ui4(); break;
	case 7: ui0();
	}
}

//以总分降序比较
bool compare(students a, students b) {
	return a.sum > b.sum;
}

//以姓名进行查询
students find_name()  {
	string name;
	cout << "请输入姓名：  ";
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

//以学号进行查询
students find_number() {
	long long int number;
	cout << "请输入学号：  ";
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

//以学科进行查询
void find_clas(void) {
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               查找系统" << endl;
	cout << "===========================================================================" << endl;
	cout << "大一：" << endl;
	cout << "1.高等数学" << endl;
	cout << "2.大学计算机信息导论" << endl;
	cout << "4.c语言程序设计" << endl;
	cout << "5.大学生心理健康教育" << endl;
	cout << "6.大学英语" << endl << endl;
	cout << "大二：" << endl;
	cout << "7.线性代数" << endl;
	cout << "8.Java程序设计" << endl;
	cout << "9.数据结构与算法" << endl;
	cout << "10.大学物理，" << endl;
	cout << "11.计算机网络" << endl << endl;
	cout << "大三：" << endl;
	cout << "12.网络编程" << endl;
	cout << "13.计算机组成原理" << endl;
	cout << "14.计算机操作系统" << endl;
	cout << "15.网络安全技术" << endl << endl;
	cout << "大四：" << endl;
	cout << "16.互联网应用开发" << endl;
	cout << "17.嵌入式系统" << endl;
	cout << "18.生产实习" << endl << endl << endl;
	cout << "请选择课程(输入序号)：  ";
	int select1;
	cin >> select1;
	clear_input();
	while (select1 < 0 || select1 > 18) {
		cout << "课程不存在，请重新输入！" << endl;
		cout << "请选择课程(输入序号)：  ";
		cin >> select1;
		clear_input();
	}
	int i =select1 - 1;
	clear_ui();
	cout << "                     学生管理系统内部测试v0.1（作业版）" << endl;
	cout << "                               查找系统" << endl;
	cout << "===========================================================================" << endl;
	cout << "当前选择： " << classs[i] << endl << endl;
	cout << "1.展示总体数据" << endl;
	cout << "2.以当前数据排序学生" << endl;
	cout << "3.查看分段人数" << endl << endl;
	cout << "4.返回主菜单" << endl << endl;
	cout << "请选择操作：  ";
	int select;
	cin >> select;
	clear_input();
	cout << endl;
	while (select < 1 || select > 4) {
		cout << "操作不存在，请重新输入！" << endl;
		cout << "请选择操作：  ";
		cin >> select;
		clear_input();
		cout << endl;
	}
	switch (select) {
	case 1: {
		vector<students>::iterator p;
		list<students>::iterator x;
		float sum = 0;//学科成绩和
		vector<students> /*有效学生副本*/copy,/*最低分学生*/min,/*最高分学生*/max,/*及格学生*/pass,/*不及格学生*/unpass;

		for (x = student.begin(); x != student.end(); x++) {	//拷贝有效的学生
			if (x->a[i].score != -1) {
				copy.push_back(*x);
				sum += x->a[i].score;
			}
		}
		if (copy.empty()) {
			cout << "暂未有学生获得成绩！\n\n回车后返回主界面";
			getchar();
			clear_input();
			ui0();
		}
		sum = sum / copy.size();//此时sum = 平均成绩
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//降序排序学生
			return a.a[i].score > b.a[i].score;
			});//Lambda表达式，从外界捕获i，进而判断https://www.bilibili.com/video/BV1fG41157Ew/?spm_id_from=333.337.search-card.all.click&vd_source=1599b1fe085b1fbd7be552c71b77fe79

		float max_score, min_score;
		max_score = copy.at(0).a[i].score;
		min_score = copy.at(copy.size() - 1).a[i].score;
		for (p = copy.begin(); p != copy.end(); p++) {		//分类处理学生
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
		cout << "平均成绩：  " << sum << endl;
		cout << "及格率：  " << (float(pass.size()) / copy.size()) * 100 << "%(及格：" << pass.size() << "不及格：" << unpass.size() << ")" << endl;
		cout << "================================================" << endl;
		cout << "最高分：  " << max_score << "(共" << max.size() << "人)" << endl << endl;
		for (int j = 0; j < max.size(); j++) {
			cout << j + 1 << "." <<max.at(j).name << "：" << max.at(j).number << endl;
		}
		cout << "================================================" << endl;
		cout << "最低分：  " << min_score << "(共" << min.size() << "人)" << endl << endl;
		for (int j = 0; j < min.size(); j++) {
			cout << j + 1 << "." << min.at(j).name <<  "：" << min.at(j).number << endl;
		}
		cout << "================================================" << endl;
		cout << "及格(" << "共" << pass.size() << "人)" << endl << endl;
		for (int j = 0; j < pass.size(); j++) {
			cout << j + 1 << "." << pass.at(j).name << "：" << pass.at(j).number << "：  " << pass.at(j).a[i].score << endl;
		}
		cout << "================================================" << endl;
		cout << "不及格(" << "共" << unpass.size() << "人)" << endl << endl;
		for (int j = 0; j < unpass.size(); j++) {
			cout << j + 1 <<  "." <<unpass.at(j).name << "：" << unpass.at(j).number << "：  " << unpass.at(j).a[i].score << endl;
		}
		cout << "================================================" << endl;
	}; break;

	case 2: {							//写case保证执行退出时不会运算，哪怕代码变多
		vector<students>::iterator p;
		list<students>::iterator x;
		float sum = 0;//学科成绩和
		vector<students> /*有效学生副本*/copy;

		for (x = student.begin(); x != student.end(); x++) {	//拷贝有效的学生
			if (x->a[i].score != -1) {
				copy.push_back(*x);
			}
		}
		if (copy.empty()) {
			cout << "暂未有学生获得成绩！\n\n回车后返回主界面";
			getchar();
			clear_input();
			ui0();
		}
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//降序排序学生
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
		vector<students> /*有效学生副本*/copy;
		int stunum[10] = { 0 };

		for (x = student.begin(); x != student.end(); x++) {	//拷贝有效的学生
			if (x->a[i].score != -1) {
				copy.push_back(*x);
			}
		}
		if (copy.empty()) {
			cout << "暂未有学生获得成绩！\n\n回车后返回主界面";
			getchar();
			clear_input();
			ui0();
		}
		sort(copy.begin(), copy.end(), [i](students a, students b) -> bool {	//降序排序学生
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
	cout << "请按回车键返回" << endl;
	getchar();
}

//以学期进行查询
void find_term(void){
	int old;
	cout << "请输入学年：  ";
	cin >> old;
	clear_input();
	cout << endl;
	list<students>::iterator p;
	for (p = student.begin(); p != student.end(); p++) {	//拷贝有效数组
		if (p->old == old) {
			goal.push_back(*p);
			address_goal.push_back(p);
		}
	}
	show_student(show_list());
	cout << "按回车键返回";
	getchar();
	address_goal.clear();
	address_goal.resize(0);
	goal.clear();
	goal.resize(0);
	ui4();
}

//展示面板,展示goal，并选择
students show_list() {
	cout << "================================================" << endl;
	if (goal.empty()) {
		cout << "未查询到相关信息\n\n按回车键返回主界面" << endl;
		getchar();
		ui0();
	}
	else {
		vector<students>::iterator p;
		int i = 0;
		for (p = goal.begin(),i = 1; p < goal.end(); p++,i++) {
			cout << i << ".  " << "姓名：" << p->name << "  " << "学号：" << p -> number << endl;
		}
		cout << "================================================" << endl << endl;
		cout << "请选择学生序号:  ";
		int select;
		cin >> select;
		clear_input();
		while (select < 0 || select > goal.size()) {
			cout << "输入非法!请重新输入!(输入回车后继续)" << endl;
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

//录入数据，进入界面
int main(void) {
	ifstream student_read;
	student_read.open("students.txt");	//创建读取流

	if (!student_read.is_open()) {
		cout << "警告！！文件打开失败！！请检查程序读写权限！！" << endl;//判断读取操作结果
		cout << "按任意键退出程序" << endl;
		getchar();
		return 1;
	}
	string stu, a;
	while (getline(student_read, stu)) {
		if (stu.size() == 0) {		//空行(被删除),o跳过;
			continue;
		}
		students std1;		//创建临时学生信息
		istringstream iss(stu);	//将每行数据（每个学生）依次存入
		iss >> std1.name >> std1.sex >> std1.number >> std1.old >> std1.cla_num >> std1.sum;
		int i = 0;
		while (iss >> std1.a[i].score) {//录入每科成绩
			i++;
		}
		std1.newscore();
		student.push_back(std1);
	}
	student_read.close();
	ui0();
	return 0;
}
