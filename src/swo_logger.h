#include <stdint.h>

#ifndef SWO_LOGGER_H_
#define SWO_LOGGER_H_

typedef enum
{
    SWO_LOGGER_LOG_LEVEL_ERROR,
    SWO_LOGGER_LOG_LEVEL_WARNING,
    SWO_LOGGER_LOG_LEVEL_INFO,
    SWO_LOGGER_LOG_LEVEL_DEBUG,
} SWO_Logger_Log_Level;

typedef struct
{
    SWO_Logger_Log_Level log_level;
    uint32_t (*send_char)(uint32_t);
} SWO_Logger_Config;

void swo_logger_init(const SWO_Logger_Config* config);
void swo_logger_log_error(char const *const format, ...);
void swo_logger_log_warning(char const *const format, ...);
void swo_logger_log_info(char const *const format, ...);
void swo_logger_log_debug(char const *const format, ...);

#endif
