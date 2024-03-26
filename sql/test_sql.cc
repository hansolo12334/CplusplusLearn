#include<stdio.h>
#include<mysql/mysql.h>
#include<iostream>


using namespace std;
void func()
{
    MYSQL connect;//mysql连接对象
    mysql_init(&connect);

    //连接mysql
    if(mysql_real_connect(&connect,"localhost","hansolo","dxy6964363","database_hansolo",0,NULL,0))//123456为数据库密码,database_hansolo是数据库
    {
        printf("连接数据库成功\n");
       
    }
    else
    {
        printf("error:%s\n", mysql_error(&connect));
        printf("连接失败\n");
    }
    if(mysql_select_db(&connect, "database_hansolo")){
        cout << "选择数据库失败" << mysql_error(&connect) << endl;
        return;
    }
    

    // 关闭连接
    mysql_close(&connect);
}

int main()
{
    func();
}
