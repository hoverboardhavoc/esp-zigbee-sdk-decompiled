/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_scenes_recall_scene_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_scenes_recall_scene_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  ezb_zcl_status_t eVar1;
  esp_err_t err;
  undefined4 uStack_24;
  esp_zb_zcl_recall_scene_message_t app_message;
  
  app_message.field_set = (esp_zb_zcl_scenes_extension_field_t *)0x0;
                    /* WARNING: Load size is inaccurate */
  uStack_24 = *arg;
  app_message.info.cluster._1_1_ = 0;
  app_message.info._0_3_ = *(uint3 *)((int)arg + 0xc);
  app_message._6_2_ = 0;
  app_message.group_id = *(ushort *)((int)arg + 0x10);
  app_message._8_4_ = *(undefined4 *)((int)arg + 0x14);
  if (cb != (esp_zb_core_action_callback_t)0x0) {
    err = (*cb)(ESP_ZB_CORE_SCENES_RECALL_SCENE_CB_ID,&uStack_24);
    eVar1 = esp_err_to_zcl_status(err);
    *(ezb_zcl_status_t *)((int)arg + 0x18) = eVar1;
  }
  return;
}

