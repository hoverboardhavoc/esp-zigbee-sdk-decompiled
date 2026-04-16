/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_thermostat_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_thermostat_value_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined4 uStack_1c;
  esp_zb_zcl_thermostat_value_message_t app_message;
  
                    /* WARNING: Load size is inaccurate */
  uStack_1c = *arg;
  app_message.info.dst_endpoint = '\0';
  app_message.info.status = *(byte *)((int)arg + 6);
  app_message.info.cluster = *(uint16_t *)((int)arg + 10);
  app_message._4_2_ = *(undefined2 *)((int)arg + 8);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_THERMOSTAT_VALUE_CB_ID,&uStack_1c);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0xc) = eVar1;
  }
  return;
}

