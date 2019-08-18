//
// Created by lw on 18.08.2019.
//

#include "Connection.h"

Connection::Connection() {

    HOSTNAME = "localhost";
    DATABASE = "cpp";
    USERNAME = "debian-sys-maint";
    PASSWORD = "0quFl0RCMAe4M7gn";
    SOCKET = "/var/run/mysqld/mysqld.sock";
}


void Connection::finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    std::cerr << mysql_error(CONN) << std::endl;
    mysql_close(con);
}

void Connection::fill_database(){
    if (mysql_query(CONN, "DROP TABLE IF EXISTS Cars")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(1,' Audi ',122121)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(2,' Mercedes ',57127)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(3,' Skoda ',9000)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(4,' Volvo ',29000)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(5,' Bentley ',350000)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(6,' Citroen ',21000)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(7,' Hummer ',41400)")) {
        finish_with_error(CONN);
    }

    if (mysql_query(CONN, "INSERT INTO Cars VALUES(8,' Volkswagen ',21600)")) {
        finish_with_error(CONN);
    }
}

void Connection::create_database(const std::string database_name){
    std::string str = "CREATE DATABASE "+database_name;
    const char *name = str.c_str();
    if (mysql_query(CONN, name))
    {
        std::cerr << mysql_error(CONN) << std::endl;
        return;
        //        return false;
    }
}
void Connection::show_tables(){
    if (mysql_query(CONN,"SHOW TABLES")){
        std::cerr << mysql_error(CONN) << std::endl;
        return;
        //        return false;
    }
    RES = mysql_use_result(CONN);
    std::cout << "*** MYSQL - SHOW TABLES *** = "<< DATABASE <<std::endl;
    while ((ROW = mysql_fetch_row(RES)) != NULL)
        std::cout << ROW[0] <<std::endl;
}

void Connection::select_arg1_from_arg2(const std::string arg1,const std::string arg2){
    /**   SELECT X FROM X   **/
    std::cout<<"SELECT x FROM x"<<std::endl;
    std::string str = "SELECT "+arg1+" FROM "+arg2;
    const char *select_command = str.c_str();
    if (mysql_query(CONN, select_command))
    {
        std::cerr << mysql_error(CONN) << std::endl;
    }

    MYSQL_RES *result = mysql_store_result(CONN);

    int num_fields = mysql_num_fields(result);

    while ((ROW = mysql_fetch_row(result)))
    {
        for (int i=0; i<num_fields; i++){
            std::cout<<ROW[i];
        }

        std::cout<<std::endl;
    }

}


bool Connection::execute(){

    try{

        CONN = mysql_init(NULL);

        if (!mysql_real_connect(CONN,HOSTNAME,USERNAME,PASSWORD,DATABASE,PORT,SOCKET,0)){
            std::cerr << mysql_error(CONN) << std::endl;
            return false;
        }

        show_tables();
        create_database("Cars");
        fill_database();
//        select_arg1_from_arg2("*","nabywca");
        select_arg1_from_arg2("*","Cars");

        mysql_free_result(RES);

        mysql_close(CONN);

        return true;


    } catch(char *e){
        std::cerr << "[EXECPTION] " << e << std::endl;
        return false;
    }

}