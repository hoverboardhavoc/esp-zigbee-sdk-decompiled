/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_list_update_cluster(ushort *param_1,int param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  
  if (param_1 == (ushort *)0x0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 2;
    if ((param_2 != 0) && (*(ushort *)(param_2 + -0xc) == param_3)) {
      iVar2 = *(int *)param_1;
      while (iVar2 != 0) {
        puVar3 = *(ushort **)param_1;
        if ((*puVar3 == param_3) && ((byte)puVar3[1] == param_4)) {
          *(char *)(param_2 + -10) = (char)param_4;
          uVar1 = *(undefined4 *)(puVar3 + 4);
          *(ushort *)(param_2 + -8) = puVar3[2];
          *(undefined4 *)(param_2 + -4) = uVar1;
          *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)param_1 + 0x10);
          ezb_zcl_free_cluster_desc(*(undefined4 *)param_1);
          *(int *)param_1 = param_2 + -0xc;
          break;
        }
        param_1 = puVar3 + 8;
        iVar2 = *(int *)(puVar3 + 8);
      }
      uVar1 = 0;
    }
  }
  esp_zigbee_err_to_esp(uVar1);
  return;
}

