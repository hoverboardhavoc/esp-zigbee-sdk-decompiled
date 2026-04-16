/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_desc_init(void)

{
  ezb_err_t eVar1;
  
  eVar1 = af_dev_desc_init();
  if (((eVar1 == 0) && (eVar1 = af_node_desc_init(), eVar1 == 0)) &&
     (eVar1 = af_node_power_desc_init(), eVar1 == 0)) {
    eVar1 = af_simple_desc_init();
  }
  return eVar1;
}

