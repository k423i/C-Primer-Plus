#include <bits/stdc++.h>
using namespace std;
char* seekCreator(char* fileName, int line) {//�ҵ��ᵥ�� 
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
		for (int i = 2; i <= line; i++) {//�ڵڶ��ţ�line����2 
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s", ah);
			if (!strcmp(ah, "�������")) fscanf(fp, "%s", ah);
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
	char* ch, * ah; int i = 1, j = 0, line = 1;//i���м��� 
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
	fscanf(fp1, "%s", ch);//���ļ�2���渴�� 
	fprintf(fp2, "%s\t", ch);
	while (!feof(fp1)) {//����Ҫ�ı���ļ�����ĩβʱ 
		j++;
		if (j == 6) {
			j = 0;
			fprintf(fp2, "\n");//���� 
			i++;
		}
		if (strcmp(ch, "�ᵥ����") == 0) fprintf(fp2, "\t");
		if (strcmp(ch, "״̬") == 0) fprintf(fp2, "\t");

		if (strcmp(ch, "��������") == 0) {//������ƵĴ��ǲ������� 
			if (seekPrice((char*)"Reimbursehanded.txt", i) <= 50000) ren = (char*)"001";
			else ren = (char*)"003";
			fprintf(fp2, "\t");
			fprintf(fp2, "%s", ren);//���д�������� 
			fscanf(fp1, "%s", ch);//����ԭ�д�����
			f = fp1;
			if (fgetc(f) == -1) break;
			j++;
			if (j == 6) {
				j = 0;
				fprintf(fp2, "\n");
				i++;
			}
		}
		else if (strcmp(ch, "��������") == 0) {//������ƵĴ��ǲ������� 
			if (seekPrice((char*)"Reimbursehanded.txt", i) <= 50000) ren = (char*)"002";
			else ren = (char*)"004";
			fprintf(fp2, "\t");
			fprintf(fp2, "%s", ren);//���д�������� 
			fscanf(fp1, "%s", ah);//����ԭ�д�����
			f = fp1;
			if (fgetc(f) == -1) break;
			j++;
			if (j == 6) {
				j = 0;
				fprintf(fp2, "\n");//���� 
				i++;
			}
		}
		else if (strcmp(ch, "�������") == 0) {
			j = 0;
			fprintf(fp2, "\n");
			i++;
		}
		else if (strcmp(ch, "����") == 0) {
			//			i++;
			strcpy(tooll, ch);
			//			fprintf(fp2,seekCreator("Reimbursehanded.txt",i));
			fprintf(fp2, "\t");
		}
		fscanf(fp1, "%s", ch);
		f = fp1;
		if (strcmp(tooll, "����") == 0) {
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
int getTotal(char* fileName) {//����ļ���������i=2,i<total
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
char* seekPerson(char* fileName, int line) {//�����ļ��е�line�ŵĴ�����,һ��6�� 
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
		for (int i = 1; i <= line; i++) {//�ڵڶ��ţ�line����2 
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s", ah);
			if (!strcmp(ah, "�������")) continue;
			else fscanf(fp, "%s", ch);
		}
		return ch;
		free(ch); free(ah);
		fclose(fp);
	}
}
void copyfile(char* name1, char* name2) {//��name1�ļ����Ƹ�name2�ļ��� 
	char ch;
	FILE* pfr = fopen(name1, "r");//��·���ĳ����ļ���·��
	FILE* pfw = fopen(name2, "w");//��·���ĳ����ļ���·��
	if (NULL == pfw) {
		perror("open file test2.txt");
	}
	if (NULL == pfr) {
		perror("open file test1.txt");
	}
	//���ϵĴ�Դ�ļ��ж�ȡ�ַ���д��Ŀ���ļ��У�ֱ������EOF�����������
	while ((ch = fgetc(pfr)) != EOF) {//EOF���ļ�������־
		fputc(ch, pfw);
	}
	fclose(pfr);
	fclose(pfw);
	pfr = NULL;
	pfw = NULL;
}
int seekPrice(char* fileName, int line) {//�����ļ��е�line�ŵĽ��,һ��6�� 
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
		for (int i = 1; i < line; i++) {//�ڵڶ��ţ�line����2 
			fscanf(fp, "%s%s", ah, ch);
			if (!strcmp(ch, "�������")) fscanf(fp, "%s", ch);
			else fscanf(fp, "%s%s", ah, ch);
			fscanf(fp, "%s%s", ah, ch);
		}
	}
	string s(ch);//��char*תΪstring 
	int kind = atoi(s.c_str());//��stringתΪint�����ڱȽ� 
	free(ch); free(ah);
	fclose(fp);
	return kind;
}
int match(string number) {//������������ŵó���Ӧ��� 
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
	for (int i = 1; i < line; i++) {//�ڵڶ��ţ�line����2 
		fscanf(fp, "%s%s", ah, ch);
		fscanf(fp, "%s%s", ah, ch);
		//        fscanf(fp, "%s",ch);
		//      fscanf(fp, "%s%s", ah,ch);
	}
	string s(ch);//��char*תΪstring 
	a = atoi(s.c_str());//��stringתΪint�����ڱȽ� 
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
string& replacelast(string& str, const   string& old_value, const   string& new_value) {//������һ�� 
	int i = 0;
	while (true) {
		string::size_type  pos(0);
		if ((pos = str.find(old_value, 10)) != string::npos) {//��10��ʼ�� 
			str.replace(pos, old_value.length(), new_value);
			//			str.replace();
		}
		else break;
	}
	return   str;
}
void addReimburse() {//���ӱ�����Ա��Ϣ 
	fstream f;//׷��д��,��ԭ�������ϼ���ios::app 
	f.open("Reimburse.txt", ios::out | ios::app);
	string no, name, phone;
	cout << "�밴˳�����빤�� ���� �ֻ���" << endl;
	cin >> no >> name >> phone;
	//��������д������� 
	f << no << "	" << name << "	" << phone << endl;
	f.close();
}
void addJudge() {//���������Ա��Ϣ 
	fstream f;
	f.open("Judge.txt", ios::out | ios::app);
	string no, name, phone, personnal;
	cout << "�밴˳�����빤�� ���� �ֻ��� ��ɫ" << endl;
	cin >> no >> name >> phone >> personnal;
	f << no << "	" << name << "	" << phone << "		" << personnal << endl;
	f.close();
}
void addform() {//�ύ������ 
	fstream f;
	f.open("Reimbursehanded.txt", ios::out | ios::app);
	string no, price, date, personnal;
	srand((unsigned)time(NULL));
	int a = rand() % 10000 + 1000;
	cout << "�밴˳�������ᵥ�˹��� �ᵥ�˽�� �ᵥ����" << endl;
	cin >> no >> price >> date;
	f << date[0] << date[1] << date[2] << date[3] << a << "	" << no << "	" << price << "	" << date << "		" << "��������" << "		" << no << endl;
	f.close();
}
/*����find����
	string a="abcdefghigklmn";
	string b="def";
	string c="123";
	string::size_type idx;
	idx=a.find(b);//��a�в���b.
	if(idx != string::npos )//���ڡ�
		cout << "not found\n";
		*/
		/*
		ofstream out("abc.txt");
   out << 3 << '\t' << "abc" << endl;
  out.close( );
  */
void bumenSet() {
	ifstream fin;
	//	string a="����"; 
	string::size_type idx;
	string number;
	fin.open("Reimbursehanded.txt", ios::in);
	int i = 1;
	cout << "�������������Ϊ��" << endl;
	cin >> number;
	int limit = match(number);
	cout << "��������Ȩ�޽��Ϊ��" << limit << endl;
	string buff;
	cout << "����Ϊ���з���Ȩ�޵Ĵ���������" << endl;
	cout << "���������	�ᵥ��	�ᵥ���	   �ᵥ����	   ״̬		������" << endl;
	//	ofstream file_writer("Reimbursehanded.txt", ios_base::out);//�ļ����� 
	while (getline(fin, buff)) {//��shenpidan.txt��д��ֻ�д�����������Ŀ 
		idx = buff.find(number);
		//		cout<<"*/*/*/*/*/*//*"<<endl;
		//		cout<<seekPrice("Reimbursehanded.txt",i++)<<endl;
		//		cout<<"*/*/*/*/*/*//*"<<endl;
		//		if(seekPrice((char*)"Reimbursehanded.txt",i++)>limit) continue;
		if (idx != string::npos) {//�Ѵ����е���Ŀд�������� 
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
	cout << "����������ı��������" << endl;
	string x;
	cin >> x;
	cout << "�˱�������Ϣ����" << endl;
	ifstream fin2;
	fin2.open("Reimbursehanded.txt", ios::in);
	string buff2;//��һ��������Ŀ 
	while (getline(fin2, buff2)) {
		idx = buff2.find(x);//ɸѡ��������ı�������� 
		if (idx != string::npos)
			cout << buff2 << endl;
	}
	fin2.close();
	int judge;
	cout << "����1Ϊͨ�� ����0Ϊ����";
	cin >> judge;
	//�Ȱ�Reimbursehanded.txt���Ƶ�shenpidan.txt 
//	ifstream fin3;
//	fin3.open("Reimbursehanded.txt", ios::in);
//	string buff3;
//	ofstream file_writer1("shenpidan.txt", ios_base::out);//д��ǰ������ļ� 
//	while (getline(fin3, buff3)){
//		/*
//			ofstream out3("shenpidan.txt");
//			string::size_type idx3;
//    		idx3=buff3.find(x);//��Reimbursehanded�в���x,������������Ŀ.
//			if(idx3 == string::npos) out3 << buff3 << endl;//����������һ�����Ų����� 
// 			out3.close( );*/
// 			fstream f3;//׷��д��,��ԭ�������ϼ���ios::app 
//			f3.open("shenpidan.txt",ios::out|ios::app);
//			string::size_type idx3;
//    		idx3=buff3.find(x);//��Reimbursehanded�в���x,������������Ŀ.
//			if(idx3 == string::npos) f3<<buff3<<endl;//����������һ�����Ų����� 
//			f3.close();
// 			
//	}
//	//x�ǲ�������� 
//	fin3.close();
	int line = 0, flag = 0;
	string buff5;
	if (judge) {
		ifstream fin5;
		fin5.open("Reimbursehanded.txt", ios::in);
		FILE* fp;
		fp = fopen("Reimbursehanded.txt", "rb+");
		//		string::size_type idx;
		//    	idx=buff2.find(x);//��a�в���b.
		//		if(idx != string::npos) cout<<buff2<<endl;
		//		replace1(line,"����","��������");
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			cout << line;
			if (idx5 != string::npos) {
				//			cout<<"������ڵ�"<<line<<endl;
				flag = 1;
				//			cout<<"before buff5   "<<buff5<<endl;
				//			replace1(buff5,"��������","��������");//�Ѳ���������Ϊ�������� 
				//			fseek( fp, 29+42*line, SEEK_SET );//���ļ�ָ���Ƶ����еĲ�������ǰ 
				char s[100];
				for (int u = 0; u < line - 1; u++)
					fgets(s, 100, fp);
				fseek(fp, 28, SEEK_CUR);
				fputs("��������		", fp);
				fclose(fp);
				//			fputs("��������		", fp);
				//			cout<<"after buff5   "<<buff5<<endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//�����Ŀ���ļ����ٽ���ʱ�ļ����Ƹ��� 
				break;
				//			replacelast(buff5,seekPerson((char*)"Reimbursehanded.txt",line),number);//�Ѵ����˱�Ϊ�Լ� 
							//��buff5д��shenpidan.txt
				//			fstream f;
				//			f.open("shenpidan.txt",ios::out|ios::app);
				////			string no,name,phone,personnal;
				////			cout<<"�밴˳�����빤�� ���� �ֻ��� ��ɫ"<<endl; 
				////			cin>>no>>name>>phone>>personnal;
				//			f<<buff5<<endl;
				//			f.close(); 
			}

		}
		if (!flag) cout << "δ�ҵ�Ŀ���������������Ƿ��������" << endl;
		else cout << "����ͨ����������ƥ��" << endl;
		//	fin5.close();
		//	read("shenpidan.txt");
		//	copyfile((char*)"shenpidan.txt",(char*)"Reimbursehanded.txt");
	}
	else {//�Ѳ���������Ϊ���� 
		ifstream fin5;
		fin5.open("Reimbursehanded.txt", ios::in);
		//		string::size_type idx;
		//    	idx=buff2.find(x);//��a�в���b.
		//		if(idx != string::npos) cout<<buff2<<endl;
		//		replace1(line,"����","��������");
		while (getline(fin5, buff5)) {
			string::size_type idx5;
			idx5 = buff5.find(x);
			line++;
			replace1(buff5, "��������", "����");

			cout << "������ͨ��" << endl;
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
	cout << "�������������Ϊ��" << endl;
	cin >> number;
	int limit = match(number);
	cout << "��������Ȩ�޽��Ϊ��" << limit << endl;
	string buff;
	cout << "����Ϊ���з���Ȩ�޵Ĵ���������" << endl;
	cout << "���������	�ᵥ��	�ᵥ���	�ᵥ����	   ״̬		������" << endl;
	while (getline(fin, buff)) {//��shenpidan.txt��д��ֻ�д�����������Ŀ 
		idx = buff.find(number);
		if (idx != string::npos) {//�Ѵ����е���Ŀд�������� 
			cout << buff << endl;
		}
	}
	cout << "����������ı��������" << endl;
	string x;
	cin >> x;
	cout << "�˱�������Ϣ����" << endl;
	ifstream fin2;
	fin2.open("Reimbursehanded.txt", ios::in);
	string buff2;//��һ��������Ŀ 
	while (getline(fin2, buff2)) {
		idx = buff2.find(x);//ɸѡ��������ı�������� 
		if (idx != string::npos)
			cout << buff2 << endl;
	}
	fin2.close();
	int judge;
	cout << "����1Ϊͨ�� ����0Ϊ����";
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
				fputs("�������					", fp);//���״̬ 
				fclose(fp);
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//�����Ŀ���ļ����ٽ���ʱ�ļ����Ƹ��� 
				break;
			}
		}
		if (!flag) cout << "δ�ҵ�Ŀ���������������Ƿ��������" << endl;
		else cout << "����ͨ����������ƥ��" << endl;
	}
	else {//�Ѳ���������Ϊ���� 
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
				fputs("����    ", fp);
				//			fputs("����    ", fp);
				fclose(fp);
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//�����Ŀ���ļ����ٽ���ʱ�ļ����Ƹ��� 
				break;
			}
			fclose(fp);
		}
		cout << "������ͨ��" << endl;
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
	cout << "������Ҫ�Ĳ������" << endl;
	cout << "1.������Ա����" << endl;
	cout << "2.������Ա����" << endl;
	cout << "3.��ѯ�����˶����Ϣ" << endl;
	cout << "4.��ѯ���б�������Ϣ" << endl;
	cout << "0.�˳�ϵͳ" << endl;
	int x; cin >> x;
	return x;
}
int menu123(int x) {//����������Ĳ��� 
	if (x == 1) {
		cout << "������Ҫ�Ĳ������" << endl;
		cout << "1.��ѯ������Ա��Ϣ" << endl;//
		cout << "2.���ӱ�����Ա��Ϣ" << endl;//
		cout << "3.�޸ı�����Ա��Ϣ" << endl;
		cout << "4.ɾ��������Ա��Ϣ" << endl;
		cout << "5.�ύ������" << endl;
		cout << "0.�˳�ϵͳ" << endl;
		int y; cin >> y;
		return y;
	}
	else if (x == 2) {
		cout << "������Ҫ�Ĳ������" << endl;
		cout << "1.��ѯ������Ա��Ϣ" << endl;
		cout << "2.����������Ա��Ϣ" << endl;
		cout << "3.�޸�������Ա��Ϣ" << endl;
		cout << "4.ɾ��������Ա��Ϣ" << endl;
		cout << "5.���в�������" << endl;
		cout << "6.���в�������" << endl;
		cout << "0.�˳�ϵͳ" << endl;
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
		case(1)://������Ա���� 
			if (k == 1) {
				system("cls");
				read("Reimburse.txt");
			}
			else if (k == 2) {
				system("cls");
				cout << "����������������......" << endl;
				addReimburse();
			}
			else if (k == 3) {
				cout << "������QwQ������" << endl;
			}
			else if (k == 4) {
				cout << "������QwQ������" << endl;
			}
			else if (k == 5) {
				system("cls");
				addform();
			}
			break;
		case(2)://������Ա���� 
			if (k == 1) {
				system("cls");
				read("Judge.txt");
			}
			else if (k == 2) {
				system("cls");
				//					cout<<"����������������......"<<endl;
				addJudge();
			}
			else if (k == 3) {
				cout << "������QwQ������" << endl;
			}
			else if (k == 4) {
				cout << "������QwQ������" << endl;
			}
			else if (k == 5) {
				system("cls");
				cout << "���Զ������������䣬�Ķ�����Reimbursehanded.txt�ļ�" << endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//�����Ŀ���ļ����ٽ���ʱ�ļ����Ƹ��� 
				bumenSet();
			}
			else if (k == 6) {
				system("cls");
				cout << "���Զ������������䣬�Ķ�����Reimbursehanded.txt�ļ�" << endl;
				autoAssign();
				ofstream file_writer2("(char*)Reimbursehanded.txt", ios_base::out);
				copyfile((char*)"tool.txt", (char*)"Reimbursehanded.txt");//�����Ŀ���ļ����ٽ���ʱ�ļ����Ƹ��� 
				caiwuSet();
			}
			break;
		case(3)://��ѯ�����˶����Ϣ
			system("cls");
			read("Power.txt");
			break;
		case(4)://��ѯ���б�������Ϣ
			system("cls");
			read("Reimbursehanded.txt");
			break;
		}
	}
	return 0;
}
/*����find����
	string a="abcdefghigklmn";
	string b="def";
	string c="123";
	string::size_type idx;
	idx=a.find(b);//��a�в���b.
	if(idx == string::npos )//�����ڡ�
		cout << "not found\n";
	else//���ڡ�
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
