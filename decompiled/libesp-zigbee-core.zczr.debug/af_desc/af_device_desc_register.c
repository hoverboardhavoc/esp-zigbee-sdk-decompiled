/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_desc_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_desc_register(af_device_desc_t *dev_desc)

{
  int iVar1;
  ezb_err_t eVar2;
  
  if (dev_desc == (af_device_desc_t *)0x0) {
    eVar2 = 3;
  }
  else {
    iVar1 = core_globals_get();
    *(af_device_desc_t **)(iVar1 + 0xd04) = dev_desc;
    iVar1 = core_globals_get();
    eVar2 = af_device_add_green_power_cluster_desc(*(af_device_desc_t **)(iVar1 + 0xd04));
    if (eVar2 == 0) {
      iVar1 = core_globals_get();
      eVar2 = af_device_desc_init(*(af_device_desc_t **)(iVar1 + 0xd04));
      if (eVar2 != 0) {
        iVar1 = core_globals_get();
        *(undefined4 *)(iVar1 + 0xd04) = 0;
      }
    }
  }
  return eVar2;
}

