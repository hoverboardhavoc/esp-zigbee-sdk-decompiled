/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_publish_price_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_price_publish_price_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined1 local_50;
  undefined1 uStack_4f;
  undefined2 uStack_4e;
  esp_zb_zcl_price_publish_price_message_t app_message;
  
  memset(&local_50,0,0x40);
                    /* WARNING: Load size is inaccurate */
  local_50 = *arg;
  uStack_4f = *(undefined1 *)((int)arg + 1);
  uStack_4e = *(undefined2 *)((int)arg + 2);
  memcpy(&app_message,(void *)((int)arg + 0xc),0x3b);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_PRICE_PUBLISH_PRICE_CB_ID,&local_50);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x48) = eVar1;
  }
  return;
}

