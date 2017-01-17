//
// Created by yishai on 12/5/16.
//

#ifndef EX2_LUXURYCAB_H
#define EX2_LUXURYCAB_H


#include "CabDecorator.h"

class LuxuryCab: public CabDecorator {
protected:
    double km;
    double tariff;
public:
    LuxuryCab(char manufacturer, int taxiType, int id,char color,double tariff, double km);
    ~LuxuryCab();
};


#endif //EX2_LUXURYCAB_H
