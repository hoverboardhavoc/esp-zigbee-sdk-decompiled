/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_add_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_filter_add_address(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar4 = 2;
  }
  else {
    puVar3 = (undefined1 *)mac_filter_find_entry();
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = (undefined1 *)mac_filter_new_entry();
      if (puVar3 == (undefined1 *)0x0) {
        return 1;
      }
      uVar4 = *param_1;
      uVar1 = *(undefined2 *)(param_1 + 1);
      uVar2 = param_1[1];
      *puVar3 = (char)*(undefined2 *)param_1;
      puVar3[1] = (char)((uint)uVar4 >> 8);
      puVar3[2] = (char)((uint)uVar4 >> 0x10);
      puVar3[3] = (char)((uint)uVar4 >> 0x18);
      puVar3[4] = (char)uVar1;
      puVar3[5] = (char)((uint)uVar2 >> 8);
      puVar3[6] = (char)((uint)uVar2 >> 0x10);
      puVar3[7] = (char)((uint)uVar2 >> 0x18);
    }
    puVar3[9] = 1;
    uVar4 = 0;
  }
  return uVar4;
}

