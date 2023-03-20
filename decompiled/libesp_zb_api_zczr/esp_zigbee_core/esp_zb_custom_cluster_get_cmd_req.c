/*
 * Last changed at upstream commit 8f416d47159477fb2dfe72f817700bc25debb587
 * https://github.com/espressif/esp-zigbee-sdk/commit/8f416d47159477fb2dfe72f817700bc25debb587
 * Upstream date: 2023-03-20 14:23:27 +0800
 * Upstream subject: zcl: support more ZCL cluster(caef391)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_custom_cluster_get_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_custom_cluster_get_cmd_req(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  
  puVar12 = param_1 + 5;
  piVar8 = (int *)zb_buf_begin_func();
  if (*piVar8 == 0x42) {
    puVar10 = (undefined1 *)realloc(param_1,*(byte *)(piVar8 + 1) + 9);
    iVar11 = *piVar8;
    *puVar10 = (char)(short)*piVar8;
    puVar10[1] = (char)((uint)iVar11 >> 8);
    puVar10[2] = (char)((uint)iVar11 >> 0x10);
    puVar10[3] = (char)((uint)iVar11 >> 0x18);
    puVar10[4] = (char)piVar8[1];
    uVar9 = *(undefined4 *)((int)piVar8 + 5);
    puVar10[5] = (char)*(undefined2 *)((int)piVar8 + 5);
    puVar10[6] = (char)((uint)uVar9 >> 8);
    puVar10[7] = (char)((uint)uVar9 >> 0x10);
    puVar10[8] = (char)((uint)uVar9 >> 0x18);
    puVar10 = (undefined1 *)((int)piVar8 + 5);
    for (iVar11 = 1; iVar11 < (int)(uint)*(byte *)(piVar8 + 1); iVar11 = iVar11 + 1) {
      puVar12 = puVar12 + 1;
      puVar10 = puVar10 + 1;
      *puVar12 = *puVar10;
    }
    if (piVar8 == (int *)0x0) {
      uVar9 = 1;
    }
    else {
      uVar9 = 0;
    }
  }
  else {
    uVar1 = *(undefined1 *)((int)piVar8 + 1);
    uVar2 = *(undefined1 *)((int)piVar8 + 2);
    uVar3 = *(undefined1 *)((int)piVar8 + 3);
    iVar11 = piVar8[1];
    uVar4 = *(undefined1 *)((int)piVar8 + 5);
    uVar5 = *(undefined1 *)((int)piVar8 + 6);
    uVar6 = *(undefined1 *)((int)piVar8 + 7);
    iVar7 = piVar8[2];
    *param_1 = (char)*piVar8;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1[4] = (char)iVar11;
    param_1[5] = uVar4;
    param_1[6] = uVar5;
    param_1[7] = uVar6;
    param_1[8] = (char)iVar7;
    uVar9 = 0;
  }
  return uVar9;
}

