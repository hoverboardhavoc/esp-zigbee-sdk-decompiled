/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_zone_table_add_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ias_ace_zone_table_add_zone(int *param_1,char *param_2)

{
  int iVar1;
  void *__dest;
  
  if ((((param_1 != (int *)0x0) && (param_2 != (char *)0x0)) && (*param_2 != -1)) &&
     (*(short *)(param_2 + 2) != -1)) {
    if (((*(int *)(param_2 + 4) != 0 || *(int *)(param_2 + 8) != 0) &&
        ((*(int *)(param_2 + 4) != -1 || (*(int *)(param_2 + 8) != -1)))) &&
       (iVar1 = ias_ace_zone_table_get_zone(param_1), iVar1 == 0)) {
      for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 1); iVar1 = iVar1 + 1) {
        __dest = (void *)(*param_1 + iVar1 * 0x1e);
        if (*(short *)((int)__dest + 2) == -1) {
          memcpy(__dest,param_2,0x1e);
          zone_table_store_zone(*(undefined1 *)((int)param_1 + 5),__dest);
          return 0;
        }
      }
    }
  }
  return 2;
}

