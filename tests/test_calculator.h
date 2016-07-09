//
// Created by James Stumme on 7/9/16.
//
#ifndef TEST_CALCULATOR_H
#define TEST_CALCULATOR_H

#include <check.h>
#include "asserts.h"
#include <falcon_calc.h>

START_TEST (test_strtoroman__converts_string_I_to_romain_numeral_1)
    {
        char str[] = "I";
        roman *expected = malloc(sizeof(roman));
        roman *actual;
        bzero(expected, sizeof(roman));

        expected->I = 1;
        actual = strtoroman(str);

        ck_assert_not_null(actual);
        ck_assert_roman_eq(expected, actual);

        free(expected);
        free(actual);
    }
END_TEST

Suite *test_calculator_suite(void)
{
    Suite *suite = suite_create("FalconCalc");
    TCase *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_strtoroman__converts_string_I_to_romain_numeral_1);
    suite_add_tcase(suite, tc_core);

    return suite;
}

#endif //TEST_CALCULATOR_H