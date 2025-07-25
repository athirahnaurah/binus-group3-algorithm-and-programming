#include <stdio.h>
#include <string.h>

#define MAX_PEGAWAI 3
struct Pegawai {
    int nip;
    char namaPegawai[50];
    char alamat[100];
    char noHp[13];
    char jabatan[50];
    char golongan[3];
    int gaji;
    int jamLembur;
};

int getGajiPegawai(char golongan[2]);
int getTarifLembur(char golongan[2]);
int hitungTotalGaji(int gaji, int jamLembur, int tarifLembur) {
    return gaji + (jamLembur * tarifLembur);
}

int main(){
    struct Pegawai pegawai[MAX_PEGAWAI];

    /* INPUT 1*/
    printf("=== Input Data Pegawai ===");
    for(int i = 0; i < MAX_PEGAWAI; i++) {
        printf("\n Data Pegawai ke-%d\n", i + 1);
        
        printf("NIP: ");
        scanf("%d", &pegawai[i].nip);
        getchar();

        printf("Nama Pegawai: ");
        fgets(pegawai[i].namaPegawai, sizeof(pegawai[i].namaPegawai), stdin);
        pegawai[i].namaPegawai[strcspn(pegawai[i].namaPegawai, "\n")] = '\0';
        
        printf("Alamat: ");
        fgets(pegawai[i].alamat, sizeof(pegawai[i].alamat), stdin);
        pegawai[i].alamat[strcspn(pegawai[i].alamat, "\n")] = '\0';
        
        printf("No HP: ");
        fgets(pegawai[i].noHp, sizeof(pegawai[i].noHp), stdin);
        pegawai[i].noHp[strcspn(pegawai[i].noHp, "\n")] = '\0';
        
        printf("Jabatan: ");
        fgets(pegawai[i].jabatan, sizeof(pegawai[i].jabatan), stdin);
        pegawai[i].jabatan[strcspn(pegawai[i].jabatan, "\n")] = '\0';
        
        printf("Golongan: ");
        fgets(pegawai[i].golongan, sizeof(pegawai[i].golongan), stdin);
        pegawai[i].golongan[strcspn(pegawai[i].golongan, "\n")] = '\0';
        
        pegawai[i].gaji = getGajiPegawai(pegawai[i].golongan);
        printf("Gaji: Rp%d \n", pegawai[i].gaji);

        /* Input 2*/
        printf("\n=== Penghitungan Lembur ===\n");
        printf("Nip = %d\n", pegawai[i].nip);
        printf("Golongan = %s\n", pegawai[i].golongan);
        printf("Jam Lembur = ");
        scanf("%d", &pegawai[i].jamLembur);

        int tarifLembur = getTarifLembur(pegawai[i].golongan);
        int totalGaji = hitungTotalGaji(pegawai[i].gaji, pegawai[i].jamLembur, tarifLembur);

        printf("Total Gaji Bulan ini = Rp%d\n", totalGaji);
    }

    return 0;

}

int getGajiPegawai(char golongan[2]) {
    if(strcmp(golongan, "D1") == 0) {
        return 2500000;;
    } else if(strcmp(golongan, "D2") == 0) {
        return 2000000;
    } else if(strcmp(golongan, "D3") == 0) {
        return 1500000;
    } else {
        return 0; 
    }
}

int getTarifLembur(char golongan[2]) {
    if (strcmp(golongan, "D1") == 0) {
        return 10000;
    } else if (strcmp(golongan, "D2") == 0) {
        return 5000;
    } else if (strcmp(golongan, "D3") == 0) {
        return 2500;
    } else {
        return 0;
    }
}

