/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_device_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_device_info_rsp_handler(int param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint *puVar9;
  undefined1 *puVar10;
  int iVar11;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar6 = *(int *)(param_1 + 0xc);
  if ((iVar6 == 0) || (piVar8 = (int *)touchlink_transaction_get(), iVar6 != *piVar8)) {
    uVar7 = 3;
  }
  else {
    uVar7 = 2;
    if (*(byte *)(param_1 + 0x11) < 9) {
      iVar6 = touchlink_disc_table_find(param_1 + 2);
      uVar7 = 5;
      if (iVar6 != 0) {
        bVar1 = *(byte *)(param_1 + 0x11);
        bVar2 = *(byte *)(param_1 + 0x12);
        puVar10 = (undefined1 *)((uint)bVar1 * 0x12 + 0x2a + iVar6);
        for (iVar11 = 0; (iVar11 < (int)(uint)bVar2 && (((uint)bVar1 + iVar11 & 0xff) < 8));
            iVar11 = iVar11 + 1) {
          puVar9 = (uint *)(*(int *)(param_1 + 0x14) + iVar11 * 0x12);
          uVar3 = *puVar9;
          uVar5 = puVar9[1];
          uVar4 = puVar9[1];
          *puVar10 = (char)(int3)*puVar9;
          puVar10[1] = (char)(uVar3 >> 8);
          uVar7 = uVar3 >> 0x10;
          puVar10[3] = (char)(uVar3 >> 0x18);
          puVar10[5] = (char)(uVar4 >> 8);
          puVar10[2] = (char)(uVar3 >> 0x10);
          puVar10[4] = (char)(int3)uVar5;
          puVar10[6] = (char)(uVar4 >> 0x10);
          puVar10[7] = (char)(uVar4 >> 0x18);
          puVar10[8] = (char)puVar9[2];
          *(undefined2 *)(puVar10 + 10) = *(undefined2 *)((int)puVar9 + 10);
          *(short *)(puVar10 + 0xc) = (short)puVar9[3];
          puVar10[0xe] = *(undefined1 *)((int)puVar9 + 0xe);
          puVar10[0xf] = *(undefined1 *)((int)puVar9 + 0xf);
          *(char *)(iVar6 + 0x28) = *(char *)(iVar6 + 0x28) + '\x01';
          puVar10 = puVar10 + 0x12;
        }
        touchlink_print_disc_device(uVar7);
        if ((*(byte *)(param_1 + 0x12) != 0) &&
           ((uint)*(byte *)(param_1 + 0x11) + (uint)*(byte *)(param_1 + 0x12) < 8)) {
          iVar11 = touchlink_transaction_get();
          *(undefined1 *)(iVar11 + 0x60c) = 2;
          iVar11 = touchlink_transaction_get();
          *(int *)(iVar11 + 0x610) = iVar6;
          iVar6 = touchlink_transaction_get();
          touchlink_schedule_transaction_event(iVar6 + 0x60c);
        }
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}

