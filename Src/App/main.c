#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/Dio.h"
#include "../Mcal/Inc/Port.h"
#include "../Mcal/Inc/Clk.h"
#include "../Mcal/Inc/SysTick.h"


volatile uint8 on_seconds = 1;
volatile uint8 off_seconds = 1;
uint8 unconfirmed_value = 1;

volatile uint8 current_led_status = 0;
volatile uint8 second_countdown = 1;

const Dio_ChannelType led = F3;
const Dio_ChannelType increment_pb = F4;
const Dio_ChannelType confirmation_pb = F0;

void handle_SysTickInterrupt(void)
{
    second_countdown -= 1;
    if (second_countdown == 0)
    {
        if (current_led_status == 0)
        {
            Dio_WriteChannel(led, HIGH);
            current_led_status = 1;
            second_countdown = on_seconds;
        }
        else
        {
            Dio_WriteChannel(led, LOW);
            current_led_status = 0;
            second_countdown = off_seconds;
        }
    }
    SysTick_InterruptCountdown(1000);
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
        if (Dio_ReadChannel(increment_pb) == LOW)
        {
            unconfirmed_value+=1;
            while(Dio_ReadChannel(increment_pb) == LOW);
        }
        else if (Dio_ReadChannel(confirmation_pb) == LOW)
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
            while(Dio_ReadChannel(confirmation_pb) == LOW);
        }
    }
    return 0;
}



