/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_set_permit_joining_duration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_set_permit_joining_duration(uint param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(byte *)(iVar1 + 0xb07) != param_1) {
    if (param_1 == 0) {
      nwk_set_mac_permit_joining(0);
    }
    else {
      nwk_set_mac_permit_joining(1);
    }
    nwk_permit_joining_status_indication(param_1);
    iVar1 = core_globals_get();
    *(char *)(iVar1 + 0xb07) = (char)param_1;
  }
  return;
}

