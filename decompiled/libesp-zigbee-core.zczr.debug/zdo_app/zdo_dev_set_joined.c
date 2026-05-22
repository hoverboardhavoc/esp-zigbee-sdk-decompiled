/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app.o -> zdo_dev_set_joined
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_dev_set_joined(_Bool joined)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xcf4) = *(byte *)(iVar1 + 0xcf4) & 0xfd | (byte)((joined & 1) << 1);
  return;
}

