#include "../ei_classifier_porting.h"
#if EI_PORTING_IMXRT1010 == 1

#include "tensorflow/lite/micro/debug_log.h"
#include <stdio.h>
#include <stdarg.h>

// On IMXRT1010, we set up a serial port and write to it for debug logging.
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C"
#endif // defined(__cplusplus) && EI_C_LINKAGE == 1
void DebugLog(const char* s) {
    ei_printf("%s", s);
}

#endif // EI_PORTING_IMXRT1010
