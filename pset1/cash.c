#include <stdio.h>
#include <cs50.h>

int rest(int price);

int main(void) {
    int price;
    int totalcoins;

    do {
        price = get_int ("Amount : ");
    } while (proce < 0);

    totalcoins = rest(price);
    printf ("%i\n" , totalcoins);
}

int rest(int price) {
    int quarters = price / 25 ;
    price %= 25 ; 

    int dimes = price / 10 ;
    price %= 10 ;

    int nickels = price / 5 ; 
    price %= 5 ;

    int pennis = price ;
    
    return quarters + dimes + nickels + pennis;
}
