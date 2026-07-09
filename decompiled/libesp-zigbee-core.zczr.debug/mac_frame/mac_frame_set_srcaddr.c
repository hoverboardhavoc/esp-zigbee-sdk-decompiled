/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_set_srcaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * mac_frame_set_srcaddr(undefined4 *param_1,char *param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined2 *)*param_1;
  puVar3 = (undefined4 *)mac_fcf_find_srcaddr_index(*puVar2);
  if (puVar3 == (undefined4 *)0xff) {
    puVar3 = (undefined4 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1d5,
                           "mac_frame_set_srcaddr","(index != 0xff)");
  }
  else if (*param_2 != '\x02') {
    if (*param_2 == '\x03') {
      uVar1 = *(undefined4 *)(param_2 + 6);
      puVar3 = (undefined4 *)((int)puVar3 + (int)puVar2);
      *puVar3 = *(undefined4 *)(param_2 + 2);
      puVar3[1] = uVar1;
      return puVar3;
    }
    puVar3 = (undefined4 *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_frame.c",0x1e1,
                           "mac_frame_set_srcaddr",&_LC4);
    if ((*(ushort *)*puVar3 & 0x200) == 0) {
      puVar3 = (undefined4 *)mac_fcf_skip_addr_field_index();
    }
    else {
      puVar3 = (undefined4 *)0xff;
    }
    return puVar3;
  }
  *(undefined2 *)((int)puVar2 + (int)puVar3) = *(undefined2 *)(param_2 + 2);
  return puVar3;
}

