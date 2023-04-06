/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_attr_list_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * esp_zb_attr_list_get_tail(ushort *param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
    *param_4 = 0x102;
    puVar2 = (ushort *)0x0;
  }
  else {
    puVar1 = *(ushort **)(param_1 + 6);
    uVar4 = (uint)puVar1[5];
    if (param_2 < 0xfc00) {
      if (uVar4 != param_2) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC2,uVar3,"ESP_ZIGBEE_ATTRIBUTE",uVar4);
        *param_4 = 0x102;
        return param_1;
      }
    }
    else if ((param_2 == 0xfc00) && (uVar4 < 0xfc00)) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC3,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
      *param_4 = 0x102;
      return param_1;
    }
    do {
      puVar2 = puVar1;
      if (puVar2 == (ushort *)0x0) {
        return (ushort *)0x0;
      }
      if (param_3 == *puVar2) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar3,"ESP_ZIGBEE_ATTRIBUTE",param_3);
        *param_4 = 0x102;
      }
      puVar1 = *(ushort **)(puVar2 + 6);
    } while (*(ushort **)(puVar2 + 6) != (ushort *)0x0);
  }
  return puVar2;
}

