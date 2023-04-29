#include "header.h"

void SetColor(char text,char bg)  //UNTUK SET WARNA BORDER DAN TEXT
{
	unsigned short color=bg*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

void maximizeScreen() //UNTUK FULLSCREEN LAYAR CONSOLE
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void hide_cur()	//MENGHILANGKAN VISUAL KURSOR
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize=20;
	ConCurInf.bVisible=FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
	
}
void show_cur()	//MENGHILANGKAN VISUAL KURSOR
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize=20;
	ConCurInf.bVisible=TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}
void screen_console(int WIDTH,int HEIGHT)	//UNTUK MENENTUKAN PANJANG DAN LEBAR LAYAR KONSOL
{
	SMALL_RECT windowSize = {0, 0, WIDTH, HEIGHT};
   	COORD bufferSize = {WIDTH+1, HEIGHT+1};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);
}

void gotoxy(int x, int y) 		//UNTUK MENENTUKAN KOORDINAT X dan Y
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
// void cls(){
// 	int i;
// 	for(i=0;i<54;i++){
// 		gotoxy(0,i);printf("                                                                                                                                                                                                                                                                                                                  ");
// 	} 
// 	gotoxy(0,0);
// }
void clearAt(int x, int y, int row, int col){
	int temp=col;
	gotoxy(x,y);
	if(row!=0){
		while(temp!=0){
			printf(" ");
			temp--;
		}
		clearAt(x,y+1,row-1,col);
	}
}
void bingkaiBesar(int x, int y, int row, int  column, int sleep)  //UNTUK MEMBUAT BORDER UTAMA DI MENU AWAL
{
	int i,j;
	printf("  ");
	gotoxy(x,y);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<= column;j++)
		{
			if(i==1 && j==1)
				printf("%c",220);
			if(i==1 && j== column)
				printf("%c",220);
			if(i==row && j== column)
				printf("%c",223);
			if(i==row && j==1)
				printf("%c",223);
			if(j==1 && i!=1 && i!=row)
				printf("%c",219);
			if((i==1 || i==row) && j!= column)
				printf("%c",219);
			else if(j== column && i!=1 && i!=row)
				printf("%c",219);
			else if(j!= column)
				printf(" ");
		}
		Sleep(sleep);
		gotoxy(x,y+i);
	}
}
void bingkaiKecil(int x,int y, int row, int column,int sleep)  //UNTUK MEMBUAT BORDER MENU
{
	hide_cur();
	int i, j;
	gotoxy(x,y);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<=column;j++)
		{
			if(i==1 && j==1)
				printf("%c",TLDB);
			else if(i==1 && j==column)
				printf("%c",TRDB);
			else if((j==1 || j==column )&& i!=1 && i!=row)
				printf("%c",VSB);
			else if(i==row && j==column)
				printf("%c",BRDB);
			else if(i==row && j==1)
				printf("%c",BLDB);
			else if((i==1 || i==row) && j!=column)
				printf("%c",HSB);
			else if(j!=column)
				printf(" ");
		}
		Sleep(5);
		gotoxy(x,y+i);
	}
}

void judul(string atas, string bawah)	//JUDUL PADA TAMPILAN AWAL
{
	hide_cur();
	int x=82,y=7,a=110,b=9,i,j;
	for(i=0;i<10;i++)
	{
		gotoxy(x,y); printf(" %s ",atas); printf(" ");
		Sleep (50);
		x++;
		gotoxy(a,b); printf(" %s ",bawah);  printf(" ");
		a--;
	}
}
void menuUtama(int sleep) //TAMPILAN UTAMA
{
	hide_cur();
	SetColor(yellow,black);
	bingkaiBesar(80, 4, 33, 52, sleep);
	judul("Selamat Datang di","Klinik Cinta Satwa"); 
	gotoxy(90,7); printf("[");
	gotoxy(121,9); printf("]");
	bingkaiKecil(88,12,7,37,sleep);
	gotoxy(99,15); printf("[ Login Admin ]");
	bingkaiKecil(88,19,7,37,sleep);
	gotoxy(99,22);printf("[ Login Dokter ]");
	bingkaiKecil(88,26,7,37,sleep);
	gotoxy(103,29);	printf("[ Exit ]");
	SetColor(green,black);
	gotoxy(87,34);printf("Enter = Masuk Menu   Arrow = Pilih Menu ");
}
void menuAdmin(int sleep){
	system("cls");
	hide_cur();
	SetColor(yellow,black);
	bingkaiBesar(59, 4, 23, 95, 0);
	gotoxy(87,6); printf("- - - [ Selamat Datang di Menu Admin ] - - -");
	bingkaiKecil(67,8,3,37,0);
	gotoxy(77,9); printf("[ Tambah Dokter ]");
	bingkaiKecil(67,11,3,37,0);
	gotoxy(78,12); printf("[ Cari Dokter ]");
	bingkaiKecil(67,14,3,37,0);
	gotoxy(77,15); printf("[ Tampil Dokter ]");
	bingkaiKecil(67,17,3,37,0);
	gotoxy(78,18); printf("[ Ubah Dokter ]");
	bingkaiKecil(67,20,3,37,0);
	gotoxy(78,21); printf("[ Hapus Dokter ]");

	bingkaiKecil(109,8,3,37,0);
	
	gotoxy(117,9); printf("[ Pendaftaran Pasien ]");
	bingkaiKecil(109,11,3,37,0);
	gotoxy(118,12); printf("[ Hapus Data Pasien ]");
	bingkaiKecil(109,14,3,37,0);
	gotoxy(115,15); printf("[ Tampil Laporan Dokter ]");
	bingkaiKecil(109,17,3,37,0);
	gotoxy(113,18); printf("[ Tampil Seluruh Data Hewan ]");
	bingkaiKecil(109,20,3,37,0);
	gotoxy(122,21); printf("[ Logout ]");
	SetColor(green,black); gotoxy(87,24);printf("Enter = Masuk Menu   Arrow = Pilih Menu ");
}
void menuDokter(int sleep, string dokter){
	system("cls");
	hide_cur();
	SetColor(yellow,black);
	bingkaiBesar(80, 4, 36, 52, sleep);
	gotoxy(86,6); printf("- - - [ Selamat Datang dr. %s ]- - -",dokter); 
	bingkaiKecil(88,8,7,37,sleep);
	gotoxy(98,11); printf("[ Tampil Pasien ]");
	bingkaiKecil(88,15,7,37,sleep);
	gotoxy(97,18);printf("[ Selesai Periksa ]");
	bingkaiKecil(88,22,7,37,sleep);
	gotoxy(98,25);	printf("[ Lihat Laporan ]");
	bingkaiKecil(88,29,7,37,sleep);
	gotoxy(102,32);	printf("[ Logout ]");
	SetColor(green,black); gotoxy(87,37);printf("Enter = Masuk Menu   Arrow = Pilih Menu ");
}
void menuExit(int x,int y,int time){
	int i,coodDot=x;
	gotoxy(x,y);printf("Exit");
	for(i=x;i<100;i++){
		gotoxy(i,y-1);printf("%c",176);
	}
	for(i=x;i<100;i++){
		if(i==90){
			time-=50;
		} else if(i==96){
			time-=25;
		}
		if(coodDot+i<=100){
			gotoxy(coodDot+i-3,y);printf(".");
		}
		if(i%5==0){
			gotoxy(85,y);printf("        ");
			coodDot = 86-i;
		}
		Sleep(time);
		gotoxy(i,y-1);printf("%c",178);
	}
}
void showCoders(int sleep)
{
	hide_cur();
	SetColor(yellow,black);
	bingkaiKecil(76,8,10,50,sleep);
	gotoxy(80,8);printf("[ Tugas Besar Informasi dan Struktur Data ]");
	gotoxy(80,10);printf("[Nama Anggota]                     [NPM]");
	gotoxy(80,12);printf("Made Riksi Purnama Sadnya Agung   210711396");
	gotoxy(80,13);printf("I Made Panji Pusaka Suryeswara    210711397");
	gotoxy(80,14);printf("Simon Adrian Agis                 210711401");
	gotoxy(80,15);printf("Ferdy Firmansyah                  210711480");
	
}
void warning(int x, int y, int row, int col)
{
	hide_cur();
	bingkaiKecil(x,y,row,col,0);
	gotoxy(x+(col/2)-7,y);printf("[ Notifikasi ]");
}

void checkMenuUtama(int menu){
	if(menu==12){
		gotoxy(99,15); printf("[ Login Admin ]");
	}else if (menu==19){
		gotoxy(99,22);	printf("[ Login Dokter ]");
	}else if (menu==26){
		gotoxy(103,29);	printf("[ Exit ]");
	}
}
void checkMenuAdmin(Index idx){
	if(idx.x==67 && idx.y==8){
		gotoxy(77,9); printf("[ Tambah Dokter ]");
	}else if(idx.x==67 && idx.y==11){
		gotoxy(78,12); printf("[ Cari Dokter ]");
	}else if(idx.x==67 && idx.y==14){
		gotoxy(77,15); printf("[ Tampil Dokter ]");
	}else if(idx.x==67 && idx.y==17){
		gotoxy(78,18); printf("[ Ubah Dokter ]");
	}else if(idx.x==67 && idx.y==20){
		gotoxy(78,21); printf("[ Hapus Dokter ]");
	}else if(idx.x==109 && idx.y==8){
		gotoxy(117,9); printf("[ Pendaftaran Pasien ]");
	}else if(idx.x==109 && idx.y==11){
		gotoxy(118,12); printf("[ Hapus Data Pasien ]");
	}else if(idx.x==109 && idx.y==14){
		gotoxy(115,15); printf("[ Tampil Laporan Dokter ]");
	}else if(idx.x==109 && idx.y==17){
		gotoxy(113,18); printf("[ Tampil Seluruh Data Hewan ]");
	}else if(idx.x==109 && idx.y==20){
		gotoxy(122,21); printf("[ Logout ]");
	}
}
void checkMenuDokter(Index idx){
	if(idx.y==8){
		gotoxy(98,11); printf("[ Tampil Pasien ]");
	}else if(idx.y==15){
		gotoxy(97,18);printf("[ Selesai Periksa ]");
	}else if(idx.y==22){
		gotoxy(98,25);	printf("[ Lihat Laporan ]");
	}else if(idx.y==29){
		gotoxy(102,32);	printf("[ Logout ]");
	}
}
