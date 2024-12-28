extern void ITM_SendChar(char ch);

typedef char const *const SWO_Logger_Log_Level_Format;

typedef enum
{
    SWO_LOGGER_LOG_LEVEL_ERROR,
    SWO_LOGGER_LOG_LEVEL_WARNING,
    SWO_LOGGER_LOG_LEVEL_INFO,
    SWO_LOGGER_LOG_LEVEL_DEBUG,
} SWO_Logger_Log_Level;

void swo_logger_init(SWO_Logger_Log_Level log_level);
void swo_logger_log_error(SWO_Logger_Log_Level_Format format, ...);
void swo_logger_log_warning(SWO_Logger_Log_Level_Format format, ...);
void swo_logger_log_info(SWO_Logger_Log_Level_Format format, ...);
void swo_logger_log_debug(SWO_Logger_Log_Level_Format format, ...);
