/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_report_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_report_attr_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  undefined2 uVar2;
  esp_err_t err;
  int iVar3;
  uint local_30;
  esp_zb_zcl_report_attr_message_t app_message;
  
  app_message.status = '\0';
  app_message._1_3_ = 0;
  app_message.src_address.addr_type = '\0';
  app_message.src_address._1_3_ = 0;
  app_message.src_address.u.src_id = 0;
  app_message.src_address.u._4_4_ = 0;
  app_message.src_endpoint = '\0';
  app_message.dst_endpoint = '\0';
  app_message.cluster = 0;
  app_message.attribute.id = 0;
  app_message.attribute._2_2_ = 0;
  app_message.attribute.data.type = '\0';
  app_message.attribute.data._1_1_ = 0;
  app_message.attribute.data.size = 0;
                    /* WARNING: Load size is inaccurate */
  local_30 = (uint)*arg;
  convert_ezb_address_to_esp_zb_zcl_addr
            ((esp_zb_zcl_addr_t *)&app_message,*(ezb_address_t **)((int)arg + 8));
  app_message.src_address.u._4_4_ = *(undefined4 *)(*(int *)((int)arg + 8) + 0x14);
  if (*(undefined2 **)((int)arg + 0xc) != (undefined2 *)0x0) {
    app_message._16_2_ = **(undefined2 **)((int)arg + 0xc);
    iVar3 = *(int *)((int)arg + 0xc);
    app_message.attribute.id._0_1_ = *(undefined1 *)(iVar3 + 2);
    app_message.attribute.data._0_4_ = *(undefined4 *)(iVar3 + 4);
    uVar2 = ezb_zcl_get_attr_value_size(*(undefined1 *)(iVar3 + 2),*(undefined4 *)(iVar3 + 4));
    app_message.attribute._2_2_ = uVar2;
  }
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_REPORT_ATTR_CB_ID,&local_30);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar1;
  }
  return;
}

