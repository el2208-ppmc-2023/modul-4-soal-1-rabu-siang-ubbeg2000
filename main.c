/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bahan{
    char* nama_bahan;
    int bahan_ada; //0 jika bahan kadaluarsa, 1 jika bahan tidak kadaluarsa
}bahan;

bahan* processing_file_bahan(bahan* bahan_bahan, int* jumlah_bahan){
    FILE* file_bahan;
    char nama_file[30]; //asumsi nama file tidak akan lebih dari 30 karakter
    char tanggal_hari_ini[15]; //asumsi input tanggal tidak lebih dari 15 karakter
    char line[255]; //asumsi satu baris dalam file tidak akan lebih dari 255 karakter
    char* token;
    int n = 0, hari, bulan, tahun, hari_ini, bulan_ini, tahun_ini;

    printf("Masukkan nama file bahan: ");
    scanf("%s", nama_file);
    printf("Masukkan tanggal hari ini (ex: 10 Februari 2023->10/02/2023): ");
    scanf("%s", tanggal_hari_ini);

    token = strtok(tanggal_hari_ini,"/");
    hari_ini = atoi(token);
    token = strtok(NULL,"/");
    bulan_ini = atoi(token);
    token = strtok(NULL,"\0");
    tahun_ini = atoi(token);

    file_bahan=fopen(nama_file, "r");

    while(fgets(line, 255, file_bahan)){
        if(n>0){
            bahan_bahan = realloc(bahan_bahan, (n+1)*sizeof(bahan));
        }

        token = strtok(line,",");
        (bahan_bahan+n)->nama_bahan =  malloc((strlen(token)+1) * sizeof(char));
        strcpy((bahan_bahan+n)->nama_bahan, token);
        token = strtok(NULL,"/");
        hari = atoi(token);
        token = strtok(NULL,"/");
        bulan = atoi(token);
        token = strtok(NULL,"\n");
        tahun = atoi(token);

        // Memberi keterangan kadaluarsa pada bahan, 0 -> kadaluarsa, 1 -> belum kadaluarsa
        if(tahun>tahun_ini){
            (bahan_bahan+n)->bahan_ada = 1;
        }
        else if(tahun==tahun_ini){
            if((bulan==bulan_ini && hari>hari_ini) || bulan>bulan_ini){
                (bahan_bahan+n)->bahan_ada = 1;
            }
            else{
                (bahan_bahan+n)->bahan_ada = 0;
            }
        }
        else{
            (bahan_bahan+n)->bahan_ada = 0;
        }

        n++;
    } fclose(file_bahan);

    *jumlah_bahan = n;
    return bahan_bahan;
}

void processing_file_menu(bahan* bahan_bahan, int jumlah_bahan){
    FILE* file_menu;
    char nama_file[255]; //asumsi nama file tidak akan lebih dari 255 karakter
    char line[255]; //asumsi satu baris dalam file tidak akan lebih dari 30 karakter
    char* token;
    char nama_menu[30]; //asumsi nama menu tidak lebih dari 30 karakter
    int ada_menu = 0, i = 0, j = 0, koma = 0;

    printf("Masukan nama file resep: ");
    scanf("%s", nama_file);
    printf("Masukan nama menu: ");
    scanf(" %[^\n]", nama_menu);

    file_menu=fopen(nama_file, "r");
    while(fgets(line, 255, file_menu)){
        koma = 0;
        for(i=0; i<strlen(line); i++){
            if(line[i]==','){
                koma++;
            }
        }

        token = strtok(line,":");
        if(strcmp(nama_menu, token)==0){
            ada_menu = 1;
            int beli = 1;

            for(i=0; i<=koma; i++){
                if(i==koma){
                    token = strtok(NULL,"\n");
                }
                else {
                    token = strtok(NULL,",");
                }
                int apakah_ada = 0;
                for(j=0; j<jumlah_bahan; j++){
                    if(strcmp(token,(bahan_bahan+j)->nama_bahan)==0){
                        apakah_ada = 1;
                        if(((bahan_bahan+j)->bahan_ada)==0){
                            if(beli==1){
                                printf("Anda perlu membeli bahan makanan berikut untuk membuat menu yang Anda pilih: \n");
                            }
                            printf("%d. %s\n", beli, (bahan_bahan+j)->nama_bahan);
                            beli++;
                        }
                    }
                }
                if(apakah_ada==0){
                    if(beli==1){
                        printf("Anda perlu membeli bahan makanan berikut untuk membuat menu yang Anda pilih: \n");
                    }
                    printf("%d. %s\n", beli, token);
                    beli++;
                }
            }

            if(beli==1){
                printf("Semua bahan makanan tersedia!\nAnda dapat membuat menu makanan yang Anda inginkan!\n");
            }

        }
    } fclose(file_menu);

    if(ada_menu == 0){
        printf("Menu yang Anda masukkan tidak ada di daftar menu resep\n");
    }
}

int main(){
    bahan* bahan_bahan;
    int jumlah_bahan = 0;
    bahan_bahan = (bahan*)malloc(sizeof(bahan));
    bahan_bahan = processing_file_bahan(bahan_bahan, &jumlah_bahan);
    processing_file_menu(bahan_bahan, jumlah_bahan);
    return 0;
}
