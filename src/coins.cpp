#include <iostream>
#include "coins.h"
using namespace std;

Coins::Coins(int q, int d, int n, int p)
    :quarters(q), dimes(d), nickels(n), pennies(p)
{}

void Coins::deposit_coins(Coins& coins)
{
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;
}

bool Coins::has_exact_change_for_coins(Coins const& coins) const
{
    return coins.quarters <= quarters && coins.dimes <= dimes && coins.nickels <= nickels && coins.pennies <= pennies;
}

Coins Coins::extract_exact_change(Coins const& coins)
{
    if (has_exact_change_for_coins(coins))
    {
        quarters -= coins.quarters;
        dimes -= coins.dimes;
        nickels -= coins.nickels;
        pennies -= coins.pennies;

        return coins;
    }
    else
    {
        return Coins(0,0,0,0);
    }
}

int Coins::total_value_in_cents() const
{
    return (quarters * CENTS_PER_QUARTER) + (dimes * CENTS_PER_DIME) + (nickels * CENTS_PER_NICKEL) + pennies;
}

void Coins::print(std::ostream& out) const
{
    out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";
}

std::ostream& operator<<(std::ostream& out, Coins const& coins)
{
    coins.print(out);
    return out;
}

Coins coins_required_for_cents(int amount_in_cents)
{
    int q = amount_in_cents / CENTS_PER_QUARTER;
    int q_del = q * CENTS_PER_QUARTER;

    int d = (amount_in_cents - q_del) / CENTS_PER_DIME;
    int d_del = d * CENTS_PER_DIME;

    int n = (amount_in_cents - q_del - d_del) / CENTS_PER_NICKEL;
    int n_del = n * CENTS_PER_NICKEL;

    int p = (amount_in_cents - q_del - d_del - n_del);

    return Coins(q, d, n, p);
}

void print_cents(int cents, std::ostream& out)
{
    int remain = cents % 100;
    out << "$" << cents / 100 << ".";
    if (remain % 10 == 0)
    {
        if (remain / 10 == 0)
        {
            out << 0 << 0;
        }
        else
        {
            out << remain;
        }
    }
    else if (remain % 10 != 0)
    {
        if (remain / 10 == 0)
        {
            out << 0;
        }
        out << remain;
    }
}

Coins ask_for_coins(std::istream& in, std::ostream& out)
{
    int q = 0, d = 0, n = 0, p = 0;

    out << "Quarters? ";
    in >> q;
    out << "Dimes? ";
    in >> d;
    out << "Nickels? ";
    in >> n; 
    out << "Pennies? ";
    in >> p; 

    return Coins(q, d, n, p);
}

void coins_menu(std::istream& in, std::ostream& out)
{
    string cmd;
    Coins myCoins(0,0,0,0);
    out << "Coins Menu" << endl;

    while (true)
    {
        out << "1. Deposit Change\n2. Extract Change\n3. Print Balance\n4. Exit\n\nUser Input: ";
        in >> cmd;
        out << endl;
        
        if (cmd == "1")
        {
            Coins deposit = ask_for_coins(in, out);
            myCoins.deposit_coins(deposit);
            out << endl << "Thank you!" << endl << endl;
    }
        else if (cmd == "2")
        {
            Coins extract = myCoins.extract_exact_change(ask_for_coins(in, out));
            out << endl << "Thank you!" << endl << endl;
            if (extract == Coins(0,0,0,0))
            {
            out << "ERROR: Insufficient Funds" << endl << endl;
            }
        }
        else if (cmd == "3")
        {
            print_cents(myCoins.total_value_in_cents(), out);
            out << endl<< "Thank you!" << endl << endl;
        }
        else if (cmd == "4")
        {
            break;
        }
        else
        {
            out << "ERROR: Invalid Command" << endl << endl;
        }
    }
}
