/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> af_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_indication_handler(int param_1)

{
  short sVar1;
  int unaff_s0;
  
  if (param_1 != 0) {
    unaff_s0 = param_1;
    if (*(char *)(param_1 + 7) != -1) goto _L0;
  }
  param_1 = __assert_func(0,0,0,0);
_L0:
  sVar1 = *(short *)(param_1 + 10);
  if ((sVar1 == 0x104) || (sVar1 == -0x3fa2)) {
    zcl_indication_handler(unaff_s0);
  }
  else if (sVar1 == 0) {
    zdo_indication_handler();
  }
  zmsg_free(*(undefined4 *)(unaff_s0 + 0x10));
  return;
}

