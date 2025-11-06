/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_secur.o -> esp_zb_secur_broadcast_network_key_switch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_broadcast_network_key_switch(undefined1 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = zb_is_device_zc();
  if ((iVar1 == 0) &&
     ((iVar1 = zb_is_device_zr(), iVar1 == 0 || (iVar1 = zb_is_network_distributed(), iVar1 == 0))))
  {
    uVar3 = esp_log_timestamp();
    uVar4 = zb_get_network_role();
    esp_log(1,"ESP_ZIGBEE_SECUR",
            "E (%lu) %s: %s(%d): Role %d is not supported to switch network key\n",uVar3,
            "ESP_ZIGBEE_SECUR","esp_zb_secur_broadcast_network_key_switch",0x12d,uVar4);
    uVar3 = 0x106;
  }
  else {
    iVar1 = zb_buf_get_out_func();
    if (iVar1 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,"ESP_ZIGBEE_SECUR",
              "E (%lu) %s: %s(%d): No memory for broadcasting network key switch\n",uVar3,
              "ESP_ZIGBEE_SECUR","esp_zb_secur_broadcast_network_key_switch",0x12f);
      uVar3 = 0x101;
    }
    else {
      puVar2 = (undefined1 *)zb_buf_get_tail_func(9);
      *puVar2 = 0xff;
      puVar2[1] = 0xff;
      puVar2[2] = 0xff;
      puVar2[3] = 0xff;
      puVar2[4] = 0xff;
      puVar2[5] = 0xff;
      puVar2[6] = 0xff;
      puVar2[7] = 0xff;
      puVar2[8] = param_1;
      zb_schedule_callback(&zb_apsme_switch_key_request,iVar1);
      uVar3 = 0;
    }
  }
  return uVar3;
}

