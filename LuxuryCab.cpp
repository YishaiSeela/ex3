
#include "LuxuryCab.h"


LuxuryCab::LuxuryCab(char manufactore, int taxiType, int id,char color,double tariff, double km)
      :CabDecorator (manufactore, taxiType, id,color)

/**
/**
 * Ctor
 */
{
    this->tariff=tariff;
    this->km=km;
}


LuxuryCab::~LuxuryCab()
/**
 * Dtor
 */
{
}
