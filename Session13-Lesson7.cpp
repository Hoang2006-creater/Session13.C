#include <stdio.h>

void tao_ma_tran(int so_hang, int so_cot, float ma_tran[so_hang][so_cot]) {
    printf("Moi ban nhap tung gia tri trong mang:\n");
    for (int i = 0; i < so_hang; i++) {
        for (int j = 0; j < so_cot; j++) {
            printf("Moi ban nhap gia tri hang %d, cot %d: ", i + 1, j + 1);
            scanf("%f", &ma_tran[i][j]);
        }
    }
}

void in_ma_tran(int so_hang, int so_cot, float ma_tran[so_hang][so_cot]) {
    printf("Cac gia tri trong ma tran la:\n");
    for (int i = 0; i < so_hang; i++) {
        for (int j = 0; j < so_cot; j++) {
            printf("%8.2f ", ma_tran[i][j]); 
        }
        printf("\n"); 
    }
}

int main() {
    int so_hang, so_cot;
    printf("Moi ban nhap so hang de tao ma tran: ");
    scanf("%d", &so_hang);
    printf("Moi ban nhap so cot de tao ma tran: ");
    scanf("%d", &so_cot);

    float ma_tran[so_hang][so_cot];
    tao_ma_tran(so_hang, so_cot, ma_tran);
    in_ma_tran(so_hang, so_cot, ma_tran);

    return 0;
}


