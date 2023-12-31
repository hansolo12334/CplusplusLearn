#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/mman.h>
#include<linux/fb.h>
#include<time.h>

#include <errno.h>
#include <wchar.h>

#include <math.h> //数学库函数头文件
#include <stdint.h>


#include <sys/mman.h>
#include <sched.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#include "font.h"

#define FB_DEV "/dev/fb0"  //oled 设备节点

#define OLED_I2C_ADDR 0x3c

// Control byte
#define OLED_CTRL_BYTE_CMD_SINGLE 0x80
#define OLED_CTRL_BYTE_CMD_STREAM 0x00
#define OLED_CTRL_BYTE_DATA_STREAM 0x40
// Fundamental commands (page 28)
#define OLED_CMD_SET_CONTRAST 0x81
#define OLED_CMD_DISPLAY_RAM 0xA4
#define OLED_CMD_DISPLAY_ALLON 0xA5
#define OLED_CMD_DISPLAY_NORMAL 0xA6
#define OLED_CMD_DISPLAY_INVERTED 0xA7
#define OLED_CMD_DISPLAY_OFF 0xAE
#define OLED_CMD_DISPLAY_ON 0xAF
// Addressing Command Table (page 30)
#define OLED_CMD_SET_MEMORY_ADDR_MODE 0x20
#define OLED_CMD_SET_COLUMN_RANGE 0x21
#define OLED_CMD_SET_PAGE_RANGE 0x22
// Hardware Config (page 31)
#define OLED_CMD_SET_DISPLAY_START_LINE 0x40
#define OLED_CMD_SET_SEGMENT_REMAP 0xA1
#define OLED_CMD_SET_MUX_RATIO 0xA8
#define OLED_CMD_SET_COM_SCAN_MODE 0xC8
#define OLED_CMD_SET_DISPLAY_OFFSET 0xD3
#define OLED_CMD_SET_COM_PIN_MAP 0xDA
#define OLED_CMD_NOP 0xE3
// Timing and Driving Scheme (page 32)
#define OLED_CMD_SET_DISPLAY_CLK_DIV 0xD5
#define OLED_CMD_SET_PRECHARGE 0xD9
#define OLED_CMD_SET_VCOMH_DESELCT 0xDB
// Charge Pump (page 62)
#define OLED_CMD_SET_CHARGE_PUMP 0x8D
// SH1106 Display
#define OLED_SET_PAGE_ADDRESS 0xB0
static const unsigned char display_config[] = {
		OLED_CTRL_BYTE_CMD_STREAM,
		OLED_CMD_DISPLAY_OFF,

		OLED_SET_PAGE_ADDRESS,
		0x02, /*set lower column address*/
		0x10, /*set higher column address*/

		OLED_CMD_SET_MUX_RATIO, 0x3F,
		// Set the display offset to 0
		OLED_CMD_SET_DISPLAY_OFFSET, 0x00,
		// Display start line to 0
		OLED_CMD_SET_DISPLAY_START_LINE,
		// Mirror the x-axis. In case you set it up such that the pins are north.
		// 0xA0 - in case pins are south - default
		OLED_CMD_SET_SEGMENT_REMAP,
		// Mirror the y-axis. In case you set it up such that the pins are north.
		// 0xC0 - in case pins are south - default
		OLED_CMD_SET_COM_SCAN_MODE,
		// Default - alternate COM pin map
		OLED_CMD_SET_COM_PIN_MAP, 0x12,
		// set contrast
		OLED_CMD_SET_CONTRAST, 0x7F,
		// Set display to enable rendering from GDDRAM (Graphic Display Data RAM)
		OLED_CMD_DISPLAY_RAM,
		// Normal mode!
		OLED_CMD_DISPLAY_NORMAL,
		// Default oscillator clock
		OLED_CMD_SET_DISPLAY_CLK_DIV, 0x80,
		// Enable the charge pump
		OLED_CMD_SET_CHARGE_PUMP, 0x14,
		// Set precharge cycles to high cap type
		OLED_CMD_SET_PRECHARGE, 0x22,
		// Set the V_COMH deselect volatage to max
		OLED_CMD_SET_VCOMH_DESELCT, 0x30,
		// Horizonatal addressing mode - same as the KS108 GLCD
		OLED_CMD_SET_MEMORY_ADDR_MODE, 0x00,
		// Turn the Display ON
		OLED_CMD_DISPLAY_ON
    };

struct sized_array
{
	int size;
	const uint8_t *array;
};
struct display_info
{
	int address;
	int file;
	struct font_info font;
	uint8_t buffer[8][128];
};

int fd;


int oled_init(struct display_info *disp)
{
	struct sched_param sch;
	int status = 0;
	struct sized_array payload;

	payload.size = sizeof(display_config);
	payload.array = display_config;


	memset(disp->buffer, 0, sizeof(disp->buffer));

	return 0;
}
int oled_open(struct display_info *disp)
{

  disp->file = open(FB_DEV, O_RDWR);
  if (disp->file < 0)
    return -1;

	return 0;
}


void oled_putpixel(struct display_info *disp, uint8_t x, uint8_t y, uint8_t on)
{
	uint8_t pageId = y / 8;
	uint8_t bitOffset = y % 8;
	if (x < 128 - 2)
	{
		if (on == 1)
			disp->buffer[pageId][x] |= (1 << bitOffset);
		else
			disp->buffer[pageId][x] &= ~(1 << bitOffset);
	}
}

void oled_putstrto(struct display_info *disp, uint8_t x, uint8_t y, char *str)
{
	uint8_t a;
	int slen = strlen(str);
	uint8_t fwidth = disp->font.width;
	uint8_t fheight = disp->font.height;
	uint8_t foffset = disp->font.offset;
	uint8_t fspacing = disp->font.spacing;
	int i = 0;
	int j = 0;
	int k = 0;

	for (k = 0; k < slen; k++)
	{
		a = (uint8_t)str[k];
		for (i = 0; i < fwidth; i++)
		{
			for (j = 0; j < fheight; j++)
			{
				if (((disp->font.data[(a - foffset) * fwidth + i] >> j) & 0x01))
					oled_putpixel(disp, x + i, y + j, 1);
				else
					oled_putpixel(disp, x + i, y + j, 0);
			}
		}
		x += fwidth + fspacing;
	}
}

int oled_send(struct display_info *disp, struct sized_array *payload)
{
	if (write(disp->file, payload->array, payload->size) != payload->size)
		return -1;

	return 0;
}

// send buffer to oled (show)
int oled_send_buffer(struct display_info *disp)
{
	struct sized_array payload;
	uint8_t packet[129];
	int index;

	for (index = 0; index < 8; index++)
	{
		packet[0] = OLED_CTRL_BYTE_DATA_STREAM;
		memcpy(packet + 1, disp->buffer[index], 128);
		payload.size = 129;
		payload.array = packet;
		oled_send(disp, &payload);
	}
	return 0;
}


void oled_clear(struct display_info *disp)
{
	memset(disp->buffer, 0, sizeof(disp->buffer));
	oled_send_buffer(disp);
}


int oled_show(struct display_info *disp)
{
  int i;
  char buf[100];

  // disp->font = font1;
  // oled_putstrto(disp, 0, 1, "Welcome to linux ");

  disp->font = font2;
  oled_putstrto(disp, 1, 20, "haolo");

  

  oled_send_buffer(disp);

  return 0;
}

int main()
{
  int e;
  struct display_info disp;
  e = oled_open(&disp);

  oled_show(&disp);

  oled_clear(&disp);

  exit(0);
}