/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_current_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_current_channel(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte abStack_30 [28];
  
  uVar4 = touchlink_touchlink_info();
  if ((uVar4 & 1) == 0) {
    uVar4 = nwk_get_pan_channel();
    uVar5 = 0xc;
    do {
      if (((uVar4 & 0x7ffffff) >> (uVar5 & 0x1f) & 1) != 0) {
        return uVar5 & 0xff;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x1b);
    return 0xb;
  }
  iVar3 = touchlink_device_info_get();
  iVar3 = touchlink_channel_is_valid(*(undefined1 *)(iVar3 + 1));
  if (iVar3 == 0) {
    abStack_30[0] = 0xb;
    abStack_30[1] = 0xf;
    abStack_30[2] = 0x14;
    abStack_30[3] = 0x19;
    iVar3 = 0;
    do {
      bVar1 = abStack_30[iVar3];
      iVar2 = touchlink_channel_is_valid((uint)bVar1);
      if (iVar2 != 0) {
        return (uint)bVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
    memcpy(abStack_30 + 4,&_LC1,0xc);
    iVar3 = 0;
    do {
      uVar4 = (uint)(abStack_30 + 4)[iVar3];
      iVar2 = touchlink_channel_is_valid(uVar4);
      if (iVar2 != 0) {
        return uVar4;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0xc);
    return 0xb;
  }
  iVar3 = touchlink_device_info_get();
  return (uint)*(byte *)(iVar3 + 1);
}

