#include <iostream>
#include <string>
#include <mysql/mysql.h>

#include "Connection.h"

int main()
{
    try{

        Connection objConn;
        bool result = objConn.execute();
        if (!result) std::cout << "ERROR!!!!" <<std::endl;

    } catch (char *e){
        std::cerr << "[EXECPTION] " << e << std::endl;
    }

    return 0;
}