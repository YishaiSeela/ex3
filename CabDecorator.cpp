
#include "CabDecorator.h"


CabDecorator::CabDecorator(char manufactore,int taxiType,int id,char color)
  : Vehicle(manufactore, id, color)
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


