/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_update_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_set_update_id(uint param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  if (*(byte *)(iVar1 + 0x9df) != param_1) {
    iVar1 = core_globals_get();
    *(char *)(iVar1 + 0x9df) = (char)param_1;
    nwk_update_beacon_payload();
  }
  return;
}

