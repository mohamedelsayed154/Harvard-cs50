#include <stdio.h>
#include <cs50.h>

bool is_valid(long long card_number);
string get_card_type(long long card_number);

int main(void)
{
    long long card_number;

     //get input from user
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    //check if input is less than 13 or more than 17 which is invalid
    if (is_valid(card_number))
    {
        printf("%s\n", get_card_type(card_number));
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_valid(long long card_number)
{
    int sum = 0, digit;
    bool is_even = false;

    while (card_number > 0)
    {
        digit = card_number % 10;
        card_number /= 10;

        if (is_even)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }
        sum += digit;
        is_even = !is_even;
    }

    return sum % 10 == 0;
}

string get_card_type(long long card_number)
{
    int digits = 0;
    long long temp = card_number;

    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    if ((digits == 13 || digits == 16) && (card_number / 100000000000000 == 4))
    {
        return "VISA";
    }
    else if ((digits == 16) && (card_number / 100000000000000 >= 51 && card_number / 100000000000000 <= 55))
    {
        return "MASTERCARD";
    }
    else if ((digits == 15) && (card_number / 1000000000000 == 34 || card_number / 1000000000000 == 37))
    {
        return "AMEX";
    }
    else
    {
        return "INVALID";
    }
}