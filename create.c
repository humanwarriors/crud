#include <stdio.h>
#include "crud.h"
struct info_list{
    char name[25];
    char address[30];
    char email[30];
    int p_num;
}list[100];
static int index[100];
void create(void){
    // FILE * pfile = fopen("list.txt","w+");

    // struct info_list *list[100];
    
    int i = 0;

    printf("이름을 입력하세요: \n");
    scanf("%s",list[i].name);
    printf("주소를 입력하세요(해당 구,동을 붙여서 입력하세요): \n");
    scanf("%s",list[i].address);
    printf("이메일 주소를 입력하세요: \n");
    scanf("%s",list[i].email);
    printf("전화번호를 입력하세요: \n");
    scanf("%d",&list[i].p_num);
    
    index[i]= i ;
    i++;
    
    
}

void read_data(void){
    int i;
    //int check_choice=0;
    char read_check[25];
    int read_check_2 = 0;
    
    printf("이름을 입력해주세요: \n");
    scanf("%s",read_check);
    printf("핸드폰번호를 입력해주세요(-,공란없이 입력): \n");
    scanf("%d",&read_check_2);
    
    for(i=0; i<= 100;i++){
        if (list[i].name == read_check){
            if (list[i].p_num == read_check_2){
                printf("이름: %s \n주소: %s \n메일주소: %s \n 전화번호: %d \n",list[i].name,list[i].address,list[i].email,list[i].p_num);
                
                
            }
            else{
                printf("일치하는 번호가 없습니다.");
                break;
            }
        }
        else{
            printf("일치하는 이름이 없습니다.");
            break;
        }
    }
    
    /*
    switch(check_choice){
        case :;
    }
    */
    
}
/*
void check_list(void){
    create();
    
    int i;

    for (i = 0; i<100;i++){
        int list_empty_check = 0;
        
        
        char *name;
        char *address;
        char *email;
        int *p_num;
        
        name    = list[i].name;
        address = list[i].address;
        email   = list[i].email;
        p_num   = list[i].p_num;
        
        
        if (name == NULL ){
            printf("%s",name);
             list_empty_check = 1;
        }
    
        else if(address == NULL){
            printf("%s",address);
            list_empty_check = 2;
        
        }

        else if(email == NULL){
            printf("%s",email);
            list_empty_check = 3;
        }

        else if(p_num == NULL){
            printf("%d",p_num);
            list_empty_check = 4;
        }

        switch(list_empty_check){
            //case 0: break;
            case 1: index[i]--; break;
            case 2: index[i]--; break;
            case 3: index[i]--; break;
            case 4: index[i]--; break;
        }

        
    }

}
*/
