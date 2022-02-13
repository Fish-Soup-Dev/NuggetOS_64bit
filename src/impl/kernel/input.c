#include "input.h"

uint8 get_input_keycode()
{
    uint8 code = 0;
    while (!code)
    {
        sleep(10000);
        code = inb(KEYBOARD_PORT);
    }
    
    return code;
}

boolean input_str(uint8* str, uint32 max_len)
{
    boolean capslock = false;
    boolean shift = false;
    boolean alt = false;
    boolean ctrl = false;
    boolean numlock = false;
    boolean scrolllock = false;
    uint32 repeats = 0;

    uint8 last_keycode = 0;
    uint32 pos = 0;
    while (true)
    {
        uint8 c = get_input_keycode();

        if (c == last_keycode)
        {
            ++repeats;
            if (repeats < 40 || repeats % 8 != 0)
            {
                continue;
            }
        }
        else
        {
            repeats = 0;
        }
        last_keycode = c;
        if (c == KEY_LEFT_SHIFT_RELEASE)
        {
            shift = false;
        }
        if (c == KEY_RIGHT_SHIFT_RELEASE)
        {
            shift = false;
        }

        if (c > 127)
        {
            continue;
        }
        if (c == KEY_ENTER)
        {
            str[pos] = '\0';
            return true;
        }
        else if (c == KEY_ESC)
        {
            str[pos] = '\0';
            return true;
        }
        else if (c == KEY_BACKSPACE)
        {
            if (pos)
            {
                pos--;
                clr_col();
            }
        }
        else if (c == KEY_LEFT_SHIFT_PRESS)
        {
            shift = true;
        }
        else if (c == KEY_CAPS_LOCK_PRESS)
        {
            capslock = !capslock;
        }
        else if ((c >=2 && c <= 13) || (c >= 16 && c <= 27) || (c >= 30 && c <= 41) || (c >= 43 && c <= 53) || c == 57)
        {
            if (pos + 1 < max_len)
            {
                uint8 ch;
                if (capslock || shift)
                {
                    ch = get_ascii_char(c);
                }
                else
                {
                    ch = get_ascii_char_lower(c);
                }
                str[pos] = ch;
                print_c(ch);

                pos++;
            }
        }
    }
}