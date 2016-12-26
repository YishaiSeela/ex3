
#include "LuxuryCab.h"


LuxuryCab::LuxuryCab(char manufacturer, int taxiType, int id,char color,double tariff, double km)
      :CabDecorator (manufacturer, taxiType, id,color)

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
