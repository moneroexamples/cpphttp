#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <stdlib.h>


namespace
{

bool result {true};

TEST(ACCOUNT, DefaultConstruction)
{
    EXPECT_TRUE(result);
}

}

int main(int argc, char **argv)
{
  
  ::testing::InitGoogleTest(&argc, argv);

#if defined(RANDOM_FAIL)  
      std::cout << "Random fail enabled! " << std::endl;

      srand(time(NULL));
      
      result = rand() % 2 ? true: false;
#endif

  return RUN_ALL_TESTS();
}

