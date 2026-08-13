/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_tcpol_set_allow_rejoins_with_well_known_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_tcpol_set_allow_rejoins_with_well_known_key(uint param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0x9bc) = *(ushort *)(iVar1 + 0x9bc) & 0xfeff | (ushort)((param_1 & 1) << 8);
  return;
}

