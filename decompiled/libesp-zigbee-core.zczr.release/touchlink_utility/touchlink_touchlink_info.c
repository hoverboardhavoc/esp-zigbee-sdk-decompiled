/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_touchlink_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_touchlink_info(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  
  iVar2 = nwk_is_joined();
  uVar1 = 1;
  if (iVar2 != 0) {
    uVar1 = nwk_is_authed();
    uVar1 = (uVar1 ^ 1) & 0xff;
  }
  uVar3 = nwk_is_device_zczr();
  pbVar4 = (byte *)touchlink_device_info_get();
  return (uVar1 | (uVar3 & 0x7fff) << 1 | (uint)*pbVar4 << 4) & 0xff;
}

