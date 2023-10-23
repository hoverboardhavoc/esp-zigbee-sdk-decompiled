/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_scene_resp_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar2 + 0x14) != '\x01') {
    return 0;
  }
  if (zb_core_action_cb == 0) {
    return 0;
  }
  bVar1 = *(byte *)(iVar2 + 0x13);
  if (bVar1 == 3) {
    iVar3 = zcl_scenes_remove_all_scene_res(param_1);
  }
  else if (bVar1 < 4) {
    if (bVar1 == 1) {
      iVar3 = zcl_scenes_view_scene_res(param_1);
    }
    else if (bVar1 == 2) {
      iVar3 = zcl_scenes_remove_scene_res(param_1);
    }
    else {
      if (bVar1 != 0) goto _L0;
      iVar3 = zcl_scenes_add_scene_res(param_1);
    }
  }
  else if (bVar1 == 4) {
    iVar3 = zcl_scenes_store_scene_res(param_1);
  }
  else {
    if (bVar1 != 6) {
_L0:
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC22,uVar4,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar2 + 0x13)
                   );
      return 0;
    }
    zcl_scenes_get_scene_membership_res(param_1);
    iVar3 = 0;
  }
  zb_zcl_send_default_handler(param_1,iVar2,iVar3 != 0);
  return 1;
}

