/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
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
  undefined4 uVar3;
  
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    *param_4 = 0x102;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1 + 6) + 10);
    if ((short)param_2 < 0) {
      if ((param_2 == 0x8000) && (-1 < (short)uVar1)) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC3,uVar3,0x10000);
        *param_4 = 0x102;
        return param_1;
      }
    }
    else if (uVar1 != param_2) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,(uint)uVar1);
      *param_4 = 0x102;
      return param_1;
    }
    do {
      puVar2 = param_1;
      param_1 = *(ushort **)(puVar2 + 6);
      if (param_1 == (ushort *)0x0) {
        return puVar2;
      }
    } while (param_3 != *param_1);
    uVar3 = esp_log_timestamp(puVar2);
    esp_log_write(1,0x10000,&_LC4,uVar3,0x10000,param_3);
    *param_4 = 0x102;
  }
  return (ushort *)0x0;
}

