#include"lcd.h"




int main()
{
    lcd test_lcd;
    test_lcd.getLcdInfo();

    useconds_t sleep_time = 0.1 * 1000 * 1000; //0.3秒
    int mm = 100;
    for (int n = 0; n < 10; n++)
    {
        for (int t = 0; t < mm; t++)
        {
            test_lcd.lcd_draw_line(0, t * (test_lcd.height / mm), 1, test_lcd.width, 0xFF);

            usleep(sleep_time);
            test_lcd.clear_screen();
        }
    }


    return 0;
}
