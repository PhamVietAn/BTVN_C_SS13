#include <stdio.h>

void createMatrix(int rows, int cols, int matrix[100][100]){
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[100][100]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows, cols;
    int matrix[100][100];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);
    
    createMatrix(rows, cols, matrix);
    
    printf("Ma tran da tao:\n");
    printMatrix(rows, cols, matrix);

    return 0;
}
