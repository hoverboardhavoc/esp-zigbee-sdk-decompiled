/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_assign_random_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_assign_random_channel(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_30;
  undefined1 local_2c [24];
  
  local_30 = 0x19140f0b;
  iVar2 = 0;
  do {
    uVar1 = local_2c[iVar2 + -4];
    iVar3 = touchlink_channel_is_valid(uVar1);
    if (iVar3 != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 4);
  memcpy(local_2c,&_LC1,0xc);
  iVar2 = 0;
  do {
    uVar1 = local_2c[iVar2];
    iVar3 = touchlink_channel_is_valid(uVar1);
    if (iVar3 != 0) {
      return uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0xc);
  return 0xb;
}

