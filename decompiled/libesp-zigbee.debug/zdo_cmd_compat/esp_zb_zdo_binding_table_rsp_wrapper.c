/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_binding_table_rsp_wrapper
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_binding_table_rsp_wrapper
               (int *param_1,undefined4 *param_2,int param_3,void *param_4)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined1 uVar15;
  uint uVar16;
  uint extraout_a1;
  uint uVar17;
  undefined1 *puVar18;
  char *pcVar19;
  undefined1 *puVar20;
  code *pcVar21;
  undefined4 uStack_18;
  void *pvStack_14;
  
  pcVar21 = (code *)*param_2;
  uStack_18 = 0;
  pvStack_14 = (void *)0x0;
  if (pcVar21 != (code *)0x0) {
    if (*param_1 == 0) {
      puVar20 = (undefined1 *)param_1[1];
      if (puVar20 == (undefined1 *)0x0) {
        pcVar19 = "result->rsp";
        uVar16 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/zdo_cmd_compat.c"
                               ,0x1ca,"esp_zb_zdo_binding_table_rsp_wrapper");
        uVar17 = extraout_a1;
        goto _L0;
      }
      bVar1 = puVar20[3];
      uStack_18 = CONCAT13(bVar1,CONCAT12(puVar20[1],CONCAT11(puVar20[2],*puVar20)));
      if ((*(int *)(puVar20 + 4) != 0) && (bVar1 != 0)) {
        pvStack_14 = calloc((uint)bVar1,0x1c);
        if (pvStack_14 != (void *)0x0) {
          uVar16 = 0;
          while (uVar16 < *(byte *)(param_1[1] + 3)) {
            puVar18 = (undefined1 *)((int)pvStack_14 + uVar16 * 0x1c);
            param_3 = uVar16 * 0x18;
            puVar20 = (undefined1 *)(*(int *)(param_1[1] + 4) + param_3);
            uVar9 = puVar20[1];
            uVar10 = puVar20[2];
            uVar11 = puVar20[3];
            uVar12 = puVar20[4];
            uVar13 = puVar20[5];
            uVar14 = puVar20[6];
            uVar15 = puVar20[7];
            *puVar18 = *puVar20;
            puVar18[1] = uVar9;
            puVar18[2] = uVar10;
            puVar18[3] = uVar11;
            puVar18[4] = uVar12;
            puVar18[5] = uVar13;
            puVar18[6] = uVar14;
            puVar18[7] = uVar15;
            puVar20 = (undefined1 *)(uVar16 * 0x1c + (int)pvStack_14);
            puVar20[8] = *(undefined1 *)(*(int *)(param_1[1] + 4) + param_3 + 8);
            *(undefined2 *)(puVar20 + 10) = *(undefined2 *)(*(int *)(param_1[1] + 4) + param_3 + 10)
            ;
            puVar20[0xc] = *(undefined1 *)(*(int *)(param_1[1] + 4) + param_3 + 0xc);
            pcVar19 = (char *)(*(int *)(param_1[1] + 4) + param_3);
            uVar17 = uVar16;
            param_4 = pvStack_14;
            if (pcVar19[0xc] == '\x01') {
              *(undefined2 *)(puVar20 + 0xe) = *(undefined2 *)(pcVar19 + 0xe);
            }
            else {
_L0:
              cVar2 = pcVar19[0xf];
              cVar3 = pcVar19[0x10];
              cVar4 = pcVar19[0x11];
              cVar5 = pcVar19[0x12];
              cVar6 = pcVar19[0x13];
              cVar7 = pcVar19[0x14];
              cVar8 = pcVar19[0x15];
              puVar20[0xe] = pcVar19[0xe];
              puVar20[0xf] = cVar2;
              puVar20[0x10] = cVar3;
              puVar20[0x11] = cVar4;
              puVar20[0x12] = cVar5;
              puVar20[0x13] = cVar6;
              puVar20[0x14] = cVar7;
              puVar20[0x15] = cVar8;
            }
            puVar20[0x16] = *(undefined1 *)(*(int *)(param_1[1] + 4) + param_3 + 0x16);
            if ((int)uVar17 < (int)(*(byte *)(param_1[1] + 3) - 1)) {
              param_4 = (void *)((uVar16 + 1) * 0x1c + (int)param_4);
            }
            else {
              param_4 = (void *)0x0;
            }
            *(void **)(puVar20 + 0x18) = param_4;
            uVar16 = uVar17 + 1 & 0xff;
          }
        }
      }
    }
    else {
      uStack_18 = 0x85;
    }
    (*pcVar21)(&uStack_18,param_2[1]);
  }
  if (pvStack_14 != (void *)0x0) {
    free(pvStack_14);
  }
  free(param_2);
  return;
}

