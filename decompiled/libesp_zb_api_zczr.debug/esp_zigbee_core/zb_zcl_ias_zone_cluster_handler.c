/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zb_zcl_ias_zone_cluster_handler
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

