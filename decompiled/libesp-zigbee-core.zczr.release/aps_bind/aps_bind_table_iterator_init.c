/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_iterator_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_iterator_init(uint param_1,char *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  memset(param_2,0,0xc);
  do {
    if (*param_2 != '\0') {
      return;
    }
    uVar1 = uVar1 + 1 & 0xffff;
    aps_bind_table_iterator_next(param_2);
  } while (uVar1 <= param_1);
  return;
}

