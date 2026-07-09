/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_refresh_stored_zones
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zone_table_refresh_stored_zones(uint param_1)

{
  int iVar1;
  int *piVar2;
  byte abStack_34 [30];
  undefined2 uStack_16;
  char cStack_14;
  
  uStack_16 = 0;
  cStack_14 = '\0';
  ds_ias_zone_info_itor_read(abStack_34);
  while (cStack_14 == '\0') {
    if (abStack_34[0] == param_1) {
      ds_ias_zone_info_delete(abStack_34);
      ds_ias_zone_info_itor_read(abStack_34);
    }
    else {
      ds_ias_zone_info_next(abStack_34);
    }
  }
  piVar2 = (int *)ezb_zcl_ias_ace_get_zone_table(param_1);
  iVar1 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(piVar2 + 1) <= iVar1) {
      return;
    }
    if (*(short *)(*piVar2 + iVar1 * 0x1e + 2) == -1) break;
    zone_table_store_zone(param_1);
    iVar1 = iVar1 + 1;
  }
  return;
}

