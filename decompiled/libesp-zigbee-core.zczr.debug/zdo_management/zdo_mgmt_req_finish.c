/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_management.o -> zdo_mgmt_req_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_req_finish(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      (**(code **)(param_1 + 0x18))(param_2,*(undefined4 *)(param_1 + 0x1c));
    }
    zdo_free_mgmt_req(param_1);
  }
  return;
}

