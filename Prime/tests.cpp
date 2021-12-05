#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "Prime.h"

using namespace testing;

class TestClass : public TestWithParam<int>
{
    public: 


        virtual void SetUp()
        {


        }

        virtual void TearDown()
        {


        }
};

TEST_F(TestClass,TC_isPrime)
{
    ASSERT_TRUE(IsPrime(13));

}