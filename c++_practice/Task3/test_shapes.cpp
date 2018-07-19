#include "Headers/IShape.h"
#include "Headers/Ellipse.h"
#include "Headers/Rectangle.h"
#include "gtest/gtest.h"

TEST(ShapesTest, InitAndOutputTest)
{
    IShape ** shapes = new IShape*[5];
    shapes[0] = new Line(5);
    shapes[1] = new Rectangle(10, 12);
    shapes[2] = new Circle(8);
    shapes[3] = new Ellipse(4, 3);
    shapes[4] = new Circle(5);

    std::string output[5];

    for (int i = 0; i < 5; i++)
    {
        ::testing::internal::CaptureStdout();
        std::cout << shapes[i] << std::endl << "Perimeter: " << shapes[i]->Perimeter() << std::endl;
        std::cout << "Square: " << shapes[i]->Square();
        output[i] = ::testing::internal::GetCapturedStdout();
        delete shapes[i];
    }
    delete[] shapes;

    std::string expected = "object: line; len = 5\nPerimeter: 5\nSquare: 0";
    ASSERT_STREQ(expected.c_str(), output[0].c_str());
    expected = "object: rectangle; w = 10; h = 12\nPerimeter: 44\nSquare: 120";
    ASSERT_STREQ(expected.c_str(), output[1].c_str());
    expected = "object: circle; r = 8\nPerimeter: 50.2655\nSquare: 201.062";
    ASSERT_STREQ(expected.c_str(), output[2].c_str());
    expected = "object: ellipse; r1 = 4 r2 = 3\nPerimeter: 21.9911\nSquare: 37.6991";
    ASSERT_STREQ(expected.c_str(), output[3].c_str());
    expected = "object: circle; r = 5\nPerimeter: 31.4159\nSquare: 78.5398";
    ASSERT_STREQ(expected.c_str(), output[4].c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}