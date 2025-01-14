/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_custom_cluster.o -> zb_zcl_custom_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_custom_cluster_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint auStack_48 [5];
  undefined1 uStack_31;
  short sStack_30;
  undefined1 uStack_2c;
  char cStack_2b;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_48);
  if (iVar2 == 0) {
    if ((sStack_30 < 0) && (iVar2 = esp_zb_has_core_action_handler(), iVar2 != 0)) {
      auStack_48[0] = (uint)(iVar1 == 0);
      uStack_28 = zb_buf_len_func(param_1);
      uStack_24 = zb_buf_begin_func(param_1);
      iVar4 = esp_zb_zcl_get_cluster(uStack_31,sStack_30,2);
      iVar5 = esp_zb_zcl_get_cluster(uStack_31,sStack_30,1);
      if (((iVar4 == 0) || (cStack_2b != '\x01')) && ((iVar5 == 0 || (cStack_2b != '\0')))) {
        uVar3 = esp_log_timestamp();
        if (cStack_2b == '\x01') {
          pcVar6 = "TO_CLI";
          pcVar7 = "client";
        }
        else {
          pcVar6 = "TO_SRV";
          pcVar7 = "server";
        }
        esp_log_write(1,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",&_LC6,uVar3,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
                      pcVar6,pcVar7,sStack_30);
        iVar4 = -0x1c;
      }
      else {
        iVar4 = esp_zb_core_action_handler_schedule(0x1040,auStack_48);
      }
      if (iVar1 != 0) {
        zb_zcl_send_default_handler(param_1,iVar1,iVar4 != 0);
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",&_LC7,uVar3,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
                    uStack_2c,uStack_31,sStack_30);
      iVar2 = 0;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",&_LC5,uVar3,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
                  "zb_zcl_custom_cluster_handler",0x37);
    iVar2 = 1;
  }
  return iVar2;
}

