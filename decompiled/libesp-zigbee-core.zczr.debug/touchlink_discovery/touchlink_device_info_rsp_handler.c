/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_device_info_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_device_info_rsp_handler(int param_1)

{
  undefined3 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  
  if (param_1 == 0) {
    uVar6 = 2;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
    if ((iVar3 == 0) || (piVar4 = (int *)touchlink_transaction_get(), iVar3 != *piVar4)) {
      uVar6 = 3;
    }
    else if (*(byte *)(param_1 + 0x11) < 9) {
      iVar3 = touchlink_disc_table_find(param_1 + 2);
      if (iVar3 == 0) {
        uVar6 = 5;
      }
      else {
        uVar7 = (uint)*(byte *)(param_1 + 0x11);
        while( true ) {
          if (((int)(uint)*(byte *)(param_1 + 0x12) <= (int)(uVar7 - *(byte *)(param_1 + 0x11))) ||
             (7 < uVar7)) break;
          puVar9 = (undefined1 *)(uVar7 * 0x12 + iVar3 + 0x2a);
          iVar5 = (uVar7 - *(byte *)(param_1 + 0x11) & 0xff) * 0x12;
          puVar8 = (undefined4 *)(*(int *)(param_1 + 0x14) + iVar5);
          uVar6 = *puVar8;
          uVar1 = *(undefined3 *)(puVar8 + 1);
          uVar2 = puVar8[1];
          *puVar9 = (char)*(undefined3 *)puVar8;
          puVar9[1] = (char)((uint)uVar6 >> 8);
          puVar9[2] = (char)((uint)uVar6 >> 0x10);
          puVar9[3] = (char)((uint)uVar6 >> 0x18);
          puVar9[4] = (char)uVar1;
          puVar9[5] = (char)((uint)uVar2 >> 8);
          puVar9[6] = (char)((uint)uVar2 >> 0x10);
          puVar9[7] = (char)((uint)uVar2 >> 0x18);
          puVar9[8] = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar5 + 8);
          *(undefined2 *)(puVar9 + 10) = *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar5 + 10);
          *(undefined2 *)(puVar9 + 0xc) = *(undefined2 *)(*(int *)(param_1 + 0x14) + iVar5 + 0xc);
          puVar9[0xe] = *(undefined1 *)(*(int *)(param_1 + 0x14) + iVar5 + 0xe);
          puVar9[0xf] = *(undefined1 *)(iVar5 + *(int *)(param_1 + 0x14) + 0xf);
          *(char *)(iVar3 + 0x28) = *(char *)(iVar3 + 0x28) + '\x01';
          uVar7 = uVar7 + 1 & 0xff;
        }
        touchlink_print_disc_device();
        if (*(byte *)(param_1 + 0x12) == 0) {
          uVar6 = 0;
        }
        else if ((uint)*(byte *)(param_1 + 0x12) + (uint)*(byte *)(param_1 + 0x11) < 8) {
          iVar5 = touchlink_transaction_get();
          *(undefined1 *)(iVar5 + 0x60c) = 2;
          iVar5 = touchlink_transaction_get();
          *(int *)(iVar5 + 0x610) = iVar3;
          iVar3 = touchlink_transaction_get();
          touchlink_schedule_transaction_event(iVar3 + 0x60c);
          uVar6 = 0;
        }
        else {
          uVar6 = 0;
        }
      }
    }
    else {
      uVar6 = 2;
    }
  }
  return uVar6;
}

