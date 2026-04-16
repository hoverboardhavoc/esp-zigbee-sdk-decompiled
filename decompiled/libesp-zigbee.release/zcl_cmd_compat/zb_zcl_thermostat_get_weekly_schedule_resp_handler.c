/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_thermostat_get_weekly_schedule_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_thermostat_get_weekly_schedule_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  uint8_t *puVar2;
  undefined1 auStack_38 [4];
  esp_zb_zcl_thermostat_get_weekly_schedule_resp_message_t app_message;
  
  memset(auStack_38,0,0x28);
  convert_to_esp_zb_zcl_cmd_info
            ((esp_zb_zcl_cmd_info_t *)auStack_38,*(ezb_zcl_cmd_hdr_t **)((int)arg + 8));
                    /* WARNING: Load size is inaccurate */
  auStack_38[0] = *arg;
  puVar2 = *(uint8_t **)((int)arg + 0xc);
  if (puVar2 != (uint8_t *)0x0) {
    app_message.info.command.direction = puVar2[1];
    app_message.info.command.id = *puVar2;
    app_message.info.command.is_common = puVar2[2];
    app_message.num_of_trans = puVar2[4];
    app_message.day_of_week = puVar2[5];
    app_message.mode_for_req = puVar2[6];
    app_message._35_1_ = puVar2[7];
  }
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_CMD_THERMOSTAT_GET_WEEKLY_SCHEDULE_RESP_CB_ID,auStack_38);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar1;
  }
  return;
}

