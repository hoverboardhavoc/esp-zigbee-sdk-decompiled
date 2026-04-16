/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_groups_get_group_membership_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_groups_get_group_membership_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined1 auStack_38 [4];
  esp_zb_zcl_groups_get_group_membership_resp_message_t app_message;
  
  memset(auStack_38,0,0x28);
  convert_to_esp_zb_zcl_cmd_info
            ((esp_zb_zcl_cmd_info_t *)auStack_38,*(ezb_zcl_cmd_hdr_t **)((int)arg + 8));
                    /* WARNING: Load size is inaccurate */
  auStack_38[0] = *arg;
  app_message.info.command._0_2_ = *(undefined2 *)((int)arg + 0xc);
  app_message._32_4_ = *(undefined4 *)((int)arg + 0x10);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_CMD_GET_GROUP_MEMBERSHIP_RESP_CB_ID,auStack_38);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x14) = eVar1;
  }
  return;
}

