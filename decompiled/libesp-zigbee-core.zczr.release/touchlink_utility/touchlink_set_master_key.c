/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_set_master_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_set_master_key(uint8_t *key)

{
  int iVar1;
  ezb_err_t eVar2;
  
  if (key == (uint8_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = touchlink_device_info_get();
    *(ushort *)(iVar1 + 4) = *(ushort *)(iVar1 + 4) | 0x10;
    iVar1 = touchlink_device_info_get();
    memcpy((void *)(iVar1 + 6),key,0x10);
    eVar2 = 0;
  }
  return eVar2;
}

