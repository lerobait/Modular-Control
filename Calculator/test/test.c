#include <check.h>
#include "../src/lib.h"

START_TEST(test_calculate) {
    char expression[] = "3+5*2-67*3";
    Calculator calc = {expression};
    int expected = -188;
    int result = calculate(&calc);
    ck_assert_int_eq(expected, result);
}
END_TEST

int main(void) {
    Suite *s = suite_create("Calculator");
    TCase *tc_core = tcase_create("Modular Control");

    tcase_add_test(tc_core, test_calculate);
    suite_add_tcase(s, tc_core);

    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
