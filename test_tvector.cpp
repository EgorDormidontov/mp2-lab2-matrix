#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, not_going_out_of_boundries)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, start_index_is_not_negative)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copies)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, able_to_create)
{
  ASSERT_NO_THROW(TVector<int> v(4));
}

TEST(TVector, no_negative_number)
{
  ASSERT_ANY_THROW(TVector<int> v(-1));
}

TEST(TVector, copied_vector_is_like_first_one)
{
	TVector<int> t1(5);
	t1[1] = 3; t1[2] = 3;
	TVector<int> t2(t1);
	EXPECT_EQ(t1, t2);
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_uses_own_memory)
{
	TVector<int> t1(5);
	t1[1] = 3; t1[2] = 3;
	TVector<int> t2(t1);
	t1[0] = 2;
	EXPECT_NE(t1, t2);
}

TEST(TVector, getting_size_is_right)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}


TEST(TVector, getting_start_index_is_right)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, no_negative_index)
{
	TVector<int> t1(3);
  ASSERT_ANY_THROW(t1[-1]);
}

TEST(TVector, setting_getting_element_is_right)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, assign_to_itself_is_right)
{
	TVector<int> t1(3);
	ASSERT_NO_THROW(t1 = t1);
}

TEST(TVector, can_assign_vectors_with_equal_size)
{
	TVector<int> t1(3),t2(3);
	t1[0] = 2;
	t1[1] = 3;
	t2 = t1;
	EXPECT_EQ(t1, t2);
}

TEST(TVector, index_is_not_too_large)
{
	TVector<int> t1(3);
	ASSERT_ANY_THROW(t1[100000000]);
}

TEST(TVector, changes_vector_size_when_assighning)
{
	TVector<int> t1(3), t2(2);
	t1[0] = 2;
	t1[1] = 3;
	t2 = t1;
	EXPECT_EQ(3, t2.GetSize());
}

TEST(TVector, equal_vectors_return_true)
{
	TVector<int> t1(3), t2(3);
	t1[0] = 2;
	t1[1] = 3;
	t2[0] = 2;
	t2[1] = 3;
	EXPECT_EQ(t1, t2);
}

TEST(TVector, vector_with_itself_return_true)
{
	TVector<int> t1(3);
	t1[0] = 2;
	t1[1] = 3;
	EXPECT_EQ(t1, t1);
}
TEST(TVector, assigning_vectors_of_different_size_is_right)
{
	TVector<int> t1(3), t2(2);
	t1[0] = 2;
	t1[1] = 3;
	ASSERT_NO_THROW(t2 = t1);
}