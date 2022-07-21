#include <stdio.h>
#include "mysql.h"

  

void main() {
  
   MYSQL *conn; //mysql과의 커넥션을 잡는데 지속적으로 사용되는 변수에요.
   MYSQL_RES *res;  //쿼리문에 대한 result값을 받는 위치변수에요.
   MYSQL_ROW row;   //쿼리문에 대한 실제 데이터값이 들어있는 변수에요.
  
   char *server = "localhost";  //서버의 경로인데요 localhost로 하면 자기 컴퓨터란 의미랍니다.
   char *user = "root"; //mysql로그인 아이디인데요. 기본적으로 별다른 설정이 없으면 root에요
   char *password = ""; /* set me first */   //password를 넣는부분이에요
   char *database = "list";  //Database 이름을 넣어주는 부분이에요.
  
   conn = mysql_init(NULL); //connection 변수를 초기화 시켜요.
  
   /* Connect to database *///DB없이 MYSQL만 접속시킬꺼에요
   if (!mysql_real_connect(conn, server,    //mysql_real_connect()함수가 연결을 시켜주는 함수에요
         user, password, NULL, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
  
   res = mysql_use_result(conn);    //접속한 결과값은 res에 넣는건데요. 딱히 지금은 안해도 상관없어요.
  
    //mysql_query(conn, "create database 데이터베이스이름 DEFAULT CHARACTER SET euckr DEFAULT COLLATE euckr_korean_ci;");
    //mysql_query()는 제 두번째 글 step by step으로 따라했던 부분에 보시면 mysql에서 직접 입력했던 부분을 그대로
    //옮겨온 것을 볼 수 있는데요. 즉 이 값을 C에서 직접 mysql로 쳐준다고 생각하시면 되요.
  
   /* Connect to database *///MYSQL에 생성된 DB에 접속
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }
}

void view()
{
    char    abc = "name";
    char    def ;
    char    show[100]= "";
  
    sprintf( &show[], "select * from student where %s=%s;",abc, def );
    //예제를 이용해 sprintf함수를 설명하면 show라는 변수에 다음의 값들을 넣어줍니다.
    //printf를 쓰면서 많이 본 방식이죠 뒷부분은? %s는 문자열이 들어가는데
    //총 2번의 %s는 차례로 abc, def 의 값이 들어가서 즉 show라는 변수에는
    //select * from student where name=노홍석;
    //이라는 내용이 들어가 있는 것입니다.
  
    if ( mysql_query( conn, show ) != 0 )   //show변수를 query에 넣어준것이죠. 즉, 실행한거죠
    {
        printf( "query fail; err=%s\n", mysql_error( conn ) );
        //만약 에러가 생겼을 때 다음을 출력하는거랍니다.
     }
  
    res=mysql_store_result(conn);
    //query를 통해 나온 결과를 mysql_store_result()함수를 통해 받아옵니다.
    //결과값은 res변수안에 들어갑니다.(아까 메인에 선언되있었죠?저는 그래서 전역변수로 선언했습니다.
  
    //이제 받아온 결과값의 마지막까지 while문을 돌면서
    //해당 값들을 printf시켜 주는 구문입니다.
    while((row=mysql_fetch_row(res))!=NULL)
    {
        printf("%s %s\n", row[0], row[1]);
    }
    mysql_free_result(res);
    //결과를 모두 출력했으니 *형이였던 res 변수를 mysql_free_result해줍니다.
}



/*
int main(void)
{
    MYSQL       *connection=NULL, conn;
    MYSQL_RES   *sql_result;
    MYSQL_ROW   sql_row;
    int       query_stat;

    char name[12];
    char address[80];
    char tel[12];
    char query[255];
    
    mysql_init(&conn);

    connection = mysql_real_connect(&conn, DB_HOST,
                                    DB_USER, DB_PASS,
                                    DB_NAME, 3306,
                                    (char *)NULL, 0);

    if (connection == NULL)
    {
        fprintf(stderr, "Mysql connection error : %s", mysql_error(&conn));
        return 1;
    }

    query_stat = mysql_query(connection, "select * from address");
    if (query_stat != 0)
    {
        fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
        return 1;
    }
    
    sql_result = mysql_store_result(connection);
    
    printf("%+11s %-30s %-10s", "이름", "주소", "전화번호");
    while ( (sql_row = mysql_fetch_row(sql_result)) != NULL )
    {
        printf("%+11s %-30s %-10s", sql_row[0], sql_row[1], sql_row[2]);
    }

    mysql_free_result(sql_result);

    printf("이름 :");
    fgets(name, 12, stdin);
    CHOP(name);

    printf("주소 :");
    fgets(address, 80, stdin);
    CHOP(address);

    printf("전화 :");
    fgets(tel, 12, stdin);
    CHOP(tel);

    sprintf(query, "insert into address values "
                   "('%s', '%s', '%s')",
                   name, address, tel);

    query_stat = mysql_query(connection, query);
    if (query_stat != 0)
    {
        fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
        return 1;
    }

    mysql_close(connection);
}
*/
