/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_intrp_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_intrp_data_indication(int param_1)

{
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x10b,
                  "af_intrp_data_indication",0x102dc);
  }
  else if (*(short *)(param_1 + 0x18) != -0x3fa2) goto _L0;
  zcl_intrp_indication_handler();
_L0:
  zmsg_free(*(undefined4 *)(param_1 + 0x20));
  return;
}

