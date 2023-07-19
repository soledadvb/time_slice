#ifndef __TIME_SLICE_H__
#define __TIME_SLICE_H__

void task1(void);
void task2(void);
void task3(void);
void task4(void);

typedef struct
{
    u8 isRun;
    u16 Time_Number;
    u16 Time_Init;
    void (*tasks)(void);
} _Task_Struct;

#endif
