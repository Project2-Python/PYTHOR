

#define MAXBARIS 5
#define MAXKOLOM 20

//Variabel Global
char TextEditor[MAXBARIS][MAXKOLOM]; 

enum KeyInput{
	
	ENTER = 13,
	CTRL_S = 19,
	CTRL_N = 14,
	CTRL_Q = 17,
	CTRL_C = 3,
	BACKSPACE = 8
	
};

//Procedure dan Fungsi

void gotoxy(int x,int y);

int i,j,ec,fg,ec2;
char fn[20],e,c;
FILE *fp1,*fp2,*fp;

void Create();
void Append();
void Delete();
void Display();
