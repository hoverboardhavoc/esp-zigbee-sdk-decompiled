/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_set_node_desc
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
    memcpy((void *)(iVar1 + 0xcec),desc,0x10);
    eVar2 = 0;
  }
  return eVar2;
}

