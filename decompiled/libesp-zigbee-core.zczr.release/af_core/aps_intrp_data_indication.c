/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_core.o -> aps_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_intrp_data_indication(int param_1)

{
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
  }
  if (*(short *)(param_1 + 0x18) == -0x3fa2) {
    zcl_intrp_indication_handler();
  }
  zmsg_free(*(undefined4 *)(param_1 + 0x20));
  return;
}

