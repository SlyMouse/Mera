#include "Headers/BitArray.h"
#include "gtest/gtest.h"

TEST(BitArrayTest, InitTest)
{
    BitArray a(0x00ff00ff);

    ::testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "00000000 11111111 00000000 11111111";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(BitArrayTest, LeftShiftTest)
{
    BitArray a(0x00ff00ff);
    a = a << 4;

    ::testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "00001111 11110000 00001111 11110000";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(BitArrayTest, CopyingTest)
{
    BitArray a(0x00ff00ff);
    BitArray b(a);

    ::testing::internal::CaptureStdout();
    std::cout << a;
    std::string output_a = ::testing::internal::GetCapturedStdout();

    ::testing::internal::CaptureStdout();
    std::cout << b;
    std::string output_b = ::testing::internal::GetCapturedStdout();

    ASSERT_STREQ(output_a.c_str(), output_b.c_str());
}

TEST(BitArrayTest, SetLengthTest)
{
    BitArray a(0x00ff00ff);
    a.SetLength(65);

    ::testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "0 00000000 00000000 00000000 00000000 00000000 11111111 00000000 11111111";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(BitArrayTest, AndTest)
{
    BitArray a(0x00ff00ff);
    BitArray b(a);
    a = a << 4;

    ::testing::internal::CaptureStdout();
    std::cout << (a & b);
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "00000000 11110000 00000000 11110000";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(BitArrayTest, OrTest)
{
    BitArray a(0x00ff00ff);
    a.SetLength(65);
    a = (a << 41) | a;

    ::testing::internal::CaptureStdout();
    std::cout << a;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "1 11111110 00000001 11111110 00000000 00000000 11111111 00000000 11111111";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(BitArrayTest, NotTest)
{
    BitArray a(0x00ff00ff);
    a.SetLength(65);
    a = (a << 41) | a;

    ::testing::internal::CaptureStdout();
    std::cout << ~a;
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "0 00000001 11111110 00000001 11111111 11111111 00000000 11111111 00000000";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}