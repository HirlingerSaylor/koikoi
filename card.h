#ifndef CARD_H
#define CARD_H


class card
{
    public:
        card(int mymonth, int myvalue, int myid, int myowner);
        ~card();
        int  getMonth();
        int  getValue();
        int  getId();
        int  getOwner();
        void setOwner(int);
    private:
        int  month;
        int  value;
        int  id;
        int  owner;

};

#endif // CARD_H
