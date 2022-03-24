#include "tampilan.h"
#include "IOText.h"
#include "kelolafile.h"


void menu(){

   system("cls");	
   int ec;
	
   printf("\n\t\t***** TEXT EDITOR *****");
   printf("\n\n\tMENU:\n\t-----\n ");
   printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.APPEND\n\t4.DELETE\n\t5.EXIT\n");
   printf("\n\tEnter your choice: ");
   scanf("%d",&ec);
   
	switch(ec){
		case 1:
			Create();
	      	break;
	    default :
	    	return;
	     
	  }
	
	
}
