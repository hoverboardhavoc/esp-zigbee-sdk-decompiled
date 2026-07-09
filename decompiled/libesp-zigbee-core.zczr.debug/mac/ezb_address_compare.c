/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> ezb_address_compare
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_address_compare(char *param_1,char *param_2)

{
  if (*param_1 != *param_2) {
    return 0;
  }
  if (*param_1 != '\x02') {
    if ((*(int *)(param_1 + 2) == *(int *)(param_2 + 2)) &&
       (*(int *)(param_1 + 6) == *(int *)(param_2 + 6))) {
      return 1;
    }
    return 0;
  }
  if (*(short *)(param_1 + 2) != *(short *)(param_2 + 2)) {
    return 0;
  }
  return 1;
}

