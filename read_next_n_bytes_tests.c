#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_next_n_bytes(int fd, int n);

static int fd = -1;

static void open_file(void)
{
    fd = open("read_next_n_bytes.txt", O_RDONLY);
    assert(fd != -1);
    cr_redirect_stdout();
}

static void close_file(void)
{
    if (fd != -1)
        close(fd);
}

Test(read_next_n_bytes, should_handle_wrong_fd, .init = open_file, .fini = close_file)
{
    cr_assert_null(read_next_n_bytes(-1, 0));
}

Test(read_next_n_bytes, should_handle_empty_read, .init = open_file, .fini = close_file)
{
    cr_assert_null(read_next_n_bytes(fd, 0));
}

Test(read_next_n_bytes, should_handle_non_empty_read, .init = open_file, .fini = close_file)
{
    char *str;
    
    str = read_next_n_bytes(fd, 4);
    cr_assert_not_null(str);
    cr_assert_str_eq("read", str);
    free(str);
}

Test(read_next_n_bytes, should_handle_twice_read, .init = open_file, .fini = close_file)
{
    char *str;
    
    str = read_next_n_bytes(fd, 4);
    cr_assert_not_null(str);
    cr_assert_str_eq("read", str);
    free(str);
    
    str = read_next_n_bytes(fd, 5);
    cr_assert_not_null(str);
    cr_assert_str_eq("_next", str);
    free(str);
}

Test(read_next_n_bytes, should_handle_read_all, .init = open_file, .fini = close_file)
{
    char *str;
    
    str = read_next_n_bytes(fd, 17);
    cr_assert_not_null(str);
    cr_assert_str_eq("read_next_n_bytes", str);
    free(str);
    
    str = read_next_n_bytes(fd, 17);
    cr_assert_null(str);
}
