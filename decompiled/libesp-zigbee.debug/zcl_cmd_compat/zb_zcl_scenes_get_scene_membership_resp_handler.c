/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_scenes_get_scene_membership_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_scenes_get_scene_membership_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined1 auStack_3c [4];
  esp_zb_zcl_scenes_get_scene_membership_resp_message_t app_message;
  
  auStack_3c[0] = '\0';
  auStack_3c[1] = 0;
  auStack_3c[2] = '\0';
  auStack_3c[3] = 0;
  app_message.info.status = '\0';
  app_message.info._1_1_ = 0;
  app_message.info.header.fc = '\0';
  app_message.info.header._1_1_ = 0;
  app_message.info.header.manuf_code = 0;
  app_message.info.header.tsn = '\0';
  app_message.info.header.rssi = '\0';
  app_message.info.src_address.addr_type = '\0';
  app_message.info.src_address._1_3_ = 0;
  app_message.info.src_address.u.src_id = 0;
  app_message.info.src_address.u._4_4_ = 0;
  app_message.info.dst_address = 0;
  app_message.info.src_endpoint = '\0';
  app_message.info.dst_endpoint = '\0';
  app_message.info.cluster = 0;
  app_message.info.profile = 0;
  app_message.info.command.id = '\0';
  app_message.info.command.direction = '\0';
  app_message.info.command.is_common = '\0';
  app_message.info._31_1_ = 0;
  app_message.capacity = '\0';
  app_message._33_1_ = 0;
  app_message.group_id = 0;
  app_message.scene_count = '\0';
  app_message._37_3_ = 0;
  convert_to_esp_zb_zcl_cmd_info
            ((esp_zb_zcl_cmd_info_t *)auStack_3c,*(ezb_zcl_cmd_hdr_t **)((int)arg + 8));
  auStack_3c[0] = *(esp_zb_zcl_status_t *)((int)arg + 0xc);
  app_message.info.command.id = *(uint8_t *)((int)arg + 0xd);
  app_message.info._30_2_ = *(undefined2 *)((int)arg + 0xe);
  app_message.capacity = *(uint8_t *)((int)arg + 0x10);
  app_message._36_4_ = *(undefined4 *)((int)arg + 0x14);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_CMD_GET_SCENE_MEMBERSHIP_RESP_CB_ID,auStack_3c);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x18) = eVar1;
  }
  return;
}

