/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  memset((void *)(iVar1 + 0xd60),0,0x6a0);
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

