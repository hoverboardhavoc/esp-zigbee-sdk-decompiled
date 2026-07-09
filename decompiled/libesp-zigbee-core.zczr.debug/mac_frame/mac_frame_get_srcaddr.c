/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_get_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_get_srcaddr(undefined4 *param_1,undefined1 *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  
  puVar5 = (ushort *)*param_1;
  uVar1 = *puVar5;
  iVar2 = mac_fcf_find_srcaddr_index(uVar1);
  if ((uVar1 & 0xc000) != 0x8000) {
    if ((uVar1 & 0xc000) != 0xc000) {
      if ((uVar1 & 0xc000) != 0) {
        *param_2 = 0;
        return 0x10;
      }
      goto _L0;
    }
    if (iVar2 != 0xff) {
      *param_2 = 3;
      uVar3 = *(undefined4 *)(iVar2 + (int)puVar5);
      uVar4 = ((undefined4 *)(iVar2 + (int)puVar5))[1];
      *(short *)(param_2 + 2) = (short)uVar3;
      *(short *)(param_2 + 4) = (short)((uint)uVar3 >> 0x10);
      *(short *)(param_2 + 6) = (short)uVar4;
      *(short *)(param_2 + 8) = (short)((uint)uVar4 >> 0x10);
      return 0;
    }
    iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1b8,
                          "mac_frame_get_srcaddr","(index != 0xff)");
  }
  if (iVar2 != 0xff) {
    *param_2 = 2;
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)((int)puVar5 + iVar2);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1be,
                "mac_frame_get_srcaddr","(index != 0xff)");
_L0:
  *param_2 = 0;
  return 0;
}

