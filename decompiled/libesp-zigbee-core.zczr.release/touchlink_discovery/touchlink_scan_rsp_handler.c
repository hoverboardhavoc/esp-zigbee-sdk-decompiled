/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_discovery.o -> touchlink_scan_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 touchlink_scan_rsp_handler(int param_1)

{
  char cVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 uVar7;
  ushort uVar8;
  int *piVar9;
  undefined4 *puVar10;
  
  if (param_1 == 0) {
    return 2;
  }
  iVar6 = *(int *)(param_1 + 0xc);
  if ((iVar6 != 0) && (piVar9 = (int *)touchlink_transaction_get(), iVar6 == *piVar9)) {
    uVar2 = *(ushort *)(param_1 + 0x16);
    uVar8 = touchlink_get_key_bitmask();
    if ((uVar2 & uVar8) == 0) {
      return 2;
    }
    iVar6 = touchlink_disc_table_find(param_1 + 2);
    if (iVar6 == 0) {
      puVar10 = (undefined4 *)touchlink_disc_table_get_entry();
      if (puVar10 == (undefined4 *)0x0) {
        return 1;
      }
      uVar3 = *(undefined2 *)(param_1 + 6);
      uVar4 = *(undefined4 *)(param_1 + 2);
      uVar5 = *(undefined4 *)(param_1 + 6);
      *(char *)((int)puVar10 + 0xf) = (char)*(undefined2 *)(param_1 + 2);
      *(char *)(puVar10 + 4) = (char)((uint)uVar4 >> 8);
      *(char *)((int)puVar10 + 0x12) = (char)((uint)uVar4 >> 0x18);
      *(char *)(puVar10 + 5) = (char)((uint)uVar5 >> 8);
      *(char *)((int)puVar10 + 0x11) = (char)((uint)uVar4 >> 0x10);
      *(char *)((int)puVar10 + 0x13) = (char)uVar3;
      *(char *)((int)puVar10 + 0x15) = (char)((uint)uVar5 >> 0x10);
      *(char *)((int)puVar10 + 0x16) = (char)((uint)uVar5 >> 0x18);
      uVar3 = *(undefined2 *)(param_1 + 0x1d);
      uVar4 = *(undefined4 *)(param_1 + 0x19);
      uVar5 = *(undefined4 *)(param_1 + 0x1d);
      *(char *)((int)puVar10 + 0x17) = (char)*(undefined2 *)(param_1 + 0x19);
      *(char *)(puVar10 + 6) = (char)((uint)uVar4 >> 8);
      *(char *)((int)puVar10 + 0x1a) = (char)((uint)uVar4 >> 0x18);
      *(char *)(puVar10 + 7) = (char)((uint)uVar5 >> 8);
      *(char *)((int)puVar10 + 0x19) = (char)((uint)uVar4 >> 0x10);
      *(char *)((int)puVar10 + 0x1b) = (char)uVar3;
      *(char *)((int)puVar10 + 0x1d) = (char)((uint)uVar5 >> 0x10);
      *(char *)((int)puVar10 + 0x1e) = (char)((uint)uVar5 >> 0x18);
      *puVar10 = *(undefined4 *)(param_1 + 0xc);
      *(ushort *)(puVar10 + 2) = (ushort)*(byte *)(param_1 + 0x14);
      *(undefined1 *)((int)puVar10 + 10) = *(undefined1 *)(param_1 + 0x15);
      *(undefined2 *)(puVar10 + 3) = *(undefined2 *)(param_1 + 0x16);
      *(undefined1 *)((int)puVar10 + 0xe) = *(undefined1 *)(param_1 + 0x18);
      puVar10[1] = *(undefined4 *)(param_1 + 0x10);
      *(undefined1 *)((int)puVar10 + 0x1f) = *(undefined1 *)(param_1 + 0x21);
      *(undefined1 *)(puVar10 + 8) = *(undefined1 *)(param_1 + 0x22);
      uVar7 = touchlink_get_intrp_channel(1);
      *(undefined1 *)((int)puVar10 + 0x21) = uVar7;
      *(undefined2 *)((int)puVar10 + 0x22) = *(undefined2 *)(param_1 + 0x24);
      *(undefined2 *)(puVar10 + 9) = *(undefined2 *)(param_1 + 0x26);
      cVar1 = *(char *)(param_1 + 0x28);
      *(char *)((int)puVar10 + 0x26) = cVar1;
      *(undefined1 *)((int)puVar10 + 0x27) = *(undefined1 *)(param_1 + 0x29);
      *(undefined1 *)(puVar10 + 0x2f) = *(undefined1 *)(param_1 + 0xb);
      if ((cVar1 == '\x01') && (*(char *)(puVar10 + 10) == '\0')) {
        uVar3 = *(undefined2 *)(param_1 + 6);
        uVar4 = *(undefined4 *)(param_1 + 2);
        uVar5 = *(undefined4 *)(param_1 + 6);
        *(undefined2 *)((int)puVar10 + 0x2a) = *(undefined2 *)(param_1 + 2);
        *(short *)(puVar10 + 0xb) = (short)((uint)uVar4 >> 0x10);
        *(undefined2 *)((int)puVar10 + 0x2e) = uVar3;
        *(short *)(puVar10 + 0xc) = (short)((uint)uVar5 >> 0x10);
        *(undefined1 *)((int)puVar10 + 0x32) = *(undefined1 *)(param_1 + 0x2a);
        *(undefined2 *)(puVar10 + 0xd) = *(undefined2 *)(param_1 + 0x2c);
        *(undefined2 *)((int)puVar10 + 0x36) = *(undefined2 *)(param_1 + 0x2e);
        *(undefined1 *)(puVar10 + 0xe) = *(undefined1 *)(param_1 + 0x30);
        uVar7 = *(undefined1 *)(param_1 + 0x31);
        *(undefined1 *)(puVar10 + 10) = 1;
        *(undefined1 *)((int)puVar10 + 0x39) = uVar7;
      }
      touchlink_print_disc_device();
      return 0;
    }
  }
  return 3;
}

