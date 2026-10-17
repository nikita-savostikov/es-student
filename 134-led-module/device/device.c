#include "device.h"

#include <stdio.h>
#include "pico/unique_id.h"
#include "hardware/regs/addressmap.h"
#include "hardware/regs/sysinfo.h"

void device_info(void)
{
    char board_id[PICO_UNIQUE_BOARD_ID_SIZE_BYTES * 2 + 1];
    pico_get_unique_board_id_string(board_id, sizeof(board_id));

    volatile uint32_t *chip_id = (uint32_t *)(0x40000000 + 0x00);
    uint32_t id = *chip_id;
    uint32_t manufacturer = (id & 0x00000FFFu) >> 0;
    uint32_t part = (id & 0x0FFFF000u) >> 12;
    uint32_t revision = (id & 0xF0000000u) >> 28;


    printf("project: %s\n", DEVICE_PROJECT);
    printf("repo: %s\n", DEVICE_REPO);
    printf("board: %s\n", DEVICE_BOARD);
    printf("serial: %s\n", board_id);
    printf("chip: manufacturer 0x%03x, part 0x%04x, revision %u\n", manufacturer, part, revision);
}