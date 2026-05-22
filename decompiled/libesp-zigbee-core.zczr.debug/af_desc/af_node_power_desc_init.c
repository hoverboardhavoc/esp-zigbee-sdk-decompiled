/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_node_power_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_node_power_desc_init(void)

{
  int iVar1;
  
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xfff0;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xff0f | 0x10;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xf0ff | 0x100;
  iVar1 = core_globals_get();
  *(ushort *)(iVar1 + 0xc98) = *(ushort *)(iVar1 + 0xc98) & 0xfff | 0xc000;
  return 0;
}

