#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define ALL(a) a.begin(),a.end()
struct book{
	string title;
	string author;
	friend bool operator < (const book&a,const book&b){
		return a.author<b.author||(a.author==b.author&&a.title==b.title);
	}
}tmp;

int main()
{
	vector<book>library;
	map<string,int>ID;
	set<int>desk,shelve;
	string op,line,title;
	while(getline(cin,line)&&line!="END"){
		int pos=line.find("by");
		tmp=book{line.substr(0,pos-1),line.substr(pos+3)};
		library.push_back(tmp);
	}
	sort(ALL(library));
	for(int i=0;i<library.size();i++){
		ID[library[i].title]=i;
		shelve.insert(i);
	}
	while(cin>>op&&op!="END")
	{
		if(op=="SHELVE"){
			for(auto&e:desk){
				auto p=shelve.find(e);
				cout<<"Put "<<library[e].title;
				if(p==shelve.begin())cout<<" first"<<endl;
				else cout<<" after "<<library[*(--p)].title<<endl;
			}
			desk.clear();
			cout<<"END"<<endl;
			continue;
		}
		else
		{
			getline(cin,title);
			title=title.substr(1);
			if(op=="RETURN") desk.insert(ID[title]),shelve.insert(ID[title]);
			else if(op=="BORROW") shelve.erase(ID[title]);
		}
	}
	return 0;
}
