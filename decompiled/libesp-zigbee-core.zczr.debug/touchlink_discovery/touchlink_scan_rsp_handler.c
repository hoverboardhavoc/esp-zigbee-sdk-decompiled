/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_discovery.o -> touchlink_scan_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_scan_rsp_handler(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 uVar5;
  ushort uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  
  if (param_1 == 0) {
    uVar8 = 2;
  }
  else {
    iVar4 = *(int *)(param_1 + 0xc);
    if ((iVar4 == 0) || (piVar7 = (int *)touchlink_transaction_get(), iVar4 != *piVar7)) {
      uVar8 = 3;
    }
    else {
      uVar1 = *(ushort *)(param_1 + 0x16);
      uVar6 = touchlink_get_key_bitmask();
      if ((uVar1 & uVar6) == 0) {
        uVar8 = 2;
      }
      else {
        iVar4 = touchlink_disc_table_find(param_1 + 2);
        if (iVar4 == 0) {
          puVar9 = (undefined4 *)touchlink_disc_table_get_entry();
          if (puVar9 == (undefined4 *)0x0) {
            uVar8 = 1;
          }
          else {
            uVar8 = *(undefined4 *)(param_1 + 2);
            uVar2 = *(undefined2 *)(param_1 + 6);
            uVar3 = *(undefined4 *)(param_1 + 6);
            *(char *)((int)puVar9 + 0xf) = (char)*(undefined2 *)(param_1 + 2);
            *(char *)(puVar9 + 4) = (char)((uint)uVar8 >> 8);
            *(char *)((int)puVar9 + 0x11) = (char)((uint)uVar8 >> 0x10);
            *(char *)((int)puVar9 + 0x12) = (char)((uint)uVar8 >> 0x18);
            *(char *)((int)puVar9 + 0x13) = (char)uVar2;
            *(char *)(puVar9 + 5) = (char)((uint)uVar3 >> 8);
            *(char *)((int)puVar9 + 0x15) = (char)((uint)uVar3 >> 0x10);
            *(char *)((int)puVar9 + 0x16) = (char)((uint)uVar3 >> 0x18);
            uVar8 = *(undefined4 *)(param_1 + 0x19);
            uVar2 = *(undefined2 *)(param_1 + 0x1d);
            uVar3 = *(undefined4 *)(param_1 + 0x1d);
            *(char *)((int)puVar9 + 0x17) = (char)*(undefined2 *)(param_1 + 0x19);
            *(char *)(puVar9 + 6) = (char)((uint)uVar8 >> 8);
            *(char *)((int)puVar9 + 0x19) = (char)((uint)uVar8 >> 0x10);
            *(char *)((int)puVar9 + 0x1a) = (char)((uint)uVar8 >> 0x18);
            *(char *)((int)puVar9 + 0x1b) = (char)uVar2;
            *(char *)(puVar9 + 7) = (char)((uint)uVar3 >> 8);
            *(char *)((int)puVar9 + 0x1d) = (char)((uint)uVar3 >> 0x10);
            *(char *)((int)puVar9 + 0x1e) = (char)((uint)uVar3 >> 0x18);
            *puVar9 = *(undefined4 *)(param_1 + 0xc);
            *(ushort *)(puVar9 + 2) = (ushort)*(byte *)(param_1 + 0x14);
            *(undefined1 *)((int)puVar9 + 10) = *(undefined1 *)(param_1 + 0x15);
            *(undefined2 *)(puVar9 + 3) = *(undefined2 *)(param_1 + 0x16);
            *(undefined1 *)((int)puVar9 + 0xe) = *(undefined1 *)(param_1 + 0x18);
            puVar9[1] = *(undefined4 *)(param_1 + 0x10);
            *(undefined1 *)((int)puVar9 + 0x1f) = *(undefined1 *)(param_1 + 0x21);
            *(undefined1 *)(puVar9 + 8) = *(undefined1 *)(param_1 + 0x22);
            uVar5 = touchlink_get_intrp_channel();
            *(undefined1 *)((int)puVar9 + 0x21) = uVar5;
            *(undefined2 *)((int)puVar9 + 0x22) = *(undefined2 *)(param_1 + 0x24);
            *(undefined2 *)(puVar9 + 9) = *(undefined2 *)(param_1 + 0x26);
            *(undefined1 *)((int)puVar9 + 0x26) = *(undefined1 *)(param_1 + 0x28);
            *(undefined1 *)((int)puVar9 + 0x27) = *(undefined1 *)(param_1 + 0x29);
            *(undefined1 *)(puVar9 + 0x2f) = *(undefined1 *)(param_1 + 0xb);
            if ((*(char *)(param_1 + 0x28) == '\x01') && (*(char *)(puVar9 + 10) == '\0')) {
              uVar8 = *(undefined4 *)(param_1 + 2);
              uVar2 = *(undefined2 *)(param_1 + 6);
              uVar3 = *(undefined4 *)(param_1 + 6);
              *(undefined2 *)((int)puVar9 + 0x2a) = *(undefined2 *)(param_1 + 2);
              *(short *)(puVar9 + 0xb) = (short)((uint)uVar8 >> 0x10);
              *(undefined2 *)((int)puVar9 + 0x2e) = uVar2;
              *(short *)(puVar9 + 0xc) = (short)((uint)uVar3 >> 0x10);
              *(undefined1 *)((int)puVar9 + 0x32) = *(undefined1 *)(param_1 + 0x2a);
              *(undefined2 *)(puVar9 + 0xd) = *(undefined2 *)(param_1 + 0x2c);
              *(undefined2 *)((int)puVar9 + 0x36) = *(undefined2 *)(param_1 + 0x2e);
              *(undefined1 *)(puVar9 + 0xe) = *(undefined1 *)(param_1 + 0x30);
              *(undefined1 *)((int)puVar9 + 0x39) = *(undefined1 *)(param_1 + 0x31);
              *(undefined1 *)(puVar9 + 10) = 1;
            }
            touchlink_print_disc_device();
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 3;
        }
      }
    }
  }
  return uVar8;
}

