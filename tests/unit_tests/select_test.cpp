#include "gtest/gtest.h"
#include "../../src/Connection.h"
#include <vector>


class SelectTest : public testing::Test
{
public:

     void SetUp() override
    {
    }

     void TearDown() override
    {
    }
};



TEST_F(SelectTest, testElementZeroIsOne)
{
    try{
        Connection objConn;

        bool result = objConn.execute();
        if (!result) std::cout << "ERROR!!!!" <<std::endl;

    } catch (char *e){
        std::cerr << "[EXECPTION] " << e << std::endl;
    }
}
