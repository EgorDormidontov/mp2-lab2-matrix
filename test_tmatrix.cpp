#include "utmatrix.h"

#include <gtest.h>


TEST(TMatrix, able_to_create_copy_of_matrix)
{
  TMatrix<int> m(4);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, not_able_to_creat_with_negative_numbers)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-1));
}


TEST(TMatrix, wont_do_outta_boundries)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}


TEST(TMatrix, able_to_create_matrix)
{
  ASSERT_NO_THROW(TMatrix<int> m(3));
}


TEST(TMatrix, getting_size_is_right)
{
	const int size = 10;
	TMatrix<int> m1(size);

	EXPECT_EQ(10, m1.GetSize());
}


TEST(TMatrix, no_negative_index)
{
	const int size = 10;
	TMatrix<int> m1(size);
	ASSERT_ANY_THROW(m1[0][-1] = 1);
		
}


TEST(TMatrix, can_add_and_get_element)
{
	const int size = 10;
	TMatrix<int> m1(size);
	m1[0][0] = 1;
	EXPECT_EQ(1, m1[0][0]);
}

TEST(TMatrix, no_too_large_index)
{
	const int size = 10;
	TMatrix<int> m1(size);
	ASSERT_ANY_THROW(m1[10][0]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m1(10);
	ASSERT_NO_THROW(m1=m1);
}

TEST(TMatrix, can_assign_matrices_with_equal_size)
{
	TMatrix<int> m1(10),m2(10);
	m1[5][0] = 3;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}
TEST(TMatrix, copy_of_matrix_is_good)
{
	const int size = 10;
	TMatrix<int> m1(size);
	m1[0][0] = 3;
	m1[0][1] = 4;
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1==m2,1);
}

TEST(TMatrix, operator_change_matrix_size)
{
	TMatrix<int> m1(10), m2(8);
	m2 = m1;
	EXPECT_EQ(10, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(10), m2(8);
	ASSERT_NO_THROW(m2 = m1);
}

TEST(TMatrix, compare_equal_matrices_works_right)
{
	TMatrix<int> m1(10), m2(10);
	m1[5][0] = 3;
	m2[5][0] = 3;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, different_size_are_not_equal)
{
	TMatrix<int> m1(10), m2(8);
	EXPECT_NE(m1, m2);
}


