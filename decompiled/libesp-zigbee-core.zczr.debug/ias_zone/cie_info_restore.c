/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> cie_info_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cie_info_restore(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ias_zone_srv_get_attr_desc(0x10);
  iVar2 = **(int **)(iVar1 + 8);
  iVar1 = (*(int **)(iVar1 + 8))[1];
  if ((iVar2 != 0 || iVar1 != 0) && ((iVar2 != -1 || (iVar1 != -1)))) {
    iVar1 = ias_zone_srv_get_attr_desc(param_1,0);
    if (**(char **)(iVar1 + 8) == '\x01') {
      iVar1 = ias_zone_srv_get_zone_ctx(param_1);
      *(undefined1 *)(iVar1 + 2) = 1;
    }
    else {
      log_write(1,"ZCL_IAS_ZONE","CIE address restored, but zone state is not enrolled");
    }
  }
  return;
}

