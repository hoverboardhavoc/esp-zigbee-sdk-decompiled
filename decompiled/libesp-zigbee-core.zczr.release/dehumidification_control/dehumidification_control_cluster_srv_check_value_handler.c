/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> dehumidification_control.o -> dehumidification_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool dehumidification_control_cluster_srv_check_value_handler
               (uint param_1,undefined4 param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == 0x13) {
    bVar1 = *param_3 - 2 < 0x13;
_L0:
    bVar1 = (bool)(bVar1 ^ 1);
  }
  else {
    if (param_1 < 0x14) {
      if (param_1 == 1) {
        iVar2 = zcl_get_attr_desc(param_2,0x203,1,0x14,0);
        if ((iVar2 != 0) && (*(byte **)(iVar2 + 8) != (byte *)0x0)) {
          return **(byte **)(iVar2 + 8) < *param_3;
        }
      }
      else if (param_1 == 0x10) {
        bVar1 = *param_3 - 0x1e < 0x47;
        goto _L0;
      }
    }
    else if (param_1 == 0x14) {
      bVar1 = *param_3 - 0x14 < 0x51;
      goto _L0;
    }
    bVar1 = false;
  }
  return bVar1;
}

