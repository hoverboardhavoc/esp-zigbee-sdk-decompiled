/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
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
  uint uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  
  puVar2 = (undefined2 *)malloc(6);
  uVar3 = zb_buf_len_func(param_1);
  if (5 < uVar3) {
    puVar5 = (undefined1 *)zb_buf_begin_func(param_1);
    *(undefined1 *)puVar2 = *puVar5;
    *(undefined1 *)((int)puVar2 + 1) = puVar5[1];
    *(undefined1 *)(puVar2 + 1) = puVar5[2];
    *(undefined1 *)((int)puVar2 + 3) = puVar5[3];
    *(undefined1 *)(puVar2 + 2) = puVar5[4];
    *(undefined1 *)((int)puVar2 + 5) = puVar5[5];
  }
  bVar1 = 5 >= uVar3;
  if ((zcl_ias_zone_status_notification_cb == (code *)0x0) || (bVar1)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",bVar1);
    uVar4 = 0;
  }
  else {
    (*zcl_ias_zone_status_notification_cb)
              (*puVar2,*(undefined1 *)(puVar2 + 1),*(undefined1 *)((int)puVar2 + 3),puVar2[2]);
    uVar4 = 1;
  }
  return uVar4;
}

