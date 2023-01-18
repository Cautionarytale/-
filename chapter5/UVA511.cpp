#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<functional>
#define EPS 1e-7

struct Map{
	string name;
	double x1,y1,x2,y2,area,length,height;
	pair<double,double>mid;
	pair<double,double>RD=make_pair(x2,y1);//右下角
	Map(double a=0,double b=0,double c=0,double d=0)
		:x1(a),y1(b),x2(c),y2(d)
		{
			length=x2-x1;
			height=y2-y1;
			area=length*height;
			double x=(x1+x2)/2,y=(y1+y2)/2;
			mid=make_pair(x,y);
		} 
};

map<string,Map>mp;//从地图名到详细信息的映射
map<string,map<double,vector<string>,greater<double>>>level;//按面积从小到大排序，向量中存放的是位置名 

bool cmp(string&s,string&t,double&a,double&b){//对面积相同的地图进行排序 
	double s1,s2;
	s1=hypot(fabs(a-mp[s].mid.first),fabs(b-mp[s].mid.second));
	s2=hypot(fabs(a-mp[t].mid.first),fabs(b-mp[t].mid.second));
	if(fabs(s1-s2)>EPS)
		return s1<s2;//与中点距离近的优先级高
	s1=mp[s].length/mp[s].height;
	s2=mp[t].length/mp[t].height;
	if(fabs(s1-s2)>EPS)
		return s1>s2;//比例 
	s1=hypot(fabs(a-mp[s].RD.first),fabs(b-mp[s].RD.second));
	s2=hypot(fabs(a-mp[t].RD.first),fabs(b-mp[t].RD.second));
	if(fabs(s1-s2)>EPS)
		return s1<s2;//右下角 
	return mp[s].x1<mp[t].x1;//横坐标 
}

int main(){
	string str;
	double x1,y1,x2,y2;
	cin>>str;
	while(cin>>str,str!="LOCATIONS"){
		cin>>x1>>y1>>x2>>y2;
		if(x1>x2)
			swap(x1,x2);
		if(y1>y2)
			swap(y1,y2);
		Map m(x1,y1,x2,y2);
		mp[str]=m;
	}
	while(cin>>str,str!="REQUESTS"){
		cin>>x1>>y1;
		for(auto m:mp)
			if(x1>m.second.x1&&x1<m.second.x2&&y1>m.second.y1&&y1<m.second.y2)
				level[str][m.second.area].push_back(m.first);
		for(auto m:level[str]){
			vector<string>v(m.second);
			sort(v.begin(),v.end(),bind(cmp,placeholders::_1,placeholders::_2,x1,y1));
			m.second=v;
			
		}		
	}
	while(cin>>str,str!="END"){
		int n;
		bool flag=false;
		string s;
		cin>>n;
		if (!level.count(str)) {  //查询的位置不存在时
			cout << str << " at detail level " << n << " unknown location" << endl;
			continue;
		}
		if(level[str].empty())
			cout << str << " at detail level " << n << " no map contains that location" << endl;
		else{
			int i=1;
			for(auto it=level[str].begin();it!=level[str].end();it++,i++){
				if(i==n){
					cout << str << " at detail level " << n << " using " << it->second[0] << endl;
					flag = true;
				}
				if (i == level[str].size())  //到达地图末尾，说明没有该等级的地图，使用最详细的地图输出
					s = it->second[0];

			}
			if(!flag)
			cout << str << " at detail level " << n << " no map at that detail level; using " << s << endl;
		}	
	}
	return 0;
}
