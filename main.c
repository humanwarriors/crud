#include <stdio.h>
#include "crud.h"

int main(void) {
    printf("hello world\n");
    int choice_1 = 0;
    int choice_2 = 0;
    // void create();
    for(;;){

        printf("선택하실 메뉴를 선택하세요:\n 1.생성 \n 2.데이터체크 \n 3.종료 \n");
        scanf("%d",&choice_1);
    
        switch(choice_1)
        {
            case 1:create(); break;
                
            case 2: read_data();//check_list();

            case 3: 
                choice_2 = 1;
                break;
        }
        if (choice_2 == 1) {
            break;
        }
    }   
        return 0;
}
