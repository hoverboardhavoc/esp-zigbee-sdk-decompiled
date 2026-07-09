/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> ias_zone_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ias_zone_cluster_srv_check_value_handler(int param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  
  if (param_1 == 0x10) {
    iVar1 = ias_zone_srv_get_zone_ctx(param_2);
    if (*(char *)(iVar1 + 2) != '\0') {
      iVar1 = ias_zone_srv_get_attr_desc(param_2,0x10);
      if ((**(int **)(iVar1 + 8) == *(int *)param_3) &&
         ((*(int **)(iVar1 + 8))[1] == *(int *)(param_3 + 4))) {
        return 0x7e;
      }
    }
  }
  else if ((param_1 == 0x13) && (*param_3 < 2)) {
    return 0x87;
  }
  return 0;
}

