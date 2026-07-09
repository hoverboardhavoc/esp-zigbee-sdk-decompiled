/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_dstaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * mac_frame_set_dstaddr(undefined4 *param_1,char *param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *extraout_a1;
  undefined4 uVar5;
  undefined4 uVar6;
  ushort *puVar7;
  
  puVar2 = (undefined2 *)*param_1;
  puVar3 = (undefined4 *)mac_fcf_find_dstaddr_index(*puVar2);
  if (puVar3 == (undefined4 *)0xff) {
    puVar3 = (undefined4 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x19c,
                           "mac_frame_set_dstaddr","(index != 0xff)");
_L0:
    *(undefined2 *)((int)puVar2 + (int)puVar3) = *(undefined2 *)(param_2 + 2);
    return puVar3;
  }
  if (*param_2 == '\x02') goto _L0;
  if (*param_2 == '\x03') {
    uVar5 = *(undefined4 *)(param_2 + 6);
    puVar3 = (undefined4 *)((int)puVar3 + (int)puVar2);
    *puVar3 = *(undefined4 *)(param_2 + 2);
    puVar3[1] = uVar5;
    return puVar3;
  }
  puVar3 = (undefined4 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1a8,
                         "mac_frame_set_dstaddr",&_LC4);
  puVar7 = (ushort *)*puVar3;
  uVar1 = *puVar7;
  iVar4 = mac_fcf_find_srcaddr_index(uVar1);
  if ((uVar1 & 0xc000) != 0x8000) {
    if ((uVar1 & 0xc000) != 0xc000) {
      if ((uVar1 & 0xc000) != 0) {
        *extraout_a1 = 0;
        return (undefined4 *)0x10;
      }
      goto _L0;
    }
    if (iVar4 != 0xff) {
      *extraout_a1 = 3;
      uVar5 = *(undefined4 *)(iVar4 + (int)puVar7);
      uVar6 = ((undefined4 *)(iVar4 + (int)puVar7))[1];
      *(short *)(extraout_a1 + 2) = (short)uVar5;
      *(short *)(extraout_a1 + 4) = (short)((uint)uVar5 >> 0x10);
      *(short *)(extraout_a1 + 6) = (short)uVar6;
      *(short *)(extraout_a1 + 8) = (short)((uint)uVar6 >> 0x10);
      return (undefined4 *)0x0;
    }
    iVar4 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1b8,
                          "mac_frame_get_srcaddr","(index != 0xff)");
  }
  if (iVar4 != 0xff) {
    *extraout_a1 = 2;
    *(undefined2 *)(extraout_a1 + 2) = *(undefined2 *)((int)puVar7 + iVar4);
    return (undefined4 *)0x0;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1be,
                "mac_frame_get_srcaddr","(index != 0xff)");
_L0:
  *extraout_a1 = 0;
  return (undefined4 *)0x0;
}

