// Ackermann’s function ackermann(x, y):


#include <iostream>
using namespace std;

int ackermann(int x, int y){
	if (x == 0){
		return y + 1;
	}
	else if((x > 0) && (y == 0)){
		return ackermann(x - 1, 1);
	}
	else if((x > 0) && (y > 0)){
		return ackermann(x - 1, ackermann(x, y - 1));
	}
	return 0;
} 

int main(){
  int answer;
	int x, y;
	cout<<"Enter an integer x: "<<endl;
	cin >> x;
	cout<<"Enter an integer y: "<<endl;
	cin>> y;
	answer= ackermann(x,y);
  cout <<"Answer: "<<answer<<endl ;
  return 0;
}



