#include <stdarg.h>
#include <stdio.h>

#include "swo_logger.h"

const static SWO_Logger_Config *swo_logger_config;

int __io_putchar(char ch) {
  swo_logger_config->send_char(ch);

  return 1;
}

void swo_logger_init(const SWO_Logger_Config *config) {
  swo_logger_config = config;
}

static void _log(SWO_Logger_Log_Level const level, char const *const format,
                 va_list args);

void swo_logger_log_eror(char const *const format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_ERROR, format, args);
  va_end(args);
}

void swo_logger_log_warning(char const *const format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_WARNING, format, args);
  va_end(args);
}

void swo_logger_log_info(char const *const format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_INFO, format, args);
  va_end(args);
}

void swo_logger_log_debug(char const *const format, ...) {
  va_list args;
  va_start(args, format);
  _log(SWO_LOGGER_LOG_LEVEL_DEBUG, format, args);
  va_end(args);
}

char const *const _get_log_level_string(SWO_Logger_Log_Level const log_level);

static void _log(SWO_Logger_Log_Level const level, char const *const format,
                 va_list args) {
  if (level > swo_logger_config->log_level)
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
