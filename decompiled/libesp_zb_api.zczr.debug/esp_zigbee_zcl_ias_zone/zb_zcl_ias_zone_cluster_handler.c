/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_ias_zone.o -> zb_zcl_ias_zone_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_ias_zone_cluster_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else if (*(char *)(iVar1 + 0x14) == '\x01') {
    iVar4 = esp_zb_has_core_action_handler();
    if (iVar4 != 0) {
      if (*(char *)(iVar1 + 0x13) == '\0') {
        iVar2 = zcl_ias_zone_status_change_notification(param_1);
      }
      else {
        if (*(char *)(iVar1 + 0x13) != '\x01') {
          uVar3 = esp_log_timestamp();
          esp_log(2,"ESP_ZIGBEE_ZCL_IAS_ZONE",
                  "W (%lu) %s: Unsupported ias zone cluster response command(0x%x)\n",uVar3,
                  "ESP_ZIGBEE_ZCL_IAS_ZONE",*(undefined1 *)(iVar1 + 0x13));
          return 0;
        }
        iVar2 = zcl_ias_zone_enroll_req(param_1);
      }
      zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}

