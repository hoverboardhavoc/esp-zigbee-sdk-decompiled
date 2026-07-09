/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_get_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_get_dstaddr(undefined4 *param_1,undefined1 *param_2)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort uVar5;
  
  puVar1 = (ushort *)*param_1;
  uVar5 = *puVar1 & 0xc00;
  if ((*puVar1 & 0xc00) == 0) {
    *param_2 = 0;
  }
  else {
    iVar2 = mac_fcf_skip_dst_panid_index();
    if (uVar5 == 0x800) {
      *param_2 = 2;
      *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)puVar1 + iVar2);
    }
    else {
      if (uVar5 != 0xc00) {
        *param_2 = 0;
        return 0x10;
      }
      *param_2 = 3;
      uVar3 = *(undefined4 *)((int)puVar1 + iVar2);
      uVar4 = ((undefined4 *)((int)puVar1 + iVar2))[1];
      *(short *)(param_2 + 2) = (short)uVar3;
      *(short *)(param_2 + 6) = (short)uVar4;
      *(short *)(param_2 + 4) = (short)((uint)uVar3 >> 0x10);
      *(short *)(param_2 + 8) = (short)((uint)uVar4 >> 0x10);
    }
  }
  return 0;
}

