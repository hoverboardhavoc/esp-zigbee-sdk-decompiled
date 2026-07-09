/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void af_data_confirm(int param_1)

{
  if (param_1 != 0) {
    af_data_schedule_cnf_cb();
    zmsg_free(*(undefined4 *)(param_1 + 0x14));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xc4,"af_data_confirm",
                0x10000);
  af_data_confirm();
  return;
}

