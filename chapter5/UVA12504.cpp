#include<iostream>
using namespace std;
#include<map>
#include<vector>
#include<string>
#include<sstream>
void standardize(string&s){
	for(auto&e:s){
		if(e==','||e==':')
			e=' ';
	}
}
void get(string s,map<string,string>&mp){
	standardize(s);
	stringstream ss(s);
	string key,value;
	while(ss>>key>>value)
		mp[key]=value;
}
void print(char ch,map<string,string>&mp){
	for(map<string,string>::iterator it=mp.begin();it!=mp.end();it++){
		if(it==mp.begin())
			cout<<ch<<it->first;
		else 
			cout<<','<<it->first;
	}
	cout<<endl;
}
int main(){
	int n;cin>>n;
	while(n--){
		string str1,str2;
		map<string,string>mp1,mp2;
		vector<string>temp;
		cin>>str1>>str2;
		get(str1.substr(1,str1.size()-2),mp1);
		get(str2.substr(1,str2.size()-2),mp2);
		if(mp1==mp2){
			cout<<"No changes"<<endl<<endl;
			continue;
		}
		map<string,string>::iterator it1=mp1.begin();
		map<string,string>::iterator it2=mp2.begin();
		while(it1!=mp1.end()&&it2!=mp2.end()){
			if(it1->first==it2->first)
			{
				if(it1->second!=it2->second)
					temp.push_back(it1->first);
				mp1.erase(it1++);
				mp2.erase(it2++);
			}
			else if(it1->first<it2->first)
				it1++;
			else if(it1->first>it2->first)
				it2++;
		}	
		if(!mp2.empty()) print('+',mp2);
		if(!mp1.empty()) print('-',mp1);
		for(int i=0;i<temp.size();i++){
			if(!i) cout<<'*'<<temp[i];
			else cout<<','<<temp[i];
		}
		if(temp.size())cout<<endl;
		cout<<endl;
	}
	
	return 0;
}
