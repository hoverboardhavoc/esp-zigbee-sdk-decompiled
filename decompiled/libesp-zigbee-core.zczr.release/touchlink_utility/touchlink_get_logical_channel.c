/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_logical_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_get_logical_channel(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_30;
  undefined1 auStack_2c [24];
  
  iVar3 = touchlink_device_info_get();
  iVar3 = touchlink_channel_is_valid(*(undefined1 *)(iVar3 + 1));
  if (iVar3 != 0) {
    iVar3 = touchlink_device_info_get();
    return *(undefined1 *)(iVar3 + 1);
  }
  uStack_30 = 0x19140f0b;
  iVar3 = 0;
  do {
    uVar1 = auStack_2c[iVar3 + -4];
    iVar2 = touchlink_channel_is_valid(uVar1);
    if (iVar2 != 0) {
      return uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  memcpy(auStack_2c,&_LC1,0xc);
  iVar3 = 0;
  do {
    uVar1 = auStack_2c[iVar3];
    iVar2 = touchlink_channel_is_valid(uVar1);
    if (iVar2 != 0) {
      return uVar1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0xc);
  return 0xb;
}

