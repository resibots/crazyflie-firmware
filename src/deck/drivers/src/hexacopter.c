/*
 * hexacopter.c
 *
 *  Created on: Apr 13, 2018
 *      Author: bitcraze
 */
#define DEBUG_MODULE "Hexacopter"
#include "debug.h"
#include "deck.h"

void hexaInit(DeckInfo*info)
{
	pinMode(DECK_GPIO_IO1,OUTPUT);
	pinMode(DECK_GPIO_IO2,OUTPUT);
}

bool hexaTest()
{
	return true;
}

const DeckDriver hexacopter_driver = {
  .vid = 0,
  .pid = 0,
  .name = "meHexacopter",

  .usedGpio = DECK_USING_IO_1 | DECK_USING_IO_2,

  .init = hexaInit,
  .test = hexaTest,
};

DECK_DRIVER(hexacopter_driver);
