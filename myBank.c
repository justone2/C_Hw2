#include "myBank.h"
#include <stdio.h>

#define MAXACCOUNTS 50
#define STARTERID 901
#define ERROR -1

enum
{
	Status,
	Balance,
	Options
};

enum
{
	Closed,
	Open
};

float accounts[MAXACCOUNTS][Options];

void OperationO( float amount )
{
	int id = ERROR;

	for( int i = 0; i < MAXACCOUNTS; i++ )
	{
		if( accounts[i][Status] == Closed )
		{
			id = i;
			break;
		}
	}
	
	if( id == ERROR )
	{
		printf( "Failed, Bank reached max accounts!\n" );
		return;
	}
	
	accounts[id][Status] = Open;
	accounts[id][Balance] = amount;
	
	printf( "Account %d Created, Balance: %.2f\n", id + STARTERID, accounts[id][Balance] );
}

void OperationB(int id)
{
	if( accounts[id-STARTERID][Status] == Open )
	{
		printf( "Account %d Balance is: %.2f\n", id, accounts[id-STARTERID][Balance] );
		return;
	}

	printf( "Account %d is closed\n", id);
}

void OperationD( int id, float amount )
{
	id -= STARTERID;

	if( accounts[id][Status] == Open ) {
		accounts[id][Balance] += amount;

		printf( "Deposited %.2f to Account %d New balance is: %.2f\n", amount, id + STARTERID, accounts[id][Balance] );

		return;
	}

	printf( "Failed to deposit\n" );
}

void OperationW( int id, float amount )
{
	id -= STARTERID;

	if( accounts[id][Status] == Open )
	{
		if( accounts[id][Balance] >= amount )
		{
			accounts[id][Balance] -= amount;
			printf("Withdrawed %.2f to Account %d New balance is: %.2f\n", amount, id, accounts[id][Balance]);
		}

		else
		{ 
			printf("You dont have enough money!\n");
		}

		return;
	}

	printf("Failed to withdraw\n");
}

void OperationC( int id )
{
	id -= STARTERID;

	if( accounts[id][Status] == Open )
	{
		accounts[id][Balance] = 0;
		accounts[id][Status] = Closed;
		printf( "Account %d is now closed!\n", id + STARTERID );
		return;
	}

	printf( "Account %d is already closed!\n", id + STARTERID );
}

void OperationI( float interest )
{
	for( int i = 0; i < MAXACCOUNTS; i++ )
	{
		if( accounts[i][Status] == Open )
		{
			double balance = accounts[i][Balance] * (1 + (interest / 100));

			accounts[i][Balance] = balance;
		}
	}

	printf( "Entire accounts balanced increased by %.2f\n", interest );
}

void OperationP( ) {
	for( int i = 0; i < MAXACCOUNTS; i++ )
	{
		if(accounts[i][Status] == Open)
		{
			printf( "Account %d balance is: %.2f\n", i + STARTERID, accounts[i][Balance] );
		}
	}
}

void OperationE( ) {
	for( int i = 0; i < MAXACCOUNTS; i++ )
	{
		if(accounts[i][Status] == Open)
		{
			accounts[i][Status] = Closed;
			accounts[i][Balance] = 0;
		}
	}

	printf( "All accounts are closed!\n" );
}
