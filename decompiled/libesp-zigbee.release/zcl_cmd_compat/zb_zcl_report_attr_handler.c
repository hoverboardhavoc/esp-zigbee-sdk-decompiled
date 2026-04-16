/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: app_message */
/* WARNING: Unknown calling convention */

void zb_zcl_report_attr_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined2 *puVar2;
  esp_zb_zcl_status_t *peVar3;
  undefined1 local_30 [4];
  esp_zb_zcl_report_attr_message_t app_message;
  
  memset(local_30,0,0x20);
                    /* WARNING: Load size is inaccurate */
  local_30[0] = *arg;
  peVar3 = *(esp_zb_zcl_status_t **)((int)arg + 8);
  app_message.status = *peVar3;
  memcpy(&app_message.src_address,peVar3 + 2,8);
  app_message.src_address.u._6_2_ = *(undefined2 *)(peVar3 + 0x16);
  app_message.src_address.u._4_2_ = *(undefined2 *)(peVar3 + 0x14);
  puVar2 = *(undefined2 **)((int)arg + 0xc);
  if (puVar2 != (undefined2 *)0x0) {
    app_message._16_2_ = *puVar2;
    app_message.attribute.id._0_1_ = *(undefined1 *)(puVar2 + 1);
    app_message.attribute.data._0_4_ = *(undefined4 *)(puVar2 + 2);
    app_message.attribute._2_2_ = ezb_zcl_get_attr_value_size();
  }
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_REPORT_ATTR_CB_ID,local_30);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar1;
  }
  return;
}

