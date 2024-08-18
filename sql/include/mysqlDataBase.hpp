#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

#include<mysql/mysql.h>

class DataBase
{
private:
    bool m_state;
    MYSQL *m_connect;
    std::vector<MYSQL_FIELD *> m_fd;
    std::vector<std::string> m_field;
    MYSQL_RES *m_res;
    MYSQL_ROW m_column;

public:
    DataBase();
    ~DataBase();

    bool connect(const std::string &ip, const std::string &name, const std::string &password, const std::string &dataBaseName, int port);

    bool disconnect();
    
    int getTableField(const std::string &tableName);

    std::vector<std::vector<std::string>> query(const std::string &tableName);

    bool implement(const std::string &sentence);
};