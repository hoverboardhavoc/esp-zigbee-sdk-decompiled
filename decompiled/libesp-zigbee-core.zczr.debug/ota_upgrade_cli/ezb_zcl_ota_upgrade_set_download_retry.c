/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_set_download_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_ota_upgrade_set_download_retry(uint8_t ep_id,uint8_t retry,uint32_t timeout)

{
  ota_upgrade_downloading_context_t *poVar1;
  ezb_err_t eVar2;
  
  poVar1 = ota_upgrade_downloading_context_get(ep_id);
  if (poVar1 == (ota_upgrade_downloading_context_t *)0x0) {
    eVar2 = 5;
  }
  else if (timeout == 0) {
    eVar2 = 2;
  }
  else {
    (poVar1->config).retry_num = retry;
    (poVar1->config).retry_timeout = timeout;
    eVar2 = 0;
  }
  return eVar2;
}

