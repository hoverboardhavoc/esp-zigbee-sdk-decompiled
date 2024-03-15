/*
 * Last changed at upstream commit ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * https://github.com/espressif/esp-zigbee-sdk/commit/ba8582df6bc62b9e5e69a4c6f3ae02f0e1da194a
 * Upstream date: 2024-03-15 18:43:30 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.1(aaf0078d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_custom_cluster_handler
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
  int iVar4;
  undefined4 uVar5;
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
    if ((sStack_30 < 0) && (zb_core_action_cb != (code *)0x0)) {
      auStack_48[0] = (uint)(iVar1 == 0);
      uStack_28 = zb_buf_len_func(param_1);
      uStack_24 = zb_buf_begin_func(param_1);
      iVar3 = esp_zb_zcl_get_cluster(uStack_31,sStack_30,2);
      iVar4 = esp_zb_zcl_get_cluster(uStack_31,sStack_30,1);
      iVar2 = 0;
      if (((iVar3 == 0) || (cStack_2b != '\x01')) && ((iVar4 == 0 || (cStack_2b != '\0')))) {
        if (((iVar3 == 0) || (cStack_2b != '\0')) && ((iVar4 == 0 || (cStack_2b != '\x01')))) {
          uVar5 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC39,uVar5,"ESP_ZIGBEE_CORE",sStack_30,uStack_31);
          iVar2 = -0x1c;
        }
        else if (zb_core_action_cb != (code *)0x0) {
          iVar2 = (*zb_core_action_cb)(0x1041,auStack_48);
        }
      }
      else if (zb_core_action_cb != (code *)0x0) {
        iVar2 = (*zb_core_action_cb)(0x1040,auStack_48);
      }
      if (iVar1 == 0) {
        uVar5 = 1;
      }
      else {
        zb_zcl_send_default_handler(param_1,iVar1,iVar2 != 0);
        uVar5 = 1;
      }
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"ESP_ZIGBEE_CORE",&_LC40,uVar5,"ESP_ZIGBEE_CORE",uStack_2c,uStack_31,sStack_30
                   );
      uVar5 = 0;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar5,"ESP_ZIGBEE_CORE","zb_zcl_custom_cluster_handler",
                  0x967);
    uVar5 = 1;
  }
  return uVar5;
}

