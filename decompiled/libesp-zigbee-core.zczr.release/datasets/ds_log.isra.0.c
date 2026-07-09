/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> datasets.o -> ds_log.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_log_isra_0(int param_1,int param_2,int param_3)

{
  if ((param_2 != 0) && (((param_1 != 3 && (1 < (param_1 - 5U & 0xff))) || (param_2 != 5)))) {
    log_write(2,"datasets.c",0x10000,*(undefined4 *)(action_string_1 + param_1 * 4),
              *(undefined4 *)(key_string_0 + param_3 * 4));
    return;
  }
  return;
}

