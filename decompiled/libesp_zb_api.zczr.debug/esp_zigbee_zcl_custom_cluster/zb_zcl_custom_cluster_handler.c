/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
        esp_log(1,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
                "E (%lu) %s: Received %s custom command, but cannot find the custom %s cluster (0x%x) on endpoint (%d)\n"
                ,uVar3,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",pcVar6,pcVar7,sStack_30);
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
      esp_log(2,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
              "W (%lu) %s: Failed to find custom command(0x%x) callback for endpoint(%d) cluster(0x%x)\n"
              ,uVar3,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",uStack_2c,uStack_31,sStack_30);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 1;
    uVar3 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
            "E (%lu) %s: %s(%d): Failed to create custom_cluster message\n",uVar3,
            "ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER","zb_zcl_custom_cluster_handler",0x37);
  }
  return iVar2;
}

