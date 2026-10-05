#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "terminal.h"

ST_terminalData_t terminal;
ST_terminalData_t* terminalptr = &terminal;



EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t Error = 0;

	uint8_t transDate[20] = { 0 };

	printf("\n Enter the transaction date in form DD/MM/YYYY: ");
	gets(transDate);

	if ((NULL == transDate) || (strlen(transDate) < 10) ||(strlen(transDate) > 10) ||
		(transDate[2] != '/' || transDate[5] != '/'))
	{
		Error = WRONG_DATE;
	}
	else
	{
		Error = TERMINAL_OK;
		strcpy(termData->transactionDate, transDate);
	}

	return Error;
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	EN_terminalError_t expired = 0;
	uint8_t mm_t[3] = { 0 };	     uint8_t yy_t[3] = { 0 };
	uint8_t mm_exp[3] = { 0 };	     uint8_t yy_exp[3] = { 0 };
	uint8_t mm_t_n = 0;      	     uint8_t yy_t_n = 0;
	uint8_t mm_exp_n = 0;   	     uint8_t yy_exp_n = 0;

	mm_t[0] = termData->transactionDate[3];  	 mm_t[1] = termData->transactionDate[4];

	mm_t[2] = '\0';                            	 mm_t_n = atoi(mm_t);

	yy_t[0] = termData->transactionDate[8];  	 yy_t[1] = termData->transactionDate[9];

	yy_t[2] = '\0';                       	     yy_t_n = atoi(yy_t);

	mm_exp[0] = cardData->cardExpirationDate[0]; mm_exp[1] = cardData->cardExpirationDate[1];

	mm_exp[2] = '\0';	                         mm_exp_n = atoi(mm_exp);

	yy_exp[0] = cardData->cardExpirationDate[3]; yy_exp[1] = cardData->cardExpirationDate[4];

	yy_exp[2] = '\0';	                         yy_exp_n = atoi(yy_exp);

	if (yy_t_n > yy_exp_n)
	{
		expired = EXPIRED_CARD;
	}
	else if (yy_t_n < yy_exp_n)
	{
		expired = TERMINAL_OK;
	}
	else if (yy_t_n == yy_exp_n)
	{
		if (mm_t_n <= mm_exp_n)
		{
			expired = TERMINAL_OK;
		}
		else if (mm_t_n > mm_exp_n)
		{
			expired = EXPIRED_CARD;
		}
	}

	return expired;

}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t trans_ = 0; 
	float t_amount = 0.0;

	printf("Enter Transaction Amount : ");
	
	scanf_s("%f", &t_amount);

	if (t_amount <= 0.0)
	{
		trans_ = INVALID_AMOUNT;
	}
	else
	{
		trans_ = TERMINAL_OK;
		termData->transAmount = t_amount;
	}
	return trans_;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t below = 0; 

	if (termData->transAmount > termData->maxTransAmount)
	{
		below = EXCEED_MAX_AMOUNT;
	}
	else
	{
		below = TERMINAL_OK;
	}
	return below;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	EN_terminalError_t max = 0;

	if (maxAmount <= 0.0)
	{
		max = INVALID_MAX_AMOUNT;
	}
	else
	{
		max = TERMINAL_OK;
		termData->maxTransAmount = maxAmount;
	}

	return max;

}


