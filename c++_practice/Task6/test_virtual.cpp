#include "Headers/Derived.h"
#include "gtest/gtest.h"

TEST(VirtualTest, DerivedCallsTest)
{
    Base *base = new Derived();
	
    ::testing::internal::CaptureStdout();
    base->Func1();
    base->Func2();
    base->Func3();
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "Derived::Func1\nBase::Func2\nDerived::Func3\n";
    
    ASSERT_STREQ(expected.c_str(), output.c_str());
}

TEST(VirtualTest, BaseCallsTest)
{
    Base *base = new Base();

    ::testing::internal::CaptureStdout();
    base->Func1();
    base->Func2();
    base->Func3();
    std::string output = ::testing::internal::GetCapturedStdout();
    std::string expected = "Base::Func1\nBase::Func2\nPure virtual function call\n";
    
    ASSERT_STREQ(expected.c_str(), output.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}