/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_set_device_type
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t nwk_set_device_type(nwk_device_type_t device_type)

{
  int iVar1;
  ezb_err_t eVar2;
  
  if (device_type < NWK_DEVICE_TYPE_NONE) {
    iVar1 = core_globals_get();
    if (*(nwk_device_type_t *)(iVar1 + 0xa2c) == device_type) {
      eVar2 = 0;
    }
    else {
      nwk_dev_ctx_deinit();
      iVar1 = core_globals_get();
      *(nwk_device_type_t *)(iVar1 + 0xa2c) = device_type;
      nwk_dev_ctx_init();
      eVar2 = 0;
    }
  }
  else {
    eVar2 = 2;
  }
  return eVar2;
}

