/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_update_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ias_ace_zone_table_update_zone(int param_1,char *param_2)

{
  void *__dest;
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 2;
  }
  uVar1 = 2;
  if (((param_2 != (char *)0x0) && (*param_2 != -1)) && (*(short *)(param_2 + 2) != -1)) {
    if ((*(int *)(param_2 + 8) + 1U == (uint)(*(int *)(param_2 + 4) == 0)) &&
       (0xfffffffd < *(int *)(param_2 + 4) - 1U)) {
      return 2;
    }
    __dest = (void *)ias_ace_zone_table_get_zone(param_1);
    uVar1 = 2;
    if (__dest != (void *)0x0) {
      memcpy(__dest,param_2,0x1e);
      zone_table_remove_stored_zone_isra_0(*(undefined1 *)(param_1 + 5),*param_2);
      zone_table_store_zone_isra_0(*(undefined1 *)(param_1 + 5),__dest);
      uVar1 = 0;
    }
  }
  return uVar1;
}

