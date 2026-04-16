/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_price_get_tier_labels_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: app_message */
/* WARNING: Unknown calling convention */

void zb_zcl_price_get_tier_labels_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  char cVar1;
  undefined4 uVar2;
  uint32_t *puVar3;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  esp_zb_zcl_price_get_tier_labels_message_t app_message;
  
  uStack_2a = *(undefined2 *)((int)arg + 2);
                    /* WARNING: Load size is inaccurate */
  uStack_2c = *arg;
  app_message.info = *(esp_zb_device_cb_common_info_t *)((int)arg + 0xc);
  app_message.issuer_tariff_id = 0;
  app_message.resp_info_offered.provider_id = 0;
  app_message.resp_info_offered.issuer_event_id = 0;
  app_message.resp_info_offered.issuer_tariff_id = 0;
  app_message.resp_info_offered.number_of_labels = '\0';
  app_message.resp_info_offered._13_3_ = 0;
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    (*cb)(ESP_ZB_CORE_PRICE_GET_TIER_LABELS_CB_ID,&uStack_2c);
  }
  uVar2 = app_message.resp_info_offered._12_4_;
  cVar1 = (char)app_message.resp_info_offered.issuer_tariff_id;
  if (((char)app_message.resp_info_offered.issuer_tariff_id == '\0') ||
     (app_message.resp_info_offered._12_4_ == 0)) {
    *(undefined1 *)((int)arg + 0x10) = 0x8b;
  }
  else {
    *(undefined1 *)((int)arg + 0x10) = 0;
    puVar3 = (uint32_t *)calloc(1,0x14);
    *(uint32_t **)((int)arg + 0x14) = puVar3;
    *(char *)((int)puVar3 + 0xe) = cVar1;
    *puVar3 = app_message.issuer_tariff_id;
    puVar3[4] = uVar2;
    *(uint32_t **)((int)arg + 0x1c) = puVar3;
    puVar3[1] = app_message.resp_info_offered.provider_id;
    puVar3[2] = app_message.resp_info_offered.issuer_event_id;
    *(undefined2 *)(puVar3 + 3) = 0x100;
    *(code **)((int)arg + 0x18) = free_memory_in_data_cnf;
  }
  return;
}

