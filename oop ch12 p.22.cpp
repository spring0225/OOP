#include<iostream>
using namespace std;
typedef void(*fp_t)(ostream&);
void adar(ostream& os){os<<"adar is a very nice professor!";}
ostream& operator<<(ostream& os,fp_t adar){
	adar(os);
	return os;
}
int main()
{
	cout<<adar<<endl;
	return 0;
}
