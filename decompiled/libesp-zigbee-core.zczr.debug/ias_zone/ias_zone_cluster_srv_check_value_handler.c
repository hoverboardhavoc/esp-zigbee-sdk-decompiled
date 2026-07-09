/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_zone_cluster_srv_check_value_handler(int param_1,undefined4 param_2,byte *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0x10) {
    iVar2 = ias_zone_srv_get_zone_ctx(param_2);
    if (*(char *)(iVar2 + 2) == '\0') {
      uVar1 = 0;
    }
    else {
      iVar2 = ias_zone_srv_get_attr_desc(param_2,0x10);
      if ((*(int *)param_3 == **(int **)(iVar2 + 8)) &&
         (*(int *)(param_3 + 4) == (*(int **)(iVar2 + 8))[1])) {
        uVar1 = 0x7e;
      }
      else {
        uVar1 = 0;
      }
    }
  }
  else if (param_1 == 0x13) {
    if (*param_3 < 2) {
      uVar1 = 0x87;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

