/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_touchlink_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_touchlink_info(void)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = nwk_is_joined();
  bVar1 = 1;
  if (iVar2 != 0) {
    bVar1 = nwk_is_authed();
    bVar1 = bVar1 ^ 1;
  }
  iVar2 = nwk_is_device_zczr();
  pcVar3 = (char *)touchlink_device_info_get();
  return bVar1 | (byte)(iVar2 << 1) | *pcVar3 << 4;
}

