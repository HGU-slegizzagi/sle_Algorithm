#include <iostream>
int main(){
	short a;
	short o;
	std::cin>>a;

	a=1000-a;
	std::cout<<a/500+(a%500)/100+((a%500)%100)/50+(((a%500)%100)%50)/10+((((a%500)%100)%50)%10)/5+((((a%500)%100)%50)%10)%5;

	return 0;
}