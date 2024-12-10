#include <stdio.h>

// Ham tinh UCLN su dung thuat toan Euclid
int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int so1, so2;

    // Nhap 2 so nguyen tu ban phim
    printf("Nhap so thu nhat: ");
    scanf("%d", &so1);

    printf("Nhap so thu hai: ");
    scanf("%d", &so2);

    // Tim UCLN bang ham da xay dung
    int ucln = timUCLN(so1, so2);

    // In ket qua
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", so1, so2, ucln);

    return 0;
}

