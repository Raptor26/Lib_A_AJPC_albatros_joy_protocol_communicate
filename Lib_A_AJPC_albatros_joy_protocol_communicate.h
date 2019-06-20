/**
 * @file    %<%NAME%>%.%<%EXTENSION%>%
 * @author  %<%USER%>%
 * @version
 * @date    %<%DATE%>%, %<%TIME%>%
 * @brief
 */


#ifndef LIB_A_AJPC_ALBATROS_JOY_PROTOCOL_COMMUNICATION_H_
#define LIB_A_AJPC_ALBATROS_JOY_PROTOCOL_COMMUNICATION_H_


/*#### |Begin| --> Секция - "Include" ########################################*/
/*==== |Begin| --> Секция - "C libraries" ====================================*/
/*==== |End  | <-- Секция - "C libraries" ====================================*/

/*==== |Begin| --> Секция - "MK peripheral libraries" ========================*/
/*==== |End  | <-- Секция - "MK peripheral libraries" ========================*/

/*==== |Begin| --> Секция - "Extern libraries" ===============================*/
#if defined (__AJPC_EXTERN_MODE_ENABLE__)
	#include "macros_definitions.h"
#endif

#include "Lib_A_CRC_cyclic_redundancy_check/Lib_A_CRC_cyclic_redundancy_check.h"
/*==== |End  | <-- Секция - "Extern libraries" ===============================*/
/*#### |End  | <-- Секция - "Include" ########################################*/


/*#### |Begin| --> Секция - "Определение констант" ###########################*/
/*==== |Begin| --> Секция - Макросы для встраиваемых функций =================*/
#if defined (__GNUC__)

	/* inline*/
	#ifndef __AJPC_INLINE
		#define __AJPC_INLINE          inline
	#endif

	/* static inline */
	#ifndef __AJPC_STATIC_INLINE
		#define __AJPC_STATIC_INLINE   static inline
	#endif

	/* always inline */
	#ifndef __AJPC_ALWAYS_INLINE
		#define __AJPC_ALWAYS_INLINE    inline __attribute__((always_inline)) static
	#endif

	/* force inline */
	#ifndef __AJPC_FORCE_INLINE
		#define __AJPC_FORCE_INLINE    inline __attribute__((always_inline))
	#endif

#else
	#define __AJPC_INLINE
	#define __AJPC_STATIC_INLINE   static
	#define __AJPC_ALWAYS_INLINE
#endif
/*==== |End  | <-- Секция - Макросы для встраиваемых функций =================*/

/*==== |Begin| --> Секция - Расположение функций библиотеки в специальной
 *                          области памяти ===================================*/
#if defined (__AJPC_FNC_ONCE_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __AJPC_FNC_ONCE_MEMORY_LOCATION  __attribute__ ((section(__AJPC_FNC_ONCE_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __AJPC_FNC_ONCE_MEMORY_LOCATION_NAME__ or extend the macro definition __AJPC_FNC_ONCE_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __AJPC_FNC_ONCE_MEMORY_LOCATION
#endif

#if defined (__AJPC_FNC_LOOP_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __AJPC_FNC_LOOP_MEMORY_LOCATION  __attribute__ ((section(__AJPC_FNC_LOOP_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __AJPC_FNC_LOOP_MEMORY_LOCATION_NAME__ or extend the macro definition __AJPC_FNC_LOOP_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __AJPC_FNC_LOOP_MEMORY_LOCATION
#endif
/*==== |End  | <-- Секция - Расположение функций библиотеки в специальной
 *                          области памяти ===================================*/

/*==== |Begin| --> Секция - Расположение констант библиотеки в специальной
 *                          области памяти ===================================*/
#if defined (__AJPC_CONST_MEMORY_LOCATION_NAME__)
	#if defined (__GNUC__)
		#define __AJPC_CONST_MEMORY_LOCATION  __attribute__ ((section(__AJPC_CONST_MEMORY_LOCATION_NAME__)))
	#else
		#error "You defined the name of the memory area for the function location, but the type of your compiler is not supported by the library. You can delete the macro definition __AJPC_CONST_LOOP_MEMORY_LOCATION_NAME__ or extend the macro definition __AJPC_CONST_MEMORY_LOCATION for your compiler type"
	#endif
#else
	#define __AJPC_CONST_MEMORY_LOCATION
#endif
/*==== |End  | <-- Секция - Расположение констант библиотеки в специальной
 *                          области памяти ===================================*/

/*==== |Begin| --> Секция - Локальная оптимизация функций ====================*/
#if defined (__GNUC__)
	#ifndef __AJPC_FNC_ONCE_OPTIMIZE_MODE
		#define __AJPC_FNC_ONCE_OPTIMIZE_MODE
	#endif
#endif

#if defined (__GNUC__)
	#ifndef __AJPC_FNC_LOOP_OPTIMIZE_MODE
		#define __AJPC_FNC_LOOP_OPTIMIZE_MODE
	#endif
#endif
/*==== |End| --> Секция - Локальная оптимизация функций ======================*/
/*#### |End  | <-- Секция - "Определение констант" ###########################*/


/*#### |Begin| --> Секция - "Определение типов" ##############################*/
typedef enum
{
	AJPC_MOTOR_MODE_DISABLE = 0u,
	AJPC_MOTOR_MODE_ATTENTION,
	AJPC_MOTOR_MODE_FLY_HOME,
} ajpc_vibro_status_e;

typedef struct
{
	uint8_t startFrame;
	uint8_t vibroStatus;
	uint16_t joyADC_a[2u];
	uint8_t buttonPresEvents;
	uint8_t crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
ajpc_joy_status_pack_s;
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
__AJPC_ALWAYS_INLINE uint8_t
AJPC_GetCrcJoyStatusPack(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	return (CRC_XOR_Crc8(
				(uint8_t*) &pJoyStausPack_s->vibroStatus,
				sizeof(ajpc_joy_status_pack_s)
				- sizeof(pJoyStausPack_s->startFrame)
				- sizeof(pJoyStausPack_s->crc)));
}

__AJPC_ALWAYS_INLINE ajpc_vibro_status_e
AJPC_GetVibroStatus(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	return (pJoyStausPack_s->vibroStatus);
}

__AJPC_ALWAYS_INLINE void
AJPC_GetJoyADC(
	ajpc_joy_status_pack_s *pJoyStausPack_s,
	uint16_t *pRollPitch)
{
	pRollPitch[0u] = pJoyStausPack_s->joyADC_a[0u];
	pRollPitch[1u] = pJoyStausPack_s->joyADC_a[1u];
}

__AJPC_ALWAYS_INLINE size_t
AJPC_GetPackageValidation(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	if (AJPC_GetCrcJoyStatusPack(pJoyStausPack_s) == pJoyStausPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}

extern uint8_t
AJPC_SetJoyStatusPackage(
	ajpc_joy_status_pack_s *pPack_s,
	uint16_t *pJoyRollPitchADC,
	uint8_t buttonPresEvents,
	uint8_t vibroStatus);
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/

#endif  /* LIB_A_AJPC_ALBATROS_JOY_PROTOCOL_COMMUNICATION_H_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
