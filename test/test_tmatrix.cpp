#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 1; m[0][1] = 2; m[1][0] = 3; m[1][1] = 4;
	TDynamicMatrix<int> a(m);
	EXPECT_EQ(a, m);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 1; m[0][1] = 2; m[1][0] = 3; m[1][1] = 4;
	TDynamicMatrix<int> a(m);
	m[0][0] = 0; m[0][1] = 0; m[1][0] = 0; m[1][1] = 0;
	EXPECT_EQ(1, a[0][0]);
	EXPECT_EQ(2, a[0][1]);
	EXPECT_EQ(3, a[1][0]);
	EXPECT_EQ(4, a[1][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(2);
	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(m);
	m[0][0] = 4;
	a[0][0] = m[0][0];

	EXPECT_EQ(a, m);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(-1, 0) = 0);
	ASSERT_ANY_THROW(m.at(0, -1) = 0);
	ASSERT_ANY_THROW(m.at(-1, -1) = 0);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(3, 1) = 0);
	ASSERT_ANY_THROW(m.at(1, 3) = 0);
	ASSERT_ANY_THROW(m.at(3, 3) = 0);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 0; m[0][1] = 1;
	m[1][0] = 2; m[1][1] = 3;
	ASSERT_NO_THROW(m = m);
	EXPECT_EQ(0, m[0][0]);
	EXPECT_EQ(1, m[0][1]);
	EXPECT_EQ(2, m[1][0]);
	EXPECT_EQ(3, m[1][1]);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(2);
	m[0][0] = 0; m[0][1] = 1;
	m[1][0] = 2; m[1][1] = 3;
	a = m;
	EXPECT_EQ(a, m);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(3);
	m = a;
	EXPECT_EQ(m.size(), 9);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> res(3);
	m[0][0] = 0; m[0][1] = 0;
	m[1][0] = 0; m[1][1] = 0;

	a[0][0] = 0;  a[0][1] = 1;  a[0][2] = 2;
	a[1][0] = 3;  a[1][1] = 4; a[1][2] = 5;
	a[2][0] = 6; a[2][1] = 7; a[2][2] = 8;

	res[0][0] = 0;  res[0][1] = 1;  res[0][2] = 2;
	res[1][0] = 3;  res[1][1] = 4; res[1][2] = 5;
	res[2][0] = 6; res[2][1] = 7; res[2][2] = 8;

	m = a;
	EXPECT_EQ(m, res);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(2);
	a[0][0] = 0;  a[0][1] = 1;
	a[1][0] = 2;  a[1][1] = 3;

	m[0][0] = 0;  m[0][1] = 1;
	m[1][0] = 2;  m[1][1] = 3;
	ASSERT_TRUE(m == a);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(2);
	m[0][0] = 0;  m[0][1] = 1;
	m[1][0] = 2;  m[1][1] = 3;
	ASSERT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(3);
	m[0][0] = 0; m[0][1] = 1;
	m[1][0] = 2; m[1][1] = 3;

	a[0][0] = 0; a[0][1] = 1; a[0][2] = 2;
	a[1][0] = 3; a[1][1] = 4; a[1][2] = 5;
	a[2][0] = 6; a[2][1] = 7; a[2][2] = 8;

	ASSERT_TRUE(m != a);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> res(2);
	m[0][0] = 0;  m[0][1] = 1;
	m[1][0] = 2;  m[1][1] = 3;

	a[0][0] = 4; a[0][1] = 5;
	a[1][0] = 6; a[1][1] = 7;

	res[0][0] = 4;  res[0][1] = 6;
	res[1][0] = 8;  res[1][1] = 10;
	EXPECT_EQ(m + a, res);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> a(2);
	m[0][0] = 0;  m[0][1] = 1;  m[0][2] = 2;
	m[1][0] = 3;  m[1][1] = 4; m[1][2] = 5;
	m[2][0] = 6; m[2][1] = 7; m[2][2] = 8;

	a[0][0] = 9; a[0][1] = 10;
	a[1][0] = 11; a[1][1] = 12;

	ASSERT_ANY_THROW(m + a);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{

	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> res(2);
	m[0][0] = 0;  m[0][1] = 1;
	m[1][0] = 2;  m[1][1] = 3;

	a[0][0] = 4; a[0][1] = 5;
	a[1][0] = 6; a[1][1] = 7;

	res[0][0] = 4;   res[0][1] = 4;
	res[1][0] = 4;  res[1][1] = 4;
	ASSERT_TRUE(a - m == res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> a(2);
	m[0][0] = 0;  m[0][1] = 1;  m[0][2] = 2;
	m[1][0] = 3;  m[1][1] = 4; m[1][2] = 5;
	m[2][0] = 6; m[2][1] = 7; m[2][2] = 8;

	a[0][0] = 9; a[0][1] = 10;
	a[1][0] = 11; a[1][1] = 12;

	ASSERT_ANY_THROW(m - a);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
	TDynamicMatrix<int> m(2);
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> res(2);

	m[0][0] = 0; m[0][1] = 1;
	m[1][0] = 2; m[1][1] = 3;

	a[0][0] = 4; a[0][1] = 5;
	a[1][0] = 6; a[1][1] = 7;

	res[0][0] = 6; res[0][1] = 7;
	res[1][0] = 26; res[1][1] = 31;

	ASSERT_TRUE(m * a == res);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> a(2);
	m[0][0] = 0;  m[0][1] = 1;  m[0][2] = 2;
	m[1][0] = 3;  m[1][1] = 4; m[1][2] = 5;
	m[2][0] = 6; m[2][1] = 7; m[2][2] = 8;

	a[0][0] = 9; a[0][1] = 10;
	a[1][0] = 11; a[1][1] = 12;

	ASSERT_ANY_THROW(m * a);
}

