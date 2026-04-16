/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_init(void)

{
  int iVar1;
  touchlink_device_info_t *ptVar2;
  
  iVar1 = core_globals_get();
  memset((void *)(iVar1 + 0xdb4),0,0x6a0);
  ptVar2 = touchlink_device_info_get();
  ptVar2->key_bitmask = 0x8000;
  ptVar2 = touchlink_device_info_get();
  ptVar2->rssi_correction = '\0';
  ptVar2 = touchlink_device_info_get();
  ptVar2->rssi_threshold = -0x40;
  ptVar2 = touchlink_device_info_get();
  memset(ptVar2->master_key,0,0x10);
  return 0;
}

