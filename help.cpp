void help(){
 char help[300];
 
 FILE *filetubes;
 printf("\n\n\n");
 if((filetubes = fopen(".txt","r")) == NULL){
  printf("File ini kosong !!! Silahkan hubungi admin");
  
  exit(1);
 }
 while(fgets(help, sizeof(help),filetubes)){ 
  printf("%s",help);            
 }                  
  
 fclose(filetubes);
}