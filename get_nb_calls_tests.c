#include <criterion/criterion.h>

int get_nb_calls();

Test(get_nb_calls, should_return_1)
{
    cr_assert_eq(1, get_nb_calls());
}

Test(get_nb_calls, should_return_2)
{
    cr_assert_eq(1, get_nb_calls());
    cr_assert_eq(2, get_nb_calls());
}

Test(get_nb_calls, should_return_3)
{
    cr_assert_eq(1, get_nb_calls());
    cr_assert_eq(2, get_nb_calls());
    cr_assert_eq(3, get_nb_calls());
}

