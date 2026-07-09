/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_lqi_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_lqi_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  undefined4 uStack_38;
  void *pvStack_34;
  
  pcVar6 = (code *)*param_2;
  if (pcVar6 != (code *)0x0) {
    uStack_38 = 0;
    pvStack_34 = (void *)0x0;
    if (*param_1 == 0) {
      puVar4 = (undefined4 *)param_1[1];
      if (puVar4 == (undefined4 *)0x0) {
        __assert_func(0,0,0,0);
      }
      uStack_38 = *puVar4;
      if ((puVar4[1] != 0) && (*(byte *)((int)puVar4 + 3) != 0)) {
        pvStack_34 = calloc((uint)*(byte *)((int)puVar4 + 3),0x16);
        uVar7 = 0;
        if (pvStack_34 != (void *)0x0) {
          for (; uVar7 < *(byte *)((int)puVar4 + 3); uVar7 = uVar7 + 1 & 0xff) {
            iVar8 = uVar7 * 0x16;
            memcpy((void *)((int)pvStack_34 + iVar8),(void *)(puVar4[1] + iVar8),8);
            pvVar3 = pvStack_34;
            memcpy((void *)((int)pvStack_34 + iVar8 + 8),
                   (void *)(*(int *)(param_1[1] + 4) + iVar8 + 8),8);
            puVar4 = (undefined4 *)param_1[1];
            iVar5 = puVar4[1] + iVar8;
            uVar1 = *(undefined2 *)(iVar5 + 0x12);
            uVar2 = *(undefined2 *)(iVar5 + 0x12);
            *(undefined2 *)((int)pvVar3 + iVar8 + 0x10) = *(undefined2 *)(iVar5 + 0x10);
            *(byte *)((int)pvVar3 + iVar8 + 0x12) =
                 *(byte *)((int)pvVar3 + iVar8 + 0x12) & 0x80 | (byte)uVar1 & 3 | (byte)uVar2 & 0xc
                 | (byte)*(undefined2 *)(iVar5 + 0x12) & 0x70;
            *(byte *)((int)pvVar3 + iVar8 + 0x13) =
                 (byte)((ushort)*(undefined2 *)(iVar5 + 0x12) >> 8) & 3;
            *(undefined1 *)((int)pvVar3 + iVar8 + 0x14) = *(undefined1 *)(iVar5 + 0x14);
            *(undefined1 *)((int)pvVar3 + iVar8 + 0x15) = *(undefined1 *)(iVar5 + 0x15);
          }
        }
      }
    }
    else {
      uStack_38 = 0x85;
    }
    (*pcVar6)(&uStack_38,param_2[1]);
    if (pvStack_34 != (void *)0x0) {
      free(pvStack_34);
    }
  }
  free(param_2);
  return;
}

