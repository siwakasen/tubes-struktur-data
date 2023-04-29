#include "header.h"
// Main Function
void createEmpty(Admin *D) {
    D->firstDokter = NULL;
    D->firstMasterHewan = NULL;
    strcpy(D->username, "admincintasatwa");
    strcpy(D->password, "admincintasatwa");
} 

int checkDate(string date){
    int i;
    int count = 0;
    string getDate;
    strcpy(getDate, date);
    for(i=0; i<strlen(date); i++){
        if(date[i] == '/'){
            count++;
        }
    }
    if(count == 2){
        int tanggal = atoi(strtok(getDate, "/"));
        int bulan = atoi(strtok(NULL, "/"));
        int tahun = atoi(strtok(NULL, "/"));
        if(tanggal >= 1 && tanggal <= 31 && bulan >= 1 && bulan <= 12 && tahun >= 1900 && tahun <= 2100){
            return 1;
        }else if(tanggal<1 || tanggal>31){
            return -2;
        }else if(bulan<1 || bulan>12){
            return -3;
        }else if(tahun<1900 || tahun>2100){
            return -4;
        }
        else {
            return -1;
        }
    }else{
        return -1;
    }
}
bool checkdigit(string temp){
    int length=strlen(temp);
    int i;
    for(i=0;i<length;i++){
        if(!isdigit(temp[i])){
            return false;
        }
    }
    return true;
}
bool isUniqueDokter(Admin D, string username){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        if(strcmp(P->Data_Dokter.username, username) == 0){
            return false;
        }
        P = P->next;
    }
    return true;
}

bool isEmptyDokter(Admin D) {
    return (D.firstDokter == NULL);
}

bool isEmptyHewan(addressChildDokter D) {
    return (D->firstHewan == NULL);
}

bool isEmptyRiwayat(addressChildHewan D) {
    return (D->firstRiwayat == NULL);
}

bool isEmptyLaporan(addressChildDokter D) {
    return (D->firstLaporan == NULL);
}

bool loginAdmin(Admin D, string username, string password){
    if(strcmp(D.username, username) == 0 && strcmp(D.password, password) == 0){
        return true;
    }else{
        return false;
    }
}

bool isEmptyMasterHewan(Admin D) {
    return (D.firstMasterHewan == NULL);
}

bool loginDokter(Admin D, string username, string password){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        if(strcmp(P->Data_Dokter.username, username) == 0 && strcmp(P->Data_Dokter.password, password) == 0){
            return true;
        }
        P = P->next;
    }
    return false;
}

// Alokasi
addressChildDokter alokasiDokter(DataDokter D) {
    addressChildDokter P = (addressChildDokter) malloc (sizeof(ChildDokter));
    if (P != NULL) {
        P->Data_Dokter = D;
        P->next = NULL;
        P->firstHewan = NULL;
        P->firstLaporan = NULL;
    }
    return P;
}

addressChildHewan alokasiHewan(DataHewan D) {
    addressChildHewan P = (addressChildHewan) malloc (sizeof(ChildHewan));
    if (P != NULL) {
        P->Data_Hewan = D;
        P->next = NULL;
        P->firstRiwayat = NULL;
    }
    return P;
}

addressChildRiwayat alokasiRiwayat(DataRiwayat D) {
    addressChildRiwayat P = (addressChildRiwayat) malloc (sizeof(ChildRiwayat));
    if (P != NULL) {
        P->Data_Riwayat = D;
        P->next = NULL;
    }
    return P;
}

addressChildMasterHewan alokasiMasterHewan(DataHewan D) {
    addressChildMasterHewan P = (addressChildMasterHewan) malloc (sizeof(ChildMasterHewan));
    if (P != NULL) {
        P->Data_Hewan = D;
        P->next = NULL;
    }
    return P;
}

addressChildLaporan alokasiLaporan(DataLaporan D) {
    addressChildLaporan P = (addressChildLaporan) malloc (sizeof(ChildLaporan));
    if (P != NULL) {
        P->Data_Laporan = D;
        P->firstRiwayat = NULL;
        P->next = NULL;
    }
    return P;
}

void printInfoMasterHewan(Admin D){
    addressChildMasterHewan P = D.firstMasterHewan;
    addressChildMasterHewan temp = P;
    int i,j,baris,n=29;
    int count=0;
    while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        if(count == 0){
	    	SetColor(red,black);
	        warning(88,28,5,37);
	    	gotoxy(94,30); printf("Data Master Hewan Kosong");
	    	return;
		}
        
        baris=4+count;
        bingkaiKecil(4,28,baris,203,0);
        gotoxy(5,n);
        for(i=1;i<baris-1;i++){
            for(j=1;j<202;j++){
                if(i==2 && j%40==0 && j!=200){
                    printf("%c",197);
                }else if(i==2){
                    printf("%c",196);  
                }else if(j%40==0 && j!=200){
                    printf("%c",179);
                }
                else{
                    printf(" ");
                }
                
            }
            gotoxy(5,n+i);
        }
    
    gotoxy(24,29); printf("ID Hewan");
    gotoxy(24+(40*1)-2,29); printf("Nama Hewan");
    gotoxy(24+(40*2)-7,29); printf("Jenis Hewan");
    gotoxy(24+(40*3)-2,29); printf("Tanggal Lahir");
	gotoxy(24+(40*4)-2,29); printf("Status");
    i=31;
    while(P != NULL){
        gotoxy(24,i); printf("%s", P->Data_Hewan.id_hewan);
        gotoxy(24+(40*1)-2,i); printf("%s", P->Data_Hewan.nama_hewan);
        gotoxy(24+(40*2)-7,i); printf("%s", P->Data_Hewan.jenis_hewan);
        gotoxy(24+(40*3)-2,i); printf("%s", P->Data_Hewan.tgl_lahir);
        gotoxy(24+(40*4)-2,i); printf("%s", P->Data_Hewan.status);
        i++;
        P = P->next;
    }
}

void insertFirstMasterHewan(Admin *D, addressChildMasterHewan P){
    if (isEmptyMasterHewan(*D)) {
        D->firstMasterHewan = P;
    } else {
        P->next = D->firstMasterHewan;
        D->firstMasterHewan = P;
    }
}
void insertLastMasterHewan(Admin *D, addressChildMasterHewan P){
    if (isEmptyMasterHewan(*D)) {
        D->firstMasterHewan = P;
    } else {
        addressChildMasterHewan Q = D->firstMasterHewan;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertAfterMasterHewan(Admin *D, addressChildMasterHewan Prec, addressChildMasterHewan P){
    if (isEmptyMasterHewan(*D)) {
        D->firstMasterHewan = P;
    } else {
        P->next = Prec->next;
        Prec->next = P;
    }
}
void insertMasterHewan(Admin *D, addressChildMasterHewan P){
	if (isEmptyMasterHewan(*D)) {
        insertFirstMasterHewan(D, P);
    } else {
        addressChildMasterHewan Q = D->firstMasterHewan;
        if (strcmpi(Q->Data_Hewan.jenis_hewan, P->Data_Hewan.jenis_hewan) > 0) {
            insertFirstMasterHewan(D, P);
        } else {
            while (Q->next != NULL && strcmpi(Q->next->Data_Hewan.jenis_hewan, P->Data_Hewan.jenis_hewan) < 0) {
                Q = Q->next;
            }
            if (Q->next == NULL) {
                insertLastMasterHewan(D, P);
            } else {
                insertAfterMasterHewan(D, Q, P);
            }
        }
    }
}

addressChildMasterHewan findElmMasterHewan(Admin D, string id_hewan){
    addressChildMasterHewan P = D.firstMasterHewan;
    while(P != NULL){
        if(strcmpi(P->Data_Hewan.id_hewan, id_hewan) == 0){
            return P;
            break;
        }else{
            P = P->next;
        }
    }
}



void insertFirstLaporan(Admin *D, addressChildLaporan P, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyLaporan(Q)) {
        Q->firstLaporan = P;
    } else {
        P->next = Q->firstLaporan;
        Q->firstLaporan = P;
    }
}
void insertLastLaporan(Admin *D, addressChildLaporan P, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyLaporan(Q)) {
        insertFirstLaporan(&(*D), P, id);
    } else {    
        addressChildLaporan S = Q->firstLaporan;
        while (S->next != NULL) {
            S = S->next;
        }
        S->next = P;
    }
}
void inserAfterLaporan(Admin *D, addressChildLaporan P, int id){
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyLaporan(Q)) {
        insertFirstLaporan(D, P, id);
    } else {
        addressChildLaporan S = Q->firstLaporan;
        while (S->next != NULL) {
            S = S->next;
        }
        S->next = P;
    }
}
void deleteFirstLaporan(Admin *D, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (!isEmptyLaporan(Q)) {
        addressChildLaporan P = Q->firstLaporan;
        Q->firstLaporan = P->next;
        P->next = NULL;
        free(P);
    }
}
void deleteLastLaporan(Admin *D, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildLaporan del, prec;
    if (!isEmptyLaporan(Q)) {
        if (Q->firstLaporan->next == NULL) {
            deleteFirstLaporan(D, id);
        } else {
            prec = Q->firstLaporan;
            del = prec->next;
            while (del->next != NULL) {
                prec = del;
                del = del->next;
            }
            prec->next = NULL;
            free(del);
        }
    }
}
void deleteAtLaporan(Admin *D, addressChildLaporan Prec, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildLaporan del;
    if (!isEmptyLaporan(Q)) {
        if (Q->firstLaporan->next == NULL) {
            deleteFirstLaporan(D, id);
        } else {
            del = Prec->next;
            Prec->next = del->next;
            del->next = NULL;
            free(del);
        }
    }
}

void printInfoLaporan(Admin D, int id) {
	addressChildDokter Q = findElmDokter(D, id);
    if (Q!=NULL) {
    	if(Q->firstLaporan != NULL){
	        addressChildLaporan P = Q->firstLaporan;
	        addressChildLaporan temp = P;
	        int jmlLap=0, tempRwyt, maxRwyt=0;
	        int i,j,k,l,baris,kolom,n=29;
	        while(temp!=NULL){
	        	jmlLap++;
	        	addressChildRiwayat X = temp->firstRiwayat;
	        	tempRwyt = 0;
	        	while(X != NULL){
	        		tempRwyt++;
	        		X = X->next;
				}
				if(tempRwyt>maxRwyt){
					maxRwyt = tempRwyt;
				}
				temp = temp->next;
			}
	        
	        baris=4+(4*jmlLap);
	        kolom=41+(40*maxRwyt);
	        bingkaiKecil(4,28,baris,kolom,0);
	        gotoxy(5,n);
	        for(i=1;i<baris-1;i++){
	            for(j=1;j<kolom-1;j++){
	                if(i==2 && j%40==0 && j!=kolom-3){
	                    printf("%c",197);
	                }else if(i==2){
	                    printf("%c",196);  
	                }else if(j%40==0 && j!=kolom-3){
	                    printf("%c",179);
	                }
	                else{
	                    printf(" ");
	                }
	                
	            }
	            gotoxy(5,n+i);
	        }        
	        gotoxy(22,29); printf("Data Hewan");
	        for(i = 1; i<=maxRwyt; i++){
	        	gotoxy(22+(40*i)-2,29); printf("Riwayat %d", i);	
			}
	        i = 6;
	        j = 31;
	        l = 1;
	        while (P != NULL) {
	        	k = 1;
	            gotoxy(i,j++); printf("ID Laporan\t: %s", P->Data_Laporan.id_laporan);
				gotoxy(i,j++);printf("Tanggal Laporan\t: %s", P->Data_Laporan.tgl_laporan);
	            gotoxy(i,j++);printf("Nama Hewan\t: %s", P->Data_Laporan.nama_hewan);
	            gotoxy(i,j++);printf("Status\t\t: %s", P->Data_Laporan.status);
	            
	            addressChildRiwayat S = P->firstRiwayat;
	            while(S != NULL){
	                gotoxy(40*k+(6), 28+4*l-1 ); printf("Tanggal Periksa\t: %s", S->Data_Riwayat.tgl_periksa);
	                gotoxy(40*k+(6), 29+4*l-1 ); printf("Diagnosa\t\t: %s", S->Data_Riwayat.diagnosa_penyakit);
	                gotoxy(40*k+(6), 30+4*l-1 ); printf("Obat\t\t: %s", S->Data_Riwayat.obat);
	                S = S->next;
	                k++;
	            }
	            P = P->next;
	            l++;
	        }
	    }else{
	    	SetColor(red,black);
		    warning(88,28,5,37);
		   	gotoxy(94,30); printf("Belum Ada Data Laporan");
		    return;
		}
    }else{
    	SetColor(red,black);
	    warning(88,28,5,37);
	   	gotoxy(94,30); printf("Data Dokter Tidak Ditemukan");
	    return;
	}
	
}

void printSeluruhLaporanDokter(Admin D){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        printInfoLaporan(D, P->Data_Dokter.id_dokter);
        P = P->next;
    }
}
addressChildLaporan findElmLaporan(Admin D, int id, string id_laporan){
    addressChildDokter Q = findElmDokter(D, id);
    addressChildLaporan P = Q->firstLaporan;
    while(P != NULL){
        if(strcmpi(P->Data_Laporan.id_laporan, id_laporan) == 0){
            return P;
            break;
        }else{
            P = P->next;
        }
    }
}
void cekHewanMatiByDokter(Admin D){
    if (!isEmptyDokter(D)){
        addressChildDokter P = D.firstDokter;
        int i = 1, j;
        int count=0;

        P=D.firstDokter;
        while (P != NULL){
            addressChildHewan temp = P->firstHewan;
            while(temp != NULL){
                if(strcmpi(temp->Data_Hewan.status, "Mati")==0){
                    count++;
                    break;
                }
                temp = temp->next;
            }
            P = P->next;
        }
        if(count!=0){
            int baris=8+count;
            bingkaiBesar(10, 4,baris+1, 50, 0);
            bingkaiBesar(80, 4, 33, 53, 0);
            gotoxy(91,6); printf("- - - [ Hapus Data Pasien ] - - -");

            int a=11,b=8;
            gotoxy(a,b);
            for(i=1;i<baris-3;i++){
                for(j=1;j<49;j++){
                    if((i==1 || i==3)&&j<50){
                        printf("%c",196);
                    }else if(j==25){
                        printf("%c",179);
                    }else{
                        printf(" ");
                    }
                    if(i==1 && j==24){
                        printf("%c",194);
                    }
                    if(i==3&&j==24){
                        printf("%c",197);
                    }
                    
                }
                gotoxy(a,b+i);
            }
            gotoxy(23,6); printf("Data Dokter Yang Tersedia");
            gotoxy(21,9); printf("ID");
            gotoxy(45,9); printf("Nama");
            i=11;
            //
            P=D.firstDokter;
            while (P != NULL){
                addressChildHewan Q = P->firstHewan;
                while(Q != NULL){
                    if(strcmpi(Q->Data_Hewan.status, "Mati")==0){
                        gotoxy(21,i);printf("%d",P->Data_Dokter.id_dokter);
                        gotoxy(45,i);printf("%s", P->Data_Dokter.nama_dokter);
                        i++;
                    }
                    Q = Q->next;
                }
                P = P->next;
            }
        }else if(count==0){
            SetColor(yellow,black);
            bingkaiBesar(80, 4, 11, 53, 0);
            gotoxy(91,6); printf("- - - [ Hapus Data Dokter ] - - -");
            SetColor(red,black);
            warning(88,8,5,37);
            gotoxy(93,10); printf("Tidak Ada Hewan Yang Mati");
        }
    }else{
        SetColor(yellow,black);
        bingkaiBesar(80, 4, 11, 53, 0);
        gotoxy(91,6); printf("- - - [ Hapus Data Dokter ] - - -");
        SetColor(red,black);
        warning(88,8,5,37);
        gotoxy(93,10); printf("Data Dokter Masih Kosong");
    }
}
bool isEmptyRiwayatLaporan(Admin D, int id, string id_laporan){
    addressChildDokter Q = findElmDokter(D, id);
    addressChildLaporan P = findElmLaporan(D, id, id_laporan);
    if(P->firstRiwayat == NULL){
        return true;
    }else{
        return false;
    }
}
void insertRiwayatLaporan(Admin *D, addressChildRiwayat P, int id, string id_laporan){
    addressChildLaporan Q = findElmLaporan(*D, id, id_laporan);
    if(isEmptyRiwayatLaporan(*D, id, id_laporan)){
        Q->firstRiwayat = P;
    }else{
        P->next = Q->firstRiwayat;
        Q->firstRiwayat = P;
    }
}
bool cariIDLaporan(Admin D, int id, string id_laporan){
    addressChildDokter Q = findElmDokter(D, id);
    addressChildLaporan P = Q->firstLaporan;
    while(P != NULL){
        if(strcmpi(P->Data_Laporan.id_laporan, id_laporan) == 0){
            return false;
            break;
        }else{
            P = P->next;
        }
    }
    return true;
}
void updateLaporanHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat, string status){
    addressChildLaporan Q = findElmLaporan(*D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    while(R != NULL){
        if(strcmpi(R->Data_Riwayat.id_riwayat_periksa, Data_Riwayat.id_riwayat_periksa)==0){
            R->Data_Riwayat = Data_Riwayat;
            strcpy(Q->Data_Laporan.status, status);
            break;
        }else{
            R = R->next;
        }
    }
}




void insertFirstDokter(Admin *D, addressChildDokter P) {
    if (isEmptyDokter(*D)) {
        D->firstDokter = P;
    } else {
        P->next = D->firstDokter;
        D->firstDokter = P;
    }
}
void insertLastDokter(Admin *D, addressChildDokter P) {
    if (isEmptyDokter(*D)) {
        insertFirstDokter(&(*D), P);
    } else {    
        addressChildDokter Q = D->firstDokter;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void inserAfterDokter(Admin *D, addressChildDokter P){
    if (isEmptyDokter(*D)) {
        insertFirstDokter(D, P);
    } else {
        addressChildDokter Q = D->firstDokter;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void deleteFirstDokter(Admin *D) {
    if (!isEmptyDokter(*D)) {
        addressChildDokter P = D->firstDokter;
        D->firstDokter = P->next;
        P->next = NULL;
        free(P);
    }
}
void deleteLastDokter(Admin *D) {
    addressChildDokter del, prec;
    if (!isEmptyDokter(*D)) {
        if (D->firstDokter->next == NULL) {
            deleteFirstDokter(D);
        } else {
            prec = D->firstDokter;
            del = prec->next;
            while (del->next != NULL) {
                prec = del;
                del = del->next;
            }
            prec->next = NULL;
            free(del);
        }
    }
}
void deleteAtDokter(Admin *D, int id_dokter) {
    if(!isEmptyDokter(*D)){
        addressChildDokter P = D->firstDokter;
        addressChildDokter Q = P->next;
        if(P->Data_Dokter.id_dokter == id_dokter){
            deleteFirstDokter(D);
        }else{
            while(Q != NULL){
                if(Q->Data_Dokter.id_dokter == id_dokter){
                    P->next = Q->next;
                    Q->next = NULL;
                    free(Q);
                    break;
                }
                P = Q;
                Q = Q->next;
            }
        }
    }
}
void printInfoDokter(Admin D) {
    if (!isEmptyDokter(D)) {
        addressChildDokter P = D.firstDokter;
        addressChildDokter temp = P;
        int i,j,baris,n=29;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        baris=4+count;
        bingkaiKecil(4,28,baris,203,0);
        gotoxy(5,n);
        for(i=1;i<baris-1;i++){
            for(j=1;j<202;j++){
                if(i==2 && j%40==0 && j!=200){
                    printf("%c",197);
                }else if(i==2){
                    printf("%c",196);  
                }else if(j%40==0 && j!=200){
                    printf("%c",179);
                }
                else{
                    printf(" ");
                }
                
            }
            gotoxy(5,n+i);
        }
        gotoxy(24,29); printf("ID");
        gotoxy(24+(40*1)-2,29); printf("Nama");
        gotoxy(24+(40*2)-7,29); printf("Tanggal Bergabung");
        gotoxy(24+(40*3)-2,29); printf("Username");
        gotoxy(24+(40*4)-2,29); printf("Password");
        i=31;
        while (P != NULL) {
            gotoxy(24,i); printf("%d", P->Data_Dokter.id_dokter);
            gotoxy(24+(40*1)-2,i); printf("%s", P->Data_Dokter.nama_dokter);
            gotoxy(24+(40*2)-7,i); printf("%s", P->Data_Dokter.tgl_bergabung);
            gotoxy(24+(40*3)-2,i); printf("%s", P->Data_Dokter.username);
            gotoxy(24+(40*4)-2,i); printf("%s", P->Data_Dokter.password);
            i++;
            P = P->next;
        }
    } else {
        SetColor(red,black);
        warning(88,28,5,37);
        gotoxy(98,30); printf("Data Dokter Kosong");
    }
}
addressChildDokter findElmDokter(Admin D, int id){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        if(P->Data_Dokter.id_dokter == id){
            return P;
            break;
        }
        P = P->next;
    }
    return NULL;
}
void updateDataDokter(Admin *D, int id_dokter, DataDokter Dok){
    addressChildDokter P = findElmDokter(*D, id_dokter);
    if(P != NULL){
        P->Data_Dokter = Dok;
    }
}
addressChildDokter findDokterByLogin(Admin D, string username, string password){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        if(strcmp(P->Data_Dokter.username, username) == 0 && strcmp(P->Data_Dokter.password, password) == 0){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void printHewanTersedia(Admin D){
    addressChildMasterHewan P = D.firstMasterHewan;
    addressChildMasterHewan temp = P;

    int i,j,count=0;
    if(!isEmptyMasterHewan(D)){
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int baris=8+count;
        bingkaiBesar(155,4,baris+1,50,0);

        int a=156,b=8;
        gotoxy(a,b);
        for(i=1;i<baris-3;i++){
            for(j=1;j<49;j++){
                if((i==1 || i==3||i==baris-11)&&j<49){
                     printf("%c",196);
                }else if(j==25){
                    printf("%c",179);
                }else{
                    printf(" ");
                }
                if(i==1 && j==24){
                    printf("%c",194);
                }
                if(i==3&&j==24){
                    printf("%c",197);
                }
            }
            gotoxy(a,b+i);
        }
        gotoxy(166,6); printf("Data Hewan Yang Sudah Terdaftar");
        gotoxy(166,9); printf("ID");
        gotoxy(190,9); printf("Nama");
        i=11;
        while (P!=NULL){
            gotoxy(166,i); printf("%s", P->Data_Hewan.id_hewan);
            gotoxy(190,i); printf("%s", P->Data_Hewan.nama_hewan);
            i++;
            P=P->next;
        }
    }
}
void printCariDokter(Admin D){
	if (!isEmptyDokter(D)) {
        addressChildDokter P = D.firstDokter;
        addressChildDokter temp=P;
        int i,j,count=0;
        
        
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int baris=8+count;
        bingkaiBesar(10, 4,baris+1, 50, 0);

        int a=11,b=8;
        gotoxy(a,b);
        for(i=1;i<baris-3;i++){
            for(j=1;j<49;j++){
                if((i==1 || i==3)&&j<50){
                    printf("%c",196);
                }else if(j==25){
                    printf("%c",179);
                }else{
                    printf(" ");
                }
                if(i==1 && j==24){
                    printf("%c",194);
                }
                if(i==3&&j==24){
                    printf("%c",197);
                }
                
            }
            gotoxy(a,b+i);
        }
        gotoxy(23,6); printf("Data Dokter Yang Tersedia");
        gotoxy(21,9); printf("ID");
        gotoxy(45,9); printf("Nama");
        i=11;
        while (P != NULL) {
            gotoxy(21,i); printf("%d", P->Data_Dokter.id_dokter);
            gotoxy(45,i); printf("%s", P->Data_Dokter.nama_dokter);
            i++;
            P = P->next;
        }
    }
}



void insertFirstRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan) {
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    if (isEmptyRiwayat(R)) {
        R->firstRiwayat = P;
    } else {
        P->next = R->firstRiwayat;
        R->firstRiwayat = P;
    }
}
void insertLastRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    if (isEmptyRiwayat(R)) {
        insertFirstRiwayat(&(*D), P, id, id_hewan);
    } else {    
        addressChildRiwayat S = R->firstRiwayat;
        while (S->next != NULL) {
            S = S->next;
        }
        S->next = P;
    }
}
void inserAfterRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan){
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    if (isEmptyRiwayat(R)) {
        insertFirstRiwayat(D, P, id, id_hewan);
    } else {
        addressChildRiwayat S = R->firstRiwayat;
        while (S->next != NULL) {
            S = S->next;
        }
        S->next = P;
    }
}
void deleteFirstRiwayat(Admin *D, int id, string id_hewan) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    if (!isEmptyRiwayat(R)) {
        addressChildRiwayat P = R->firstRiwayat;
        R->firstRiwayat = P->next;
        P->next = NULL;
        free(P);
    }
}
void deleteLastRiwayat(Admin *D, int id, string id_hewan) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    addressChildRiwayat del, prec;
    if (!isEmptyRiwayat(R)) {
        if (R->firstRiwayat->next == NULL) {
            deleteFirstRiwayat(D, id, id_hewan);
        } else {
            prec = R->firstRiwayat;
            del = prec->next;
            while (del->next != NULL) {
                prec = del;
                del = del->next;
            }
            prec->next = NULL;
            free(del);
        }
    }
}
void deleteAtRiwayat(Admin *D, addressChildRiwayat Prec, int id, string id_hewan) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan R = findElmHewan(*D, id, id_hewan);
    addressChildRiwayat del;
    if (!isEmptyRiwayat(R)) {
        if (R->firstRiwayat->next == NULL) {
            deleteFirstRiwayat(D, id, id_hewan);
        } else {
            del = Prec->next;
            Prec->next = del->next;
            del->next = NULL;
            free(del);
        }
    }
}
void printInfoRiwayat(Admin D, int id, string id_hewan) {
    addressChildHewan R = findElmHewan(D, id, id_hewan);
    if (!isEmptyRiwayat(R)) {
        addressChildRiwayat P = R->firstRiwayat;
        int i = 1;
        while (P != NULL) {
            printf("Data Riwayat ke-%d\n", i);
            printf("Tanggal Periksa : %s\n", P->Data_Riwayat.tgl_periksa);
            printf("Diagnosa : %s\n", P->Data_Riwayat.diagnosa_penyakit);
            printf("Obat : %s\n", P->Data_Riwayat.obat);
            printf("====================================\n");
            P = P->next;
            i++;
        }
    } else {
        printf("Data Riwayat Kosong\n");
    }
}
addressChildRiwayat findElmRiwayat(Admin D, int id, string id_hewan, string id_riwayat){
    addressChildDokter Q = findElmDokter(D, id);
    addressChildHewan R = findElmHewan(D, id, id_hewan);
    addressChildRiwayat P = R->firstRiwayat;
    while(P != NULL){
        if(strcmpi(P->Data_Riwayat.id_riwayat_periksa, id_riwayat) == 0){
            return P;
            break;
        }else{
            P = P->next;
        }
    }
    return NULL;
}
bool cariIDRiwayatHewan(Admin D, int id_dokter, string id_hewan, string id_riwayat){
    addressChildDokter P = findElmDokter(D, id_dokter);
    addressChildHewan Q = findElmHewan(D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    int i = 1;
    while(R != NULL){
        if(strcmpi(R->Data_Riwayat.id_riwayat_periksa, id_riwayat)==0){
            return true;
            break;
        }else{
            R = R->next;
            i++;
        }
    }
    return false;
}
void updateRiwayatdanHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat){
    addressChildDokter P = findElmDokter(*D, id_dokter);
    addressChildHewan Q = findElmHewan(*D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    while(R != NULL){
        if(strcmpi(R->Data_Riwayat.id_riwayat_periksa, Data_Riwayat.id_riwayat_periksa)==0){
            R->Data_Riwayat = Data_Riwayat;
            break;
        }else{
            R = R->next;
        }
    }
}
void printInfoRiwayatHewan(Admin D, int id_dokter, string id_hewan){
    addressChildHewan Q = findElmHewan(D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    addressChildRiwayat temp= R;
    int i,j,count=0;

    while(temp!=NULL){
            count++;
            temp=temp->next;
    }
    int baris=8+count;
        bingkaiBesar(10, 4,baris+1, 50, 0);

        int a=11,b=8;
        gotoxy(a,b);
        for(i=1;i<baris-3;i++){
            for(j=1;j<49;j++){
                if((i==1 || i==3)&&j<50){
                    printf("%c",196);
                }else if(j==25){
                    printf("%c",179);
                }else{
                    printf(" ");
                }
                if(i==1 && j==24){
                    printf("%c",194);
                }
                if(i==3&&j==24){
                    printf("%c",197);
                }
                
            }
            gotoxy(a,b+i);
        }
        gotoxy(23,6); printf("Data Riwayat Yang Tersedia");
        gotoxy(21,9); printf("ID");
        gotoxy(40,9); printf("Tanggal Periksa");
        i=11;
        while (R != NULL) {
            gotoxy(21,i); printf("%s", R->Data_Riwayat.id_riwayat_periksa);
            gotoxy(40,i); printf("%s", R->Data_Riwayat.tgl_periksa);
            i++;
            R = R->next;
        }
}

void updateRiwayatHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat){
    addressChildDokter P = findElmDokter(*D, id_dokter);
    addressChildHewan Q = findElmHewan(*D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    while(R != NULL){
        if(strcmpi(R->Data_Riwayat.id_riwayat_periksa, Data_Riwayat.id_riwayat_periksa)==0){;
            R->Data_Riwayat = Data_Riwayat;
            break;
        }else{
            R = R->next;
        }
    }
}

bool findIDRiwayat(Admin D, int id_dokter, string id_hewan, string id_riwayat_periksa){
    addressChildHewan Q = findElmHewan(D, id_dokter, id_hewan);
    addressChildRiwayat R = Q->firstRiwayat;
    while(R != NULL){
        if(strcmpi(R->Data_Riwayat.id_riwayat_periksa, id_riwayat_periksa)==0){;
            return true;
        }else{
            R = R->next;
        }
    }
    return false;
}




void insertFirstHewan(Admin *D, addressChildHewan P, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyHewan(Q)) {
        Q->firstHewan = P;
    } else {
        P->next = Q->firstHewan;
        Q->firstHewan = P;
    }
}
void insertLastHewan(Admin *D, addressChildHewan P, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyHewan(Q)) {
        insertFirstHewan(&(*D), P, id);
    } else {    
        addressChildHewan R = Q->firstHewan;
        while (R->next != NULL) {
            R = R->next;
        }
        R->next = P;
    }
}
void insertAfterHewan(Admin *D, addressChildHewan prec, addressChildHewan P, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (isEmptyHewan(Q)) {
        insertFirstHewan(&(*D), P, id);
    } else {
        P->next = prec->next;
        prec->next = P;
    }
}
void inputDataByJenisHewan(Admin *D, DataHewan H, int id_dokter){
    addressChildHewan P = alokasiHewan(H);
    addressChildDokter Q = findElmDokter(*D, id_dokter);
    if (isEmptyHewan(Q)) {
        insertFirstHewan(&(*D), P, id_dokter);
    } else {
        addressChildHewan R = Q->firstHewan;
        if (strcmpi(R->Data_Hewan.jenis_hewan, "anjing") == 0) {
            if (strcmpi(P->Data_Hewan.jenis_hewan, "anjing") == 0) {
                insertFirstHewan(&(*D), P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "burung") == 0) {
                insertAfterHewan(&(*D), R, P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "kucing") == 0) {
                while (R->next != NULL) {
                    R = R->next;
                }
                insertAfterHewan(&(*D), R, P, id_dokter);
            }
        } else if (strcmpi(R->Data_Hewan.jenis_hewan, "burung") == 0) {
            if (strcmpi(P->Data_Hewan.jenis_hewan, "anjing") == 0) {
                insertFirstHewan(&(*D), P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "burung") == 0) {
                insertFirstHewan(&(*D), P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "kucing") == 0) {
                while (R->next != NULL) {
                    R = R->next;
                }
                insertAfterHewan(&(*D), R, P, id_dokter);
            }
        } else if (strcmpi(R->Data_Hewan.jenis_hewan, "kucing") == 0) {
            if (strcmpi(P->Data_Hewan.jenis_hewan, "anjing") == 0) {
                insertFirstHewan(&(*D), P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "burung") == 0) {
                insertFirstHewan(&(*D), P, id_dokter);
            } else if (strcmpi(P->Data_Hewan.jenis_hewan, "kucing") == 0) {
                while (R->next != NULL) {
                    R = R->next;
                }
                insertAfterHewan(&(*D), R, P, id_dokter);
            }
        }
    }
}
void deleteFirstHewan(Admin *D, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    if (!isEmptyHewan(Q)) {
        addressChildHewan P = Q->firstHewan;
        Q->firstHewan = P->next;
        P->next = NULL;
        free(P);
    }
}
void deleteLastHewan(Admin *D, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan del, prec;
    if (!isEmptyHewan(Q)) {
        if (Q->firstHewan->next == NULL) {
            deleteFirstHewan(D, id);
        } else {
            prec = Q->firstHewan;
            del = prec->next;
            while (del->next != NULL) {
                prec = del;
                del = del->next;
            }
            prec->next = NULL;
            free(del);
        }
    }
}
void deleteAtHewan(Admin *D, addressChildHewan Prec, int id) {
    addressChildDokter Q = findElmDokter(*D, id);
    addressChildHewan del;
    if (!isEmptyHewan(Q)) {
        if (Q->firstHewan->next == NULL) {
            deleteFirstHewan(D, id);
        } else {
            del = Prec->next;
            Prec->next = del->next;
            del->next = NULL;
            free(del);
        }
    }
}
void printHewanDariDokter(Admin D, int id){
    addressChildDokter Q = findElmDokter(D, id);
    if (!isEmptyHewan(Q)) {
        addressChildHewan P = Q->firstHewan;
        addressChildHewan temp = P;
        int i,j,k=1,baris;
	    int count=0;
	    while(temp!=NULL){
	            count++;
	            temp=temp->next;
	    }
	    baris=8+count;
        bingkaiBesar(155,4,baris+1,50,0);

        int a=156,b=8;
        gotoxy(a,b);
        for(i=1;i<baris-3;i++){
            for(j=1;j<49;j++){
                if((i==1 || i==3||i==baris-11)&&j<49){
                     printf("%c",196);
                }else if(j==25){
                    printf("%c",179);
                }else{
                    printf(" ");
                }
                if(i==1 && j==24){
                    printf("%c",194);
                }
                if(i==3&&j==24){
                    printf("%c",197);
                }
            }
            gotoxy(a,b+i);
        }
        gotoxy(166,6); printf("Data Hewan Yang Tersedia");
        gotoxy(166,9); printf("ID");
        gotoxy(190,9); printf("Nama");
        i=11;
        while (P!=NULL&& strcmpi(P->Data_Hewan.status, "hidup") == 0){
            gotoxy(166,i); printf("%s", P->Data_Hewan.id_hewan);
            gotoxy(190,i); printf("%s", P->Data_Hewan.nama_hewan);
            i++;
            P=P->next;
        }
    } else {
        SetColor(red,black);
        warning(88,17,5,37);
    	gotoxy(94,19); printf("Data Hewan Kosong");
    	return;
    }
}
void printInfoHewan(Admin D, int id) {
    addressChildDokter Q = findElmDokter(D, id);
    if (!isEmptyHewan(Q)) {
        addressChildHewan P = Q->firstHewan;
        addressChildHewan temp = P;
        int i,j,k=1,baris,n=29;
	    int count=0;
	    while(temp!=NULL){
	            count++;
	            temp=temp->next;
	        }
	        
	        baris=4+count;
	        bingkaiKecil(4,28,baris,203,0);
	        gotoxy(5,n);
	        for(i=1;i<baris-1;i++){
	            for(j=1;j<202;j++){
	                if(i==2 && j%40==0 && j!=200){
	                    printf("%c",197);
	                }else if(i==2){
	                    printf("%c",196);  
	                }else if(j%40==0 && j!=200){
	                    printf("%c",179);
	                }
	                else{
	                    printf(" ");
	                }
	                
	            }
	            gotoxy(5,n+i);
	        }
	    
	    gotoxy(24,29); printf("NO");
	    gotoxy(24+(40*1)-2,29); printf("ID Hewan");
	    gotoxy(24+(40*2)-7,29); printf("Nama Hewan");
	    gotoxy(24+(40*3)-2,29); printf("Jenis Hewan");
		gotoxy(24+(40*4)-2,29); printf("Tanggal Lahir");
	    i=31;
        while (P != NULL && strcmpi(P->Data_Hewan.status, "hidup") == 0) {
            gotoxy(24,i); printf("%d", k);
            gotoxy(24+(40*1)-2,i); printf("%s", P->Data_Hewan.id_hewan);
	        gotoxy(24+(40*2)-7,i); printf("%s", P->Data_Hewan.nama_hewan);
	        gotoxy(24+(40*3)-2,i); printf("%s", P->Data_Hewan.jenis_hewan);
	        gotoxy(24+(40*4)-2,i); printf("%s", P->Data_Hewan.tgl_lahir);
            P = P->next;
            k++;
            i++;
        }
    } else {
        SetColor(red,black);
        warning(88,17,5,37);
    	gotoxy(94,19); printf("Data Hewan Kosong");
    	return;
    }
}
        
addressChildHewan findElmHewan(Admin D, int id, string id_hewan){
    addressChildDokter Q = findElmDokter(D, id);
    addressChildHewan P = Q->firstHewan;
    while(P != NULL){
        if(strcmpi(P->Data_Hewan.id_hewan, id_hewan) == 0){
            return P;
            break;
        }else{
            P = P->next;
        }
    }
}
void updateDataHewan(Admin *D, int id_dokter, string id_hewan, DataHewan H){
    addressChildHewan P = findElmHewan(*D, id_dokter, id_hewan);
    if(P != NULL){
        if(strcmpi(P->Data_Hewan.id_hewan, id_hewan) == 0){
            strcpy(P->Data_Hewan.status, H.status);
        }
        P = P->next;
    }
}
void printHewanMati(Admin D, int id_dokter){
    addressChildDokter Q = findElmDokter(D, id_dokter);
    if (!isEmptyHewan(Q)) {
        addressChildHewan P = Q->firstHewan;
        int i = 1,count=0,j;
        while (P != NULL && strcmpi(P->Data_Hewan.status, "mati") == 0) {
            count++;
            P = P->next;
        }
        int baris=8+count;
        bingkaiBesar(155,4,baris+1,50,0);

        int a=156,b=8;
        gotoxy(a,b);
        for(i=1;i<baris-3;i++){
            for(j=1;j<49;j++){
                if((i==1 || i==3||i==baris-11)&&j<49){
                     printf("%c",196);
                }else if(j==25){
                    printf("%c",179);
                }else{
                    printf(" ");
                }
                if(i==1 && j==24){
                    printf("%c",194);
                }
                if(i==3&&j==24){
                    printf("%c",197);
                }
            }
            gotoxy(a,b+i);
        }
        gotoxy(166,6); printf("Data Hewan Yang Sudah Meninggal");
        gotoxy(166,9); printf("ID");
        gotoxy(190,9); printf("Nama");
        i=11;
        P = Q->firstHewan;
        while (P != NULL && strcmpi(P->Data_Hewan.status, "mati") == 0) {
            gotoxy(166,i); printf("%s", P->Data_Hewan.id_hewan);
            gotoxy(190,i); printf("%s", P->Data_Hewan.nama_hewan);
            i++;
            P=P->next;
        }

    } else {
        printf("Data Hewan Kosong\n");
    }
}
bool cekIDTersedia(Admin D, int id_dokter){
    addressChildDokter P = D.firstDokter;
    while(P != NULL){
        if(P->Data_Dokter.id_dokter == id_dokter){
            addressChildHewan Q = P->firstHewan;
            while(Q != NULL){
                if(strcmpi(Q->Data_Hewan.status, "Mati")==0){
                    return true;
                    break;
                }else{
                    Q = Q->next;
                }
            }
            break;
        }
        P = P->next;
    }
    return false;
}
void deleteHewanMati(Admin *D, int id_dokter, string id_hewan){
    addressChildDokter P = findElmDokter(*D, id_dokter);
    addressChildHewan Q = P->firstHewan;
    if(strcmpi(Q->Data_Hewan.id_hewan, id_hewan)==0){
        P->firstHewan = Q->next;
        Q->next = NULL;
        free(Q);
    }else{
        addressChildHewan Prec = P->firstHewan;
        while(Prec->next != NULL && strcmpi(Prec->next->Data_Hewan.id_hewan, id_hewan)!=0){
            Prec = Prec->next;
        }
        if(Prec->next != NULL){
            addressChildHewan del = Prec->next;
            Prec->next = del->next;
            del->next = NULL;
            free(del);
        }
    }
}
bool cariIDHewan(Admin D, int id_dokter, string id_hewan){
    addressChildDokter P = findElmDokter(D, id_dokter);
    addressChildHewan Q = P->firstHewan;
    while(Q != NULL){
        if(strcmpi(Q->Data_Hewan.id_hewan, id_hewan)==0){
            return true;
            break;
        }else{
            Q = Q->next;
        }
    }
    return false;
}
bool cekHewanMatiBool(Admin D){
	if (!isEmptyDokter(D)) {
        addressChildDokter P = D.firstDokter;
        while (P != NULL){
            addressChildHewan Q = P->firstHewan;
            while(Q != NULL){
                if(strcmpi(Q->Data_Hewan.status, "Mati")==0){
                    return true;
                }
                Q = Q->next;
            }
            P = P->next;
        }
    } 
}

bool cekHewanMatiMaster(Admin D, string id_hewan){
	if(!isEmptyMasterHewan(D)){
		addressChildMasterHewan P = D.firstMasterHewan;
		while(P != NULL){
			if(strcmpi(P->Data_Hewan.id_hewan, id_hewan) == 0 && strcmpi(P->Data_Hewan.status, "Mati") == 0){
				return true;
				break;
			}
			P = P->next;
		}
	}
	return false;
}

void updateDataMasterHewan(Admin *D, string id_hewan, DataHewan H){
    addressChildMasterHewan P = D->firstMasterHewan;
    if(P != NULL){
        if(strcmpi(P->Data_Hewan.id_hewan, id_hewan) == 0){
            strcpy(P->Data_Hewan.status, H.status);
        }
        P = P->next;
    }
}

