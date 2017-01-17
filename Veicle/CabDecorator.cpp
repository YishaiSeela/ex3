
#include "CabDecorator.h"


CabDecorator::CabDecorator(char manufacturer,int taxiType,int id,char color)
  : Vehicle(manufacturer,taxiType, id, color)
/**
 * Ctor
 */
{
    this->taxiType=taxiType;
    this->tariff=tariff;
    this->km=km;
}


CabDecorator::~CabDecorator()
/**
 * Dtor
 */
{
}


