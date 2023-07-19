#include "time_slice.h"

uint8_t Tx_state = 0x00;

// 时间片调度

void task1(void)
{
    /* to do */
}

void task2(void)
{
    /* to do */
}

void task3(void)
{
    /* to do */
}

void task4(void)
{
    /* to do */
}

_Task_Struct Task_Struct[] =
    {
        {0, 10, 10, task1},
        {0, 20, 20, task2},
        {0, 100, 100, task3},
        {0, 150, 150, task4},

};

u8 task_num = sizeof(Task_Struct) / sizeof(_Task_Struct);

void Tasks_Process(void)
{
    u8 i = 0;
    for (; i < task_num; i++)
    {
        if (Task_Struct[i].isRun)
        {
            Task_Struct[i].tasks();
            Task_Struct[i].isRun = 0;
        }
    }
}

void TIM2_IRQHandler(void)
{
    u8 i = 0;
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        for (i = 0; i < task_num; i++)
        {
            if (Task_Struct[i].Time_Number)
            {
                Task_Struct[i].Time_Number--;
            }
            if (Task_Struct[i].Time_Number == 0)
            {
                Task_Struct[i].isRun = 1;
                Task_Struct[i].Time_Number = Task_Struct[i].Time_Init;
            }
        }
    }
}
