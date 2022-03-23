#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "kelolafile.h"
#include "IOText.h"

int main(){
 do {
  
   printf("\n\t\t***** TEXT EDITOR *****");
   printf("\n\n\tMENU:\n\t-----\n ");
   printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");
   printf("\n\tEnter your choice: ");
   scanf("%d",&ec);
   
	  switch(ec){
	   case 1:
	     Create();
	     break;
	     
	   case 2:
	     Display();
	     break;
	     
	   case 3:
	     Append();
	     break;
	     
	   case 4:
	     Delete();
	     break;
	     
	   case 5:
	     exit(0);
	  }
	  
	 } while(1);
 
}
