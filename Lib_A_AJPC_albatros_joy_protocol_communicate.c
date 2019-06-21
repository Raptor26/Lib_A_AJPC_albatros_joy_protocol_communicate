/**
 * @file   	%<%NAME%>%.%<%EXTENSION%>%
 * @author 	%<%USER%>%
 * @version
 * @date 	%<%DATE%>%, %<%TIME%>%
 * @brief
 */


/*#### |Begin| --> Секция - "Include" ########################################*/
#include "Lib_A_AJPC_albatros_joy_protocol_communicate.h"
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Глобальные переменные" ##########################*/
/*#### |End  | <-- Секция - "Глобальные переменные" ##########################*/


/*#### |Begin| --> Секция - "Локальные переменные" ###########################*/
/*#### |End  | <-- Секция - "Локальные переменные" ###########################*/


/*#### |Begin| --> Секция - "Прототипы локальных функций" ####################*/
/*#### |End  | <-- Секция - "Прототипы локальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание глобальных функций" ####################*/
uint8_t
AJPC_JoyStatus_SetPack(
	ajpc_joy_status_pack_s *pPack_s,
	uint16_t *pJoyRollPitchADC,
	uint8_t buttonPresEvents,
	uint8_t vibroStatus)
{
	pPack_s->startFrame 		= 0xAA;
	pPack_s->vibroStatus 		= vibroStatus;
	pPack_s->joyADC_a[0u] 		= *pJoyRollPitchADC++;
	pPack_s->joyADC_a[1u] 		= *pJoyRollPitchADC;
	pPack_s->buttonPresEvents 	= buttonPresEvents;
	pPack_s->crc 				= AJPC_JoyStatus_GetCrcPack(pPack_s);

	return (sizeof(ajpc_joy_status_pack_s));
}

uint8_t
AJPC_VibtoMode_SetPack(
	ajpc_vibro_mode_pack_s *pVibroModePack_s,
	uint8_t vibroMode)
{
	pVibroModePack_s->startFrame 	= 0xAAAA;
	pVibroModePack_s->vibroStatus 	= vibroMode;
	pVibroModePack_s->crc 			= AJPC_VibroMode_GetCrcPack(pVibroModePack_s);

	return (sizeof(ajpc_vibro_mode_pack_s));
}
/*#### |End  | <-- Секция - "Описание глобальных функций" ####################*/


/*#### |Begin| --> Секция - "Описание локальных функций" #####################*/
/*#### |End  | <-- Секция - "Описание локальных функций" #####################*/


/*#### |Begin| --> Секция - "Обработчики прерываний" #########################*/
/*#### |End  | <-- Секция - "Обработчики прерываний" #########################*/

/*############################################################################*/
/*############################ END OF FILE  ##################################*/
/*############################################################################*/
