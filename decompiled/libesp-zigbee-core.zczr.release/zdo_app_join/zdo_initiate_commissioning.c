/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_initiate_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_initiate_commissioning(uint16_t comm_ops)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(uint16_t *)(iVar1 + 0xcc2) = comm_ops;
  iVar1 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xcc0) = 0;
  iVar1 = core_globals_get();
  tasklet_post(iVar1 + 0xcc4);
  return;
}

