#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct {
    char TenDV[20];
    float TL, GT, DG;
    int So_DV_Duoc_Chon; 
} DoVat;

DoVat* ReadFromConsole(float* W, int* n) {
    DoVat* dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;

    // Nhap trong luong cua tui
    printf("Nhap trong luong cua tui: ");
    scanf("%f", W);

    // Nhap thong tin cua cac do vat 
    while (1) {
        printf("Nhap thong tin cho do vat thu %d (nhap 'q' de ket thuc):\n", i + 1);
        printf("Trong luong: ");
        if (scanf("%f", &dsdv[i].TL) != 1) {
            break; // K?t thúc n?u ngý?i dùng nh?p 'q'
        }

        printf("Gia tri: ");
        scanf("%f", &dsdv[i].GT);

        printf("Ten do vat: ");
        getchar(); // An ki tu Enter 
        fgets(dsdv[i].TenDV, sizeof(dsdv[i].TenDV), stdin);
        dsdv[i].TenDV[strcspn(dsdv[i].TenDV, "\n")] = '\0'; // Lo?i b? kí t? newline n?u có

        dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
        dsdv[i].So_DV_Duoc_Chon = 0;

        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
    }

    *n = i;
    return dsdv;
}


void swap(DoVat* x, DoVat* y) {
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat* dsdv, int n) {
    int i, j;
    for (i = 0; i <= n - 2; i++) {
        for (j = 0; j <= n - i - 2; j++) {
            if (dsdv[j].DG < dsdv[j + 1].DG) {
                swap(&dsdv[j], &dsdv[j + 1]);
            }
        }
    }
}

void InDSDV(DoVat* dsdv, int n, float W) {
    int i;
    float TongTL = 0.0, TongGT = 0.0;
    printf("\nPhuong an thu duoc tu ky thuat THAM AN nhu sau:\n");
    printf("|---|------------------|------------|-------------|-------------|------------------|\n");
    printf("|STT|   Ten Do Vat     |   T.Luong  |   Gia Tri   |   Don Gia   | So DV Duoc Chon  |\n");
    printf("|---|------------------|------------|-------------|-------------|------------------|\n");
    for (i = 0; i < n; i++) {
        printf("|%-3d|%-18s|%12.2f|%13.2f|%13.2f|%9d         |\n", i + 1, dsdv[i].TenDV, dsdv[i].TL, dsdv[i].GT, dsdv[i].DG, dsdv[i].So_DV_Duoc_Chon);
        TongTL = TongTL + dsdv[i].So_DV_Duoc_Chon * dsdv[i].TL;
        TongGT = TongGT + dsdv[i].So_DV_Duoc_Chon * dsdv[i].GT;
    }
    printf("|---|------------------|------------|-------------|-------------|------------------|\n");
    printf("\nTrong luong cua balo = %-9.2f\n", W);
    printf("\nTrong luong cac vat duoc chon = %-9.2f\n\nTong gia tri = %9.2f\n", TongTL, TongGT);
}

void Greedy(DoVat* dsdv, int n, float W) {
    int i;
    for (i = 0; i < n; i++) {
        dsdv[i].So_DV_Duoc_Chon = (int)(W / dsdv[i].TL);
        W = W - dsdv[i].So_DV_Duoc_Chon * dsdv[i].TL;
    }
}

int main() {
    int n;
    float W;
    DoVat* dsdv;
    dsdv = ReadFromConsole(& W, & n);
    BubbleSort(dsdv, n);
    Greedy(dsdv, n, W);
    InDSDV(dsdv, n, W);
    free(dsdv);
    return 0;
}
