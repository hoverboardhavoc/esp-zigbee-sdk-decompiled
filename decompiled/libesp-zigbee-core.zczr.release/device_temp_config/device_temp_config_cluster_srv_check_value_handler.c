/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> device_temp_config.o -> device_temp_config_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte device_temp_config_cluster_srv_check_value_handler(uint param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_1 == 0x10) {
    return -(2 < *param_2) & 0x87;
  }
  if (param_1 < 0x11) {
    if ((param_1 == 1) || ((param_1 == 2 || (param_1 == 0)))) {
_L0:
      bVar1 = 0;
      if ((*(short *)param_2 != -0x8000) && (400 < ((int)*(short *)param_2 + 200U & 0xffff))) {
        bVar1 = 0x87;
      }
      return bVar1;
    }
  }
  else if ((param_1 == 0x11) || (param_1 == 0x12)) goto _L0;
  return 0;
}

