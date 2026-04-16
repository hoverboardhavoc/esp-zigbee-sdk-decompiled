/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_set_download_block_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_set_download_block_size(uint8_t ep_id,uint8_t allowed_block_size)

{
  ota_upgrade_downloading_context_t *poVar1;
  ezb_err_t eVar2;
  
  poVar1 = ota_upgrade_downloading_context_get(ep_id);
  if (poVar1 == (ota_upgrade_downloading_context_t *)0x0) {
    eVar2 = 5;
  }
  else {
    (poVar1->config).allowed_block_size = allowed_block_size;
    eVar2 = 0;
  }
  return eVar2;
}

