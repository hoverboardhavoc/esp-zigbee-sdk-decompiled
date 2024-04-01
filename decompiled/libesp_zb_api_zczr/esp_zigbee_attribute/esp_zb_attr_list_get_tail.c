/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
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
  undefined4 uVar3;
  undefined *puVar4;
  ushort *puVar5;
  
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC1;
  }
  else {
    puVar5 = *(ushort **)(param_1 + 6);
    uVar1 = puVar5[5];
    if (-1 < (short)param_2) {
      if (uVar1 == param_2) {
_L0:
        do {
          puVar2 = puVar5;
          if (*puVar2 == param_3) {
            uVar3 = esp_log_timestamp();
            esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar3,"ESP_ZIGBEE_ATTRIBUTE",param_3);
            *param_4 = 0x102;
          }
          puVar5 = *(ushort **)(puVar2 + 6);
        } while (*(ushort **)(puVar2 + 6) != (ushort *)0x0);
        return puVar2;
      }
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC2,uVar3,"ESP_ZIGBEE_ATTRIBUTE",(uint)uVar1);
      goto _L0;
    }
    if ((param_2 != 0x8000) || ((short)uVar1 < 0)) goto _L0;
    uVar3 = esp_log_timestamp();
    puVar4 = &_LC3;
  }
  esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",puVar4,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
_L0:
  *param_4 = 0x102;
  return param_1;
}

