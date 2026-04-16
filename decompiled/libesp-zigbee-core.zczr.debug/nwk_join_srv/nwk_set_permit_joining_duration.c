/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_set_permit_joining_duration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_set_permit_joining_duration(uint8_t permit_duration)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = core_globals_get();
  if ((uint)*(byte *)(iVar1 + 0xb07) != CONCAT31(in_register_00002029,permit_duration)) {
    if (CONCAT31(in_register_00002029,permit_duration) == 0) {
      nwk_set_mac_permit_joining(false);
    }
    else {
      nwk_set_mac_permit_joining(true);
    }
    nwk_permit_joining_status_indication(permit_duration);
    iVar1 = core_globals_get();
    *(uint8_t *)(iVar1 + 0xb07) = permit_duration;
  }
  return;
}

