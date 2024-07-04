#include <bits/stdc++.h>
using namespace std;
char* seekCreator(char* fileName, int line) {//找到提单人 
	FILE* fp;
	char* ch, * ah;
	ch = (char*)malloc(sizeof(char) * 100);
	ah = (char*)malloc(sizeof(char) * 100);
	fp = fopen(fileName, "r");
	int i = 0;
	if (fp == NULL) {
		printf("Open filefailure!");
		exit(1);
	}
	else {
		fscanf(fp, "%s%s", ah, ch);
		for (int i = 2; i <= line; i++) {//在第二排，line等于2 
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s", ah);
			if (!strcmp(ah, "付款结束")) fscanf(fp, "%s", ah);
			else fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s", ch);
		}
		return ch;
		free(ch); free(ah);
		fclose(fp);
	}
}
//ofstream file_writer1("shenpidan.txt", ios_base::out); 
void read(string fileName);
int seekPrice(char* fileName, int line);
void autoAssign() {
	FILE* fp1, * fp2, * f;
	char* ch, * ah; int i = 1, j = 0, line = 1;//i是行计数 
	char* ren;
	char* tooll;
	tooll = (char*)malloc(sizeof(char) * 100);
	ren = (char*)malloc(sizeof(char) * 100);
	ch = (char*)malloc(sizeof(char) * 100);
	ah = (char*)malloc(sizeof(char) * 100);
	fp1 = fopen("Reimbursehanded.txt", "r");
	f = fp1;
	fp2 = fopen("tool.txt", "w+");
	ofstream file_writer1("tool.txt", ios_base::out);
	fscanf(fp1, "%s", ch);//往文件2里面复制 
	fprintf(fp2, "%s\t", ch);
	while (!feof(fp1)) {//当需要改变的文件不到末尾时 
		j++;
		if (j == 6) {
			j = 0;
			fprintf(fp2, "\n");//换行 
			i++;
		}
		if (strcmp(ch, "提单日期") == 0) fprintf(fp2, "\t");
		if (strcmp(ch, "状态") == 0) fprintf(fp2, "\t");

		if (strcmp(ch, "部门审批") == 0) {//如果复制的串是部门审批 
			if (seekPrice((char*)"Reimbursehanded.txt", i) <= 50000) ren = (char*)"001";
			else ren = (char*)"003";
			fprintf(fp2, "\t");
			fprintf(fp2, "%s", ren);//向后写入审批人 
			fscanf(fp1, "%s", ch);//跳过原有处理人
			f = fp1;
			if (fgetc(f) == -1) break;
			j++;
			if (j == 6) {
				j = 0;
				fprintf(fp2, "\n");
				i++;
			}
		}
		else if (strcmp(ch, "财务审批") == 0) {//如果复制的串是财务审批 
			if (seekPrice((char*)"Reimbursehanded.txt", i) <= 50000) ren = (char*)"002";
			else ren = (char*)"004";
			fprintf(fp2, "\t");
			fprintf(fp2, "%s", ren);//向后写入审批人 
			fscanf(fp1, "%s", ah);//跳过原有处理人
			f = fp1;
			if (fgetc(f) == -1) break;
			j++;
			if (j == 6) {
				j = 0;
				fprintf(fp2, "\n");//换行 
				i++;
			}
		}
		else if (strcmp(ch, "付款结束") == 0) {
			j = 0;
			fprintf(fp2, "\n");
			i++;
		}
		else if (strcmp(ch, "创建") == 0) {
			//			i++;
			strcpy(tooll, ch);
			//			fprintf(fp2,seekCreator("Reimbursehanded.txt",i));
			fprintf(fp2, "\t");
		}
		fscanf(fp1, "%s", ch);
		f = fp1;
		if (strcmp(tooll, "创建") == 0) {
			strcpy(tooll, "");
			cout << "asdfhsd";
			fputs(seekCreator("Reimbursehanded.txt", i), fp2);
			continue;
		}
		if (fgetc(f) == -1) break;
		fprintf(fp2, "%s\t", ch);
	}
	//	ofstream file_writer2("ceshiassign.txt", ios_base::out);
	//	copyfile((char*)"tool.txt",(char*)"ceshiassign.txt");
	fclose(fp1);
	fclose(fp2);
	fclose(f);
}
int getTotal(char* fileName) {//获得文件的总行数i=2,i<total
	fstream fin(fileName, ios::in);
	if (!fin) {
		cerr << "can not open file" << endl;
		return -1;
	}
	char c;
	int lineCnt = 0;
	while (fin.get(c))
	{
		if (c == '\n')
			lineCnt++;
	}
	fin.close();
	return lineCnt + 1;
}
char* seekPerson(char* fileName, int line) {//查找文件中第line排的处理人,一排6个 
	FILE* fp;
	char* ch, * ah;
	ch = (char*)malloc(sizeof(char) * 100);
	ah = (char*)malloc(sizeof(char) * 100);
	fp = fopen(fileName, "r");
	int i = 0;
	if (fp == NULL) {
		printf("Open filefailure!");
		exit(1);
	}
	else {
		for (int i = 1; i <= line; i++) {//在第二排，line等于2 
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s", ah);
			if (!strcmp(ah, "付款结束")) continue;
			else fscanf(fp, "%s", ch);
		}
		return ch;
		free(ch); free(ah);
		fclose(fp);
	}
}
void copyfile(char* name1, char* name2) {//把name1文件复制给name2文件了 
	char ch;
	FILE* pfr = fopen(name1, "r");//把路径改成你文件的路径
	FILE* pfw = fopen(name2, "w");//把路径改成你文件的路径
	if (NULL == pfw) {
		perror("open file test2.txt");
	}
	if (NULL == pfr) {
		perror("open file test1.txt");
	}
	//不断的从源文件中读取字符并写入目的文件中，直到遇到EOF结束这个过程
	while ((ch = fgetc(pfr)) != EOF) {//EOF是文件结束标志
		fputc(ch, pfw);
	}
	fclose(pfr);
	fclose(pfw);
	pfr = NULL;
	pfw = NULL;
}
int seekPrice(char* fileName, int line) {//查找文件中第line排的金额,一排6个 
	FILE* fp;
	char* ch, * ah;
	ch = (char*)malloc(sizeof(char) * 100);
	ah = (char*)malloc(sizeof(char) * 100);
	fp = fopen(fileName, "r");
	int i = 0;
	if (fp == NULL) {
		printf("Open filefailure!");
		exit(1);
	}
	else {
		fscanf(fp, "%s%s", ah, ch);
		fscanf(fp, "%s", ch);
		for (int i = 1; i < line; i++) {//在第二排，line等于2 
			fscanf(fp, "%s%s", ah, ch);
			if (!strcmp(ch, "付款结束")) fscanf(fp, "%s", ch);
			else fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s%s", ah, ch);
		}
	}
	string s(ch);//将char*转为string 
	int kind = atoi(s.c_str());//将string转为int，便于比较 
	free(ch); free(ah);
	fclose(fp);
	return kind;
}
int match(string number) {//根据审批人序号得出相应额度 
	ifstream fin;
	fin.open("Power.txt", ios::in);
	int line = 0;
	int a = 0;
	string buff;
	while (getline(fin, buff)) {
		string::size_type idx;
		idx = buff.find(number);
		line++;
		if (idx != string::npos) {
			break;
		}
	}
	fin.close();

	FILE* fp;
	char* ch, * ah;
	ch = (char*)malloc(sizeof(char) * 100);
	ah = (char*)malloc(sizeof(char) * 100);
	fp = fopen("Power.txt", "r");
	rewind(fp);
	fscanf(fp, "%s%s", ah, ch);
	fscanf(fp, "%s%s", ah, ch);
	//    cout<<ch<<endl;
	for (int i = 1; i < line; i++) {//在第二排，line等于2 
		fscanf(fp, "%s%s", ah, ch);
		fscanf(fp, "%s%s", ah, ch);
		//        fscanf(fp, "%s",ch);
		//      fscanf(fp, "%s%s", ah,ch);
	}
	string s(ch);//将char*转为string 
	a = atoi(s.c_str());//将string转为int，便于比较 
	free(ch); free(ah);
	fclose(fp);
	return a;
}
string& replace1(string& str, const string& old_value, const string& new_value) {
	while (true) {
		string::size_type  pos(0);
		if ((pos = str.find(old_value)) != string::npos) {
			str.replace(pos, old_value.length(), new_value);
		}

		else   break;
	}
	return   str;
}
string& replacelast(string& str, const   string& old_value, const   string& new_value) {//不换第一个 
	int i = 0;
	while (true) {
		string::size_type  pos(0);
		if ((pos = str.find(old_value, 10)) != string::npos) {//从10开始找 
			str.replace(pos, old_value.length(), new_value);
			//			str.replace();
		}
		else break;
	}
	return   str;
}
void addReimburse() {//增加报销人员信息 
	fstream f;//追加写入,在原来基础上加了ios::app 
	f.open("Reimburse.txt", ios::out | ios::app);
	string no, name, phone;
	cout << "请按顺序输入工号 姓名 手机号" << endl;
	cin >> no >> name >> phone;
	//输入你想写入的内容 
	f << no << "	" << name << "	" << phone << endl;
	f.close();
}
void addJudge() {//增加审核人员信息 
	fstream f;
	f.open("Judge.txt", ios::out | ios::app);
	string no, name, phone, personnal;
	cout << "请按顺序输入工号 姓名 手机号 角色" << endl;
	cin >> no >> name >> phone >> personnal;
	f << no << "	" << name << "	" << phone << "		" << personnal << endl;
	f.close();
}
void addform() {//提交报销单 
	fstream f;
	f.open("Reimbursehanded.txt", ios::out | ios::app);
	string no, price, date, personnal;
	srand((unsigned)time(NULL));
	int a = rand() % 10000 + 1000;
	cout << "请按顺序输入提单人工号 提单人金额 提单日期" << endl;
	cin >> no >> price >> date;
	f << date[0] << date[1] << date[2] << date[3] << a << "	" << no << "	" << price << "	" << date << "		" << "部门审批" << "		" << no << endl;
	f.close();
}
/*测试find函数
	string a="abcdefghigklmn";
	string b="def";
	string c="123";
	string::size_type idx;
	idx=a.find(b);//在a中查找b.
	if(idx != string::npos )//存在。
		cout << "not found\n";
		*/
		/*
		ofstream out("abc.txt");
   out << 3 << '\t' << "abc" << endl;
  out.close( );
  */
void bumenSet() {
	ifstream fin;
	//	string a="创建"; 
	string::size_type idx;
	string number;
	fin.open("Reimbursehanded.txt", ios::in);
	int i = 1;
	cout << "您的审批人序号为：" << endl;
	cin >> number;
	int limit = match(number);
	cout << "您的审批权限金额为：" << limit << endl;
	string buff;
	cout << "以下为所有符合权限的待审批单号" << endl;
	cout << "报销单编号	提单人	提单金额	   提单日期	   状态		处理人" << endl;
	//	ofstream file_writer("Reimbursehanded.txt", ios_base::out);//文件内容 
	while (getline(fin, buff)) {//在shenpidan.txt中写入只有创建的所有条目 
		idx = buff.find(number);
		//		cout<<"*/*/*/*/*/*//*"<<endl;
		//		cout<<seekPrice("Reimbursehanded.txt",i++)<<endl;
		//		cout<<"*/*/*/*/*/*//*"<<endl;
		//		if(seekPrice((char*)"Reimbursehanded.txt",i++)>limit) continue;
		if (idx != string::npos) {//把创建中的条目写入审批单 
//			fstream f;
//			f.open("shenpidan.txt",ios::out|ios::app);
//			string no,name,phone,personnal;
////			if(seekPrice("Reimbursehanded.txt",i++)>50000) continue;
//			f<<buff<<endl;
//			f.close();
////			ofstream out("shenpidan.txt");
////  		out << buff<< endl;
//// 			out.close( );
			cout << buff << endl;
		}
	}
	//	read("shenpidan.txt");
	cout << "输入想操作的报销单编号" << endl;
	string x;
	cin >> x;
	cout << "此报销单信息如下" << endl;
	ifstream fin2;
	fin2.open("Reimbursehanded.txt", ios::in);
	string buff2;//单一报销单条目 
	while (getline(fin2, buff2)) {
		idx = buff2.find(x);//筛选出想操作的报销单编号 
		if (idx != string::npos)
			cout << buff2 << endl;
	}
	fin2.close();
	int judge;
	cout << "输入1为通过 输入0为驳回";
	cin >> judge;
	//先把Reimbursehanded.txt复制到shenpidan.txt 
//	ifstream fin3;
//	fin3.open("Reimbursehanded.txt", ios::in);
//	string buff3;
//	ofstream file_writer1("shenpidan.txt", ios_base::out);//写入前先清空文件 
//	while (getline(fin3, buff3)){
//		/*
//			ofstream out3("shenpidan.txt");
//			string::size_type idx3;
//    		idx3=buff3.find(x);//在Reimbursehanded中查找x,即想审批的条目.
//			if(idx3 == string::npos) out3 << buff3 << endl;//想审批的那一个单号不复制 
// 			out3.close( );*/
// 			fstream f3;//追加写入,在原来基础上加了ios::app 
//			f3.open("shenpidan.txt",ios::out|ios::app);
//			string::size_type idx3;
//    		idx3=buff3.find(x);//在Reimbursehanded中查找x,即想审批的条目.
//			if(idx3 == string::npos) f3<<buff3<<endl;//想审批的那一个单号不复制 
//			f3.close();
// 			
//	}
//	//x是操作单编号 
//	fin3.close();
	int line = 0, flag = 0;
	string buff5;
	if (judge) {
		ifstream fin5;
		fin5.open("Reimbursehanded.txt", ios::in);
		FILE* fp;
		fp = fopen("Reimbursehanded.txt", "rb+");
		//		string::size_type idx;
		//    	idx=buff2.find(x);//在a中查找b.
		//		if(idx != string::npos) cout<<buff2<<endl;
		//		replace1(line,"创建","部门审批");
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			cout << line;
			if (idx5 != string::npos) {
				//			cout<<"这个人在第"<<line<<endl;
				flag = 1;
				//			cout<<"before buff5   "<<buff5<<endl;
				//			replace1(buff5,"部门审批","财务审批");//把部门审批变为财务审批 
				//			fseek( fp, 29+42*line, SEEK_SET );//将文件指针移到此行的部门审批前 
				char s[100];
				for (int u = 0; u < line - 1; u++)
					fgets(s, 100, fp);
				fseek(fp, 28, SEEK_CUR);
				fputs("财务审批		", fp);
				fclose(fp);
				//			fputs("财务审批		", fp);
				//			cout<<"after buff5   "<<buff5<<endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//先清空目标文件，再将临时文件复制给它 
				break;
				//			replacelast(buff5,seekPerson((char*)"Reimbursehanded.txt",line),number);//把处理人变为自己 
							//把buff5写入shenpidan.txt
				//			fstream f;
				//			f.open("shenpidan.txt",ios::out|ios::app);
				////			string no,name,phone,personnal;
				////			cout<<"请按顺序输入工号 姓名 手机号 角色"<<endl; 
				////			cin>>no>>name>>phone>>personnal;
				//			f<<buff5<<endl;
				//			f.close(); 
			}

		}
		if (!flag) cout << "未找到目标审批单，请检查是否输入错误" << endl;
		else cout << "审批通过，已重新匹配" << endl;
		//	fin5.close();
		//	read("shenpidan.txt");
		//	copyfile((char*)"shenpidan.txt",(char*)"Reimbursehanded.txt");
	}
	else {//把部门审批变为创建 
		ifstream fin5;
		fin5.open("Reimbursehanded.txt", ios::in);
		//		string::size_type idx;
		//    	idx=buff2.find(x);//在a中查找b.
		//		if(idx != string::npos) cout<<buff2<<endl;
		//		replace1(line,"创建","部门审批");
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			replace1(buff5, "部门审批", "创建");

			cout << "审批不通过" << endl;
		}
		fin.close();
		//	fclose(fp);
	}
}
void caiwuSet() {
	ifstream fin;
	string::size_type idx;
	string number;
	fin.open("Reimbursehanded.txt", ios::in);
	int i = 1;
	cout << "您的审批人序号为：" << endl;
	cin >> number;
	int limit = match(number);
	cout << "您的审批权限金额为：" << limit << endl;
	string buff;
	cout << "以下为所有符合权限的待审批单号" << endl;
	cout << "报销单编号	提单人	提单金额	提单日期	   状态		处理人" << endl;
	while (getline(fin, buff)) {//在shenpidan.txt中写入只有创建的所有条目 
		idx = buff.find(number);
		if (idx != string::npos) {//把创建中的条目写入审批单 
			cout << buff << endl;
		}
	}
	cout << "输入想操作的报销单编号" << endl;
	string x;
	cin >> x;
	cout << "此报销单信息如下" << endl;
	ifstream fin2;
	fin2.open("Reimbursehanded.txt", ios::in);
	string buff2;//单一报销单条目 
	while (getline(fin2, buff2)) {
		idx = buff2.find(x);//筛选出想操作的报销单编号 
		if (idx != string::npos)
			cout << buff2 << endl;
	}
	fin2.close();
	int judge;
	cout << "输入1为通过 输入0为驳回";
	cin >> judge;
	int line = 0, flag = 0;
	string buff5;
	if (judge) {
		ifstream fin5;
		fin5.open("Reimbursehanded.txt", ios::in);
		FILE* fp;
		fp = fopen("Reimbursehanded.txt", "rb+");
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			cout << line;
			if (idx5 != string::npos) {
				flag = 1;
				char s[100];
				for (int u = 0; u < line - 1; u++) fgets(s, 100, fp);
				line = 0;
				fseek(fp, 28, SEEK_CUR);
				fputs("付款结束					", fp);//变更状态 
				fclose(fp);
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//先清空目标文件，再将临时文件复制给它 
				break;
			}
		}
		if (!flag) cout << "未找到目标审批单，请检查是否输入错误" << endl;
		else cout << "审批通过，已重新匹配" << endl;
	}
	else {//把财务审批变为创建 
		ifstream fin5;
		FILE* fp;
		fp = fopen("Reimbursehanded.txt", "rb+");
		fin5.open("Reimbursehanded.txt", ios::in);
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			cout << line << endl;
			char* person;
			if (idx5 != string::npos) {
				char s[100];
				for (int u = 1; u < line; u++) fgets(s, 100, fp);
				line = 0;
				fseek(fp, 28, SEEK_CUR);
				fputs("创建    ", fp);
				//			fputs("创建    ", fp);
				fclose(fp);
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//先清空目标文件，再将临时文件复制给它 
				break;
			}
			fclose(fp);
		}
		cout << "审批不通过" << endl;
		fin.close();
	}
}
void read(string fileName) {
	ifstream fin;
	fin.open(fileName, ios::in);
	int i = 0;
	string buff;
	while (getline(fin, buff)) {
		cout << buff << endl;
	}
	fin.close();
}

int menu0() {
	cout << "输入想要的操作序号" << endl;
	cout << "1.报销人员管理" << endl;
	cout << "2.审批人员管理" << endl;
	cout << "3.查询审批人额度信息" << endl;
	cout << "4.查询现有报销单信息" << endl;
	cout << "0.退出系统" << endl;
	int x; cin >> x;
	return x;
}
int menu123(int x) {//报销管理里的操作 
	if (x == 1) {
		cout << "输入想要的操作序号" << endl;
		cout << "1.查询报销人员信息" << endl;//
		cout << "2.增加报销人员信息" << endl;//
		cout << "3.修改报销人员信息" << endl;
		cout << "4.删除报销人员信息" << endl;
		cout << "5.提交报销单" << endl;
		cout << "0.退出系统" << endl;
		int y; cin >> y;
		return y;
	}
	else if (x == 2) {
		cout << "输入想要的操作序号" << endl;
		cout << "1.查询审批人员信息" << endl;
		cout << "2.增加审批人员信息" << endl;
		cout << "3.修改审批人员信息" << endl;
		cout << "4.删除审批人员信息" << endl;
		cout << "5.进行部门审批" << endl;
		cout << "6.进行财务审批" << endl;
		cout << "0.退出系统" << endl;
		int y; cin >> y;
		return y;
	}
}
int main() {
	int x = 12;
	while (x) {
		int y = menu0();
		if (!y) break;
		int k = menu123(y);
		if (!k) break;
		switch (y) {
		case(1)://报销人员管理 
			if (k == 1) {
				system("cls");
				read("Reimburse.txt");
			}
			else if (k == 2) {
				system("cls");
				cout << "在增加了在增加了......" << endl;
				addReimburse();
			}
			else if (k == 3) {
				cout << "建设中QwQ。。。" << endl;
			}
			else if (k == 4) {
				cout << "建设中QwQ。。。" << endl;
			}
			else if (k == 5) {
				system("cls");
				addform();
			}
			break;
		case(2)://审批人员管理 
			if (k == 1) {
				system("cls");
				read("Judge.txt");
			}
			else if (k == 2) {
				system("cls");
				//					cout<<"在增加了在增加了......"<<endl;
				addJudge();
			}
			else if (k == 3) {
				cout << "建设中QwQ。。。" << endl;
			}
			else if (k == 4) {
				cout << "建设中QwQ。。。" << endl;
			}
			else if (k == 5) {
				system("cls");
				cout << "已自动进行审批分配，改动存入Reimbursehanded.txt文件" << endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//先清空目标文件，再将临时文件复制给它 
				bumenSet();
			}
			else if (k == 6) {
				system("cls");
				cout << "已自动进行审批分配，改动存入Reimbursehanded.txt文件" << endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//先清空目标文件，再将临时文件复制给它 
				caiwuSet();
			}
			break;
		case(3)://查询审批人额度信息
			system("cls");
			read("Power.txt");
			break;
		case(4)://查询现有报销单信息
			system("cls");
			read("Reimbursehanded.txt");
			break;
		}
	}
	return 0;
}
/*测试find函数
	string a="abcdefghigklmn";
	string b="def";
	string c="123";
	string::size_type idx;
	idx=a.find(b);//在a中查找b.
	if(idx == string::npos )//不存在。
		cout << "not found\n";
	else//存在。
		cout <<"found\n"; */
		//void readReimbursehanded(){
		//	ifstream fin;
		//	fin.open("Reimbursehanded.txt", ios::in);
		//	int i=0;
		//	string buff;
		//	while (getline(fin, buff)){
		//		cout<<buff<<endl;
		//	}
		//	fin.close();
		//}
		//void readshenpidan(){
		//	ifstream fin;
		//	fin.open("shenpidan.txt", ios::in);
		//	int i=0;
		//	string buff;
		//	while (getline(fin, buff)){
		//		cout<<buff<<endl;
		//	}
		//	fin.close();
		//}
		//void readReimburse(){
		//	ifstream fin;
		//	fin.open("Reimburse.txt", ios::in);
		//	int i=0;
		//	string buff;
		//	while (getline(fin, buff)){
		//		cout<<buff<<endl;
		//	}
		//	fin.close();
		//}
		//void readJudge(){
		//	ifstream fin;
		//	fin.open("Judge.txt", ios::in);
		//	int i=0;
		//	string buff;
		//	while (getline(fin, buff)){
		//		cout<<buff<<endl;
		//	}
		//	fin.close();
		//}
		///*
		//void readPower(){
		//	ifstream fin;
		//	fin.open("Power.txt", ios::in);
		//	int i=0;
		//	string buff;
		//	while (getline(fin, buff)){
		//		cout<<buff<<endl;
		//	}
		//	fin.close();
		//}
		//*/
