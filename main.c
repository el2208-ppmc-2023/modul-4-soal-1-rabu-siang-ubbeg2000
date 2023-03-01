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

//Catatan: Anda boleh menambah variabel ataupun fungsi lainnya sesuai keperluan Anda.

typedef struct bahan{
    char* nama_bahan; /
    ///.... boleh tambah variabel
} bahan;

int main(){
    char nama_file[30]; //asumsi nama file tidak akan lebih dari 30 karakter
    char tanggal_hari_ini[15]; //asumsi input tanggal tidak lebih dari 15 karakter
    char nama_menu[30]; //asumsi nama menu tidak lebih dari 30 karakter
    
    printf("Masukkan nama file bahan: ");
    scanf("%s", &nama_file);
    printf("Masukkan tanggal hari ini (ex: 10 Februari 2023->10/02/2023): ");
    scanf("%s", &tanggal_hari_ini);

    printf("Masukan nama file resep: ");
    scanf("%s", &nama_file);
    printf("Masukan nama menu: ");
    scanf(" %[^\n]", &nama_menu);

//     printf("Anda perlu membeli bahan makanan berikut untuk membuat menu yang Anda pilih: \n");
//     printf("%d. %s\n", xx, yy);
    
//     printf("Semua bahan makanan tersedia!\nAnda dapat membuat menu makanan yang Anda inginkan!\n");

//     printf("Menu yang Anda masukkan tidak ada di daftar menu resep\n");

}
