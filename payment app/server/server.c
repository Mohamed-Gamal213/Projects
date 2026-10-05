#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include "server.h"


ST_accountsDB_t accountsDB[255] =
{
	{ 6032.0, RUNNING, "1234568778985611" },	{ 1561.0, BLOCKED, "1651231879823465" },
	{ 2022.0, RUNNING, "1325498454813156" },	{ 9845.0, BLOCKED, "7389425643156981" },
	{ 9995.0, RUNNING, "5498432156484645" },	{ 2011.0, BLOCKED, "2034666520498103" },
	{ 2023.0, RUNNING, "2156489413246542" },	{ 2623.0, BLOCKED, "3750627061324444" },
	{ 5021.0, RUNNING,"1468235175689131" }, 	{ 1285.0, BLOCKED,  "1560132065654234" }
};
ST_accountsDB_t* accountsDBptr = accountsDB;       ST_accountsDB_t* valid_account_ptr = 0;

ST_transaction_t transactionsDB[255] = { 0 };      ST_transaction_t* transactionsDBptr = transactionsDB;

      
uint32_t trans_index = 0;


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t trans_ = 0;                         EN_transState_t transaction_state = 0;


	ST_transaction_t* save_transaction_ptr = transData;



	if (isValidAccount(cardptr, accountsDBptr) == ACCOUNT_NOT_FOUND)
	{
		trans_ = FRAUD_CARD;
		transaction_state = FRAUD_CARD;
	}
	else
	{
		trans_ = APPROVED;
		transaction_state = APPROVED;
		valid_account_ptr->balance = valid_account_ptr->balance - terminalptr->transAmount;
	}
	if (isBlockedAccount(valid_account_ptr) == BLOCKED_ACCOUNT)
	{
		trans_ = DECLINED_STOLEN_CARD;
		transaction_state = DECLINED_STOLEN_CARD;
	}
	 if (isAmountAvailable(terminalptr, valid_account_ptr) == LOW_BALANCE)
	{
		trans_ = DECLINED_INSUFFECIENT_FUND;
		transaction_state = DECLINED_INSUFFECIENT_FUND;
	}


	if (saveTransaction(save_transaction_ptr) != SERVER_OK)
	{
		trans_ = INTERNAL_SERVER_ERROR;
		transaction_state = INTERNAL_SERVER_ERROR;
	}

	return trans_;
}

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t server = 0; 	uint32_t cmp = 0;

	valid_account_ptr = 0;

	for (uint8_t i = 0; i < accounts; i++)
	{
		cmp = 0;
		cmp = strcmp(cardData->primaryAccountNumber, accountRefrence->primaryAccountNumber);

		if (cmp == 0)
		{
			server = SERVER_OK;
			valid_account_ptr = accountRefrence;
			break;
		}
		accountRefrence++;
	}

	if (valid_account_ptr == 0)
	{
		server = ACCOUNT_NOT_FOUND;
	}


	return  server;

}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t server = 0;
	if (accountRefrence != 0)
	{
		if (accountRefrence->state == RUNNING)
		{
			server = SERVER_OK;
		}
		else if (accountRefrence->state == BLOCKED)
		{
			server = BLOCKED_ACCOUNT;
		}
	}


	return  server;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t server = 0;
	if (accountRefrence != 0)
	{
		if (termData->transAmount > accountRefrence->balance)
		{
			server = LOW_BALANCE;
		}
		else
		{
			
			server = SERVER_OK;
		}
	}

	return  server;

}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	EN_serverError_t server = SERVER_OK;

	transData = transData + trans_index;
	

	strcpy(CardName, cardptr->cardHolderName);             	strcpy(CardDate, cardptr->cardExpirationDate);

	strcpy(CardPAN, cardptr->primaryAccountNumber);     	strcpy(TransDate, terminalptr->transactionDate);


	TransAmount = terminalptr->transAmount;             	MaxAmount = terminalptr->maxTransAmount;

	
	SeqNumber = 1 + trans_index;

	listSavedTransactions();

	trans_index++;
	
	printf("\n");
	printf("Terminal Max Amount: %f", MaxAmount);
	printf("\n");
	printf("Cardholder Name: %s", CardName);
	printf("\n");
	printf("PAN: %s", CardPAN);
	printf("\n");
	printf("Card Exp Date: %s", CardDate);
	printf("\n");
	
	printf("Trans Sequence Number: %ld", SeqNumber);
	printf("\n");
	printf("#########################");	
	printf("\n");
	
	
	
	return server;
}

void listSavedTransactions(void)
{
	


	 if (isAmountAvailable(terminalptr, valid_account_ptr) == LOW_BALANCE)
	{

		printf("Trans State: Declined -> Insufficient fund");
	}
	
		
	if (isBlockedAccount(valid_account_ptr) == BLOCKED_ACCOUNT)
	{
		printf("Trans State: Declined -> Blocked Account");
	}


    if (isValidAccount(cardptr, accountsDBptr) == ACCOUNT_NOT_FOUND)
	{
		printf("Trans State: Declined -> Fraud Card");
	}

	if (isValidAccount(cardptr, accountsDBptr) != ACCOUNT_NOT_FOUND)
	{
		if (isAmountAvailable(terminalptr, valid_account_ptr) != LOW_BALANCE)
		{

			printf("Trans State: Approved");
		}

	}



}
