/*
 * Last changed at upstream commit fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * https://github.com/espressif/esp-zigbee-sdk/commit/fdd7b02c333322a6b0be71e313fe2aad2eac22c5
 * Upstream date: 2023-08-11 14:15:41 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.0(793f8578)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_handle_ias_zone_status_change_notification
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_handle_ias_zone_status_change_notification(undefined4 param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  
  puVar2 = (undefined2 *)malloc(6);
  iVar3 = zb_buf_get_tail_func(param_1,0x1b);
  if (puVar2 == (undefined2 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar5,"ESP_ZIGBEE_CORE",
                  "esp_zb_handle_ias_zone_status_change_notification",0x632);
    uVar5 = 0;
  }
  else {
    uVar4 = zb_buf_len_func(param_1);
    if (5 < uVar4) {
      puVar6 = (undefined1 *)zb_buf_begin_func(param_1);
      *(undefined1 *)puVar2 = *puVar6;
      *(undefined1 *)((int)puVar2 + 1) = puVar6[1];
      *(undefined1 *)(puVar2 + 1) = puVar6[2];
      *(undefined1 *)((int)puVar2 + 3) = puVar6[3];
      *(undefined1 *)(puVar2 + 2) = puVar6[4];
      *(undefined1 *)((int)puVar2 + 5) = puVar6[5];
    }
    bVar1 = 5 >= uVar4;
    if ((zcl_ias_zone_status_notification_cb == (code *)0x0) || (bVar1)) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC11,uVar5,"ESP_ZIGBEE_CORE",bVar1);
      uVar5 = 0;
    }
    else {
      (*zcl_ias_zone_status_notification_cb)
                (*puVar2,*(undefined1 *)(puVar2 + 1),*(undefined1 *)((int)puVar2 + 3),puVar2[2]);
      uVar5 = 1;
    }
    if (*(char *)(iVar3 + 0x17) == '\0') {
      uVar5 = 0;
    }
  }
  return uVar5;
}

