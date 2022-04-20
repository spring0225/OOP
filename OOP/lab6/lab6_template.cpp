#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;



class science{
	friend ostream& operator<<(ostream&out, science &sci);
	friend istream& operator>>(istream&in, science &sci);
private:
	double a;   
	int n;
public:
	science():a(0), n(0) {}
	science(double a_) : a(a_), n(0) {}
    science(double a_, int n_): a(a_), n(n_){
    	if(a!=0)
	{
		while(abs(a)>=10)
		{
			a/=10;
			n+=1;
		}
		while(abs(a)<1)
		{
			a*=10;
			n-=1;
		}
	}
	}
    // Member function declarations
    // ------------- Write Your Code Here ------------- //
    // 
    const science operator+(const science&)const;
    const science operator-(const science&)const;
    const science operator*(const science&)const;
    const science operator/(const science&)const;
    science operator=(const science&);
    
    
    
    // ------------------------------------------------ //
};

// Finish the ctor and function definitions
// ------------- Write Your Code Here ----------------- //
// 
ostream& operator<<(ostream&out, science &sci){
	
	if(sci.a!=0)
	{
		while(abs(sci.a)>=10)
		{
			sci.a/=10;
			sci.n+=1;
		}
		while(abs(sci.a)<1)
		{
			sci.a*=10;
			sci.n-=1;
		}
	}
	out<<sci.a<<"*10^"<<sci.n;
	return out;
}
istream& operator>>(istream&in,science &sci){
	in>>sci.a>>sci.n;
	return in;
}
const science science::operator+(const science& rhs) const{
		int i=n-rhs.n;
		return science(pow(10,i)*a+rhs.a,rhs.n);
	}
const science science::operator-(const science& rhs) const{
		int i=n-rhs.n;
		return science(pow(10,i)*a-rhs.a,rhs.n);
	}
const science science::operator*(const science& rhs) const{
		return science(a*rhs.a,n+rhs.n);
	}
const science science::operator/(const science& rhs) const{
		return science(a/rhs.a,n-rhs.n);
	}
science science::operator=(const science& rhs) {
		a=rhs.a;
		n=rhs.n;
		return *this;
	}

// ---------------------------------------------------- //

int main(){
	science v, t, w;
	char op;
	while(1){
		cout << "Please enter an expression:" << endl << endl;

        cin >> v;

		cin >> op;
		if( op != '+' && op != '-' && op != '*' && op != '/' ) break;

		cin >> t;
		if(cin.fail()) break;

		switch(op){
			case '+':  w = v + t; break;
			case '-':  w = v - t; break;
			case '*':  w = v * t; break;
			case '/':  w = v / t; break;
		}
		cout << v << ' ' << op << ' ' << t << " = " << w << endl << endl;
	}
	return 0;
}
