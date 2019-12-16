#include <criterion/criterion.h>

#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <stdlib.h>

char *get_sentence_chunk_by_chunk(void);

Test(get_sentence_chunk_by_chunk, should_work_1)
{
    char *str;
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("Hello", str);
    free(str);
}

Test(get_sentence_chunk_by_chunk, should_work_2)
{
    char *str;
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("Hello", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq(" my n", str);
    free(str);
}

Test(get_sentence_chunk_by_chunk, should_work_3)
{
    char *str;
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("Hello", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq(" my n", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("ame i", str);
    free(str);
}

Test(get_sentence_chunk_by_chunk, should_work_all)
{
    char *str;
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("Hello", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq(" my n", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("ame i", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("s Chu", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("cky. ", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("Do yo", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("u wan", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("t to ", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("be my", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq(" frie", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_not_null(str);
    cr_assert_str_eq("nd?", str);
    free(str);
    
    str = get_sentence_chunk_by_chunk();
    cr_assert_null(str);
}