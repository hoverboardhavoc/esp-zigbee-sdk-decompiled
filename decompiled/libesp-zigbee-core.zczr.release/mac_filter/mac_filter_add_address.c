/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_add_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_filter_add_address(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  puVar4 = (undefined1 *)mac_filter_find_entry();
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = (undefined1 *)mac_filter_new_entry();
    if (puVar4 == (undefined1 *)0x0) {
      return 1;
    }
    uVar1 = *(undefined2 *)(param_1 + 1);
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *puVar4 = (char)*(undefined2 *)param_1;
    puVar4[1] = (char)((uint)uVar2 >> 8);
    puVar4[3] = (char)((uint)uVar2 >> 0x18);
    puVar4[5] = (char)((uint)uVar3 >> 8);
    puVar4[2] = (char)((uint)uVar2 >> 0x10);
    puVar4[4] = (char)uVar1;
    puVar4[6] = (char)((uint)uVar3 >> 0x10);
    puVar4[7] = (char)((uint)uVar3 >> 0x18);
  }
  puVar4[9] = 1;
  return 0;
}

