/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_ias_zone_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zb_zcl_ias_zone_cluster_handler(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
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
          uVar4 = esp_log_timestamp();
          esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC6,uVar4,"ESP_ZIGBEE_CORE",
                        *(undefined1 *)(iVar1 + 0x13));
          return 0;
        }
        iVar3 = zcl_ias_zone_enroll_req(param_1);
      }
      uVar2 = (uint)*(byte *)(iVar1 + 0x17);
      if (uVar2 == 0) {
        uVar2 = zb_zcl_send_default_handler(param_1,iVar1,iVar3 != 0);
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

