#include "card.h"

card::card(int mymonth, int myvalue, int myid, int myowner)
{
    month = mymonth;
    value = myvalue;
    id    = myid;
    owner = myowner;
}

card::~card()
{

}

int card::getMonth()
{
    return month;
}

int card::getValue()
{
    return value;
}

int card::getId()
{
    return id;
}

int card::getOwner()
{
    return owner;
}

void card::setOwner(int myowner)
{
    owner = myowner;
}
