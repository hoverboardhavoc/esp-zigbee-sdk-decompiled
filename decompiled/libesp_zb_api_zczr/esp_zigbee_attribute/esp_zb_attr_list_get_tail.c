/*
 * Last changed at upstream commit a67793c7af0a02d983345915fecc5d8fce7a0945
 * https://github.com/espressif/esp-zigbee-sdk/commit/a67793c7af0a02d983345915fecc5d8fce7a0945
 * Upstream date: 2024-02-22 20:57:09 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.2(af7a8c4d)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_attr_list_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * esp_zb_attr_list_get_tail(ushort *param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  if (param_1 == (ushort *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
    *param_4 = 0x102;
    puVar3 = (ushort *)0x0;
  }
  else {
    puVar2 = *(ushort **)(param_1 + 6);
    uVar1 = puVar2[5];
    if ((short)param_2 < 0) {
      if ((param_2 == 0x8000) && (-1 < (short)uVar1)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC3,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        *param_4 = 0x102;
        return param_1;
      }
    }
    else if (uVar1 != param_2) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC2,uVar4,"ESP_ZIGBEE_ATTRIBUTE",(uint)uVar1);
      *param_4 = 0x102;
      return param_1;
    }
    do {
      puVar3 = puVar2;
      if (puVar3 == (ushort *)0x0) {
        return (ushort *)0x0;
      }
      if (param_3 == *puVar3) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar4,"ESP_ZIGBEE_ATTRIBUTE",param_3);
        *param_4 = 0x102;
      }
      puVar2 = *(ushort **)(puVar3 + 6);
    } while (*(ushort **)(puVar3 + 6) != (ushort *)0x0);
  }
  return puVar3;
}

