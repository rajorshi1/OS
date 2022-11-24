#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <linux/kernel.h>
#include <unistd.h>
#include <errno.h>

#define TWOD_COPY_SYSCALL 451

void check_equal(int** lhs, int** rhs, int size) {
    int i;
    for (i = 0; i < size; i++) {
        for (int j=0; j<size; j++) {
            if (lhs[i][j] != rhs[i][j]) {
                printf("Error : LHS[%d] != RHS[%d]\n", lhs[i][j], rhs[i][j]);
                return;
            }
        }
    }
    printf("Message : Success LHS = RHS \n");
}

int main() {
    float MAT1[4][3] = {{1.0,2.0,3.0, 4.0},{3.0,4.0,5.0, 6.0},{5.0,6.0,7.0, 8.0},{7.0,8.0,9.0, 10.0}};
    float MAT2[4][4];
    long sys_call_status;
    sys_call_status = syscall(kernel_2D_memcpy, src_arr, dest_arr);
    if (sys_call_status != EFAULT) {
        printf("Message : System Call 452 successfuly invoked \n");
        check_equal(src_arr, dest_arr, 4);
    }
    return 0;
}
