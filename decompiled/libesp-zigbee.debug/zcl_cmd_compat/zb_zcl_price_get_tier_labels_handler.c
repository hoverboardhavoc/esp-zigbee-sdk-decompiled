/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_price_get_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_price_get_tier_labels_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  uint32_t *puVar2;
  undefined4 uStack_2c;
  esp_zb_zcl_price_get_tier_labels_message_t app_message;
  
  app_message.issuer_tariff_id = 0;
  app_message.resp_info_offered.provider_id = 0;
  app_message.resp_info_offered.issuer_event_id = 0;
  app_message.resp_info_offered.issuer_tariff_id = 0;
  app_message.resp_info_offered.number_of_labels = '\0';
  app_message.resp_info_offered._13_3_ = 0;
                    /* WARNING: Load size is inaccurate */
  uStack_2c = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_PRICE_GET_TIER_LABELS_CB_ID,&uStack_2c);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar1;
  }
  if (((char)app_message.resp_info_offered.issuer_tariff_id == '\0') ||
     (app_message.resp_info_offered._12_4_ == 0)) {
    *(undefined1 *)((int)arg + 0x10) = 0x8b;
  }
  else {
    *(undefined1 *)((int)arg + 0x10) = 0;
    puVar2 = (uint32_t *)calloc(1,0x14);
    *(uint32_t **)((int)arg + 0x14) = puVar2;
    *puVar2 = app_message.issuer_tariff_id;
    puVar2[1] = app_message.resp_info_offered.provider_id;
    puVar2[2] = app_message.resp_info_offered.issuer_event_id;
    *(undefined1 *)(puVar2 + 3) = 0;
    *(undefined1 *)((int)puVar2 + 0xd) = 1;
    *(char *)((int)puVar2 + 0xe) = (char)app_message.resp_info_offered.issuer_tariff_id;
    puVar2[4] = app_message.resp_info_offered._12_4_;
    *(code **)((int)arg + 0x18) = free_memory_in_data_cnf;
    *(uint32_t **)((int)arg + 0x1c) = puVar2;
  }
  return;
}

