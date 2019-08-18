#include <iostream>
#include <string>
#include <mysql/mysql.h>

class Connection{
        const char* HOSTNAME;
        const char* DATABASE;
        const char* USERNAME;
        const char* PASSWORD;
        const char* SOCKET;
        const int PORT = 3306;
        const int OPT = 0;

        MYSQL *CONN;
        MYSQL_RES *RES;
        MYSQL_ROW ROW;

        public:
        Connection();
        bool execute();

        void create_database(const std::string database_name);
        void fill_database();
        void finish_with_error(MYSQL *con);
        void show_tables();
        void select_arg1_from_arg2(const std::string arg1,const std::string arg2);
};
