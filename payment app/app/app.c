#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "app.h"

int main()
{
	appStart();
}

void appStart(void)
{
		           
	


        setMaxAmount(terminalptr, 15000.0);
	while (1)
	{
		
		for(EN_cardError_t holder_name = 0; holder_name = getCardHolderName(cardptr);)
		{
			holder_name = WRONG_NAME;
			
			printf(" wrong name");
			printf("\n");
		} 

		for(EN_cardError_t exp_date = 0; exp_date = getCardExpiryDate(cardptr);)
		{
			exp_date = WRONG_EXP_DATE;
			
			printf("wrong exp date");
			printf("\n");
		} 

		
		for(EN_cardError_t card_PAN = 0; card_PAN = getCardPAN(cardptr);)
		{
			card_PAN = WRONG_PAN;
			
			printf("Wrong PAN");
			printf("\n");
		} 

	
		for (EN_terminalError_t trans_date = 0; trans_date = getTransactionDate(terminalptr);)
		{
			trans_date = WRONG_DATE;
			
			printf("Wrong date");
			printf("\n");
		} 
		EN_terminalError_t card_expiry = 0;
		
		for (EN_terminalError_t card_expiry = 0; card_expiry = isCardExpired(cardptr, terminalptr);)
		{
			
			card_expiry = WRONG_EXP_DATE;
			printf("Declined : Expired card");
			printf("\n");

			
			break;
		}

		for(EN_terminalError_t trans_amount = 0; trans_amount = getTransactionAmount(terminalptr);)
		{
			
			trans_amount = INVALID_AMOUNT;
			
			printf("Invalid amount");
			printf("\n");
		} 
		
		
		for (EN_terminalError_t below = 0; below = isBelowMaxAmount(terminalptr);)
		{

			below = EXCEED_MAX_AMOUNT;
			printf("Declined : Amount Exceeding Limit");
			printf("\n");
			break;
			
		}

		 recieveTransactionData(transactionsDBptr);
	}

}
