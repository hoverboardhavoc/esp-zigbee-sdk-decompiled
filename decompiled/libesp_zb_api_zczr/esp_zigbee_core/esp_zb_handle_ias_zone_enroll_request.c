/*
 * Last changed at upstream commit 327f0a5451f37830bdf6e6c5c0e1933fae07fcf0
 * https://github.com/espressif/esp-zigbee-sdk/commit/327f0a5451f37830bdf6e6c5c0e1933fae07fcf0
 * Upstream date: 2023-08-29 15:32:50 +0800
 * Upstream subject: esp-zigbee-sdk: add support zigbee sleep
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_handle_ias_zone_enroll_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_handle_ias_zone_enroll_request(undefined4 param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  
  puVar2 = (undefined2 *)malloc(4);
  iVar3 = zb_buf_get_tail_func(param_1,0x1b);
  if (puVar2 == (undefined2 *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC8,uVar5,"ESP_ZIGBEE_CORE",
                  "esp_zb_handle_ias_zone_enroll_request",0x626);
    uVar5 = 0;
  }
  else {
    uVar4 = zb_buf_len_func(param_1);
    if (3 < uVar4) {
      puVar6 = (undefined1 *)zb_buf_begin_func(param_1);
      *(undefined1 *)puVar2 = *puVar6;
      *(undefined1 *)((int)puVar2 + 1) = puVar6[1];
      *(undefined1 *)(puVar2 + 1) = puVar6[2];
      *(undefined1 *)((int)puVar2 + 3) = puVar6[3];
    }
    bVar1 = 3 >= uVar4;
    if ((zcl_ias_zone_enroll_req_cb == (code *)0x0) || (bVar1)) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC9,uVar5,"ESP_ZIGBEE_CORE",bVar1);
      uVar5 = 0;
    }
    else {
      (*zcl_ias_zone_enroll_req_cb)(*puVar2,puVar2[1]);
      uVar5 = 1;
    }
    if (*(char *)(iVar3 + 0x17) == '\0') {
      uVar5 = 0;
    }
  }
  return uVar5;
}

