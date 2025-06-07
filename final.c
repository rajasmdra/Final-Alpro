#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 20

struct produk {
    char nama[25];
    int harga;
    int stok;
    int pesan;
    int terjual;
};

void listProduk(struct produk prod[]) {
    strcpy(prod[0].nama, "Beras 5kg");          prod[0].harga = 68000;  prod[0].stok = 30;   prod[0].pesan = 0;  prod[0].terjual = 10;  
    strcpy(prod[1].nama, "Minyak Goreng 1L");   prod[1].harga = 18500;  prod[1].stok = 25;   prod[1].pesan = 0;  prod[1].terjual = 12;    
    strcpy(prod[2].nama, "Gula Pasir 1kg");     prod[2].harga = 16000;  prod[2].stok = 35;   prod[2].pesan = 0;  prod[2].terjual = 10;    
    strcpy(prod[3].nama, "Garam 500gr");        prod[3].harga = 4000;   prod[3].stok = 40;   prod[3].pesan = 0;  prod[3].terjual = 18;    
    strcpy(prod[4].nama, "Tepung Terigu 1kg");  prod[4].harga = 12000;  prod[4].stok = 30;   prod[4].pesan = 0;  prod[4].terjual = 14;    
    strcpy(prod[5].nama, "Telur 1/2 lusin");    prod[5].harga = 12000;  prod[5].stok = 50;   prod[5].pesan = 0;  prod[5].terjual = 25;    
    strcpy(prod[6].nama, "Kecap Manis");        prod[6].harga = 10000;  prod[6].stok = 20;   prod[6].pesan = 0;  prod[6].terjual = 8;    
    strcpy(prod[7].nama, "Saus Sambal");        prod[7].harga = 9000;   prod[7].stok = 18;   prod[7].pesan = 0;  prod[7].terjual = 7;    
    strcpy(prod[8].nama, "Mie Instan");         prod[8].harga = 3000;   prod[8].stok = 60;   prod[8].pesan = 0;  prod[8].terjual = 45;    
    strcpy(prod[9].nama, "Kopi Sachet");        prod[9].harga = 2500;   prod[9].stok = 90;   prod[9].pesan = 0;  prod[9].terjual = 65;     
    strcpy(prod[10].nama, "Teh Celup");         prod[10].harga = 9000;  prod[10].stok = 55;  prod[10].pesan = 0; prod[10].terjual = 35;   
    strcpy(prod[11].nama, "Air Mineral 600ml"); prod[11].harga = 3500;  prod[11].stok = 100; prod[11].pesan = 0; prod[11].terjual = 75;   
    strcpy(prod[12].nama, "Air Mineral 1.5L");  prod[12].harga = 6000;  prod[12].stok = 90;  prod[12].pesan = 0; prod[12].terjual = 65;   
    strcpy(prod[13].nama, "Susu UHT 1L");       prod[13].harga = 17000; prod[13].stok = 40;  prod[13].pesan = 0; prod[13].terjual = 20;   
    strcpy(prod[14].nama, "Susu Kental Manis"); prod[14].harga = 12000; prod[14].stok = 25;  prod[14].pesan = 0; prod[14].terjual = 12;   
    strcpy(prod[15].nama, "Pasta Gigi");        prod[15].harga = 9000;  prod[15].stok = 35;  prod[15].pesan = 0; prod[15].terjual = 18;   
    strcpy(prod[16].nama, "Sikat Gigi");        prod[16].harga = 6000;  prod[16].stok = 40;  prod[16].pesan = 0; prod[16].terjual = 20;   
    strcpy(prod[17].nama, "Shampoo");           prod[17].harga = 16000; prod[17].stok = 30;  prod[17].pesan = 0; prod[17].terjual = 15;   
    strcpy(prod[18].nama, "Sabun Cuci Piring"); prod[18].harga = 13000; prod[18].stok = 45;  prod[18].pesan = 0; prod[18].terjual = 30;   
    strcpy(prod[19].nama, "Sabun Mandi");       prod[19].harga = 3500;  prod[19].stok = 55;  prod[19].pesan = 0; prod[19].terjual = 35;   
}
void tampilkanMenu(int *menu) {
    printf("\nSELAMAT DATANG DI DUROMART\n\n");
    printf("DAFTAR MENU\n");
    printf("1. Pesan\n");
    printf("2. Cek Stok Barang\n");
    printf("3. Rekap Penjualan\n");
    while (*menu < 1 || *menu > 3) {
        printf("Pilih menu: ");
        scanf("%d", menu);

        if (*menu < 1 || *menu > 3) {
            printf("Input tidak valid, silahkan coba lagi.\n");
        }
    }
}
void cekStok(struct produk prod[]) {
    printf("\nSTOK BARANG\n\n");
    printf("KODE\tNAMA BARANG\t\tSTOK\tKODE\tNAMA BARANG\t\tSTOK\n");
    for (int i = 0; i < MAX / 2; i++) {
        printf("%-7d %-23s %-6d| ", i + 1, prod[i].nama, prod[i].stok);
        printf("%-7d %-23s %d\n", i + 11, prod[i + 10].nama, prod[i + 10].stok);
    }
}
void rekap(struct produk prod[], int *totalRekap, int *rekapDiskon) {
    *totalRekap = 0;
    printf("\nREKAP PENJUALAN\n\n");
    printf("KODE\tNAMA BARANG\t\tTERJUAL\t\tHARGA\t\tSUBTOTAL\n");
    for (int i = 0; i < MAX; i++) {
        printf("%-7d %-23s %-15d Rp. %-11d Rp. %d\n", i + 1, prod[i].nama, prod[i].terjual, prod[i].harga, prod[i].harga * prod[i].terjual);
        *totalRekap += prod[i].harga * prod[i].terjual;
    }
    printf("\nTOTAL\t\t: Rp. %d", *totalRekap);
    printf("\nTOTAL DISKON\t: Rp. %d", *rekapDiskon);
    printf("\nTOTAL BERSIH\t: Rp. %d", *totalRekap - *rekapDiskon);
}
void namaKasir (char kasir[20]) {
    printf("\nMasukkan nama kasir: ");
    getchar();
    gets(kasir);
}
void tampilkanProduk(struct produk prod[]) {
    printf("\nDAFTAR PRODUK\n\n");
    printf("KODE\tNAMA BARANG\t\tHARGA\t\tKODE\tNAMA BARANG\t\tHARGA\n");
    for (int i = 0; i < MAX / 2; i++) {
        printf("%-7d %-23s Rp. %-10d| ", i + 1, prod[i].nama, prod[i].harga);
        printf("%-7d %-23s Rp. %-12d\n", i + 11, prod[i + 10].nama, prod[i + 10].harga);
    }
}
void pilihProduk(int *barang, struct produk prod[]) {
    *barang = 0;
    while (*barang < 1 || *barang > MAX) {
        printf("Pilih produk: ");
        scanf("%d", barang);

        if (*barang < 1 || *barang > MAX) {
            printf("Input tidak valid, silahkan coba lagi.\n");
        }
        else if (prod[*barang - 1].stok == 0) {
            printf("Stok produk habis, silahkan pilih produk lain.\n");
            *barang = 0;
        }
    }
}
void masukkanJumlah(struct produk prod[], int *jumlah, int *barang) {
    *barang -= 1;
    *jumlah = 0;
    while (*jumlah < 1 || *jumlah > prod[*barang].stok) {
        printf("Masukkan jumlah produk : ");
        scanf("%d", jumlah);

        if (*jumlah < 1 || *jumlah > prod[*barang].stok) {
            printf("Stok: %d\n", prod[*barang].stok);
            printf("Stok tidak mencukupi, silahkan coba lagi.\n");
        }
    }
    prod[*barang].stok -= *jumlah;
    prod[*barang].pesan += *jumlah;
    prod[*barang].terjual += *jumlah;
}
void hitungDiskon (struct produk prod[], int *total, int *diskon) {
    *diskon = 0;
    *total = 0;
    for (int i = 0; i < MAX; i++) {
        *total += prod[i].harga * prod[i].pesan;
    }
    if (*total >= 500000 && *total < 1000000) {
        *diskon = 0.05 * (*total);
    }
    else if (*total >= 1000000) {
        *diskon = 0.1 * (*total);
    } 
}
void tampilkanDiskon (int *total, int *diskon) {
    if (*total >= 500000 && *total < 1000000) {
        printf("\nDISKON 5%%\t\t\t: Rp. %d", *diskon);
    }
    else if (*total >= 1000000) {
        printf("\nDISKON 10%%\t\t\t: Rp. %d", *diskon);
    }
    else {
        printf("\nDISKON 0%%\t\t\t: Rp. %d", *diskon);
    } 
}
void totalPesanan (struct produk prod[], int *total, int *diskon) {
    printf("\nDETAIL PESANAN\n");
    for (int i = 0; i < MAX; i++) {
        if(prod[i].pesan > 0)
            printf("%2d. %s\n    %-2d x Rp.%-21d Rp. %d\n", i + 1, prod[i].nama, prod[i].pesan, prod[i].harga, prod[i].harga * prod[i].pesan);
    }
    printf("---------------------------------------------");
    printf("\nSUBTOTAL\t\t\t: Rp. %d", *total);
    tampilkanDiskon(total, diskon);
    printf("\nTOTAL\t\t\t\t: Rp. %d", *total - *diskon);
}
void beliLagi(int *tambah) {
    printf("\n\n1. Tambah\n");
    printf("2. Hapus\n");
    printf("3. Selesai\n");
    while (*tambah < 1 || *tambah > 3) {
        printf("Pilih menu: ");
        scanf("%d", tambah);

        if (*tambah < 1 || *tambah > 3) {
            printf("Input tidak valid, silahkan coba lagi.\n");
        }
    }
} 
void hapusProduk(struct produk prod[], int *hapus) {
    *hapus = 0;
    while (*hapus < 1 || *hapus > MAX) {
        printf("Pilih produk yang ingin dihapus: ");
        scanf("%d", hapus);

        if (*hapus < 1 || *hapus > MAX) {
            printf("Input tidak valid, silahkan coba lagi.\n");
        }
    }

    prod[*hapus - 1].stok += prod[*hapus - 1].pesan;
    prod[*hapus - 1].terjual -= prod[*hapus - 1].pesan;
    prod[*hapus - 1].pesan = 0;
}
void metodePembayaran (int *pembayaran) {
    *pembayaran = 0;
    printf("\nMETODE PEMBAYARAN\n");
    printf("1. Tunai\n");
    printf("2. QRIS\n");
    printf("3. Kredit\n");
    while (*pembayaran < 1 || *pembayaran > 3) {
        printf("Pilih metode pembayaran: ");
        scanf("%d", pembayaran);

        if (*pembayaran < 1 || *pembayaran > 3) {
            printf("Input tidak valid, silahkan coba lagi.\n");
        }
    }
}
void konfirPembayaran (int *uang, int *total, int *pembayaran, int *diskon) {
    *uang = 0;
    if (*pembayaran == 1) {
        while (*uang < *total - *diskon) {
            printf("Masukkan uang: ");
            scanf("%d", uang);
    
            if (*uang < *total - *diskon) {
                printf("Uang tidak cukup, silahkan coba lagi.\n");
            }
        }
    }
    else {
        while (*uang != 1) {
            printf("Konfirmasi pembayaran (Masukkan 1 jika SELESAI): ");
            scanf("%d", uang);
    
            if (*uang != 1) {
                printf("Pembayaran tidak valid, silahkan coba lagi.\n");
            }
        }
        *uang = *total - *diskon;
    }
}
void tampilkanMetode (int *pembayaran, int *uang, int *total) {
    if (*pembayaran == 1) {
        printf("\nTUNAI\t\t\t\t: Rp. %d", *uang);
    }
    else if (*pembayaran == 2) {
        printf("\nQRIS\t\t\t\t: Rp. %d", *total);
    }
    else if (*pembayaran == 3) {
        printf("\nKREDIT\t\t\t\t: Rp. %d", *total);
    }
}
void tampilkanJam () {
    struct tm *jam;

    time_t waktu;
    waktu = time(NULL);
    jam = localtime(&waktu);

    printf("TANGGAL\t: %02d-%02d-%-14d JAM : %02d:%02d:%02d\n", 
        jam->tm_mday,  jam->tm_mon + 1,  jam->tm_year + 1900,  
        jam->tm_hour,  jam->tm_min,  jam->tm_sec);
}
void cetakStruk (struct produk prod[], int *total, int *uang, int *pembayaran, int *diskon, int *rekapDiskon, char kasir[20]) {
    printf("\n%28s", "DUROMART\n");
    printf("%35s", "Jl. Tambak Asri No. 15\n");
    printf("%33s", "Telp: 082186520961\n");
    printf("---------------------------------------------\n");
    tampilkanJam();
    printf("KASIR\t: %s\n", kasir);
    printf("---------------------------------------------");
    totalPesanan (prod, total, diskon);
    tampilkanMetode(pembayaran, uang, total);
    printf("\nKEMBALI\t\t\t\t: Rp. %d\n", *uang - (*total - *diskon));
    printf("---------------------------------------------\n");
    printf("  TERIMA KASIH TELAH BERBELANJA DI DUROMART\n");

    for (int i = 0; i < MAX; i++) {
        prod[i].pesan = 0;
    }
    *rekapDiskon += *diskon;
}

int main() {
    int barang;
    int jumlah;
    int total;
    int program = 1;
    int totalRekap;
    int hapus;
    int pembayaran;
    int diskon;
    int uang;
    int rekapDiskon = 181100;
    char kasir[20];

    struct produk prod[MAX];
    listProduk(prod);

    while (program == 1) {
        int tambah = 1;
        int menu = 0;

        tampilkanMenu(&menu);

        if (menu == 1) {
            namaKasir (kasir);
            tampilkanProduk(prod);
            pilihProduk(&barang, prod);
            masukkanJumlah(prod, &jumlah, &barang);
            hitungDiskon (prod, &total, &diskon);
            totalPesanan(prod, &total, &diskon);
            while (tambah == 1) {
                tambah = 0;
                beliLagi(&tambah);

                if (tambah == 1) {
                    tampilkanProduk(prod);
                    pilihProduk(&barang, prod);
                    masukkanJumlah(prod, &jumlah, &barang);
                    hitungDiskon (prod, &total, &diskon);
                    totalPesanan(prod, &total, &diskon);
                }
                else if (tambah == 2) {
                    hapusProduk(prod, &hapus);
                    hitungDiskon (prod, &total, &diskon);
                    totalPesanan(prod, &total, &diskon);
                    tambah = 1;
                }
                else if (tambah == 3) {
                    metodePembayaran(&pembayaran);
                    konfirPembayaran(&uang, &total, &pembayaran, &diskon);
                    cetakStruk (prod, &total, &uang, &pembayaran, &diskon, &rekapDiskon, kasir);
                }
            }
        } 
        else if (menu == 2) {
            cekStok(prod);
        } 
        else if (menu == 3) {
            rekap(prod, &totalRekap, &rekapDiskon);
        }

        printf("\nKembali ke menu utama? (Masukkan 1 jika YA): ");
        scanf("%d", &program);
    }

    printf("Terima kasih telah menggunakan Duromart!\n");
    return 0;
}