/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_get_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_get_srcaddr(undefined4 *param_1,undefined1 *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar2 = (ushort *)*param_1;
  uVar1 = *puVar2;
  if (uVar1 < 0x4000) {
    *param_2 = 0;
  }
  else {
    iVar3 = mac_fcf_skip_src_panid_index(uVar1);
    if ((uVar1 & 0xc000) == 0x8000) {
      *param_2 = 2;
      *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)puVar2 + iVar3);
    }
    else {
      if ((uVar1 & 0xc000) != 0xc000) {
        *param_2 = 0;
        return 0x10;
      }
      *param_2 = 3;
      uVar4 = *(undefined4 *)((int)puVar2 + iVar3);
      uVar5 = ((undefined4 *)((int)puVar2 + iVar3))[1];
      *(short *)(param_2 + 2) = (short)uVar4;
      *(short *)(param_2 + 6) = (short)uVar5;
      *(short *)(param_2 + 4) = (short)((uint)uVar4 >> 0x10);
      *(short *)(param_2 + 8) = (short)((uint)uVar5 >> 0x10);
    }
  }
  return 0;
}

