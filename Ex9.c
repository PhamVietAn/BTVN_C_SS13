#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[100][100]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Nhap gia tri cho phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[100][100]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printCorners(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu o goc cua ma tran: \n");
    printf("%d ", matrix[0][0]);
    if(cols>1){
        printf("%d ", matrix[0][cols-1]);
    }
    if(rows>1){
        printf("%d ", matrix[rows-1][0]);
    }
    if(rows>1 && cols>1){
        printf("%d ", matrix[rows-1][cols-1]);
    }
    printf("\n");
}

void printBorders(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu tren duong bien cua ma tran: \n");
    for(int i=0; i<cols; i++){
        printf("%d ", matrix[0][i]); //tren
    } 
    for(int i=1; i<rows; i++){
        printf("%d ", matrix[i][cols - 1]); //phai
    } 
    for(int i=cols-2; i>=0; i--){
        printf("%d ", matrix[rows-1][i]); //duoi
    } 
    for(int i=rows-2; i>0; i--){
        printf("%d ", matrix[i][0]); //trai
    } 
    printf("\n");
}

void printDiagonals(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu tren duong cheo chinh cua ma tran: \n");
    for(int i=0; i<rows && i<cols; i++){
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
    printf("Cac phan tu tren duong cheo phu cua ma tran: \n");
    for (int i=0; i<rows && i<cols; i++){
        printf("%d ", matrix[i][cols-i-1]);
    }
    printf("\n");
}

int isPrime(int num){
    if(num<2){
        return 0;
    }
    for(int i=2; i<=num/2; i++){
        if(num%i==0){
            return 0;
        }
    }
    return 1;
}

void printPrimes(int rows, int cols, int matrix[100][100]){
    printf("Cac phan tu la so nguyen to trong ma tran: \n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            if(isPrime(matrix[i][j])){
                printf("%d ", matrix[i][j]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    int rows, cols, choose;
    int matrix[100][100];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    printf("\nMENU\n");
    printf("1. Nhap gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In ra cac phan tu o goc theo ma tran\n");
    printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
    printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
    printf("7. Thoat\n");
    do{
        
        printf("\nLua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                inputMatrix(rows, cols, matrix);
                break;
            case 2:
                printMatrix(rows, cols, matrix);
                break;
            case 3:
                printCorners(rows, cols, matrix);
                break;
            case 4:
                printBorders(rows, cols, matrix);
                break;
            case 5:
                printDiagonals(rows, cols, matrix);
                break;
            case 6:
                printPrimes(rows, cols, matrix);
                break;
            case 7:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while(choose!=7);

    return 0;
}
