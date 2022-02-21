#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#define MAX 100

using namespace std;


struct Stack{
	int top;
	int data[MAX];
}Tumpukan;

void init(){
	Tumpukan.top = -1;
}

int isEmpty(){
	return Tumpukan.top == -1;
}

bool isFull(){
	return Tumpukan.top == MAX - 1;
}

void push(){
	if (isFull()){
		cout << "\nTumpukan penuh"<<endl;
	}else{
		Tumpukan.top++;
		cout<<"Masukan Data :";
		cin>>Tumpukan.data[Tumpukan.top];
		cout<< "Data "<<Tumpukan.data[Tumpukan.top]<<" masuk ke stack"<<endl;
	}
}

void pop(){
	if(isEmpty()){
		cout<<"\nTumpukan Kosong\n"<<endl;
	}else{
		cout<<"\nData"<<Tumpukan.data[Tumpukan.top]<<"Sudah Terambil"<<endl;
		Tumpukan.top--;
	}
}

void printStack(){
	int i;
	if(isEmpty()){
		cout<<"\nTumpukan Kosong";
	}else{
		cout<<"\n Tumpukan :";
		for(int i = Tumpukan.top; i>= 0;i--)
			cout<<Tumpukan.data[i]<< ((i==0));
		
	}
}

int main(){
	int pilihan, data;
	init();
	do {
		printStack();
		cout<<"\n 1. Input\n"
			<<"2. Hapus\n"
			<<"3. Keluar"
			<<"Masukan Pilihan :";
		cin >> pilihan;
		
		switch(pilihan){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			default:
				cout<<"Pilihan tidak tersedia"<<endl;
		}
	}while(pilihan != 3);
}
