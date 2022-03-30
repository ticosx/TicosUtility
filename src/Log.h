/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2018 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on all ESPRESSIF SYSTEMS products, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef LOG_H_
#define LOG_H_

#define LOGLEVEL  LOGLEVEL_ERR

// TODO: Consider to change to ArduinoLog https://www.arduino.cc/reference/en/libraries/arduinolog/
// But now Luban cannot ensure the init of ArduinoLog is executed in the first, use this implementation first

#define LOGLEVEL_ERR		0	/* error conditions */
#define LOGLEVEL_WARNING	1	/* warning conditions */
#define LOGLEVEL_NOTICE		2	/* normal but significant condition */
#define LOGLEVEL_INFO		3	/* informational */
#define LOGLEVEL_DEBUG		4	/* debug-level messages */
#define LOGLEVEL_VERBOSE		4	/* very detail messages */

#define log(tag, level, format, ...) Serial.printf(level " %s " format "\033[0m", tag, ## __VA_ARGS__)

#define error(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_ERR) \
  log(tag, "\033[0;31;49mE", format, ## __VA_ARGS__);}
#define warn(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_WARNING) \
  log(tag, "\033[0;32;49mW", format, ## __VA_ARGS__);}
#define notice(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_NOTICE) \
  log(tag, "\033[0;33;49mN", format, ## __VA_ARGS__);}
#define info(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_INFO) \
  log(tag, "\033[0;34;49mI", format, ## __VA_ARGS__);}
#define debug(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_DEBUG) \
  log(tag, "\033[0;36;49mD", format, ## __VA_ARGS__);}
#define verbose(tag, format, ...) {if(LOGLEVEL >= LOGLEVEL_VERBOSE) \
  log(tag, "\033[0;37;49mV", format, ## __VA_ARGS__);}


#endif //LOG_H_
