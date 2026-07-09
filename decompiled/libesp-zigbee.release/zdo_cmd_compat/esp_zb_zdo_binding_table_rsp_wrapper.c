/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_binding_table_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_binding_table_rsp_wrapper(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  char cVar2;
  void *pvVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  undefined4 uStack_48;
  void *pvStack_44;
  
  pcVar8 = (code *)*param_2;
  uStack_48 = 0;
  pvStack_44 = (void *)0x0;
  if (pcVar8 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar4 = (undefined1 *)param_1[1];
      if (puVar4 == (undefined1 *)0x0) {
        __assert_func(0,0,0,0);
      }
      bVar1 = puVar4[3];
      uStack_48 = CONCAT13(bVar1,CONCAT12(puVar4[1],CONCAT11(puVar4[2],*puVar4)));
      if ((*(int *)(puVar4 + 4) != 0) && (bVar1 != 0)) {
        pvStack_44 = calloc((uint)bVar1,0x1c);
        if (pvStack_44 != (void *)0x0) {
          uVar5 = 0;
          do {
            iVar7 = uVar5 * 0x1c;
            iVar9 = uVar5 * 0x18;
            memcpy((void *)((int)pvStack_44 + iVar7),(void *)(*(int *)(puVar4 + 4) + iVar9),8);
            pvVar3 = pvStack_44;
            iVar6 = *(int *)(param_1[1] + 4) + iVar9;
            *(undefined1 *)((int)pvStack_44 + iVar7 + 8) = *(undefined1 *)(iVar6 + 8);
            *(undefined2 *)((int)pvStack_44 + iVar7 + 10) = *(undefined2 *)(iVar6 + 10);
            cVar2 = *(char *)(iVar6 + 0xc);
            *(char *)((int)pvStack_44 + iVar7 + 0xc) = cVar2;
            if (cVar2 == '\x01') {
              *(undefined2 *)((int)pvStack_44 + iVar7 + 0xe) = *(undefined2 *)(iVar6 + 0xe);
            }
            else {
              memcpy((void *)((int)pvStack_44 + iVar7 + 0xe),(void *)(iVar6 + 0xe),8);
            }
            puVar4 = (undefined1 *)param_1[1];
            iVar6 = 0;
            *(undefined1 *)((int)pvVar3 + iVar7 + 0x16) =
                 *(undefined1 *)(*(int *)(puVar4 + 4) + iVar9 + 0x16);
            bVar1 = puVar4[3];
            if ((int)uVar5 < (int)(bVar1 - 1)) {
              iVar6 = (int)pvVar3 + iVar7 + 0x1c;
            }
            *(int *)((int)pvVar3 + iVar7 + 0x18) = iVar6;
            uVar5 = uVar5 + 1 & 0xff;
          } while (uVar5 < bVar1);
        }
      }
    }
    else {
      uStack_48 = 0x85;
    }
    (*pcVar8)(&uStack_48,param_2[1]);
  }
  if (pvStack_44 != (void *)0x0) {
    free(pvStack_44);
  }
  free(param_2);
  return;
}

