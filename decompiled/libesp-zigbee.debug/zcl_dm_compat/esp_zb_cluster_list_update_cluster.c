/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_list_update_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_list_update_cluster(int param_1,ushort *param_2,uint param_3,uint param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  
  if (param_1 != 0) {
    param_1 = param_1 + -4;
  }
  if (param_2 != (ushort *)0x0) {
    param_2 = param_2 + -6;
  }
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == (ushort *)0x0) {
    uVar2 = 2;
  }
  else if (*param_2 == param_3) {
    puVar1 = (ushort *)(param_1 + 4);
    iVar3 = *(int *)(param_1 + 4);
    while (iVar3 != 0) {
      puVar4 = *(ushort **)puVar1;
      if ((*puVar4 == param_3) && ((byte)puVar4[1] == param_4)) {
        *param_2 = *puVar4;
        *(undefined1 *)(param_2 + 1) = *(undefined1 *)(*(int *)puVar1 + 2);
        param_2[2] = *(ushort *)(*(int *)puVar1 + 4);
        *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*(int *)puVar1 + 8);
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(*(int *)puVar1 + 0x10);
        ezb_zcl_free_cluster_desc(*(undefined4 *)puVar1);
        *(ushort **)puVar1 = param_2;
        uVar2 = 0;
        goto _L0;
      }
      puVar1 = puVar4 + 8;
      iVar3 = *(int *)(puVar4 + 8);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
_L0:
  esp_zigbee_err_to_esp(uVar2);
  return;
}

