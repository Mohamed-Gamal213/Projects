#pragma once
#ifndef SERVER_H_
#define SERVER_H_

#include "../terminal/terminal.c"
#define accounts 10
#define CardName  transData->cardHolderData.cardHolderName
#define CardDate  transData->cardHolderData.cardExpirationDate
#define CardPAN   transData->cardHolderData.primaryAccountNumber 
#define TransDate transData->terminalData.transactionDate
#define TransAmount transData->terminalData.transAmount
#define MaxAmount  transData->terminalData.maxTransAmount
#define SeqNumber   transData->transactionSequenceNumber
typedef enum EN_transState_t
{
    APPROVED=1, DECLINED_INSUFFECIENT_FUND=2, DECLINED_STOLEN_CARD=3, FRAUD_CARD=4, INTERNAL_SERVER_ERROR=5
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
}EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;


EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
void listSavedTransactions(void);

extern ST_transaction_t* transactionsDBptr;
#endif
