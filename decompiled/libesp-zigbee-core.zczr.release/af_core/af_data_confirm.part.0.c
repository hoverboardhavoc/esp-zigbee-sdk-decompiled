/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_confirm.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_confirm_part_0(void)

{
  int iVar1;
  
  iVar1 = __assert_func(0,0,0,0);
  if (iVar1 == 0) {
    iVar1 = af_data_confirm_part_0();
  }
  af_data_indication_handler();
  mm_free(iVar1);
  return;
}

