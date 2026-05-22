/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_join.o -> zdo_initiate_join
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zdo_initiate_join(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0xcdc) = *(byte *)(iVar1 + 0xcdc) & 0xfe;
  iVar1 = core_globals_get();
  if (*(int *)(iVar1 + 0xc) != 0 || *(int *)(iVar1 + 0x10) != 0) {
    iVar1 = core_globals_get();
    nwk_set_extended_panid(iVar1 + 0xc);
  }
  zdo_initiate_commissioning(0x1e4);
  return;
}

