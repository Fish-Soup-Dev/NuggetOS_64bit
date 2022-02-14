#include "apps.h"

void math()
{
    pprint_str(35, 24, "calc mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);

    sleep(500000);

    int max_len = 50;
    char str[max_len];

    int x = 0, y = 0, ans = 0;

    print_s("\ncalc>");

    while (1)
    {
        if (input_str(str, max_len, true))
        {
            if (ic_strcmp(str, "clear") == 0)
            {
                clr_scr();
                print_s("calc>");
                sleep(500000);
            }
            else if (ic_strcmp(str, "add") == 0)
            {
                sleep(500000);
                print_s("\nenter first number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        x = ans;
                    }
                    else
                    {
                        x = atoi(str);
                    }
                }
                sleep(500000);
                print_s("\nenter second number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        y = ans;
                    }
                    else
                    {
                        y = atoi(str);
                    }
                }

                ans = x + y;

                print_nl();
                print_nl();
                print_i(x);
                print_s(" + ");
                print_i(y);
                print_s(" = ");
                print_i(ans);
                print_nl();
                print_s("calc>");
            }
            else if (ic_strcmp(str, "sub") == 0)
            {
                sleep(500000);
                print_s("\nenter first number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        x = ans;
                    }
                    else
                    {
                        x = atoi(str);
                    }
                }
                sleep(500000);
                print_s("\nenter second number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        y = ans;
                    }
                    else
                    {
                        y = atoi(str);
                    }
                }

                ans = x - y;

                print_nl();
                print_nl();
                print_i(x);
                print_s(" - ");
                print_i(y);
                print_s(" = ");
                print_i(ans);
                print_nl();
                print_s("calc>");
            }
            else if (ic_strcmp(str, "mult") == 0)
            {
                sleep(500000);
                print_s("\nenter first number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        x = ans;
                    }
                    else
                    {
                        x = atoi(str);
                    }
                }
                sleep(500000);
                print_s("\nenter second number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        y = ans;
                    }
                    else
                    {
                        y = atoi(str);
                    }
                }

                ans = x * y;

                print_nl();
                print_nl();
                print_i(x);
                print_s(" * ");
                print_i(y);
                print_s(" = ");
                print_i(ans);
                print_nl();
                print_s("calc>");
            }
            else if (ic_strcmp(str, "div") == 0)
            {
                sleep(500000);
                print_s("\nenter first number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        x = ans;
                    }
                    else
                    {
                        x = atoi(str);
                    }
                }
                sleep(500000);
                print_s("\nenter second number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        y = ans;
                    }
                    else
                    {
                        y = atoi(str);
                    }
                }

                ans = x / y;

                print_nl();
                print_nl();
                print_i(x);
                print_s(" / ");
                print_i(y);
                print_s(" = ");
                print_i(ans);
                print_nl();
                print_s("calc>");
            }
            else if (ic_strcmp(str, "pow") == 0)
            {
                sleep(500000);
                print_s("\nenter first number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        x = ans;
                    }
                    else
                    {
                        x = atoi(str);
                    }
                }
                sleep(500000);
                print_s("\nenter second number: ");
                if (input_str(str, max_len, true))
                {
                    if (ic_strcmp(str, "ans") == 0)
                    {
                        y = ans;
                    }
                    else
                    {
                        y = atoi(str);
                    }
                }

                ans = powi(x, y);

                print_nl();
                print_nl();
                print_i(x);
                print_s("^");
                print_i(y);
                print_s(" = ");
                print_i(ans);
                print_nl();
                print_s("calc>");
            }
            else if (ic_strcmp(str, "help") == 0)
            {
                set_print_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
                print_s("\nadd: add 2 numbers");
                print_s("\nsub: subtract 2 numbers");
                print_s("\nmult: multiply 2 numbers");
                print_s("\ndiv: divide 2 numbers");
                print_s("\npow: rases the first number to the power of the second");
                print_s("\nexit: exits calculator");
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\ncalc>");
            }
            else if (ic_strcmp(str, "exit") == 0)
            {
                break;
            }
            else
            {
                set_print_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                print_s("\nerror not valid command: ");
                print_s(str);
                set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
                print_s("\ncalc>");
            }
            
        }

        pprint_str(35, 24, "calc mode", PRINT_COLOR_LIGHT_GREEN, PRINT_COLOR_BLACK);
        sleep(500000);
    }
    
}