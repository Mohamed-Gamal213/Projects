#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "card.h"



ST_cardData_t card;
ST_cardData_t* cardptr = &card;



EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    EN_cardError_t name_ = 0;    uint8_t name[30] = { 0 };   

    printf("Please enter your name :\n ");

    gets(name);  

    if (20 < strlen(name) && 26 > strlen(name))
    {
        name_ = CARD_OK;
        strcpy(cardData->cardHolderName, name);
      
    }
    else
    {
      
        name_ = WRONG_NAME;
    }

  

    return name_;

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    EN_cardError_t Error = 0;        uint8_t exp[25] = {0};

    printf(" Enter expiration date in form MM/YY: ");
    gets(exp);
  
    if( (NULL == exp)||(strlen(exp) < 5)|| (strlen(exp) > 5)||(exp[2] != '/') )
    {
        Error = WRONG_EXP_DATE;
      
    }
    else 
    {
        strcpy(cardData->cardExpirationDate, exp);
    }
    
    return Error;

}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    EN_cardError_t pan_ = 0;    uint8_t pan[30] = { 0 };
   

    printf("Please enter your card's PAN : "); 
   
    gets(pan);  


    if (16 < strlen(pan) && 21 > strlen(pan))
    {
        pan_ = CARD_OK;
        strcpy(cardData->primaryAccountNumber, pan);
     
    }
    else
    {
        pan_ = WRONG_PAN;
    }

    return pan_;

}







