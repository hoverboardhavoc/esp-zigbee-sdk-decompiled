/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_src_panid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_frame_set_src_panid(undefined4 *param_1,undefined2 param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *extraout_a1;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  
  puVar2 = (undefined2 *)*param_1;
  iVar3 = mac_fcf_find_src_panid_index(*puVar2);
  if (iVar3 != 0xff) {
    *(undefined2 *)((int)puVar2 + iVar3) = param_2;
    return iVar3;
  }
  puVar4 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x16e,
                         "mac_frame_set_src_panid","index != 0xff");
  puVar7 = (ushort *)*puVar4;
  uVar1 = *puVar7;
  iVar3 = mac_fcf_find_dstaddr_index(uVar1);
  if ((uVar1 & 0xc00) != 0x800) {
    if ((uVar1 & 0xc00) != 0xc00) {
      if ((uVar1 & 0xc00) != 0) {
        *extraout_a1 = 0;
        return 0x10;
      }
      goto _L0;
    }
    if (iVar3 != 0xff) {
      *extraout_a1 = 3;
      uVar5 = *(undefined4 *)(iVar3 + (int)puVar7);
      uVar6 = ((undefined4 *)(iVar3 + (int)puVar7))[1];
      *(short *)(extraout_a1 + 2) = (short)uVar5;
      *(short *)(extraout_a1 + 4) = (short)((uint)uVar5 >> 0x10);
      *(short *)(extraout_a1 + 6) = (short)uVar6;
      *(short *)(extraout_a1 + 8) = (short)((uint)uVar6 >> 0x10);
      return 0;
    }
    iVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x17e,
                          "mac_frame_get_dstaddr","index != 0xff");
  }
  if (iVar3 != 0xff) {
    *extraout_a1 = 2;
    *(undefined2 *)(extraout_a1 + 2) = *(undefined2 *)((int)puVar7 + iVar3);
    return 0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x184,
                "mac_frame_get_dstaddr","index != 0xff");
_L0:
  *extraout_a1 = 0;
  return 0;
}

