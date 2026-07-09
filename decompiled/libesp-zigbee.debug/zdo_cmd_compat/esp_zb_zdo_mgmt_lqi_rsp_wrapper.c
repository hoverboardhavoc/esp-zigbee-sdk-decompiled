/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_lqi_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_lqi_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  code *pcVar15;
  undefined4 uStack_18;
  void *pvStack_14;
  
  pcVar15 = (code *)*param_2;
  if (pcVar15 != (code *)0x0) {
    uStack_18 = 0;
    pvStack_14 = (void *)0x0;
    if (*param_1 == 0) {
      puVar13 = (undefined4 *)param_1[1];
      if (puVar13 == (undefined4 *)0x0) {
        pcVar11 = "result->rsp";
        uVar8 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                              ,0x19d,"esp_zb_zdo_mgmt_lqi_rsp_wrapper");
        goto _L0;
      }
      uStack_18 = *puVar13;
      if (((puVar13[1] != 0) && (*(byte *)((int)puVar13 + 3) != 0)) &&
         (pvStack_14 = calloc((uint)*(byte *)((int)puVar13 + 3),0x16), pvStack_14 != (void *)0x0)) {
        for (uVar8 = 0; pcVar11 = (char *)param_1[1], uVar8 < (byte)pcVar11[3];
            uVar8 = uVar8 + 1 & 0xff) {
_L0:
          iVar12 = uVar8 * 0x16;
          puVar14 = (undefined1 *)((int)pvStack_14 + iVar12);
          puVar9 = (undefined1 *)(*(int *)(pcVar11 + 4) + iVar12);
          uVar1 = puVar9[1];
          uVar2 = puVar9[2];
          uVar3 = puVar9[3];
          uVar4 = puVar9[4];
          uVar5 = puVar9[5];
          uVar6 = puVar9[6];
          uVar7 = puVar9[7];
          *puVar14 = *puVar9;
          puVar14[1] = uVar1;
          puVar14[2] = uVar2;
          puVar14[3] = uVar3;
          puVar14[4] = uVar4;
          puVar14[5] = uVar5;
          puVar14[6] = uVar6;
          puVar14[7] = uVar7;
          iVar10 = *(int *)(param_1[1] + 4) + iVar12;
          uVar1 = *(undefined1 *)(iVar10 + 9);
          uVar2 = *(undefined1 *)(iVar10 + 10);
          uVar3 = *(undefined1 *)(iVar10 + 0xb);
          uVar4 = *(undefined1 *)(iVar10 + 0xc);
          uVar5 = *(undefined1 *)(iVar10 + 0xd);
          uVar6 = *(undefined1 *)(iVar10 + 0xe);
          uVar7 = *(undefined1 *)(iVar10 + 0xf);
          *(undefined1 *)((int)pvStack_14 + iVar12 + 8) = *(undefined1 *)(iVar10 + 8);
          *(undefined1 *)((int)pvStack_14 + iVar12 + 9) = uVar1;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 10) = uVar2;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0xb) = uVar3;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0xc) = uVar4;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0xd) = uVar5;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0xe) = uVar6;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0xf) = uVar7;
          *(undefined2 *)((int)pvStack_14 + iVar12 + 0x10) =
               *(undefined2 *)(*(int *)(param_1[1] + 4) + iVar12 + 0x10);
          *(byte *)((int)pvStack_14 + iVar12 + 0x12) =
               *(byte *)((int)pvStack_14 + iVar12 + 0x12) & 0xfc |
               (byte)*(undefined2 *)(*(int *)(param_1[1] + 4) + iVar12 + 0x12) & 3;
          *(byte *)((int)pvStack_14 + iVar12 + 0x12) =
               (byte)((*(ushort *)(*(int *)(param_1[1] + 4) + iVar12 + 0x12) >> 2 & 3) << 2) |
               *(byte *)((int)pvStack_14 + iVar12 + 0x12) & 0xf3;
          *(byte *)((int)pvStack_14 + iVar12 + 0x12) =
               (byte)((*(ushort *)(*(int *)(param_1[1] + 4) + iVar12 + 0x12) >> 4 & 7) << 4) |
               *(byte *)((int)pvStack_14 + iVar12 + 0x12) & 0x8f;
          *(byte *)((int)pvStack_14 + iVar12 + 0x13) =
               (byte)((ushort)*(undefined2 *)(*(int *)(param_1[1] + 4) + iVar12 + 0x12) >> 8) & 3;
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0x14) =
               *(undefined1 *)(*(int *)(param_1[1] + 4) + iVar12 + 0x14);
          *(undefined1 *)((int)pvStack_14 + iVar12 + 0x15) =
               *(undefined1 *)(iVar12 + *(int *)(param_1[1] + 4) + 0x15);
        }
      }
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar15)(&uStack_18,param_2[1]);
    if (pvStack_14 != (void *)0x0) {
      free(pvStack_14);
    }
  }
  free(param_2);
  return;
}

