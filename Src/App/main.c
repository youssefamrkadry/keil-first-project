#include "../Mcal/Inc/IntCtrl.h"
#include "../Mcal/Inc/Dio.h"

int main(void)
{
    IntCrtl_Init();
    Dio_WriteChannel(B6, HIGH);
    while (1)
    {
        /* code */
    }
    return 0;
}

