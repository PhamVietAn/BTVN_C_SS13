#include <stdio.h>

void addAllItem(int arr[], int size){
    for(int i=0; i<size; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void showItems(int arr[], int length){
    for(int i=0; i<length; i++) {
        printf("Phan tu arr[%d] co gia tri %d\n", i, arr[i]);
    }
}

void addItems(int arr[], int *size){
    int index, value;
    printf("Vi tri muon them: ");
    scanf("%d", &index);
    printf("Them phan tu vao mang: ");
    scanf("%d", &value);

    if(index>=0 && index<=*size) {
        for(int i=*size; i>index; i--){
            arr[i]=arr[i-1];
        }
        arr[index]=value;
        (*size)++;
        printf("Mang sau khi them phan tu: ");
        for(int i=0; i<*size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }else{
        printf("Vi tri khong hop le\n");
    }
}

void editItem(int arr[], int size){
    int index, value;
    printf("Vi tri muon sua: ");
    scanf("%d", &index);
    if(index>=0 && index<size){
        printf("Gia tri moi: ");
        scanf("%d", &value);
        arr[index]=value;
    }else{
        printf("Vi tri khong hop le\n");
    }
}

void deleteItem(int arr[], int *size){
    int index;
    printf("Vi tri muon xoa: ");
    scanf("%d", &index);

    if(index>=0 && index<*size){
        for(int i=index; i<*size-1; i++){
            arr[i]=arr[i+1];
        }
        (*size)--;
        printf("Mang sau khi xoa phan tu: ");
        for(int i=0; i<*size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }else{
        printf("Vi tri khong hop le\n");
    }
}

void sortItems(int arr[], int size){
    char choice;
    printf("Sap xep theo thu tu\n   a. tang dan\n   b. giam dan\nLua chon: ");
    scanf(" %c", &choice);

    for(int i=0; i<size-1; i++){
        for(int j=i+1; j < size; j++){
            if((choice=='a' && arr[i]>arr[j]) || (choice=='b'&& arr[i]<arr[j])){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void linearSearch(int arr[], int size){
    int value, found=0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    for(int i=0; i<size; i++){
        if(arr[i]==value){
            printf("Gia tri %d o vi tri arr[%d]\n", value, i);
            found=1;
        }
    }
    if(found==0){
        printf("Khong tim thay gia tri %d trong mang\n", value);
    }
}

void binarySearch(int arr[], int size){
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    int left=0, right=size-1, mid, found=0;
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==value){
            printf("Gia tri %d o vi tri arr[%d]\n", value, mid);
            found=1;
            break;
        }else if(arr[mid]<value){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    if(found==0){
        printf("Khong tim thay gia tri %d trong mang\n", value);
    }
}

int main(){
    int arr[100];
    int choose, size=0;

    printf("\nMENU\n");
    printf("1. Nhap so phan tu va gan gia tri cac phan tu\n");
    printf("2. In ra cac phan tu dang quan ly\n");
    printf("3. Them mot phan tu vao vi tri chi dinh\n");
    printf("4. Sua mot phan tu o vi tri chi dinh\n");
    printf("5. Xoa mot phan tu o vi tri chi dinh\n");
    printf("6. Sap xep cac phan tu\n   a. Tang dan\n   b. Giam dan\n");
    printf("7. Tim kiem phan tu nhap vao\n   a. Tuyen tinh\n   b. Nhi phan\n");
    printf("8. Thoat\n");
    printf("-----------------------------------------------\n");
    do{
        printf("\nLua chon cua ban: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                printf("\nMoi ban nhap so luong phan tu: ");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            case 2:
                printf("\n");
                showItems(arr, size);
                break;
            case 3:
                printf("\n");
                addItems(arr, &size);
                break;
            case 4:
                printf("\n");
                editItem(arr, size);
                break;
            case 5:
                printf("\n");
                deleteItem(arr, &size);
                break;
            case 6:
                printf("\n");
                sortItems(arr, size);
                printf("Mang sau khi sap xep: ");
                for(int i = 0; i < size; i++){
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 7:
                printf("\nLua chon cach tim kiem\n   a. Tuyen tinh\n   b. Nhi phan\nLua chon: ");
                char type;
                scanf(" %c", &type);
                if(type=='a'){
                    linearSearch(arr, size);
                }else if(type=='b'){
                    sortItems(arr, size);
                    binarySearch(arr, size);
                }else{
                    printf("Lua chon khong hop le\n");
                }
                break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    }while(choose != 8);

    return 0;
}
