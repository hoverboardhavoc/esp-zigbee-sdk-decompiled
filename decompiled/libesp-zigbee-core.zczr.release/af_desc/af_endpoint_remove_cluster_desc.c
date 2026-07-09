/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_remove_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int af_endpoint_remove_cluster_desc(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  iVar1 = af_device_desc_is_registered();
  if (iVar1 == 0) {
    if (param_1 != 0) {
      puVar2 = (ushort *)(param_1 + 4);
      param_1 = *(int *)(param_1 + 4);
      while (param_1 != 0) {
        puVar3 = *(ushort **)puVar2;
        if ((((puVar3 != (ushort *)0x0) && (*puVar3 == param_2)) && ((byte)puVar3[1] == param_3)) &&
           (puVar3[2] == param_4)) {
          *(undefined4 *)puVar2 = *(undefined4 *)(param_1 + 0x10);
          *(undefined4 *)(param_1 + 0x10) = 0;
          return param_1;
        }
        puVar2 = puVar3 + 8;
        param_1 = *(int *)(puVar3 + 8);
      }
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

