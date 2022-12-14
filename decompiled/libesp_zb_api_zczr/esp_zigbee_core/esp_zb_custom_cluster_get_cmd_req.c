/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_custom_cluster_get_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool esp_zb_custom_cluster_get_cmd_req(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  
  puVar12 = param_1 + 5;
  piVar9 = (int *)zb_buf_begin_func();
  if (*piVar9 == 0x42) {
    puVar10 = (undefined1 *)realloc(param_1,*(byte *)(piVar9 + 1) + 9);
    iVar11 = *piVar9;
    *puVar10 = (char)(short)*piVar9;
    puVar10[1] = (char)((uint)iVar11 >> 8);
    puVar10[2] = (char)((uint)iVar11 >> 0x10);
    puVar10[3] = (char)((uint)iVar11 >> 0x18);
    puVar10[4] = (char)piVar9[1];
    uVar7 = *(undefined4 *)((int)piVar9 + 5);
    puVar10[5] = (char)*(undefined2 *)((int)piVar9 + 5);
    puVar10[6] = (char)((uint)uVar7 >> 8);
    puVar10[7] = (char)((uint)uVar7 >> 0x10);
    puVar10[8] = (char)((uint)uVar7 >> 0x18);
    puVar10 = (undefined1 *)((int)piVar9 + 5);
    for (iVar11 = 1; iVar11 < (int)(uint)*(byte *)(piVar9 + 1); iVar11 = iVar11 + 1) {
      puVar12 = puVar12 + 1;
      puVar10 = puVar10 + 1;
      *puVar12 = *puVar10;
    }
  }
  else {
    uVar1 = *(undefined1 *)((int)piVar9 + 1);
    uVar2 = *(undefined1 *)((int)piVar9 + 2);
    uVar3 = *(undefined1 *)((int)piVar9 + 3);
    iVar11 = piVar9[1];
    uVar4 = *(undefined1 *)((int)piVar9 + 5);
    uVar5 = *(undefined1 *)((int)piVar9 + 6);
    uVar6 = *(undefined1 *)((int)piVar9 + 7);
    iVar8 = piVar9[2];
    *param_1 = (char)*piVar9;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    param_1[4] = (char)iVar11;
    param_1[5] = uVar4;
    param_1[6] = uVar5;
    param_1[7] = uVar6;
    param_1[8] = (char)iVar8;
  }
  return piVar9 == (int *)0x0;
}

