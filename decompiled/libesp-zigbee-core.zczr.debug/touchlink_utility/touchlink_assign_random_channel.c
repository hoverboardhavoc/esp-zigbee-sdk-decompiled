/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_assign_random_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_assign_random_channel(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 auStack_14 [2];
  
  auStack_14[0] = 0x19140f0b;
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = *(undefined1 *)((int)auStack_14 + uVar2);
    iVar3 = touchlink_channel_is_valid(uVar1);
    if (iVar3 != 0) {
      return uVar1;
    }
  }
  local_20 = 0x100e0d0c;
  uStack_1c = 0x15131211;
  uStack_18 = 0x1a181716;
  uVar2 = 0;
  while( true ) {
    if (0xb < uVar2) {
      return 0xb;
    }
    uVar1 = *(undefined1 *)((int)&local_20 + uVar2);
    iVar3 = touchlink_channel_is_valid(uVar1);
    if (iVar3 != 0) break;
    uVar2 = uVar2 + 1 & 0xff;
  }
  return uVar1;
}

