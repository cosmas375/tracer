#include <stdarg.h>
#include <stdio.h>

#include "swo_logger.h"

int __io_putchar(char ch) {
  ITM_SendChar(ch);

  return 1;
}

SWO_Logger_Log_Level _log_level = SWO_LOGGER_LOG_LEVEL_DEBUG;

void swo_logger_log_init(SWO_Logger_Log_Level log_level) {
  _log_level = log_level;
}

static void _log(SWO_Logger_Log_Level const level,
                 SWO_Logger_Log_Level_Format format, va_list args);

void swo_logger_log_eror(SWO_Logger_Log_Level_Format format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_ERROR, format, args);
  va_end(args);
}

void swo_logger_log_warning(SWO_Logger_Log_Level_Format format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_WARNING, format, args);
  va_end(args);
}

void swo_logger_log_info(SWO_Logger_Log_Level_Format format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_INFO, format, args);
  va_end(args);
}

void swo_logger_log_debug(SWO_Logger_Log_Level_Format format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_DEBUG, format, args);
  va_end(args);
}

char const *const _get_log_level_string(SWO_Logger_Log_Level const log_level);

static void _log(SWO_Logger_Log_Level const level, char const *const format,
                 va_list args) {
  if (level > _log_level)
    return;

  printf("[%s] ", _get_log_level_string(level));
  vfprintf(stdout, format, args);
  printf("\n");
}

char const *const _get_log_level_string(SWO_Logger_Log_Level const log_level) {
  switch (log_level) {
  default:
  case SWO_LOGGER_LOG_LEVEL_ERROR:
    return "ERROR";
  case SWO_LOGGER_LOG_LEVEL_WARNING:
    return "INFO";
  case SWO_LOGGER_LOG_LEVEL_INFO:
    return "INFO";
  case SWO_LOGGER_LOG_LEVEL_DEBUG:
    return "DEBUG";
  }
}
