/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_remove_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cluster_remove_attr_desc(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  iVar1 = af_device_desc_is_registered();
  if (iVar1 == 0) {
    if (param_1 == 0) {
      iVar1 = 0;
    }
    else {
      puVar2 = (ushort *)(param_1 + 0xc);
      iVar1 = *(int *)(param_1 + 0xc);
      while ((iVar1 != 0 &&
             (((puVar3 = *(ushort **)puVar2, puVar3 == (ushort *)0x0 || (*puVar3 != param_2)) ||
              (puVar3[2] != param_3))))) {
        puVar2 = puVar3 + 6;
        iVar1 = *(int *)(puVar3 + 6);
      }
      if (puVar2 == (ushort *)0x0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)puVar2;
        if (iVar1 != 0) {
          *(undefined4 *)puVar2 = *(undefined4 *)(iVar1 + 0xc);
          *(undefined4 *)(iVar1 + 0xc) = 0;
        }
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

