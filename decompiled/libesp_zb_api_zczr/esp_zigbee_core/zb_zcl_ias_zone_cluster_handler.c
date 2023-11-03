/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_ias_zone_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_ias_zone_cluster_handler(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (zb_core_action_cb == 0) {
      uVar2 = 0;
    }
    else {
      if (*(char *)(iVar1 + 0x13) == '\0') {
        iVar3 = zcl_ias_zone_status_change_notification(param_1);
      }
      else {
        if (*(char *)(iVar1 + 0x13) != '\x01') {
          uVar2 = esp_log_timestamp();
          esp_log_write(2,"ESP_ZIGBEE_CORE",&_L0,uVar2,"ESP_ZIGBEE_CORE",
                        *(undefined1 *)(iVar1 + 0x13));
          return 0;
        }
        iVar3 = zcl_ias_zone_enroll_req(param_1);
      }
      zb_zcl_send_default_handler(param_1,iVar1,iVar3 != 0);
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

