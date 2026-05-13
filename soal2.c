/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algoritm
 *   Hari dan Tanggal    : Rabu, 13 Mei 2026
 *   Nama (NIM)          : Angelika Nainggolan (13224085)
 *   Nama File           : modul5yey.c
 *   Deskripsi           : Hitung jumlah pulau dan ukuran pulau terbesar pada grid biner. 
 Kondisi/Aturan 
 1. Grid berukuran R x C  
 2. Setiap sel berisi 0 atau 1  
 3. Dua sel 1 dianggap terhubung jika berdampingan atas, bawah, kiri, atau kanan  
 4. Jumlah pulau = banyak komponen terhubung dari sel 1  
 5. Ukuran pulau = banyak sel 1 di komponen itu  
 6. Jika tidak ada pulau, ukuran terbesar = 0
 */ 
#include <stdio.h>
#include <stdlib.h>

int baris, kolom;
char grid[100][100];
int modul5 (int b, int c){
    if (b < 0){
        return 0;
    }
    if (b >= baris){
        return 0;
    }
    if (c < 0){
        return 0;
    }
    if (c >= kolom){
        return 0;
    }
    if (grid[b][c]=='0'){
        return 0;
    }
    grid[b][c] = '0';
    int size = 1;
    size = size + modul5(b, c+1);
    size = size + modul5(b, c-1);
    size = size + modul5(b+1, c);
    size = size + modul5(b-1, c);
    return size;
}

int main(){
    scanf("%d %d", &baris, &kolom);
    for (int i = 0; i < baris; i++){
        scanf("%s", grid[i]);
    }
    int palingbesar = 0;
    int pulau = 0;
    int baru = 0;
    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            if (grid[i][j] == '1'){
                pulau = pulau + 1;
                baru = modul5(i, j);
                if (baru > palingbesar){
                    palingbesar = baru;
                }
            }
        }
    }
    printf ("\nISLANDS %d", pulau);
    printf ("\nLARGEST %d", palingbesar);
    return 0;
}
//referensi https://www.geeksforgeeks.org/c/c-arrays/
// referensi https://www.geeksforgeeks.org/dsa/find-the-number-of-islands-using-dfs/
