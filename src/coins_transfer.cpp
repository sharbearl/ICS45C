#include <iostream>
#include "coins.h"
using namespace std;

int main()
{
    Coins piggyBank(50,50,50,50);
    Coins pocket(8,3,6,8);

    cout << "Initial piggy bank: " << piggyBank << endl;
    cout << "Initial pocket: " << pocket << endl << endl;

    Coins chips = pocket.extract_exact_change(coins_required_for_cents(149));
    cout << "Bought chips using pocket" << endl;
    cout << "Coins required for chips: " << chips << endl;
    cout << "Pocket after paying for chips: " << pocket << endl << endl;

    cout << coins_required_for_cents(405);
    Coins transfer = piggyBank.extract_exact_change(coins_required_for_cents(405));
    pocket.deposit_coins(transfer);
    cout << "Transferring money to pocket" << endl;
    cout << "Coins for transfer: " << transfer << endl;
    cout << "Pocket: " << pocket << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;

    Coins sofa(10,10,10,10);
    piggyBank.deposit_coins(sofa);
    cout << "Transferring sofa change to piggy bank" << endl;
    cout << "Sofa: " << sofa << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;

    cout << "Piggy bank total: ";
    print_cents(piggyBank.total_value_in_cents(), cout);
}
