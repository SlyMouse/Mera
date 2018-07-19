#include <iostream>
#include "Headers/List.h"
#include "Headers/ForwardIterator.h"
#include "Headers/ReverseIterator.h"
#include "gtest/gtest.h"

TEST(ListTest, LengthTest)
{
    List<int> list;
    list.Add(1).Add(3).Add(5);
    list.Insert(2, 1).Insert(4, 3);

    ASSERT_EQ(list.Length(), 5);
}

TEST(ListTest, SearchTest)
{
    List<int> list;
    list.Add(1).Add(3).Add(5);
    list.Insert(2, 1).Insert(4, 3);

    ASSERT_EQ(list.Search(4), 3);
}

TEST(ListTest, RemoveTest)
{
    List<int> list;
    list.Add(1).Add(3).Add(5);
    list.Insert(2, 1).Insert(4, 3);
    list.Remove(0);

    ASSERT_EQ(list[0], 2);
}

TEST(IteratorTest, ForwardIteratorTest)
{
    List<int> list;
    list.Add(2).Add(3).Add(4).Add(5).Add(6);
    ForwardIterator<int> fwdIter(list);

    ::testing::internal::CaptureStdout();
    while (fwdIter.Next())
        std::cout << fwdIter.Key() << " ";
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "2 3 4 5 6 ";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(IteratorTest, ReverseIteratorTest)
{
    List<int> list;
    list.Add(2).Add(3).Add(4).Add(5).Add(6);
    ReverseIterator<int> revIter(list);

    ::testing::internal::CaptureStdout();
    while (revIter.Next())
        std::cout << revIter.Key() << " ";
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "6 5 4 3 2 ";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(IteratorTest, UndefExceptionTest)
{
    List<int> list;
    list.Add(2).Add(3).Add(4).Add(5).Add(6);
    ForwardIterator<int> fwdIter(list);

    ::testing::internal::CaptureStdout();
    while (fwdIter.Next());
    try
    {
        fwdIter.Next();
        std::cout << "Incorrect iterator behavior";
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message();
    }
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "Iterator position is out of bounds";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(IteratorTest, BoundsExceptionTest)
{
    List<int> list;
    list.Add(2).Add(3).Add(4).Add(5).Add(6);
    ForwardIterator<int> fwdIter(list);

    ::testing::internal::CaptureStdout();
    try
    {
        fwdIter.Key();
        std::cout << "Incorrect iterator behavior";
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message();
    }
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "Iterator is not initialized";

    ASSERT_STREQ(expected.c_str(), output.c_str());
}

int main(int argc, char **argv)
{
    /* List<int> list;
    list.Add(1).Add(3).Add(5);
    list.Insert(2, 1).Insert(4, 3);

    if (list.Length() != 5) std::cout<<"bad list\n";
    if (list.Search(4) != 3) std::cout << "bad list\n";

    list.Remove(0);
    if (list[0] != 2) std::cout << "bad list\n";

    ForwardIterator<int> fwdIter(list);
    ReverseIterator<int> revIter(list);

    list.Add(6);

    while (fwdIter.Next())
        std::cout << fwdIter.Key() << " ";
    std::cout << std::endl;

    while (revIter.Next())
        std::cout << revIter.Key() << " ";
    std::cout << std::endl;

    try
    {
        fwdIter.Next();
        std::cout << "Incorrect iterator behavior" << std::endl;
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message() << std::endl;
    }

    try
    {
        fwdIter.Reset();
        fwdIter.Key();
        std::cout << "Incorrect iterator behavior" << std::endl;
    }
    catch (IteratorException & e)
    {
        std::cout << e.Message() << std::endl;
    } */

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}