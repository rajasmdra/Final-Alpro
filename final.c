#include <stdio.h>
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
    struct produk data[] = {
        //NAMA                 HARGA   STOK   PESAN   TERJUAL
        {"Beras 5kg",          68000,   30,     0,       0},
        {"Minyak Goreng 1L",   18500,   25,     0,       0},
        {"Gula Pasir 1kg",     16000,   35,     0,       0},
        {"Garam 500gr",        4000,    40,     0,       0},
        {"Tepung Terigu 1kg",  12000,   30,     0,       0},
        {"Telur 1/2 lusin",    12000,   50,     0,       0},
        {"Kecap Manis",        10000,   20,     0,       0},
        {"Saus Sambal",        9000,    18,     0,       0},
        {"Mie Instan",         3000,    60,     0,       0},
        {"Kopi Sachet",        2500,    90,     0,       0},
        {"Teh Celup Isi 30",   9000,    55,     0,       0},
        {"Air Mineral 600ml",  3500,    100,    0,       0},
        {"Air Mineral 1.5L",   6000,    90,     0,       0},
        {"Susu UHT 1L",        17000,   40,     0,       0},
        {"Susu Kental Manis",  12000,   25,     0,       0},
        {"Pasta Gigi",         9000,    35,     0,       0},
        {"Sikat Gigi",         6000,    40,     0,       0},
        {"Shampoo",            16000,   30,     0,       0},
        {"Sabun Cuci Piring",  13000,   45,     0,       0},
        {"Sabun Mandi",        3500,    55,     0,       0}
    };  
    
    for (int i = 0; i < MAX; i++) {
        prod[i] = data[i];
    }
}
void tampilkanMenu(int *menu) {
    printf("\nSELAMAT DATANG DI DUROMART\n\n");
    printf("DAFTAR MENU\n");
    printf("1. Pesan\n");
    printf("2. Cek Stok Produk\n");
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
    printf("\nSTOK PRODUK\n\n");
    printf("KODE\tNAMA PRODUK\t\tSTOK\tKODE\tNAMA PRODUK\t\tSTOK\n");
    for (int i = 0; i < MAX / 2; i++) {
        printf("%-7d %-23s %-6d| ", i + 1, prod[i].nama, prod[i].stok);
        printf("%-7d %-23s %d\n", i + 11, prod[i + 10].nama, prod[i + 10].stok);
    }
}
void tambahStok(struct produk prod[], int *update, int *barang, int *stokBaru) {
    *barang = 0;
    printf("\nApakah anda ingin menambah stok? (Masukkan 1 jika YA): ");
    scanf("%d", update);

    if (*update == 1) {
        while (*barang < 1 || *barang > MAX) {
            printf("Pilih produk: ");
            scanf("%d", barang);

            if (*barang < 1 || *barang > MAX) {
                printf("Input tidak valid, silahkan coba lagi.\n");
            }
        }
        printf("Tambahkan stok: ");
        scanf("%d", stokBaru);

        prod[*barang - 1].stok += *stokBaru;
        printf("\nStok %s diperbarui: %d", prod[*barang - 1].nama, prod[*barang - 1].stok);
    }
}
void rekap(struct produk prod[], int *totalRekap, int *rekapDiskon) {
    *totalRekap = 0;
    printf("\nREKAP PENJUALAN\n\n");
    printf("KODE\tNAMA PRODUK\t\tTERJUAL\t\tHARGA\t\tSUBTOTAL\n");
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
    printf("KODE\tNAMA PRODUK\t\tHARGA\t\tKODE\tNAMA PRODUK\t\tHARGA\n");
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
    if (*total >= 250000 && *total < 500000) {
        *diskon = 5;
    }
    else if (*total >= 500000) {
        *diskon = 10;
    } 
}
void detailPesanan (struct produk prod[], int *total, int *diskon) {
    printf("\nDETAIL PESANAN\n");
    for (int i = 0; i < MAX; i++) {
        if(prod[i].pesan > 0)
        printf("%2d. %s\n    %-2d x Rp.%-21d Rp. %d\n", i + 1, prod[i].nama, prod[i].pesan, prod[i].harga, prod[i].harga * prod[i].pesan);
    }
    
    printf("---------------------------------------------");
    printf("\nSUBTOTAL\t\t\t: Rp. %d", *total);
    printf("\nDISKON %d%%\t\t\t: Rp. %d", *diskon, (*total) * (*diskon)/100);
    printf("\nTOTAL\t\t\t\t: Rp. %d", (*total) * (100 - *diskon)/100);
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
void hapusProduk(struct produk prod[], int *hapus, int *jumlahHapus) {
    *hapus = 0;
    *jumlahHapus = 0;
    while (*hapus < 1 || *hapus > MAX) {
        printf("Pilih produk yang ingin dihapus: ");
        scanf("%d", hapus);

        if (*hapus < 1 || *hapus > MAX || prod[*hapus - 1].pesan == 0) {
            printf("Input tidak valid, silahkan coba lagi.\n");
            *hapus = 0;
        }
    }

    *hapus -= 1;
    while (*jumlahHapus < 1 || *jumlahHapus > prod[*hapus].pesan) {
        printf("Masukkan jumlah produk yang ingin dihapus: ");
        scanf("%d", jumlahHapus);

        if (*jumlahHapus < 1 || *jumlahHapus >  prod[*hapus].pesan) {
            printf("Input melebihi pesanan, silahkan coba lagi.\n");
        }
    }

    prod[*hapus].stok += *jumlahHapus;
    prod[*hapus].terjual -= *jumlahHapus;
    prod[*hapus].pesan -= *jumlahHapus;
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
        while (*uang < (*total) * (100 - *diskon)/100) {
            printf("Masukkan uang: ");
            scanf("%d", uang);
    
            if (*uang < (*total) * (100 - *diskon)/100) {
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
    }
}
void pembayaran_kembalian (int *pembayaran, int *uang, int *total, int *diskon) {
    if (*pembayaran == 1) {
        printf("\nTUNAI\t\t\t\t: Rp. %d", *uang);
        printf("\nKEMBALI\t\t\t\t: Rp. %d\n", *uang - (*total) * (100 - *diskon)/100);
    }
    else if (*pembayaran == 2) {
        printf("\nQRIS\t\t\t\t: Rp. %d", *total);
        printf("\nKEMBALI\t\t\t\t: Rp. 0\n");
    }
    else if (*pembayaran == 3) {
        printf("\nKREDIT\t\t\t\t: Rp. %d", *total);
        printf("\nKEMBALI\t\t\t\t: Rp. 0\n");
    }
}
void tampilkanJam () {
    struct tm *jam;

    time_t waktu;
    waktu = time(NULL);
    jam = localtime(&waktu);

    printf("TANGGAL\t: %02d-%02d-%-14d JAM : %02d:%02d:%02d\n", 
        jam->tm_mday, jam->tm_mon + 1, jam->tm_year + 1900,  
        jam->tm_hour, jam->tm_min, jam->tm_sec);
}
void cetakStruk (struct produk prod[], int *total, int *uang, int *pembayaran, int *diskon, int *rekapDiskon, char kasir[20]) {
    printf("\n%28s", "DUROMART\n");
    printf("%36s", "Jl. Sidotopo Wetan No. 15\n");
    printf("%33s", "Telp: 085730565400\n");
    printf("---------------------------------------------\n");
    tampilkanJam();
    printf("KASIR\t: %s\n", kasir);
    printf("---------------------------------------------");
    detailPesanan (prod, total, diskon);
    pembayaran_kembalian(pembayaran, uang, total, diskon);
    printf("---------------------------------------------\n");
    printf("  TERIMA KASIH TELAH BERBELANJA DI DUROMART  ");

    for (int i = 0; i < MAX; i++) {
        prod[i].pesan = 0;
    }
    *rekapDiskon += (*total) * (*diskon)/100;
}

int main() {
    int program = 1;
    char kasir[20];
    int barang;
    int jumlah;
    int total;
    int diskon;
    int hapus;
    int jumlahHapus;
    int pembayaran;
    int uang;
    int update;
    int stokBaru;
    int totalRekap;
    int rekapDiskon = 0;
    
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
            detailPesanan(prod, &total, &diskon);
            while (tambah == 1) {
                tambah = 0;
                beliLagi(&tambah);

                if (tambah == 1) {
                    tampilkanProduk(prod);
                    pilihProduk(&barang, prod);
                    masukkanJumlah(prod, &jumlah, &barang);
                    hitungDiskon (prod, &total, &diskon);
                    detailPesanan(prod, &total, &diskon);
                }
                else if (tambah == 2) {
                    hapusProduk(prod, &hapus, &jumlahHapus);
                    hitungDiskon (prod, &total, &diskon);
                    detailPesanan(prod, &total, &diskon);
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
            tambahStok(prod, &update, &barang, &stokBaru);
        }
        else if (menu == 3) {
            rekap(prod, &totalRekap, &rekapDiskon);
        }

        printf("\n\nKembali ke menu utama? (Masukkan 1 jika YA): ");
        scanf("%d", &program);
    }

    printf("\nTerima kasih telah menggunakan Duromart!\n");
    return 0;
}