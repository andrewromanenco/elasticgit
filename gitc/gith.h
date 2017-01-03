/*
 * GitH
 * logging function for traffic volume
 * x* works with main threads
 * u* internal operations
 */

#include <unistd.h>

#ifndef GITH_H
#define GITH_H

/*
 * Metrics
 * sf - suffix to append to generated file
 */
void gith_log_usage(ssize_t xread, ssize_t xwrite, ssize_t uread, ssize_t uwrite, char *sx);

#endif