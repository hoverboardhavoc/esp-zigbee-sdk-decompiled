/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_custom_cluster.o -> zb_zcl_custom_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_custom_cluster_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  uint auStack_38 [5];
  undefined1 uStack_21;
  short sStack_20;
  char cStack_1b;
  undefined2 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x1b);
  iVar2 = zb_zcl_basic_message_create(param_1,auStack_38);
  if (iVar2 == 0) {
    if ((-1 < sStack_20) || (iVar2 = esp_zb_has_core_action_handler(), iVar2 == 0)) {
      return 0;
    }
    auStack_38[0] = (uint)(iVar1 == 0);
    uStack_18 = zb_buf_len_func(param_1);
    uStack_14 = zb_buf_begin_func(param_1);
    iVar2 = esp_zb_zcl_get_cluster(uStack_21,sStack_20,2);
    iVar3 = esp_zb_zcl_get_cluster(uStack_21,sStack_20,1);
    if (((iVar2 == 0) || (cStack_1b != '\x01')) && ((iVar3 == 0 || (cStack_1b != '\0')))) {
      uVar4 = esp_log_timestamp();
      if (cStack_1b == '\x01') {
        pcVar5 = "TO_CLI";
        pcVar6 = "client";
      }
      else {
        pcVar5 = "TO_SRV";
        pcVar6 = "server";
      }
      esp_log(1,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",
              "E (%lu) %s: Received %s custom command, but cannot find the custom %s cluster (0x%x) on endpoint (%d)\n"
              ,uVar4,"ESP_ZIGBEE_ZCL_CUSTOM_CLUSTER",pcVar5,pcVar6,sStack_20);
      iVar2 = -0x1c;
    }
    else {
      iVar2 = esp_zb_core_action_handler_schedule(0x1040,auStack_38);
    }
    if (iVar1 != 0) {
      zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
    }
  }
  return 1;
}

