/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_scenes.o -> zb_zcl_scene_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_scene_resp_handler(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar2 = zb_buf_get_tail_func(0x1b);
  if (iVar2 == 0) {
    return 0;
  }
  if (*(char *)(iVar2 + 0x14) != '\x01') {
    return 0;
  }
  iVar3 = esp_zb_has_core_action_handler();
  if (iVar3 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(iVar2 + 0x13);
  if (bVar1 == 3) {
    iVar4 = zcl_scenes_remove_all_scene_res(param_1);
  }
  else if (bVar1 < 4) {
    if (bVar1 == 1) {
      iVar4 = zcl_scenes_view_scene_res(param_1);
    }
    else if (bVar1 == 2) {
      iVar4 = zcl_scenes_remove_scene_res(param_1);
    }
    else {
      if (bVar1 != 0) goto _L0;
      iVar4 = zcl_scenes_add_scene_res(param_1);
    }
  }
  else if (bVar1 == 4) {
    iVar4 = zcl_scenes_store_scene_res(param_1);
  }
  else {
    if (bVar1 != 6) {
_L0:
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_SCENES",&_LC30,uVar5,"ESP_ZIGBEE_ZCL_SCENES",
                    *(undefined1 *)(iVar2 + 0x13));
      return 0;
    }
    zcl_scenes_get_scene_membership_res(param_1);
    iVar4 = 0;
  }
  zb_zcl_send_default_handler(param_1,iVar2,iVar4 != 0);
  return iVar3;
}

