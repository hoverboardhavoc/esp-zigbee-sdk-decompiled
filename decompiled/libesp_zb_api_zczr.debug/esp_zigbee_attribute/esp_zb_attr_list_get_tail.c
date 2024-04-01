/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_attribute.o -> esp_zb_attr_list_get_tail
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
    esp_log_write(1,0x10000,&_LC4,uVar4,0x10000);
    *param_4 = 0x102;
    puVar3 = (ushort *)0x0;
  }
  else {
    puVar2 = *(ushort **)(param_1 + 6);
    uVar1 = puVar2[5];
    if ((short)param_2 < 0) {
      if ((param_2 == 0x8000) && (-1 < (short)uVar1)) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC6,uVar4,0x10000);
        *param_4 = 0x102;
        return param_1;
      }
    }
    else if (uVar1 != param_2) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar4,0x10000,(uint)uVar1);
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
        esp_log_write(1,0x10000,&_LC7,uVar4,0x10000,param_3);
        *param_4 = 0x102;
      }
      puVar2 = *(ushort **)(puVar3 + 6);
    } while (*(ushort **)(puVar3 + 6) != (ushort *)0x0);
  }
  return puVar3;
}

