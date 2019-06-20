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
/*#### |End  | <-- Секция - "Определение типов" ##############################*/


/*#### |Begin| --> Секция - "Определение глобальных переменных" ##############*/
/*#### |End  | <-- Секция - "Определение глобальных переменных" ##############*/


/*#### |Begin| --> Секция - "Прототипы глобальных функций" ###################*/
/*#### |End  | <-- Секция - "Прототипы глобальных функций" ###################*/


/*#### |Begin| --> Секция - "Определение макросов" ###########################*/
/*#### |End  | <-- Секция - "Определение макросов" ###########################*/

#endif  /* LIB_A_AJPC_ALBATROS_JOY_PROTOCOL_COMMUNICATION_H_ */

/*############################################################################*/
/*################################ END OF FILE ###############################*/
/*############################################################################*/
