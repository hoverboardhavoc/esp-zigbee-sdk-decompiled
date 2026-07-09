/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> free_memory_for_get_profile
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_memory_for_get_profile(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x10) != (void *)0x0) {
      free(*(void **)((int)param_1 + 0x10));
    }
    free(param_1);
  }
  return;
}

