#include "header.h"

int main(){
    Admin D;

    DataDokter temp;

    DataHewan tempDataHewan;

    DataRiwayat tempDataRiwayat;

    DataLaporan tempDataLaporan;
    
    addressChildDokter tempDokter;
    addressChildRiwayat tempRiwayat;
    addressChildRiwayat tempR;
    addressChildHewan tempH;

    char ch;

    string username, password,tampung;

    int submenu = -1, id_dokter, i, id = 0;
    
    char confirm;

    createEmpty(&D);
//    maximizeScreen();
//	screen_console(200,200);
	int menu=12;
    Index idx;
	char pil,pil2;
	hide_cur();
	SetColor(yellow,black);

    while(1){
        back:
		system("cls");
		menu=12;
		menuUtama(0);

		do{
			//menu utama
			SetColor(red,black);
			gotoxy(88,menu);
			bingkaiKecil(88,menu,7,37,0);
			checkMenuUtama(menu);
			pil=getch();
			if(pil==72) // UP
			{
				SetColor(yellow,black);
				gotoxy(88,menu);
				bingkaiKecil(88,menu,7,37,0);
				checkMenuUtama(menu);
				menu-=7;
			}

			if(pil==80) //DOWN
			{
				SetColor(yellow,black);
				gotoxy(88,menu);
				bingkaiKecil(88,menu,7,37,0);
				checkMenuUtama(menu);
				menu+=7;
			}
			if(menu<12)
				menu=26;
			if(menu>26)
				menu=12;
		}while(pil!=13);
			
			//menu pilihan
			if(pil==13){
	            switch(menu){
	            case 12:
	                hide_cur();
	            	SetColor(yellow,black);  
	                bingkaiBesar(80, 4, 33, 52, 0);
	                bingkaiKecil(88,12,9,37,0);
                    gotoxy(88,8); printf("--=================================--");
                    gotoxy(91,9); printf("Silahkan Login Terlebih Dahulu!");
                    gotoxy(89,10); printf("--===============================--");
	                show_cur();
	                gotoxy(90,15); printf("Username : "); fflush(stdin); gets(username);
                    gotoxy(90,17); printf("Password : ");
                    i = 0;
                    while (true){
                        ch = getch();
                        if (ch == 13){
                            break;
                        }else if (ch == 8){
                            if (i > 0){
                                i--;
                                printf("\b \b");
                            }
                        }else{
                            password[i] = ch;
                            i++;
                            printf("%c", 771);
                        }
                    }
                    password[i] = '\0';
                    hide_cur();
                    if(!loginAdmin(D, username, password)){
                    	SetColor(red,black);
                        warning(88,28,5,37);
                        gotoxy(93,30); printf("Username atau Password Salah\n");
                        getch();
                    }else{
                        SetColor(green,black);
                        warning(88,28,5,37);
                        gotoxy(93,30); printf("Berhasil login sebagai Admin\n");
                        getch();
                        backAdmin:
                        menuAdmin(0);
                        idx.x=67;
                        idx.y=8;
                        do{
                            SetColor(red,black);
                            gotoxy(idx.x,idx.y);
                            bingkaiKecil(idx.x,idx.y,3,37,0);
                            checkMenuAdmin(idx);

                            pil2=getch();
                            if(pil2==72){ //UP
                                SetColor(yellow,black);
                                gotoxy(idx.x,idx.y);
                                bingkaiKecil(idx.x,idx.y,3,37,0);
                                checkMenuAdmin(idx);
                                idx.y-=3;
                            }
                            if(pil2==80){ //DOWN
                                SetColor(yellow,black);
                                gotoxy(idx.x,idx.y);
                                bingkaiKecil(idx.x,idx.y,3,37,0);
                                checkMenuAdmin(idx);
                                idx.y+=3;
                            }
                            if(pil2==75){ //LEFT
                                SetColor(yellow,black);
                                gotoxy(idx.x,idx.y);
                                bingkaiKecil(idx.x,idx.y,3,37,0);
                                checkMenuAdmin(idx);
                                idx.x-=42;
                            }
                            if(pil2==77){ //RIGHT
                                SetColor(yellow,black);
                                gotoxy(idx.x,idx.y);
                                bingkaiKecil(idx.x,idx.y,3,37,0);
                                checkMenuAdmin(idx);
                                idx.x+=42;
                            }
                            if(idx.y<8){
                                idx.y=20;
                            }else if(idx.y>20){
                                idx.y=8;
                            }

                            if(idx.x<67){
                                idx.x=109;
                            }else if(idx.x>109){
                                idx.x=67;
                            }
                        }while(pil2!=13);

                        if(pil2==13){
                            if(idx.x==67 && idx.y==8){
                                system("cls");
                                SetColor(yellow,black);
	                            bingkaiBesar(64, 4, 24, 85, 0);
                                gotoxy(89,6); printf("- - - [ Inputkan Data Dokter ] - - -");
                                bingkaiKecil(72,8,11,70,0);
                                while (true){
                                    show_cur();
                                    SetColor(yellow,black);
                                    gotoxy(74,10); printf("Nama Dokter : "); fflush(stdin); gets(temp.nama_dokter);
                                    if(strlen(temp.nama_dokter) > 0 && strcmpi(temp.nama_dokter, "-") != 0){
                                        break;
                                    }else if(strlen(temp.nama_dokter) == 0){
                                        SetColor(red,black);
                                        warning(89,20,5,38);
                                        gotoxy(93,22); printf("Nama Dokter Tidak Boleh Kosong");
                                        getch();
                                        clearAt(89,20,5,38);
                                    }else if(strcmpi(temp.nama_dokter, "-") == 0){
                                        SetColor(red,black);
                                        warning(89,20,5,38);
                                        gotoxy(93,22); printf("Nama Dokter Tidak Boleh Strip");
                                        getch();
                                        clearAt(89,20,5,38);
                                    }
                                    if(strcmpi(temp.nama_dokter, "-") == 0){
                                        clearAt(88,10,1,strlen(temp.nama_dokter));
                                    }
                                }
                                while (true){
                                    show_cur();
                                    SetColor(yellow,black);
                                    gotoxy(74,12); printf("Tanggal Bergabung (dd/mm/yyyy) : "); fflush(stdin); gets(temp.tgl_bergabung);
                                    if(strlen(temp.tgl_bergabung) > 0){
                                        if(checkDate(temp.tgl_bergabung)==1){
                                            break;
                                        }else if(checkDate(temp.tgl_bergabung)==-1){
                                            SetColor(red,black);
                                            warning(89,20,5,38);
                                            gotoxy(93,22); printf("Tanggal bergabung tidak valid!");
                                            getch();
                                            clearAt(89,20,5,38);
                                        }else if(checkDate(temp.tgl_bergabung)==-2){
                                            SetColor(red,black);
                                            warning(89,20,5,38);
                                            gotoxy(95,22); printf("Tanggal hanya boleh 1 ~ 31");
                                            getch();
                                            clearAt(89,20,5,38);
                                        }else if(checkDate(temp.tgl_bergabung)==-3){
                                            SetColor(red,black);
                                            warning(89,20,5,38);
                                            gotoxy(96,22); printf("Bulan hanya boleh 1 ~ 12");
                                            getch();
                                            clearAt(89,20,5,38);
                                        }else if(checkDate(temp.tgl_bergabung)==-4){
                                            SetColor(red,black);
                                            warning(89,20,5,37);
                                            gotoxy(93,22); printf("Tahun hanya boleh 1900 ~ 2100");
                                            getch();
                                            clearAt(89,20,5,37);
                                        }
                                        if(checkDate(temp.tgl_bergabung)!=1){
                                            clearAt(107,12,1,strlen(temp.tgl_bergabung));
                                        }
                                    }else{
                                        SetColor(red,black);
                                        warning(89,20,5,38);
                                        gotoxy(93,22); printf("Tanggal bergabung tidak valid!");
                                        getch();
                                        clearAt(89,20,5,38);
                                    }
                                }
                                while (true){
                                    show_cur();
                                    SetColor(yellow,black);
                                    gotoxy(74,14); printf("Username : "); fflush(stdin); gets(temp.username);
                                    if(strlen(temp.username) > 0){
                                        if(isUniqueDokter(D, temp.username)){
                                            break;
                                        }else{
                                            SetColor(red,black);
                                            warning(89,20,5,38);
                                            gotoxy(96,22); printf("Username Sudah Digunakan");
                                            getch();
                                            clearAt(89,20,5,38);
                                            clearAt(85,14,1,strlen(temp.username));
                                        }
                                    }else{
                                        SetColor(red,black);
                                        warning(89,20,5,37);
                                        gotoxy(94,22);printf("Username Tidak Boleh Kosong");
                                        getch();
                                        clearAt(89,20,5,38);
                                    }
                                }
                                while (true){
                                    show_cur();
                                    i = 0;
                                    SetColor(yellow,black);
                                    gotoxy(74,16);  printf("Password : ");
                                    while (true){
                                        ch = getch();
                                        if (ch == 13){
                                            break;
                                        }else if (ch == 8){
                                            if (i > 0){
                                                i--;
                                                printf("\b \b");
                                            }
                                        }else{
                                            temp.password[i] = ch;
                                            i++;
                                            printf("%c", 771);
                                        }
                                    }
                                    temp.password[i] = '\0';
                                    if(strlen(temp.password) > 0){
                                        break;
                                    }else{
                                        SetColor(red,black);
                                        warning(89,20,5,37);
                                        gotoxy(94,22);printf("Password Tidak Boleh Kosong");
                                        getch();
                                        clearAt(89,20,5,39);
                                    }
                                }
                                id++;
                                temp.id_dokter = id;
                                insertLastDokter(&D, alokasiDokter(temp));
                                SetColor(green,black);
                                warning(89,20,6,38);
                                gotoxy(92,22);printf("Berhasil Menambahkan Data Dokter");
                                gotoxy(98,23);printf("Dengan ID Dokter : %d",temp.id_dokter);
                                getch();
                                goto backAdmin;
                            }else if(idx.x==67 && idx.y==11){
                                system("cls");
                                if(!isEmptyDokter(D)){
                                    SetColor(yellow,black);
                                    bingkaiBesar(80, 4, 33, 53, 0);
                                    gotoxy(91,6); printf("- - - [ Cari Data Dokter ] - - -");
                                    printCariDokter(D);
                                    
                                    bingkaiKecil(84,8,5,47,0);
                                    show_cur();
                                    gotoxy(86,10); printf("ID Dokter : "); scanf("%d", &id_dokter);
                                    hide_cur();
                                    if(findElmDokter(D, id_dokter) != NULL){
                                        bingkaiKecil(84,15,9,47,0);
                                        gotoxy(86,17); printf("ID Dokter         : %d", findElmDokter(D, id_dokter)->Data_Dokter.id_dokter);
                                        gotoxy(86,18); printf("Nama Dokter       : %s", findElmDokter(D, id_dokter)->Data_Dokter.nama_dokter);
                                        gotoxy(86,19); printf("Tanggal Bergabung : %s", findElmDokter(D, id_dokter)->Data_Dokter.tgl_bergabung);
                                        gotoxy(86,20); printf("Username          : %s", findElmDokter(D, id_dokter)->Data_Dokter.username);
                                        gotoxy(86,21); printf("Password          : %s", findElmDokter(D, id_dokter)->Data_Dokter.password);
                                    }else{
                                        SetColor(red,black);
                                        warning(88,15,5,37);
                                        gotoxy(93,17); printf("Data Dokter Tidak Ditemukan");
                                    }

                                }else{
                                    SetColor(yellow,black);
                                    bingkaiBesar(80, 4, 11, 53, 0);
                                    gotoxy(91,6); printf("- - - [ Cari Data Dokter ] - - -");
                                    SetColor(red,black);
                                    warning(88,8,5,37);
                                    gotoxy(93,10); printf("Data Dokter Masih Kosong");
                                }getch();
                                goto backAdmin;
                            }else if(idx.x==67 && idx.y==14){
                                SetColor(yellow,black);
                                printInfoDokter(D); 
                                getch();
                                goto backAdmin;
                            }else if(idx.x==67 && idx.y==17){
                                system("cls");
                                if(!isEmptyDokter(D)){
                                    SetColor(yellow,black);
                                    bingkaiBesar(78, 4, 33, 57, 0);
                                    gotoxy(91,6); printf("- - - [ Ubah Data Dokter ] - - -");
                                    printCariDokter(D);
                                    bingkaiKecil(84,8,5,47,0);
                                    show_cur();
                                    gotoxy(86,10); printf("ID Dokter : "); scanf("%d", &id_dokter);
                                    hide_cur();
                                    if(findElmDokter(D, id_dokter) != NULL){
                                        bingkaiKecil(82,15,11,50,0);
                                        while (true){
                                            show_cur();
                                            SetColor(yellow,black);
                                            gotoxy(84,17); printf("Nama Dokter : "); fflush(stdin); gets(temp.nama_dokter);
                                            if(strlen(temp.nama_dokter) > 0 && strcmpi(temp.nama_dokter, "-") != 0){
                                                break;
                                            }else if(strlen(temp.nama_dokter) == 0){
                                                SetColor(red,black);
                                                warning(88,30,5,38);
                                                gotoxy(92,32); printf("Nama Dokter Tidak Boleh Kosong");
                                                getch();
                                                clearAt(88,30,5,38);
                                            }else if(strcmpi(temp.nama_dokter, "-") == 0){
                                                SetColor(red,black);
                                                warning(88,30,5,38);
                                                gotoxy(92,32); printf("Nama Dokter Tidak Boleh Strip");
                                                getch();
                                                clearAt(88,30,5,38);
                                            }
                                            if(strcmpi(temp.nama_dokter, "-") == 0){
                                                clearAt(98,17,1,strlen(temp.nama_dokter));
                                            }
                                        }
                                        while (true){
                                            show_cur();
                                            SetColor(yellow,black);
                                            gotoxy(84,19); printf("Tanggal Bergabung (dd/mm/yyyy) : "); fflush(stdin); gets(temp.tgl_bergabung);
                                            if(strlen(temp.tgl_bergabung) > 0){
                                                if(checkDate(temp.tgl_bergabung)==1){
                                                    break;
                                                }else if(checkDate(temp.tgl_bergabung)==-1){
                                                    SetColor(red,black);
                                                    warning(88,30,5,38);
                                                    gotoxy(93,32); printf("Tanggal bergabung tidak valid!");
                                                    getch();
                                                    clearAt(88,30,5,38);
                                                }else if(checkDate(temp.tgl_bergabung)==-2){
                                                    SetColor(red,black);
                                                    warning(88,30,5,38);
                                                    gotoxy(95,32); printf("Tanggal hanya boleh 1 ~ 31");
                                                    getch();
                                                    clearAt(88,30,5,38);
                                                }else if(checkDate(temp.tgl_bergabung)==-3){
                                                    SetColor(red,black);
                                                    warning(88,30,5,38);
                                                    gotoxy(96,32); printf("Bulan hanya boleh 1 ~ 12");
                                                    getch();
                                                    clearAt(88,30,5,38);
                                                }else if(checkDate(temp.tgl_bergabung)==-4){
                                                    SetColor(red,black);
                                                    warning(88,30,5,37);
                                                    gotoxy(93,32); printf("Tahun hanya boleh 1900 ~ 2100");
                                                    getch();
                                                    clearAt(88,30,5,37);
                                                }
                                                if(checkDate(temp.tgl_bergabung)!=1){
                                                    clearAt(117,19,1,strlen(temp.tgl_bergabung));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(88,30,5,38);
                                                gotoxy(93,32); printf("Tanggal bergabung tidak valid!");
                                                getch();
                                                clearAt(88,30,5,38);
                                            }
                                        }
                                        while (true){
                                            show_cur();
                                            SetColor(yellow,black);
                                            gotoxy(84,21); printf("Username : "); fflush(stdin); gets(temp.username);
                                            if(strlen(temp.username) > 0){
                                                if(isUniqueDokter(D, temp.username)){
                                                    break;
                                                }else{
                                                    SetColor(red,black);
                                                    warning(88,30,5,38);
                                                    gotoxy(96,32); printf("Username Sudah Digunakan");
                                                    getch();
                                                    clearAt(88,30,5,38);
                                                    clearAt(95,21,1,strlen(temp.username));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(88,30,5,37);
                                                gotoxy(94,32);printf("Username Tidak Boleh Kosong");
                                                getch();
                                                clearAt(88,30,5,38);
                                            }
                                        }
                                        while (true){
                                            show_cur();
                                            i = 0;
                                            SetColor(yellow,black);
                                            gotoxy(84,23);  printf("Password : ");
                                            while (true){
                                                ch = getch();
                                                if (ch == 13){
                                                    break;
                                                }else if (ch == 8){
                                                    if (i > 0){
                                                        i--;
                                                        printf("\b \b");
                                                    }
                                                }else{
                                                    temp.password[i] = ch;
                                                    i++;
                                                    printf("%c", 771);
                                                }
                                            }
                                            temp.password[i] = '\0';
                                            if(strlen(temp.password) > 0){
                                                break;
                                            }else{
                                                SetColor(red,black);
                                                warning(88,30,5,37);
                                                gotoxy(94,32);printf("Password Tidak Boleh Kosong");
                                                getch();
                                                clearAt(88,30,5,39);
                                            }
                                        }
                                        temp.id_dokter=id_dokter;
                                        updateDataDokter(&D,id_dokter,temp);
                                        SetColor(green,black);
                                        warning(88,30,5,37);
                                        gotoxy(92,32);printf("Berhasil Mengubah Data Dokter");
                                    }else{
                                        SetColor(red,black);
                                        warning(88,15,5,37);
                                        gotoxy(93,17); printf("Data Dokter Tidak Ditemukan");
                                    }

                                }else{
                                    SetColor(yellow,black);
                                    bingkaiBesar(80, 4, 11, 53, 0);
                                    gotoxy(91,6); printf("- - - [ Ubah Data Dokter ] - - -");
                                    SetColor(red,black);
                                    warning(88,8,5,37);
                                    gotoxy(93,10); printf("Data Dokter Masih Kosong");
                                }getch();
                                goto backAdmin;
                            }else if(idx.x==67 && idx.y==20){
                                system("cls");
                                if(!isEmptyDokter(D)){
                                    SetColor(yellow,black);
                                    bingkaiBesar(80, 4, 33, 53, 0);
                                    gotoxy(91,6); printf("- - - [ Hapus Data Dokter ] - - -");
                                    printCariDokter(D);
                                    bingkaiKecil(84,8,5,47,0);
                                    show_cur();
                                    gotoxy(86,10); printf("ID Dokter : "); scanf("%d", &id_dokter);
                                    hide_cur();
                                    if(findElmDokter(D, id_dokter) != NULL){
                                        bingkaiKecil(84,15,11,47,0);
                                        gotoxy(86,17); printf("ID Dokter         : %d", findElmDokter(D, id_dokter)->Data_Dokter.id_dokter);
                                        gotoxy(86,18); printf("Nama Dokter       : %s", findElmDokter(D, id_dokter)->Data_Dokter.nama_dokter);
                                        gotoxy(86,19); printf("Tanggal Bergabung : %s", findElmDokter(D, id_dokter)->Data_Dokter.tgl_bergabung);
                                        gotoxy(86,20); printf("Username          : %s", findElmDokter(D, id_dokter)->Data_Dokter.username);
                                        gotoxy(86,21); printf("Password          : %s", findElmDokter(D, id_dokter)->Data_Dokter.password);

                                        gotoxy(86,23); printf("Lanjut menghapus dokter ? ");
                                        SetColor(green,black); gotoxy(95,34);printf("Enter = Ya   ESC = Tidak ");
                                        confirm=getch();
                                        if(confirm==13){
                                            deleteAtDokter(&D, id_dokter);
                                            SetColor(green,black);
                                            warning(84,27,5,47);
                                            gotoxy(95,29); printf("Data Dokter Berhasil Dihapus");
                                        }else if(confirm==27){
                                            SetColor(green,black);
                                            warning(84,27,5,47);
                                            gotoxy(95,29); printf("Data Dokter Batal Dihapus");
                                        }else{
                                            SetColor(green,black);
                                            warning(84,27,5,47);
                                            gotoxy(100,29); printf("Inputan Invalid");
                                        }
                                    }else{
                                        SetColor(red,black);
                                        warning(84,27,5,47);
                                        gotoxy(95,29); printf("Data Dokter Tidak Ditemukan");
                                    }
                                }else{
                                    SetColor(yellow,black);
                                    bingkaiBesar(80, 4, 11, 53, 0);
                                    gotoxy(91,6); printf("- - - [ Hapus Data Dokter ] - - -");
                                    SetColor(red,black);
                                    warning(88,8,5,37);
                                    gotoxy(93,10); printf("Data Dokter Masih Kosong");
                                }
                                getch();
                                goto backAdmin;
                            }else if(idx.x==109 && idx.y==8){
                                system("cls");
                                if(D.firstDokter != NULL){
                                    SetColor(yellow,black);
                                    bingkaiBesar(64, 4, 31, 87, 0);
                                    gotoxy(91,6); printf("- - - [ Inputkan Data Hewan ] - - -");
                                    bingkaiKecil(72,8,19,70,0);
                                    printCariDokter(D);
                                    printHewanTersedia(D);
                                    while(true){
                                        SetColor(yellow,black);
                                        show_cur();
                                        gotoxy(74,10);printf("Masukkan ID dokter: "); fflush(stdin); gets(tampung);
                                        if(checkdigit(tampung)){
                                            id_dokter=atoi(tampung);
                                        }
                                        if(!checkdigit(tampung)){
                                            SetColor(red,black);
                                            warning(84,28,5,47);
                                            gotoxy(98,30); printf("ID Dokter Harus Angka");
                                            getch();
                                            clearAt(84,28,5,47);
                                            clearAt(94,10,1,strlen(tampung));
                                        }else if(findElmDokter(D, id_dokter) == NULL){
                                            SetColor(red,black);
                                            warning(84,28,5,47);
                                            gotoxy(95,30); printf("ID Dokter Tidak Ditemukan");
                                            getch();
                                            clearAt(84,28,5,47);
                                            clearAt(94,10,1,strlen(tampung));
                                            goto backAdmin;
                                        }else{
                                            break;
                                        }
                                    }
                                    while(true){
                                        SetColor(yellow,black);
                                        show_cur();
                                        gotoxy(74,12);
                                        printf("Masukkan ID Hewan yang ingin diperiksa: "); fflush(stdin); gets(tempDataHewan.id_hewan);
                                        if(strlen(tempDataHewan.id_hewan) > 0 && strcmpi(tempDataHewan.id_hewan, "-") != 0){
                                            if(!cekHewanMatiMaster(D, tempDataHewan.id_hewan)){
                                                break;
                                            }else{
                                                printf("\n");
                                                SetColor(red,black);
                                                warning(80,28,5,54);
                                                gotoxy(85,30); printf("Hewan Mati Tidak Bisa Melakukan Pendaftaran");
                                                getch();
                                                clearAt(84,28,5,47);
                                                clearAt(114,12,1,strlen(tempDataHewan.id_hewan));
                                            } 
                                        }else{
                                            SetColor(red,black);
                                            warning(84,28,5,47);
                                            gotoxy(89,30); printf("ID Hewan Tidak Boleh Kosong atau Strip");
                                            getch();
                                            clearAt(84,28,5,47);
                                            clearAt(114,12,1,strlen(tempDataHewan.id_hewan));
                                        }
                                    }
                                    
                                    if(findElmHewan(D, id_dokter, tempDataHewan.id_hewan) == NULL && findElmMasterHewan(D, tempDataHewan.id_hewan) == NULL){
                                        while(true){
                                            show_cur();
                                            gotoxy(74,14);
                                            SetColor(yellow,black);
                                            printf("Masukkan Nama Hewan yang ingin diperiksa: "); fflush(stdin); gets(tempDataHewan.nama_hewan);
                                            if(strlen(tempDataHewan.nama_hewan) > 0 && strcmpi(tempDataHewan.nama_hewan, "-") != 0){
                                                break;
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(87,30); printf("Nama Hewan Tidak Boleh Kosong atau Strip");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);

                                                //clear inputan
                                                clearAt(116,14,1,strlen(tempDataHewan.nama_hewan));
                                            }
                                        }
                                        while(true){
                                            show_cur();
                                            gotoxy(74,16);
                                            SetColor(yellow,black);
                                            printf("Masukkan Jenis Hewan: "); fflush(stdin); gets(tempDataHewan.jenis_hewan);
                                            if(strlen(tempDataHewan.jenis_hewan) > 0){
                                                if(strcmpi(tempDataHewan.jenis_hewan, "kucing") == 0 || strcmpi(tempDataHewan.jenis_hewan, "anjing") == 0 || strcmpi(tempDataHewan.jenis_hewan, "burung") == 0){
                                                    break;
                                                }else{
                                                    SetColor(red,black);
                                                    warning(84,28,5,47);
                                                    gotoxy(95,30); printf("Jenis Hewan Tidak Valid");
                                                    getch();
                                                    //clear warning
                                                    clearAt(84,28,5,47);

                                                    //clear inputan
                                                    clearAt(96,16,1,strlen(tempDataHewan.jenis_hewan));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(92,30); printf("Jenis Hewan Tidak Boleh Kosong");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);
                                            }
                                        }
                                        while(true){
                                            show_cur();
                                            gotoxy(74,18);
                                            SetColor(yellow,black);
                                            printf("Masukkan Tanggal Lahir Hewan: "); fflush(stdin); gets(tempDataHewan.tgl_lahir);
                                            if(strlen(tempDataHewan.tgl_lahir) > 0 && strcmpi(tempDataHewan.tgl_lahir, "-")!=0 && checkDate(tempDataHewan.tgl_lahir)==1){
                                                break;
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(95,30); printf("Tanggal Lahir Tidak Valid");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);

                                                //clear inputan
                                                clearAt(104,18,1,strlen(tempDataHewan.tgl_lahir));
                                            }
                                        }
                                        while(true){
                                            show_cur();
                                            gotoxy(74,20);
                                            SetColor(yellow,black);
                                            printf("Masukkan Jenis Kelamin Hewan: "); fflush(stdin); gets(tempDataHewan.jenis_kelamin);
                                            if(strlen(tempDataHewan.jenis_kelamin) > 0){
                                                if(strcmpi(tempDataHewan.jenis_kelamin, "jantan") == 0 || strcmpi(tempDataHewan.jenis_kelamin, "betina") == 0){
                                                    break;
                                                }else{
                                                    SetColor(red,black);
                                                    warning(84,28,5,47);
                                                    gotoxy(95,30); printf("Jenis Kelamin Tidak Valid");
                                                    getch();
                                                    //clear warning
                                                    clearAt(84,28,5,47);

                                                    //clear inputan
                                                    clearAt(104,20,1,strlen(tempDataHewan.jenis_kelamin));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(92,30); printf("Jenis Kelamin Tidak Boleh Kosong");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);
                                            }
                                        }
                                        strcpy(tempDataHewan.status, "Hidup"); 
                                        if(findElmMasterHewan(D, tempDataHewan.id_hewan) == NULL){
                                            insertMasterHewan(&D, alokasiMasterHewan(tempDataHewan));
                                        }
                                        //riwayat
                                        if(findElmHewan(D, id_dokter, tempDataHewan.id_hewan) == NULL){
                                            DataHewan tmp = findElmMasterHewan(D, tempDataHewan.id_hewan)->Data_Hewan;
                                            inputDataByJenisHewan(&D, tmp, id_dokter);
                                        }
                                        gotoxy(73,21);
                                        printf("----------------------------------------------------------------");
                                        while(true){
                                            show_cur();
                                            gotoxy(74,22);
                                            SetColor(yellow,black);
                                            printf("Masukkan ID Riwayat Periksa: "); fflush(stdin); gets(tempDataRiwayat.id_riwayat_periksa);
                                            if(strlen(tempDataRiwayat.id_riwayat_periksa) > 0 && strcmpi(tempDataRiwayat.id_riwayat_periksa, "-")!=0){
                                                if(findIDRiwayat(D, id_dokter, tempDataHewan.id_hewan, tempDataRiwayat.id_riwayat_periksa) == false){
                                                    break;
                                                }else{
                                                    SetColor(red,black);
                                                    warning(84,28,5,47);
                                                    gotoxy(95,30); printf("ID Riwayat Telah Ada");
                                                    getch();
                                                    //clear warning
                                                    clearAt(84,28,5,47);

                                                    //clear inputan
                                                    clearAt(103,22,1,strlen(tempDataRiwayat.id_riwayat_periksa));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(91,30); printf("ID tidak boleh kosong atau strip");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);

                                                //clear inputan
                                                clearAt(103,22,1,strlen(tempDataRiwayat.id_riwayat_periksa));
                                            }
                                        }

                                        while(true){
                                            show_cur();
                                            gotoxy(74,24);
                                            SetColor(yellow,black);
                                            printf("Masukkan Tanggal Periksa: "); fflush(stdin); gets(tempDataRiwayat.tgl_periksa);
                                            if(strlen(tempDataRiwayat.tgl_periksa) > 0 && strcmpi(tempDataRiwayat.id_riwayat_periksa, "-")!=0 && checkDate(tempDataRiwayat.tgl_periksa)==1){
                                                break;
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(95,30); printf("Tanggal Periksa Tidak Valid");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);

                                                //clear inputan
                                                clearAt(100,24,1,strlen(tempDataRiwayat.tgl_periksa));
                                            }
                                        }

                                        strcpy(tempDataRiwayat.diagnosa_penyakit, "-");
                                        strcpy(tempDataRiwayat.obat, "-");

                                        insertFirstRiwayat(&D, alokasiRiwayat(tempDataRiwayat), id_dokter, tempDataHewan.id_hewan);
                                        
                                        strcpy(tempDataLaporan.id_laporan, tempDataHewan.id_hewan);
                                        strcpy(tempDataLaporan.tgl_laporan, tempDataRiwayat.tgl_periksa);
                                        strcpy(tempDataLaporan.nama_hewan, tempDataHewan.nama_hewan);
                                        strcpy(tempDataLaporan.jenis_hewan, tempDataHewan.jenis_hewan);
                                        strcpy(tempDataLaporan.tgl_lahir, tempDataHewan.tgl_lahir);
                                        strcpy(tempDataLaporan.jenis_kelamin, tempDataHewan.jenis_kelamin);
                                        strcpy(tempDataLaporan.status, tempDataHewan.status);

                                        if(cariIDLaporan(D, id_dokter, tempDataLaporan.id_laporan)){
                                            insertFirstLaporan(&D, alokasiLaporan(tempDataLaporan), id_dokter);
                                        }

                                        insertRiwayatLaporan(&D, alokasiRiwayat(tempDataRiwayat), id_dokter, tempDataLaporan.id_laporan);

                                        SetColor(green,black);
                                        warning(89,28,5,38);
                                        gotoxy(92,30);printf("Berhasil Menambahkan Data Hewan");
                                    }else{
                                        //jika hewan sudah ada
                                        if(findElmHewan(D, id_dokter, tempDataHewan.id_hewan) == NULL){
                                            DataHewan tmp = findElmMasterHewan(D, tempDataHewan.id_hewan)->Data_Hewan;
                                            inputDataByJenisHewan(&D, tmp, id_dokter);
                                        }
                                        gotoxy(73,13);
                                        printf("----------------------------------------------------------------");
                                        while(true){
                                            show_cur();
                                            gotoxy(74,14);
                                            SetColor(yellow,black);
                                            printf("Masukkan ID Riwayat Periksa: "); fflush(stdin); gets(tempDataRiwayat.id_riwayat_periksa);
                                            if(strlen(tempDataRiwayat.id_riwayat_periksa) > 0 && strcmpi(tempDataRiwayat.id_riwayat_periksa, "-") != 0){
                                                if(findIDRiwayat(D, id_dokter, tempDataHewan.id_hewan, tempDataRiwayat.id_riwayat_periksa) == false){
                                                    break;
                                                }else{
                                                    SetColor(red,black);
                                                    warning(84,28,5,47);
                                                    gotoxy(95,30); printf("ID Riwayat Telah Ada");
                                                    getch();
                                                    //clear warning
                                                    clearAt(84,28,5,47);

                                                    //clear inputan
                                                    clearAt(103,14,1,strlen(tempDataRiwayat.id_riwayat_periksa));
                                                }
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(92,30); printf("ID tidak boleh kosong atau strip");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);
                                                
                                                //clear inputan
                                                clearAt(103,14,1,strlen(tempDataRiwayat.id_riwayat_periksa));
                                            }
                                        }

                                        while(true){
                                            show_cur();
                                            SetColor(yellow,black);
                                            gotoxy(74,16);
                                            printf("Masukkan Tanggal Periksa: "); fflush(stdin); gets(tempDataRiwayat.tgl_periksa);
                                            if(strlen(tempDataRiwayat.tgl_periksa) > 0 && checkDate(tempDataRiwayat.tgl_periksa)==1 ){
                                                break;
                                            }else{
                                                SetColor(red,black);
                                                warning(84,28,5,47);
                                                gotoxy(92,30); printf("Tanggal Periksa Tidak Valid");
                                                getch();
                                                //clear warning
                                                clearAt(84,28,5,47);

                                                //clear inputan
                                                clearAt(100,16,1,strlen(tempDataRiwayat.tgl_periksa));
                                            }
                                        }

                                        strcpy(tempDataRiwayat.diagnosa_penyakit, "-");
                                        strcpy(tempDataRiwayat.obat, "-");

                                        insertFirstRiwayat(&D, alokasiRiwayat(tempDataRiwayat), id_dokter, tempDataHewan.id_hewan);
                                        
                                        strcpy(tempDataLaporan.id_laporan, tempDataHewan.id_hewan);
                                        strcpy(tempDataLaporan.tgl_laporan, tempDataRiwayat.tgl_periksa);
                                        strcpy(tempDataLaporan.nama_hewan, tempDataHewan.nama_hewan);
                                        strcpy(tempDataLaporan.jenis_hewan, tempDataHewan.jenis_hewan);
                                        strcpy(tempDataLaporan.tgl_lahir, tempDataHewan.tgl_lahir);
                                        strcpy(tempDataLaporan.jenis_kelamin, tempDataHewan.jenis_kelamin);
                                        strcpy(tempDataLaporan.status, tempDataHewan.status);

                                        if(cariIDLaporan(D, id_dokter, tempDataLaporan.id_laporan)){
                                            insertFirstLaporan(&D, alokasiLaporan(tempDataLaporan), id_dokter);
                                        }

                                        insertRiwayatLaporan(&D, alokasiRiwayat(tempDataRiwayat), id_dokter, tempDataLaporan.id_laporan);

                                        SetColor(green,black);
                                        warning(89,28,5,38);
                                        gotoxy(92,30);printf("Berhasil Menambahkan Data Hewan");
                                    }
                                    
                                }else{
                                    SetColor(yellow,black);
                                    bingkaiBesar(64, 4, 11, 87, 0);
                                    gotoxy(91,6); printf("- - - [ Inputkan Data Hewan ] - - -");
                                    SetColor(red,black);
                                    warning(89,8,5,38);
                                    gotoxy(95,10);printf("Data Dokter Tidak Tersedia");
                                }
                                //
                                getch();
                                goto backAdmin;
                            }else if(idx.x==109 && idx.y==11){
                                system("cls");
                                SetColor(yellow,black);
                                cekHewanMatiByDokter(D);
                                if(cekHewanMatiBool(D)){
                                    bingkaiKecil(83,8,7,48,0);
                                    show_cur();
                                    gotoxy(85,10); printf("Masukkan ID Dokter : "); scanf("%d", &id_dokter);
                                    hide_cur();
                                    if(cekIDTersedia(D, id_dokter)){
                                        printHewanMati(D, id_dokter);
                                        show_cur();
                                        gotoxy(85,12); printf("Masukkan ID Hewan yang ingin dihapus: "); fflush(stdin); gets(tempDataHewan.id_hewan);
                                        hide_cur();
                                        if(cariIDHewan(D, id_dokter, tempDataHewan.id_hewan)){
                                            addressChildHewan Q = findElmHewan(D,id_dokter,tempDataHewan.id_hewan);
                                            bingkaiKecil(83,16,11,48,0);
                                            gotoxy(86,17); printf("ID Hewan        : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.id_hewan);
                                            gotoxy(86,18); printf("Nama Hewan      : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.nama_hewan);
                                            gotoxy(86,19); printf("Tanggal Lahir   : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.tgl_lahir);
                                            gotoxy(86,20); printf("Jenis Hewan     : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.jenis_hewan);
                                            gotoxy(86,21); printf("Jenis Kelamin   : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.jenis_kelamin);
                                            gotoxy(86,22); printf("Status          : %s", findElmHewan(D,id_dokter,tempDataHewan.id_hewan)->Data_Hewan.status);
                                            gotoxy(86,24); printf("Lanjut menghapus hewan ? ");
                                            SetColor(green,black); gotoxy(95,34);printf("Enter = Ya   ESC = Tidak ");
                                            confirm=getch();
                                            if(confirm==13){
                                                deleteHewanMati(&D, id_dokter, tempDataHewan.id_hewan);
                                                SetColor(green,black);
                                                warning(88,28,5,37);
                                                gotoxy(93,30); printf("Data Hewan Berhasil Dihapus");
                                            }else if(confirm==27){
                                                SetColor(green,black);
                                                warning(88,28,5,37);
                                                gotoxy(95,30); printf("Data Hewan Batal Dihapus");
                                            }else{
                                               SetColor(green,black);
                                                warning(88,28,5,37);
                                                gotoxy(100,30); printf("Inputan Invalid");
                                            }
                                        }else{
                                            SetColor(red,black);
                                            warning(88,28,5,37);
                                            gotoxy(93,30); printf("Data Hewan Tidak Ditemukan");
                                        }
                                    }else{
                                        SetColor(red,black);
                                        warning(88,30,5,37);
                                        gotoxy(93,32); printf("ID Dokter Tidak Tersedia");
                                    }
                                }
                                getch();
                                goto backAdmin;
                            }else if(idx.x==109 && idx.y==14){
                                system("cls");
                            	SetColor(yellow,black);
                                bingkaiBesar(80, 4, 12, 53, 0);
                                gotoxy(91,6); printf("- - - [ Lihat Laporan Dokter ] - - -");
                                bingkaiKecil(84,8,5,47,0);
                                show_cur();
                                gotoxy(86,10); printf("ID Dokter : "); scanf("%d", &id_dokter);
                                hide_cur();
                                SetColor(yellow,black);
								printInfoLaporan(D, id_dokter);
                                getch();
                                goto backAdmin;
                            }else if(idx.x==109 && idx.y==17){
                                SetColor(yellow,black);
                                printInfoMasterHewan(D);
                                getch();
                                goto backAdmin;
                            }else if(idx.x==109 && idx.y==20){
                                goto back;
                            }
                        }

                    }
	            break;
	            case 19:
	                system("cls");
	                hide_cur();
	            	SetColor(yellow,black);  
	                bingkaiBesar(80, 4, 33, 52, 0);
	                bingkaiKecil(88,12,9,37,0);
	                gotoxy(88,8); printf("--=================================--");
                    gotoxy(91,9); printf("Silahkan Login Terlebih Dahulu!");
                    gotoxy(89,10); printf("--===============================--");
	                show_cur();
	                gotoxy(90,15); printf("Username : "); fflush(stdin); gets(username);
                    gotoxy(90,17); printf("Password : ");
                    i = 0;
                    while (true){
                        ch = getch();
                        if (ch == 13){
                            break;
                        }else if (ch == 8){
                            if (i > 0){
                                i--;
                                printf("\b \b");
                            }
                        }else{
                            password[i] = ch;
                            i++;
                            printf("%c", 771);
                        }
                    }
                    password[i] = '\0';
                    hide_cur();
                    if(!loginDokter(D, username, password)){
                    	SetColor(red,black);
                        warning(88,28,5,37);
                        gotoxy(93,30); printf("Username atau Password Salah\n");
                        getch();
                    }else{
                        SetColor(green,black);
                        warning(88,28,5,37);
                        gotoxy(93,30); printf("Berhasil login sebagai Dokter\n");
                        tempDokter = findDokterByLogin(D, username, password);
                        getch();
                        backDokter:
                        menuDokter(0,"Dokter");
                        idx.y=8;
                        do{
                            SetColor(red,black);
                            gotoxy(88,idx.y);
                            bingkaiKecil(88,idx.y,7,37,0);
                            checkMenuDokter(idx);
                            pil2=getch();
                            if(pil2==72){ //UP
                                SetColor(yellow,black);
                                gotoxy(88,idx.y);
                                bingkaiKecil(88,idx.y,7,37,0);
                                checkMenuDokter(idx);
                                idx.y-=7;
                            }
                            if(pil2==80){ //DOWN
                                SetColor(yellow,black);
                                gotoxy(88,idx.y);
                                bingkaiKecil(88,idx.y,7,37,0);
                                checkMenuDokter(idx);
                                idx.y+=7;
                            }
                            if(idx.y<8){
                                idx.y=29;
                            }else if(idx.y>29){
                                idx.y=8;
                            }
                        }while(pil2!=13);
                        if(pil2==13){
                            if(idx.y==8){
                                system("cls");
                                SetColor(yellow,black);
                                bingkaiBesar(80, 10, 16, 53, 0);
                                gotoxy(90,12); printf("- - - [ Lihat Data Pasien ] - - -");
                                printInfoHewan(D, tempDokter->Data_Dokter.id_dokter);
                                getch();
                                goto backDokter;
                            }else if(idx.y==15){
                                system("cls");
                                SetColor(yellow,black);
                                bingkaiBesar(80, 4, 33, 53, 0);
                                gotoxy(89,6); printf("- - - [ Menu Selesai Periksa ] - - -");
                                if(isEmptyHewan(tempDokter)){
                                    SetColor(red,black);
                                    warning(88,28,5,37);
                                    gotoxy(95,30); printf("Data Hewan Masih Kosong");
                                }else{
                                    printHewanDariDokter(D, tempDokter->Data_Dokter.id_dokter);
                                    bingkaiKecil(84,8,15,47,0);
                                    show_cur();
                                    gotoxy(86,10); printf("Masukkan ID Hewan : "); fflush(stdin); gets(tempDataHewan.id_hewan);
                                    hide_cur();
                                    
                                    
                                    if(cariIDHewan(D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan)){
                                        tempH=findElmHewan(D,tempDokter->Data_Dokter.id_dokter,tempDataHewan.id_hewan);
                                        if(strcmpi(tempH->Data_Hewan.status,"Mati")!=0){
                                            printInfoRiwayatHewan(D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan);
                                            gotoxy(85,12); printf("---[ Cari Riwayat Yang Akan Diperbaharui ]---");
                                            show_cur();
                                            gotoxy(86,14); printf("Masukkan ID Riwayat: "); fflush(stdin); gets(tempDataRiwayat.id_riwayat_periksa); hide_cur();
                                            if(cariIDRiwayatHewan(D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataRiwayat.id_riwayat_periksa)){
                                                tempR=findElmRiwayat(D,tempDokter->Data_Dokter.id_dokter,tempDataHewan.id_hewan,tempDataRiwayat.id_riwayat_periksa);
                                                strcpy(tempDataRiwayat.tgl_periksa,tempR->Data_Riwayat.tgl_periksa);
                                                while(true){
                                                    SetColor(yellow,black); show_cur();
                                                    gotoxy(86,16); printf("Masukkan Diagnosa : "); fflush(stdin); gets(tempDataRiwayat.diagnosa_penyakit);
                                                    if(strlen(tempDataRiwayat.diagnosa_penyakit) > 0){
                                                        break;
                                                    }else{
                                                        SetColor(red,black);
                                                        warning(88,28,5,37);
                                                        gotoxy(95,30); printf("Diagnosa tidak boleh kosong");
                                                        getch();
                                                        //clear warning
                                                        clearAt(88,28,5,37);

                                                        //clear inputan
                                                        clearAt(106,16,1,strlen(tempDataRiwayat.tgl_periksa));
                                                    }
                                                }
                                                while(true){
                                                    SetColor(yellow,black); show_cur();
                                                    gotoxy(86,18);
                                                    printf("Masukkan Obat : "); fflush(stdin); gets(tempDataRiwayat.obat);
                                                    if(strlen(tempDataRiwayat.obat) > 0){
                                                        break;
                                                    }else{
                                                        SetColor(red,black);
                                                        warning(88,28,5,37);
                                                        gotoxy(95,30); printf("Obat tidak boleh kosong");
                                                        getch();
                                                        //clear warning
                                                        clearAt(88,28,5,37);

                                                        //clear inputan
                                                        clearAt(102,18,1,strlen(tempDataRiwayat.obat));
                                                    }
                                                }
                                                while (true){
                                                    SetColor(yellow,black); show_cur();
                                                    gotoxy(86,20);
                                                    printf("Apakah Hewan Masih Hidup ? (Y/N) : "); fflush(stdin); scanf("%c", &confirm);
                                                    if(confirm == 'Y' || confirm == 'y'){
                                                        break;
                                                    }else if(confirm == 'N' || confirm == 'n'){
                                                        strcpy(tempDataHewan.status, "Mati");
                                                        break;
                                                    }else{
                                                        SetColor(red,black);
                                                        warning(88,28,5,37);
                                                        gotoxy(95,30); printf("Inputan Invalid");
                                                        getch();
                                                        //clear warning
                                                        clearAt(88,28,5,37);

                                                        //clear inputan
                                                        clearAt(121,20,1,1);
                                                    }
                                                }
                                                if(confirm == 'Y' || confirm == 'y'){
                                                    updateRiwayatHewan(&D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataRiwayat);
                                                    updateLaporanHewan(&D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataRiwayat, tempDataHewan.status);
                                                }else if(confirm == 'N' || confirm == 'n'){
                                                    updateRiwayatHewan(&D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataRiwayat);
                                                    updateDataHewan(&D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataHewan);
                                                    updateDataMasterHewan(&D, tempDataHewan.id_hewan, tempDataHewan);
                                                    updateLaporanHewan(&D, tempDokter->Data_Dokter.id_dokter, tempDataHewan.id_hewan, tempDataRiwayat, tempDataHewan.status);
                                                }
                                                SetColor(green,black);
                                                warning(88,28,5,38);
                                                gotoxy(90,30); printf("Data Riwayat Berhasil Diperbaharui");
                                            }else{
                                                SetColor(red,black);
                                                warning(88,28,5,37);
                                                gotoxy(95,30); printf("ID Riwayat Tidak Ditemukan");
                                            }
                                        }else{
                                            SetColor(red,black);
                                            warning(88,28,5,37);
                                            gotoxy(95,30); printf("Status Hewan Sudah Mati");
                                        }
                                        
                                    }else{
                                        SetColor(red,black);
                                        warning(88,28,5,37);
                                        gotoxy(95,30); printf("Data Hewan Tidak Ditemukan");
                                    }
                                }
                                getch();
                                goto backDokter;
                            }else if(idx.y==22){
                                system("cls");
                            	SetColor(yellow,black);
                                bingkaiBesar(80, 10, 12, 53, 0);
                                gotoxy(90,12); printf("- - - [ Lihat Laporan Dokter ] - - -");
								SetColor(yellow,black);
								printInfoLaporan(D, tempDokter->Data_Dokter.id_dokter);
								getch();
                                goto backDokter;
                            }else if(idx.y==29){
                                goto back;
                            }
                        }
                    }
                break;
	                
	            case 26:
	            	system("cls");
	            	hide_cur();
					SetColor(yellow,black);
	            	menuExit(80,10,100);
	            	system("cls");
	            	showCoders(0);
	            	SetColor(black,black);
	                exit(0);
	                break;
	            }
	        }
    	}
    return 0;
}

