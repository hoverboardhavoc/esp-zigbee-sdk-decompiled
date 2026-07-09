/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> occupancy_sensing.o -> occupancy_sensing_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte occupancy_sensing_cluster_srv_check_value_handler(uint param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_1 == 0x22) {
    bVar1 = 0xfe;
  }
  else if (param_1 < 0x23) {
    if (param_1 == 0x12) {
      bVar1 = 0xfe;
    }
    else if (param_1 < 0x13) {
      if ((param_1 - 0x10 & 0xffff) < 2) {
_L0:
        return *(short *)param_2 == -1;
      }
      bVar1 = 0;
    }
    else {
      if ((param_1 - 0x20 & 0xffff) < 2) goto _L0;
      bVar1 = 0;
    }
  }
  else if (param_1 < 0x32) {
    if (0x2f < param_1) goto _L0;
    bVar1 = 0;
  }
  else if (param_1 == 0x32) {
    bVar1 = 0xfe;
  }
  else {
    bVar1 = 0;
  }
  if (bVar1 != 0) {
    if (*param_2 == 0) {
      bVar1 = 1;
    }
    else if (bVar1 < *param_2) {
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
    }
  }
  return bVar1;
}

