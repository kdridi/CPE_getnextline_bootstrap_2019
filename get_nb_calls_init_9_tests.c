#include <criterion/criterion.h>

int get_nb_calls_init_9();

Test(get_nb_calls_init_9, should_return_9)
{
    cr_assert_eq(9, get_nb_calls_init_9());
}

Test(get_nb_calls_init_9, should_return_10)
{
    cr_assert_eq(9, get_nb_calls_init_9());
    cr_assert_eq(10, get_nb_calls_init_9());
}

Test(get_nb_calls_init_9, should_return_11)
{
    cr_assert_eq(9, get_nb_calls_init_9());
    cr_assert_eq(10, get_nb_calls_init_9());
    cr_assert_eq(11, get_nb_calls_init_9());
}