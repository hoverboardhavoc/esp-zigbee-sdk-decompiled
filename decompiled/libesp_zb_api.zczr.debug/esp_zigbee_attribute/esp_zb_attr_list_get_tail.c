/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_attribute.o -> esp_zb_attr_list_get_tail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * esp_zb_attr_list_get_tail
                   (ushort *param_1,uint param_2,uint param_3,uint param_4,undefined4 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar2,0x10000);
    *param_5 = 0x102;
  }
  else if (*(ushort *)(*(int *)(param_1 + 6) + 10) == param_2) {
    if (((short)param_2 < 0) && (param_4 == 0xffff)) {
      uVar2 = esp_log_timestamp();
      esp_log_write(2,0x10000,&_LC3,uVar2,0x10000);
    }
    do {
      puVar1 = param_1;
      param_1 = *(ushort **)(puVar1 + 6);
      if (param_1 == (ushort *)0x0) {
        *param_5 = 0;
        return puVar1;
      }
    } while ((*param_1 != param_3) || (param_1[2] != param_4));
    uVar2 = esp_log_timestamp(puVar1);
    esp_log_write(1,0x10000,&_LC4,uVar2,0x10000,param_3);
    *param_5 = 0x102;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar2,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),param_2)
    ;
    *param_5 = 0x102;
  }
  return (ushort *)0x0;
}

