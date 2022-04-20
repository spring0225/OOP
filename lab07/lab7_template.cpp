#include <iostream>
#include <string>

using namespace std;

int main(){
	int mode;
	bool end = false;
	string str;
	string text[5], graph[5];
	text[0] = "(happy)";		graph[0] = "^w^";
	text[1] = "(heart)";		graph[1] = "<3";
	text[2] = "(confused)";		graph[2] = "?_?";
	text[3] = "(kiss)";			graph[3] = "-3-";
	text[4] = "(speechless)";	graph[4] = "= =";
	size_t found;
	
	// finish the program here
	while(!end)
	{
		cout<<"Please enter the mode: ";
		cin>>mode;
		cin.ignore(100,'\n');
		if(mode==-1)
		{
			cout<<"Programs ends...";
			break;
		}
		
		if(mode==0)
		{
			cout<<"Input: ";
			getline(cin,str);
			
			found=str.find(text[0]);
			while(found!=string::npos){
				str.replace(found,7,graph[0]);
				found=str.find(text[0],found+1);
			}
			found=str.find(text[1]);
			while(found!=string::npos){
				str.replace(found,7,graph[1]);
				found=str.find(text[1],found+1);
			}
			found=str.find(text[2]);
			while(found!=string::npos){
				str.replace(found,10,graph[2]);
				found=str.find(text[2],found+1);
			}
			found=str.find(text[3]);
			while(found!=string::npos){
				str.replace(found,6,graph[3]);
				found=str.find(text[3],found+1);
			}
			found=str.find(text[4]);
			while(found!=string::npos){
				str.replace(found,12,graph[4]);
				found=str.find(text[4],found+1);
			}
			cout<<"Output: "<<str<<"\n-----------------------\n";
			

		}
		if(mode==1)
		{
			cout<<"Input: ";
			getline(cin,str);
			
			found=str.find(graph[0]);
			while(found!=string::npos){
				str.replace(found,3,text[0]);
				found=str.find(graph[0],found+1);
			}
			found=str.find(graph[1]);
			while(found!=string::npos){
				str.replace(found,2,text[1]);
				found=str.find(graph[1],found+1);
			}
			found=str.find(graph[2]);
			while(found!=string::npos){
				str.replace(found,3,text[2]);
				found=str.find(graph[2],found+1);
			}
			found=str.find(graph[3]);
			while(found!=string::npos){
				str.replace(found,3,text[3]);
				found=str.find(graph[3],found+1);
			}
			found=str.find(graph[4]);
			while(found!=string::npos){
				str.replace(found,3,text[4]);
				found=str.find(graph[4],found+1);
			}
			cout<<"Output: "<<str<<"\n-----------------------\n";
			
		}
	
		
			
		
	}
	
	
	

	
	
	
	
	
	return 0;
}
