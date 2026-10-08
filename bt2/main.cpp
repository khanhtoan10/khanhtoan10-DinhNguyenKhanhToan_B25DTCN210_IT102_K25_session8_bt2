#include <stdio.h>

struct UserAccount {
    int user_id;
    char username[50];
    int plan_type;
    int days_overdue;
    int active_devices;
    int fee;
};

int main() {
    int n;
    int i;
    struct UserAccount users[100];
    int total_revenue = 0;
    int downgraded_count = 0;

    do {
        printf("Nhap so luong tai khoan (1 - 100): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
            continue;
        }
        if (n < 1 || n > 100) {
            printf("Loi: So luong tai khoan phai nam trong khoang [1, 100]. Vui long nhap lai!\n");
        }
    } while (n < 1 || n > 100);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin tai khoan thu %d ---\n", i + 1);

        printf("Nhap Ma TK (user_id): ");
        scanf("%d", &users[i].user_id);

        printf("Nhap Ten TK (username): ");
        scanf("%s", users[i].username);

        do {
            printf("Nhap Loai goi (1: Free, 2: Personal, 3: Family): ");
            if (scanf("%d", &users[i].plan_type) != 1) {
                while (getchar() != '\n');
                users[i].plan_type = 0;
            }
            if (users[i].plan_type < 1 || users[i].plan_type > 3) {
                printf("Loi: Loai goi khong hop le (phai la 1, 2 hoac 3). Nhap lai!\n");
            }
        } while (users[i].plan_type < 1 || users[i].plan_type > 3);

        do {
            printf("Nhap So ngay no cuoc (days_overdue >= 0): ");
            if (scanf("%d", &users[i].days_overdue) != 1) {
                while (getchar() != '\n');
                users[i].days_overdue = -1;
            }
            if (users[i].days_overdue < 0) {
                printf("Loi: So ngay no cuoc khong duoc la so am. Nhap lai!\n");
            }
        } while (users[i].days_overdue < 0);

        do {
            printf("Nhap So thiet bi dang ket noi (active_devices >= 0): ");
            if (scanf("%d", &users[i].active_devices) != 1) {
                while (getchar() != '\n');
                users[i].active_devices = -1;
            }
            if (users[i].active_devices < 0) {
                printf("Loi: So thiet bi ket noi khong duoc la so am. Nhap lai!\n");
            }
        } while (users[i].active_devices < 0);
    }

    for (i = 0; i < n; i++) {
        if (users[i].days_overdue >= 3) {
            users[i].plan_type = 1;
            users[i].fee = 0;
            downgraded_count++;
        } else {
            if (users[i].plan_type == 1) {
                users[i].fee = 0;
            } else if (users[i].plan_type == 2) {
                users[i].fee = 120000;
            } else if (users[i].plan_type == 3) {
                users[i].fee = 250000;
            }
        }

        if (users[i].plan_type == 2 && users[i].active_devices > 1) {
            users[i].fee += (users[i].active_devices - 1) * 30000;
        }

        total_revenue += users[i].fee;
    }

    printf("\n================================ DANH SACH TAI KHOAN SAU RA SOAT ================================\n");
    printf("%-10s %-20s %-10s %-15s %-15s %-20s\n", 
           "MA TK", "TEN TK", "MA GOI", "SO THIET BI", "SO NGAY NO", "PHI DV THUC THU");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d %-15d %-15d %-20d\n",
               users[i].user_id,
               users[i].username,
               users[i].plan_type,
               users[i].active_devices,
               users[i].days_overdue,
               users[i].fee);
    }

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Tong doanh thu thuc thu trong ky : %d VND\n", total_revenue);
    printf("Tong so tai khoan da bi ha cap ve goi Free: %d\n", downgraded_count);
    printf("=================================================================================================\n");

    return 0;
}

