//����ϲ�
//���� n ������ [li,ri]��Ҫ��ϲ������н��������䡣
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int INF = 2e9;

vector<pair<int,int> >nums,res;
int main(){
	int st = -INF,ed = -INF;
	int n;
	cin >> n;
	while(n--){
		int l,r;
		scanf("%d%d",&l,&r);
		nums.push_back({l,r});
	}
	sort(nums.begin(),nums.end()); //����˵�����
	
	for(auto num:nums){
		if(ed < num.first){		//1.���������޷��ϲ�
			if(ed != -INF) res.push_back({st,ed}); //����1�Ž�res����
			st = num.first;		//ά������2
			ed = num.second;
		}else if(ed < num.second) //2.����������Ժϲ���������1����������2������2����������1
			ed = num.second; //����ϲ�
			
		//3.����1��������2 ����Ҫ����
	}
	
	if(st != -INF && ed != -INF) res.push_back({st,ed});
	
	cout << res.size();
	return 0;
}
