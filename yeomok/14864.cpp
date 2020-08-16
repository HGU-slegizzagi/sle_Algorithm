#include <iostream>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void printarr(int *arr, int c){
	for(int i = 0; i<c; i++){
		std::cout<<arr[i]<<" ";
	}
	std::cout<<std::endl;
}

void arrange(int *arr, int dat[][2], int ptr, int datl, int c){
	if(ptr+1 == c)
		return;
	for(int i = ptr+1; i<c; i++){
		if(arr[ptr]>arr[i])
			continue;
		else{
			int d = 0, e = 0;
			for(int t = 0; t<datl; t++) {if(arr[ptr]==dat[t][0]) d++; else if(d>=1) break; else e++;}
			int f = 0;
			for(int k = e; k<d; k++) if(arr[i]!=dat[k][1]) f++;
			if(f==d){
				swap(arr[ptr],arr[i]);
				ptr-=1;
				break;
			}
		}
	}
	// printarr(arr,c);
	arrange(arr,dat,ptr+1,datl,c);
}

int check(int *sto, int dat[][2],int datl,int c){
	int *a =new int[c];
	for(int i = 0; i<c; i++){
		a[i] = 0;
		for(int j = 0; j<datl; j++) if(dat[j][0]==i+1) a[i]++;
		if(a[i]>sto[i]){
			return 0;
		}
	}
	return 1;
}

void finArr(int *arr,int *sto,int c){
	for(int i= 0; i<c; i++){
		for(int j = 0; j<c; j++){
			if(arr[j]==i+1){
				swap(arr[j],arr[i]);
				swap(sto[j],sto[i]);
			}
		}
	}
}

int main(){
	int ir, ic=1, ptr = 0;

	std::cin>>ir>>ic;
	auto dat = new int[ic][2];
	int *arr = new int[ir];
	int *sto = new int[ir];

	for(int i = 0; i<ic; i++){
		std::cin>>dat[i][0]>>dat[i][1];
	}
	for(int i = 0; i<ir; i++){
		arr[i] = i+1;
		sto[i] = ir-i;
	}

	arrange(arr,dat,0,ic,ir);
	finArr(arr,sto,ir);
	
	if(check(sto,dat,ic,ir))
		printarr(sto,ir);
	else
		std::cout<<-1;
	
	delete dat;
	delete arr;
	delete sto;
}