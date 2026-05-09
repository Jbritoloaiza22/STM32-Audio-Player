#include "unity.h"
#include "math.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_add_positive_numbers(void)
{
    TEST_ASSERT_EQUAL(5, add(2, 3));
}

void test_add_negative_numbers(void)
{
    TEST_ASSERT_EQUAL(-1, add(2, -3));
}