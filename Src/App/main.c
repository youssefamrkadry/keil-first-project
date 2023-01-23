#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/Dio.h"
#include "../Mcal/Inc/Port.h"
#include "../Mcal/Inc/Clk.h"

int main(void)
{
    Clk_Init();
    IntCrtl_Init();
    Port_Init();
    Dio_WriteChannel(B6, HIGH);
    while (1)
    {
        /* code */
    }
    return 0;
}

