/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> ezb_active_scan_result_to_esp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_active_scan_result_to_esp(int param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  
  *param_2 = *(undefined2 *)(param_1 + 2);
  *(byte *)(param_2 + 1) = (byte)*(undefined2 *)(param_1 + 0x10) & 1;
  uVar1 = *(undefined1 *)(param_1 + 5);
  uVar2 = *(undefined1 *)(param_1 + 6);
  uVar3 = *(undefined1 *)(param_1 + 7);
  uVar4 = *(undefined1 *)(param_1 + 8);
  uVar5 = *(undefined1 *)(param_1 + 9);
  uVar6 = *(undefined1 *)(param_1 + 10);
  uVar7 = *(undefined1 *)(param_1 + 0xb);
  *(undefined1 *)((int)param_2 + 3) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(param_2 + 2) = uVar1;
  *(undefined1 *)((int)param_2 + 5) = uVar2;
  *(undefined1 *)(param_2 + 3) = uVar3;
  *(undefined1 *)((int)param_2 + 7) = uVar4;
  *(undefined1 *)(param_2 + 4) = uVar5;
  *(undefined1 *)((int)param_2 + 9) = uVar6;
  *(undefined1 *)(param_2 + 5) = uVar7;
  *(undefined1 *)((int)param_2 + 0xb) = *(undefined1 *)(param_1 + 0xd);
  *(byte *)(param_2 + 6) = (byte)(*(ushort *)(param_1 + 0x10) >> 1) & 1;
  *(byte *)((int)param_2 + 0xd) = (byte)(*(ushort *)(param_1 + 0x10) >> 2) & 1;
  return;
}

