#include <stdio.h>

int main() {
    int n, denom[] = {500000, 200000, 100000, 50000, 20000, 10000};
    int num[] = {0, 0, 0, 0, 0, 0};
    
    int noteCount[] = {10, 10, 10, 10, 10, 10};  // So to tien con lai cua tung menh gia 

    printf("Nhap so tien can rut: ");
    scanf("%d", &n);

 

    for (int i = 0; i < 6; i++) {
        if (n >= denom[i]) {
            int maxNotes = n / denom[i];
            num[i] = maxNotes < noteCount[i] ? maxNotes : noteCount[i];
            n -= num[i] * denom[i];
            noteCount[i] -= num[i];
        }
    }

    if (n > 0) {
        printf("Khong the rut so tien nay voi so to tien hien co trong ATM!\n");
        return 1;  // Thoat chuong trinh va mo lai
    }

    printf("Danh sach so luong tung loai tien:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d x %d\n", num[i], denom[i]);
    }

   
    printf("So to tien con lai trong ATM:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d x %d\n", noteCount[i], denom[i]);
    }

    return 0;
}

