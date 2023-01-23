#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/Dio.h"
#include "../Mcal/Inc/Port.h"
#include "../Mcal/Inc/Clk.h"
#include "../Mcal/Inc/SysTick.h"


uint8 on_seconds = 1;
uint8 off_seconds = 1;
uint8 unconfirmed_value = 1;

uint8 current_led_status = 0;

const Dio_ChannelType led = B4;
const Dio_ChannelType increment_pb = B5;
const Dio_ChannelType confirmation_pb = B6;

void handle_SysTickInterrupt(void)
{
    if (current_led_status == 0)
    {
        Dio_WriteChannel(led, HIGH);
        current_led_status = 1;
        SysTick_InterruptCountdown(off_seconds*1000);
    }
    else
    {
        Dio_WriteChannel(led, LOW);
        current_led_status = 0;
        SysTick_InterruptCountdown(on_seconds*1000);
    }
}


int main(void)
{
    Clk_Init();
    IntCrtl_Init();
    Port_Init();

    SysTick_RegisterInterruptCallback(handle_SysTickInterrupt);

    SysTick_InterruptCountdown(off_seconds*1000);
    SysTick_Start();

    while (1)
    {
        if (Dio_ReadChannel(increment_pb) == HIGH)
        {
            unconfirmed_value+=1;
            while(Dio_ReadChannel(increment_pb) == HIGH);
        }
        else if (Dio_ReadChannel(confirmation_pb) == HIGH)
        {
            if (current_led_status == 0)
            {
                off_seconds = unconfirmed_value;
            }
            else
            {
                on_seconds = unconfirmed_value;
            }

            unconfirmed_value = 1;
            while(Dio_ReadChannel(confirmation_pb) == HIGH);
        }
    }
    return 0;
}



