#include "Headers/SymmetricMatrix.h"
#include "gtest/gtest.h"

TEST(SymmatrixTest, InitAndSymmetricTets)
{
    SymmetricMatrix a(3); // создается матрица 3х3
    a(2, 0) = 10;
    a(1, 1) = 5;

    ASSERT_TRUE(a(0, 2) == a(2, 0)); // проверка симметричности
}

TEST(SymmatrixTest, CopyingTest)
{
    SymmetricMatrix a(3);
    a(2, 0) = 10;
    a(1, 1) = 5;

    SymmetricMatrix b(a);
    b(1, 1)++;

    ASSERT_TRUE(b(1, 1) == 6);
    ASSERT_TRUE(a(1, 1) != b(1, 1));
}

TEST(SymmatrixTest, OutputTest)
{
    SymmetricMatrix a(3);
    a(2, 0) = 10;
    a(1, 1) = 5;

    SymmetricMatrix c(2);
    c = a;
    ::testing::internal::CaptureStdout();
    std::cout << c;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "  0  0 10\n  0  5  0\n 10  0  0\n";
    ASSERT_STREQ(expected.c_str(), output.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}