/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
    *(af_device_desc_t **)(iVar1 + 0xca0) = dev_desc;
    iVar1 = core_globals_get();
    af_device_add_green_power_proxy_endpoint(*(af_device_desc_t **)(iVar1 + 0xca0));
    iVar1 = core_globals_get();
    eVar2 = af_device_desc_init(*(af_device_desc_t **)(iVar1 + 0xca0));
    if (eVar2 != 0) {
      iVar1 = core_globals_get();
      *(undefined4 *)(iVar1 + 0xca0) = 0;
    }
  }
  return eVar2;
}

