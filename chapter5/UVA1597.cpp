#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include<vector>
#include<set>


vector<vector<string>>docs;//�洢���е��ĵ� dosc[i]��ʾ��iƪ�ĵ���docs[i][j]��ʾ��iƪ�ĵ��ĵ�j�� 
vector<set<string>>dictionary;//�洢ÿƪ�����г��ֵĵ���
vector<set<string>>line;//�洢���е���
int T,N; 

void standardize(string s,set<string>&st){//��һ�в��Ϊ�޷���Сд���� 
	string w;
	set<string>word;
	for(int i=0;i<s.length();i++){
		if(isalpha(s[i]))
			s[i]=tolower(s[i]);
		else 
			s[i]=' ';
	}	
	stringstream ss(s);
	while(ss>>w){
		st.insert(w);
		word.insert(w);
	}
	line.push_back(word);
}

bool find_single(string s,bool symbol){//����һ�����ʵ���� symbolΪtrue�� A��Ϊfalse��NOT A  
	bool flag1=false;
	int cnt=0;
	for(int i=0;i<T;i++){//������������ 
		bool flag2=false;
		if(symbol&&dictionary[i].count(s)||!symbol&&!dictionary[i].count(s)){
			if(flag1)
				cout << "----------" << endl;
			flag1=flag2=true;
		}
		if(flag2){
			for(int j=0;j<docs[i].size();j++,cnt++){
				if(line[cnt].count(s)||!symbol)
					cout<<docs[i][j]<<endl;
			}
		}
		else 
			cnt+=docs[i].size();//������һƪ���� 
	}
	return flag1;
}
bool find_double(string s,string t,bool symbol){//�����������ʵ������symbolΪtrue��A OR B��Ϊfalse��A AND B
	bool flag1=false;
	int cnt=0;
	for(int i=0;i<T;i++){//������������ 
		bool flag2=false;
		if(!symbol&&dictionary[i].count(s)&&dictionary[i].count(t)||symbol&&(dictionary[i].count(s)||dictionary[i].count(t))){
			if(flag1)
				cout << "----------" << endl;
			flag1=flag2=true;
		}
		if(flag2){
			for(int j=0;j<docs[i].size();j++,cnt++){
				if(line[cnt].count(s)||line[cnt].count(t))
					cout<<docs[i][j]<<endl;
			}
		}
		else 
			cnt+=docs[i].size();//������һƪ���� 
	}
	return flag1;
	
}



int main(){
	string str;
	cin>>T;getchar();
	for(int i=0;i<T;i++)
	{
		vector<string>text;
		set<string>s;
		while(getline(cin,str),str!="**********"){
			text.push_back(str);
			standardize(str,s);
		}
		docs.push_back(text);
		dictionary.push_back(s);
	}
	cin>>N;getchar();
	for(int i=0;i<N;i++){
		getline(cin,str);
		int n;
		if(str[0]=='N'){//NOT
			string a=str.substr(4);
			if(!find_single(a,false))	
				cout << "Sorry, I found nothing." << endl;
		}
		else if((n=str.find('A',0))!=string::npos){
			string a=str.substr(0,n-1);
			string b=str.substr(n+4);
			if(!find_double(a,b,false))
				cout << "Sorry, I found nothing." << endl;
		}
		else if((n=str.find('O',0))!=string::npos){
			string a=str.substr(0,n-1);
			string b=str.substr(n+3);
			if(!find_double(a,b,true))
				cout << "Sorry, I found nothing." << endl;
		}
		else 
			if(!find_single(str,true))
				cout << "Sorry, I found nothing." << endl;
			cout << "==========" << endl;
	}
	return 0;
}
