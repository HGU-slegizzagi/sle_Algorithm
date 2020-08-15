#include <iostream>

int cash[6] = {500,100,50,10,5,1};

int rem(int money,int r){
	if(r==-1)
		return 0;
	else
	{
		int cc = money/cash[5-r];
		return cc+rem(money%cash[5-r],r-1);
	}
}

int main(){
	int rema = 1000;
	int c = 0;
	int pri;

	std::cin>>pri;

	rema -=pri;

	std::cout<<rem(rema,5);

	return 0;
}