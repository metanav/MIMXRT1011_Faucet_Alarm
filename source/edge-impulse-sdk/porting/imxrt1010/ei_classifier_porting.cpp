#include "../ei_classifier_porting.h"
#if EI_PORTING_IMXRT1010 == 1

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "clock_config.h"
#include "board.h"

#define EI_WEAK_FN __attribute__((weak))



extern "C" {
    volatile uint32_t g_systickCounter;
    volatile uint32_t g_millis_counter;

    void SysTick_Handler(void)
    {
    		if (g_systickCounter != 0U)
    		{
    			g_systickCounter--;
    		}
    		g_millis_counter++;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
	g_systickCounter = n;
	while (g_systickCounter != 0U) { }
}


EI_WEAK_FN EI_IMPULSE_ERROR ei_run_impulse_check_canceled() {
    return EI_IMPULSE_OK;
}

EI_WEAK_FN EI_IMPULSE_ERROR ei_sleep(int32_t time_ms) {
    SysTick_DelayTicks(time_ms);

    return EI_IMPULSE_OK;
}

uint64_t ei_read_timer_ms() {
    return (uint64_t)g_millis_counter;
}

uint64_t ei_read_timer_us() {
    return ei_read_timer_ms() * 1000UL;
}

/**
 *  Printf function uses vsnprintf and output using Arduino Serial
 */
__attribute__((weak)) void ei_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

__attribute__((weak)) void ei_printf_float(float f) {
    ei_printf("%f", f);
}

__attribute__((weak)) void *ei_malloc(size_t size) {
    return malloc(size);
}

__attribute__((weak)) void *ei_calloc(size_t nitems, size_t size) {
    return calloc(nitems, size);
}

__attribute__((weak)) void ei_free(void *ptr) {
    free(ptr);
}

#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C"
#endif
__attribute__((weak)) void DebugLog(const char* s) {
    ei_printf("%s", s);
}

#endif // EI_PORTING_IMXRT1010 == 1
