#include"lcd.h"




int main()
{
    lcd test_lcd;
    test_lcd.getLcdInfo();

    useconds_t sleep_time = 0.08 * 1000 * 1000; //0.3秒
    int mm = 40;

    test_lcd.freetype_init("22",0,25,0);


    for (int n = 0; n < 5; n++)
    {
        for (int t = 1; t < mm; t++)
        {
            // test_lcd.lcd_draw_line(0, t * (test_lcd.height / mm), 1, test_lcd.width, 0xFF);
            test_lcd.lcd_write_charactor(10, t * (test_lcd.height / mm), L"hansolo", 0xFF0099);

            usleep(sleep_time);
            test_lcd.clear_screen();
        }
    }


    return 0;
}
