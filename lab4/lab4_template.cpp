#include<iostream>
#include<fstream>

using namespace std;

//#define FILE "input1.txt"
#define SIZE 12
void readfile(int maze[][SIZE]);

int main(void)
{
//======= don't change =================================

	int maze[SIZE][SIZE]={0};
	readfile(maze);

//======= don't change =================================

    cout<<"Maze: "<<endl;
    for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			cout<<maze[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Answer: "<<endl;
	int x=1,y=1,step=0;
	int xx[19],yy[19];
	while(step!=18)
    {
        if(maze[x+1][y]==1)//down
        {
            x+=1;
            step++;
            xx[step]=x;
            yy[step]=y;
        }
        else if(maze[x][y+1]==1)//right
        {
            y+=1;
            step++;
            xx[step]=x;
            yy[step]=y;
        }
        else{
            if(maze[x-1][y]==1)//up
            {
                step--;
                maze[x][y]=0;
                x=xx[step];
                y=yy[step];
            }
            else if(maze[x][y-1]==1)
            {
                step--;
                maze[x][y]=0;
                x=xx[step];
                y=yy[step];
            }
        }
    }
    cout<<"(1,1)"<<endl;
	for(int a=1;a<=18;a++)
    cout<<"("<<xx[a]<<","<<yy[a]<<")"<<endl;
	return 0;
}

void readfile(int maze[][SIZE])
{
	fstream ifs;
	ifs.open("input1.txt");
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			ifs>>maze[i][j];
		}
	}
}
