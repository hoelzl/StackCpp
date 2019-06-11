#include "Stack.h"
#include "gmock/gmock.h"

using namespace ::testing;

class StackTest : public ::testing::Test {
public:
    Stack unit{};
    int a_random_number_{3};
    int another_random_number_{5};
};

TEST_F(StackTest, IsEmpty_ReturnsTrue_WhenStackIsNewlyConstructed) {
    ASSERT_TRUE(unit.IsEmpty());
}

TEST_F(StackTest, IsEmpty_ReturnsFalse_WhenPopWasCalled)
{
    unit.Push(a_random_number_);

    ASSERT_FALSE(unit.IsEmpty());
}

TEST_F(StackTest, Push_PushesItem) {
    unit.Push(a_random_number_);

    ASSERT_THAT(unit.Pop(), Eq(a_random_number_));
}

TEST_F(StackTest, Push_PushesOnTopOfPreviousElements) {
    unit.Push(a_random_number_);
    unit.Push(another_random_number_);

    ASSERT_THAT(unit.Pop(), Eq(another_random_number_));
    ASSERT_THAT(unit.Pop(), Eq(a_random_number_));
    ASSERT_THAT(unit.IsEmpty(), Eq(true));
}

TEST_F(StackTest, Pop_ThrowsOnEmptyStack) {
    ASSERT_THROW(unit.Pop(), std::out_of_range);
}
