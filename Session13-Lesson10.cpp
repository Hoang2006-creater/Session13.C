#include <stdio.h>


void nhapMang(int arr[], int *n) {
    printf("Nhap so phan tu can quan ly (toi da 100): ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}


void inMang(int arr[], int n) {
    printf("Gia tri cac phan tu dang quan ly:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void themPhanTu(int arr[], int *n, int viTri, int giaTri) {
    if (*n >= 100) {
        printf("Mang da day, khong the them phan tu moi!\n");
        return;
    }
    for (int i = *n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    (*n)++;
}


void suaPhanTu(int arr[], int n, int viTri, int giaTri) {
    if (viTri >= 0 && viTri < n) {
        arr[viTri] = giaTri;
    } else {
        printf("Vi tri khong hop le!\n");
    }
}


void xoaPhanTu(int arr[], int *n, int viTri) {
    if (viTri >= 0 && viTri < *n) {
        for (int i = viTri; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    } else {
        printf("Vi tri khong hop le!\n");
    }
}


void sapXep(int arr[], int n, int tangDan) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((tangDan && arr[i] > arr[j]) || (!tangDan && arr[i] < arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


void timKiemTuyenTinh(int arr[], int n, int giaTri) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            printf("Phan tu %d xuat hien o vi tri %d\n", giaTri, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang!\n", giaTri);
    }
}


void timKiemNhiPhan(int arr[], int n, int giaTri) {
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == giaTri) {
            printf("Phan tu %d xuat hien o vi tri %d\n", giaTri, mid);
            found = 1;
            break;
        } else if (arr[mid] < giaTri) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang!\n", giaTri);
    }
}


void menu() {
    printf("\nMENU\n");
    printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
    printf("2. In ra gia tri cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n");
    printf("   a. Giam dan\n");
    printf("   b. Tang dan\n");
    printf("7. Tim kiem phan tu nhap vao\n");
    printf("   a. Tim kiem tuyen tinh\n");
    printf("   b. Tim kiem nhi phan\n");
    printf("8. Thoat\n");
}

int main() {
    int arr[100];
    int n = 0, choice, viTri, giaTri;

    do {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            nhapMang(arr, &n);
            break;
        case 2:
            inMang(arr, n);
            break;
        case 3:
            printf("Nhap vi tri can them: ");
            scanf("%d", &viTri);
            printf("Nhap gia tri can them: ");
            scanf("%d", &giaTri);
            themPhanTu(arr, &n, viTri, giaTri);
            break;
        case 4:
            printf("Nhap vi tri can sua: ");
            scanf("%d", &viTri);
            printf("Nhap gia tri moi: ");
            scanf("%d", &giaTri);
            suaPhanTu(arr, n, viTri, giaTri);
            break;
        case 5:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &viTri);
            xoaPhanTu(arr, &n, viTri);
            break;
        case 6:
            printf("Nhap lua chon (1: Giam dan, 2: Tang dan): ");
            scanf("%d", &giaTri);
            sapXep(arr, n, giaTri == 2);
            break;
        case 7:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &giaTri);
            printf("Nhap lua chon (1: Tuyen tinh, 2: Nhi phan): ");
            scanf("%d", &viTri);
            if (viTri == 1) {
                timKiemTuyenTinh(arr, n, giaTri);
            } else if (viTri == 2) {
                sapXep(arr, n, 1); // Sap xep tang dan truoc khi tim kiem nhi phan
                timKiemNhiPhan(arr, n, giaTri);
            } else {
                printf("Lua chon khong hop le!\n");
            }
            break;
        case 8:
            printf("Thoat chuong trinh!\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 8);

    return 0;
}

