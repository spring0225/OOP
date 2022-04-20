#include<iostream>
using namespace std;
int main()
{
	int x,n=0,sum=0,nn=0;
	cout<<"Input the score: ";
	cin>>x;
	n++;
	sum+=x;
	while(x!=-1)
	{
		cout<<"Input the score: ";
		cin>>x;
		if(x>=0&&x<=100)
		{
			n++;
			sum+=x;
			if(x<60){
				nn++;
			}
		}
		else{
			cout<<"Invalid score."<<endl;
		}
	}
	cout<<"Total number of scores: "<<n<<endl;
	cout<<"Average score: "<< static_cast<double>(sum)/n <<endl;
	cout<<"Failed rate: "<< static_cast<double>(nn*100)/n <<'%';
}
