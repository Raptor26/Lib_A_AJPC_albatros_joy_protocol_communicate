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

/* Key_Stop */
#define AJPC_PRESS_Key_Stop_SET_POSITION            (0u)
#define AJPC_PRESS_Key_Stop_SET_MASK                ((uint8_t)(1 << AJPC_PRESS_Key_Stop_SET_POSITION))

/* Key_Mode_manual */
#define AJPC_PRESS_Key_Mode_manual_SET_POSITION     (1u)
#define AJPC_PRESS_Key_Mode_manual_SET_MASK         ((uint8_t)(1 << AJPC_PRESS_Key_Mode_manual_SET_POSITION))

/* Key_Zoom */
#define AJPC_PRESS_Key_Zoom_SET_POSITION            (2u)
#define AJPC_PRESS_Key_Zoom_SET_MASK                ((uint8_t)(1 << AJPC_PRESS_Key_Zoom_SET_POSITION))

/* Key_Foto */
#define AJPC_PRESS_Key_Foto_SET_POSITION            (3u)
#define AJPC_PRESS_Key_Foto_SET_MASK                ((uint8_t)(1 << AJPC_PRESS_Key_Foto_SET_POSITION))

/* Key_Zoom+ */
#define AJPC_PRESS_Key_Zoom_plus_SET_POSITION       (4u)
#define AJPC_PRESS_Key_Zoom_plus_SET_MASK           ((uint8_t)(1 << AJPC_PRESS_Key_Zoom_plus_SET_POSITION))

/* Key_Up */
#define AJPC_PRESS_Key_Up_SET_POSITION              (5u)
#define AJPC_PRESS_Key_Up_SET_MASK                  ((uint8_t)(1 << AJPC_PRESS_Key_Up_SET_POSITION))

/* Key_Down */
#define AJPC_PRESS_Key_Down_SET_POSITION            (6u)
#define AJPC_PRESS_Key_Down_SET_MASK                ((uint8_t)(1 << AJPC_PRESS_Key_Down_SET_POSITION))

/* Key_FotoOrHorizont */
#define AJPC_PRESS_Key_FotoOrHorizont_SET_POSITION  (7u)
#define AJPC_PRESS_Key_FotoOrHorizont_SET_MASK      ((uint8_t)(1 << AJPC_PRESS_Key_FotoOrHorizont_SET_POSITION))
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
	uint8_t  startFrame;
	uint8_t  vibroStatus;
	uint16_t joyADC_a[2u];
	uint8_t  buttonPresEvents;
	uint8_t  crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
ajpc_joy_status_pack_s;

typedef struct
{
	uint16_t startFrame;
	uint8_t  vibroStatus;
	uint8_t  crc;
}
#if defined (__GNUC__)
	__attribute__((__packed__))
#else
	#error "Please, define compiler"
#endif
ajpc_vibro_mode_pack_s;
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/

/**
 * @addtogroup Albatros Joystick
 * @{
 */

/**
 * @defgroup    Joystick status
 * @brief       Библиотека содержит функции для работы со статусами джойстика
 * @{
 */

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief     Функция возвращает контрольную сумму пакета данных
 *
 * @param[in]   *pJoyStausPack_s: Указатель на структуру, содержащую пакет данных
 *
 * @return    Контрольная сумма, рассчитанная через исключающее "ИЛИ"
 */
__AJPC_ALWAYS_INLINE uint8_t
AJPC_JoyStatus_GetCrcPack(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	return (CRC_XOR_Crc8(
				(uint8_t*) &pJoyStausPack_s->vibroStatus,
				sizeof(ajpc_joy_status_pack_s)
				- sizeof(pJoyStausPack_s->startFrame)
				- sizeof(pJoyStausPack_s->crc)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief    Функция проверяет валидность пакета данных
 *
 * @param    pJoyStausPack_s    Радость Staus Pack S
 *
 * @return   Функция возвращает: 1u - если пакет данных валиден
 *                               0u - если пакет данных не валиден
 */
__AJPC_ALWAYS_INLINE size_t
AJPC_JoyStatus_CheckPackValidation(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	if (AJPC_JoyStatus_GetCrcPack(pJoyStausPack_s) == pJoyStausPack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief    Функция возвращает значения с АЦП малого джойстика
 *
 * @param[in]   *pJoyStausPack_s: Указатель на структуру, содержащую пакет данных
 * @param[out]  *pRollPitch: Указатель на массив данных, куда будут
 *                           записаны измерения АЦП
 * @return  None
 */
__AJPC_ALWAYS_INLINE void
AJPC_JoyStatus_GetRollPitchADC(
	ajpc_joy_status_pack_s *pJoyStausPack_s,
	uint16_t *pRollPitch)
{
	pRollPitch[0u] = pJoyStausPack_s->joyADC_a[0u];
	pRollPitch[1u] = pJoyStausPack_s->joyADC_a[1u];
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief    Функция возвращает байт данных, в котором содержится информация
 *           о том, какие кнопки джойстика были нажаты
 *
 * @param[in]   *pJoyStausPack_s: Указатель на структуру, содержащую пакет данных
 *
 * @return    байт данных, в котором каждый бит отвечает за статус
 *            соответствующей кнопки:
 *             - AJPC_PRESS_Key_Stop_SET_MASK
 *             - AJPC_PRESS_Key_Mode_manual_SET_MASK
 *             - AJPC_PRESS_Key_Zoom_SET_MASK
 *             - AJPC_PRESS_Key_Foto_SET_MASK
 *             - AJPC_PRESS_Key_Zoom_plus_SET_MASK
 *             - AJPC_PRESS_Key_Up_SET_MASK
 *             - AJPC_PRESS_Key_Down_SET_MASK
 *             - AJPC_PRESS_Key_FotoOrHorizont_SET_MASK
 *
 *             @see AJPC_PRESS_Key
 */
__AJPC_ALWAYS_INLINE uint8_t
AJPC_JoyStatus_GetButtonEvents(
	ajpc_joy_status_pack_s *pJoyStausPack_s)
{
	return (pJoyStausPack_s->buttonPresEvents);
}

extern uint8_t
AJPC_JoyStatus_SetPack(
	ajpc_joy_status_pack_s *pVibroModePack_s,
	uint16_t *pJoyRollPitchADC,
	uint8_t buttonPresEvents,
	uint8_t vibroStatus);

/**
 * @defgroup    Joystick status
 * @brief       Библиотека содержит функции для работы со статусами джойстика
 * @}
 */

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief     Функция возвращает контрольную сумму пакета данных
 *
 * @param[in]   *pJoyStausPack_s: Указатель на структуру, содержащую пакет данных
 *
 * @return    Контрольная сумма, рассчитанная через исключающее "ИЛИ"
 */
__AJPC_ALWAYS_INLINE uint8_t
AJPC_VibroMode_GetCrcPack(
	ajpc_vibro_mode_pack_s *pVibroModePack_s)
{
	return (CRC_XOR_Crc8(
				(uint8_t*) &pVibroModePack_s,
				sizeof(ajpc_vibro_mode_pack_s)
				- sizeof(pVibroModePack_s->crc)));
}

/*-------------------------------------------------------------------------*//**
 * @author    Mickle Isaev
 * @date      21-июн-2019
 *
 * @brief    Функция проверяет валидность пакета данных
 *
 * @param    pJoyStausPack_s    Радость Staus Pack S
 *
 * @return   Функция возвращает: 1u - если пакет данных валиден
 *                               0u - если пакет данных не валиден
 */
__AJPC_ALWAYS_INLINE size_t
AJPC_VibroMode_CheckPackValidation(
	ajpc_vibro_mode_pack_s *pVibroModePack_s)
{
	if (AJPC_VibroMode_GetCrcPack(pVibroModePack_s) == pVibroModePack_s->crc)
	{
		return (1u);
	}
	else
	{
		return (0u);
	}
}

__AJPC_ALWAYS_INLINE size_t
AJPC_VibroMode_GetVibroMode(
	ajpc_vibro_mode_pack_s *pVibroModePack_s)
{
	return (pVibroModePack_s->vibroStatus);
}

extern uint8_t
AJPC_VibtoMode_SetPack(
	ajpc_vibro_mode_pack_s *pVibroModePack_s,
	uint8_t vibroMode);

/**
 * @addtogroup Albatros Joystick
 * @}
 */
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/

#endif  /* LIB_A_AJPC_ALBATROS_JOY_PROTOCOL_COMMUNICATION_H_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
