#include<iostream>
#include<stack>

using namespace std;

class Z
{
	public:
		Z(){
			cout << "+Z";
		}
		
		~Z(){
			cout << "-Z";
		}
};


class X : public Z
{
	private:
		Z obj;
	public:
		X(){
			cout << "+X";
		}
		
		~X(){
			cout << "-X";
		}
};




int main(int argc, char* argv[])
{
	cout << "Main Start" <<  endl;
	
	X* px = new X;
	Z* pz = new X;
	
	cout << "Deleting px" <<  endl;
	delete px;
	
	cout << "Deleting pz" <<  endl;
	delete pz;
	
	cout << "Main Stop" << endl;
	
	return 0;
}


