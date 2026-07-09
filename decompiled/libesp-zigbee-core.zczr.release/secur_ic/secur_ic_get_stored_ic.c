/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_get_stored_ic
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void secur_ic_get_stored_ic(int *param_1,int *param_2)

{
  *(undefined2 *)(param_2 + 7) = 0;
  *(undefined1 *)((int)param_2 + 0x1e) = 0;
  while( true ) {
    ds_ic_info_itor_read(param_2);
    if (*(char *)((int)param_2 + 0x1e) != '\0') {
      return;
    }
    if ((*param_1 == *param_2) && (param_1[1] == param_2[1])) break;
    *(short *)(param_2 + 7) = (short)param_2[7] + 1;
  }
  return;
}

