/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> occupancy_sensing.o -> occupancy_sensing_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool occupancy_sensing_cluster_srv_check_value_handler(uint param_1,short *param_2)

{
  if (param_1 != 0x22) {
    if (0x22 < param_1) {
      if (param_1 < 0x32) {
        if (0x2f < param_1) goto _L0;
      }
      else if (param_1 == 0x32) goto _L0;
      return false;
    }
    if (param_1 != 0x12) {
      if (param_1 < 0x13) {
        if (1 < (param_1 - 0x10 & 0xffff)) {
          return false;
        }
      }
      else if (1 < (param_1 - 0x20 & 0xffff)) {
        return false;
      }
_L0:
      return *param_2 == -1;
    }
  }
_L0:
  return 0xfd < (byte)((char)*param_2 - 1U);
}

