#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#include <windows.h>
#include <process.h>

//	Made Riksi Purnama Sadnya Agung   210711396
//	I Made Panji Pusaka Suryeswara    210711397
//	Simon Adrian Agis                 210711401
//	Ferdy Firmansyah                  210711480

typedef char string[100];
typedef struct ChildDokter* addressChildDokter;
typedef struct ChildLaporan* addressChildLaporan;
typedef struct ChildHewan* addressChildHewan;
typedef struct ChildRiwayat* addressChildRiwayat;
typedef struct ChildMasterHewan* addressChildMasterHewan;

typedef struct{
    int x,y;
}Index;
typedef struct {
    int id_dokter;
    string nama_dokter;
    string tgl_bergabung;
    string username;
    string password;
} DataDokter;

typedef struct {
    string id_laporan;
    string tgl_laporan;
    string nama_hewan;
    string tgl_lahir;
    string jenis_hewan;
    string jenis_kelamin;
    string status;
} DataLaporan;

typedef struct {
    string id_hewan;
    string nama_hewan;
    string tgl_lahir;
    string jenis_hewan;
    string jenis_kelamin;
    string status;
} DataHewan;

typedef struct {
    string id_riwayat_periksa;
    string diagnosa_penyakit;
    string obat;
    string tgl_periksa;
} DataRiwayat;

typedef struct ChildDokter{
    DataDokter Data_Dokter;
    addressChildDokter next;
    addressChildHewan firstHewan;
    addressChildLaporan firstLaporan;
} ChildDokter;

typedef struct ChildLaporan {
    DataLaporan Data_Laporan;
    addressChildRiwayat firstRiwayat;
    addressChildLaporan next;
} ChildLaporan;

typedef struct ChildHewan {
    DataHewan Data_Hewan;
    addressChildRiwayat firstRiwayat;
    addressChildHewan next;
} ChildHewan;

typedef struct ChildRiwayat{
    DataRiwayat Data_Riwayat;
    addressChildRiwayat next;
} ChildRiwayat;

typedef struct ChildMasterHewan{
    DataHewan Data_Hewan;
    addressChildMasterHewan next;
} ChildMasterHewan;

typedef struct Admin {
    string username;
    string password;
    addressChildDokter firstDokter;
    addressChildMasterHewan firstMasterHewan;
} Admin;

void createEmpty(Admin *D);
int checkDate(string date);
bool isUnique(Admin D, string id);
bool checkdigit(string temp);

bool isEmptyDokter(Admin D);
bool isEmptyHewan(addressChildDokter D);
bool isEmptyRiwayat(addressChildHewan D);
bool isEmptyLaporan(addressChildDokter D);

addressChildDokter alokasiDokter(DataDokter D);
addressChildHewan alokasiHewan(DataHewan D);
addressChildRiwayat alokasiRiwayat(DataRiwayat D);
addressChildMasterHewan alokasiMasterHewan(DataHewan D);
addressChildLaporan alokasiLaporan(DataLaporan D);

void insertFirstDokter(Admin *D, addressChildDokter P);
void insertLastDokter(Admin *D, addressChildDokter P);
void inserAfterDokter(Admin *D, addressChildDokter P);
void deleteFirstDokter(Admin *D);
void deleteLastDokter(Admin *D);
void deleteAtDokter(Admin *D, int id_dokter);
void printInfoDokter(Admin D);
addressChildDokter findElmDokter(Admin D, int id);
void updateDataDokter(Admin *D, int id_dokter, DataDokter Dok);
addressChildDokter findDokterByLogin(Admin D, string username, string password);
void printCariDokter(Admin D);

void insertFirstHewan(Admin *D, addressChildHewan P, int id);
void insertLastHewan(Admin *D, addressChildHewan P, int id);
void insertAfterHewan(Admin *D, addressChildHewan prec, addressChildHewan P, int id);
void inputDataByJenisHewan(Admin *D, DataHewan H, int id_dokter);
void inputDataByJenisHewan(Admin *D, DataHewan H, int id_dokter);
void deleteFirstHewan(Admin *D, int id);
void deleteLastHewan(Admin *D, int id);
void deleteAtHewan(Admin *D, addressChildHewan Prec, int id);
void printInfoHewan(Admin D, int id);
addressChildHewan findElmHewan(Admin D, int id, string id_hewan);
void printHewanMati(Admin D, int id_dokter);
void updateDataHewan(Admin *D, int id_dokter, string id_hewan, DataHewan H);
void cekHewanMatiByDokter(Admin D);
bool cekIDTersedia(Admin D, int id_dokter);
void deleteHewanMati(Admin *D, int id_dokter, string id_hewan);
bool cariIDHewan(Admin D, int id_dokter, string id_hewan);
bool cekHewanMatiBool(Admin D);

void insertFirstRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan);
void insertLastRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan);
void inserAfterRiwayat(Admin *D, addressChildRiwayat P, int id, string id_hewan);
void deleteFirstRiwayat(Admin *D, int id, string id_hewan);
void deleteLastRiwayat(Admin *D, int id, string id_hewan);
void deleteAtRiwayat(Admin *D, addressChildRiwayat Prec, int id, string id_hewan);
addressChildRiwayat findElmRiwayat(Admin D, int id, string id_hewan, string id_riwayat);
bool cariIDRiwayatHewan(Admin D, int id_dokter, string id_hewan, string id_riwayat);
void updateRiwayatdanHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat);
void printInfoRiwayatHewan(Admin D, int id_dokter, string id_hewan);
void updateRiwayatHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat);
bool findIDRiwayat(Admin D, int id_dokter, string id_hewan, string id_riwayat_periksa);

void insertFirstLaporan(Admin *D, addressChildLaporan P, int id);
void insertLastLaporan(Admin *D, addressChildLaporan P, int id);
void inserAfterLaporan(Admin *D, addressChildLaporan P, int id);
void deleteFirstLaporan(Admin *D, int id);
void deleteLastLaporan(Admin *D, int id);
void deleteAtLaporan(Admin *D, addressChildLaporan Prec, int id);
void printInfoLaporan(Admin D, int id);
void printSeluruhLaporanDokter(Admin D);
addressChildLaporan findElmLaporan(Admin D, int id, string id_laporan);
bool isEmptyRiwayatLaporan(Admin D, int id, string id_laporan);
void insertRiwayatLaporan(Admin *D, addressChildRiwayat P, int id, string id_laporan);
bool cariIDLaporan(Admin D, int id, string id_laporan);
void updateLaporanHewan(Admin *D, int id_dokter, string id_hewan, DataRiwayat Data_Riwayat, string status);

void printInfoMasterHewan(Admin D);
void insertFirstMasterHewan(Admin *D, addressChildMasterHewan P);
void insertLastMasterHewan(Admin *D, addressChildMasterHewan P);
void insertAfterMasterHewan(Admin *D, addressChildMasterHewan Prec, addressChildMasterHewan P);
void insertMasterHewan(Admin *D, addressChildMasterHewan P);
addressChildMasterHewan findElmMasterHewan(Admin D, string id_hewan);
bool cekHewanMatiMaster(Admin D, string id_hewan);
void updateDataMasterHewan(Admin *D, string id_hewan, DataHewan H);

//PEWARNAAN DAN DESIGN


//------------ DOUBLE BRACKET TABLE ------------//
#define BLDB 200 //Bottom Left Double Bracket
#define VDB 186 //Vertikal Double Bracket
#define HDB 205 //Horizontal Double Bracket
#define BRDB 188 //Bottom Right Double Bracket
#define CDB 206 //Cross Double Bracket
#define TLDB 201 //Top Left Double Bracket
#define TRDB 187 //Top Right Double Bracket


//------------ SINGLE BRACKET TABLE ------------//
#define HSB 196 //Horizontal Single Bracket
#define BLSB 192 //Bottom Left Single Bracket
#define VSB 179 //Vertikal Single Bracket
#define BRSB 217 //Bottom Right Single Bracket
#define CSB 197 //Cross Single Bracket
#define TRSB 191 //Top Right Single Bracket
#define TLSB 218 //Top Left Single Bracket


//---- WARNA ----//
#define white 15
#define gray 8
#define green 10
#define blue 9
#define purple 13
#define red 12
#define sky 11
#define yellow 14

#define grayX 7
#define black 0
#define purpleX 5
#define blueX 1
#define redX 4
#define skyX 3
#define greenX 2
#define yellowX 6

void hide_cur();
void show_cur();
void maximizeScreen();
void gotoxy(int x,int y);
void SetColor(char text,char bg);
void screen_console(int WIDTH,int HEIGHT);
void showCoders(int sleep);
void clearAt(int x, int y, int row, int col);


void bingkaiBesar(int x, int y, int row, int column, int sleep);
void menuUtama(int sleep);
void menuAdmin(int sleep);
void menuDokter(int sleep, string dokter);
void judul(string atas, string bawah);
void bingkaiKecil(int x,int y, int row, int column,int sleep);
void menuExit(int x,int y,int time);
void warning(int x,int y, int row, int col);

void checkMenuUtama(int menu);
void checkMenuAdmin(Index idx);
void checkMenuDokter(Index idx);
