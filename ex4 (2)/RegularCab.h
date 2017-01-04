//
// Created by yishai on 12/5/16.
//

#ifndef EX2_REGULARCAB_H
#define EX2_REGULARCAB_H


#include "CabDecorator.h"

class RegularCab: public CabDecorator {
protected:
    double km;
    double tariff;
public:
    RegularCab(char manufacturer, int taxiType, int id,char color, double tariff, double km);
    ~RegularCab();
};


#endif //EX2_REGULARCAB_H
