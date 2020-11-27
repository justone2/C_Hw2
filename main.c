#include <stdio.h>
#include "myBank.h"

void processInput();
int flag = 0;

int main()
{
	printf( "Enter a char for the operation!\n" );
	printf( "'O': Open new account\n" );
	printf( "'B': Print balance of an account\n" );
	printf( "'D': Deposit amount to an account\n" );
	printf( "'W': Withdraw amount from account\n" );
	printf( "'C': Close specific account\n" );
	printf( "'I': Add interest to all acounts\n" );
	printf( "'P': Print all opened accounts\n" );
	printf( "'E': Close all existing accounts and exit program\n" );

	processInput();
}

void processInput()
{
	flag = 0;

	char ch;

	scanf( "%c", &ch );
	
	switch( ch )
	{
		case 'O': 
		{
			float amount;
			printf( "Enter an initial amount.\n" );

			scanf( "%f", &amount );

			OperationO( amount );
			break;
		}
		case 'B':
		{
			int acc;
			printf( "Enter an account id\n" );

			scanf( "%d", &acc );

			OperationB( acc );
			break;
		}
		case 'D':
		{
			int acc;
			float amount;

			printf( "Enter an account id\n" );
			scanf( "%d", &acc );

			printf( "Enter an amount to deposit\n" );
			scanf( "%f", &amount );

			OperationD( acc, amount );
			break;
		}
		case 'W':
		{
			int acc;
			float amount;

			printf( "Enter an account id\n" );
			scanf( "%d", &acc );

			printf( "Enter an amount to withdraw\n" );
			scanf( "%f", &amount );
	
			OperationW( acc, amount );
			break;
		}
		case 'C':
		{
			int acc;
			printf( "Enter an account id\n" );
			scanf( "%d", &acc );

			OperationC( acc );
			break;
		}
		case 'I':
		{
			float interest;
			printf( "Enter an Interest rate.\n" );
			scanf( "%f", &interest );

			if(interest >=0)
				OperationI(interest);

			break;
		}
		case 'P':
		{
			OperationP();
			break;
		}
		case 'E':
		{
			OperationE();
			return;
		}
	}

	processInput();
}
