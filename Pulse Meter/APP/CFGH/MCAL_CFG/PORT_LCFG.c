/*
 * PORT_LCFG.c
 *
 * Created: 9/16/2023 12:15:32 PM
 *  Author: alima
 */ 

#include "PORT_LCFG.h"

PIN_PARAMETERS PORT_Initialization[DEFINED_PINS]=
{
	/*LCD*/
    { PORTA_PIN1   ,  PIN_DIR_OUTPUT  },
    { PORTA_PIN2   ,  PIN_DIR_OUTPUT  },
    { PORTA_PIN3   ,  PIN_DIR_OUTPUT  },
    { PORTA_PIN4   ,  PIN_DIR_OUTPUT  },
    { PORTA_PIN5   ,  PIN_DIR_OUTPUT  },
    { PORTA_PIN6   ,  PIN_DIR_OUTPUT  },
    /*PulseMeter Pins*/
    { PORTD_PIN6   ,  PIN_DIR_INPUT   },
	{ PORTB_PIN3   ,  PIN_DIR_OUTPUT  }
						
};  //This is Array of Structs