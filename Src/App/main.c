#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/Dio.h"
#include "../Mcal/Inc/Port.h"

int main(void)
{
    IntCrtl_Init();
    Port_Init();
    Dio_WriteChannel(B6, HIGH);
    while (1)
    {
        /* code */
    }
    return 0;
}

