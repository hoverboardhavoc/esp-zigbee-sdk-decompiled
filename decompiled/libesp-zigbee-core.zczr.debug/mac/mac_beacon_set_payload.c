/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_beacon_set_payload
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

size_t mac_beacon_set_payload(int param_1,void *param_2,size_t param_3)

{
  if (param_2 == (void *)0x0) {
    param_3 = 0;
  }
  else if (param_3 != 0) {
    memcpy((void *)(param_1 + 4),param_2,param_3);
  }
  return param_3;
}

