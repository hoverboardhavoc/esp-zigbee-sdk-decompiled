/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_set_node_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_set_node_desc(af_node_desc_t *desc)

{
  int iVar1;
  ezb_err_t eVar2;
  
  if (desc == (af_node_desc_t *)0x0) {
    eVar2 = 2;
  }
  else {
    iVar1 = core_globals_get();
    memcpy((void *)(iVar1 + 0xc88),desc,0x10);
    eVar2 = 0;
  }
  return eVar2;
}

