/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_publish_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_price_publish_tier_labels_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined2 uStack_28;
  undefined2 uStack_26;
  esp_zb_zcl_price_publish_tier_labels_message_t app_message;
  
  uStack_26 = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  uStack_28 = *arg;
  app_message.provider_id = *(uint32_t *)((int)arg + 0x10);
  app_message.issuer_tariff_id._2_1_ = *(undefined1 *)((int)arg + 0x1a);
  app_message.issuer_event_id = *(uint32_t *)((int)arg + 0x14);
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  app_message._16_4_ = *(undefined4 *)((int)arg + 0x1c);
  app_message.issuer_tariff_id._0_2_ = *(undefined2 *)((int)arg + 0x18);
  app_message.issuer_tariff_id._3_1_ = 0;
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_PRICE_PUBLISH_TIER_LABELS_CB_ID,&uStack_28);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x20) = eVar1;
  }
  return;
}

