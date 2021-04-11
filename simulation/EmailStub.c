#include "../SoCalledEmailLibrary.h"
#include <stdio.h>


void Email(EmailContent_t Content)
{
    printf("Toaddr : %s\n",Content.toaddr);
    printf("Fromaddr : %s\n",Content.fromaddr);
    printf("%s\n",Content.body);
    printf("Thank you very much \n");
}
