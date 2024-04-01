/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_on_off_switch_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_on_off_switch_config_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  ushort *puVar1;
  undefined2 *__ptr;
  undefined4 uVar2;
  undefined *puVar3;
  undefined1 uVar4;
  ushort *puVar5;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC1;
  }
  else {
    puVar1 = *(ushort **)(param_1 + 0xc);
    if ((*(ushort **)(param_1 + 0xc))[5] == 7) {
      do {
        puVar5 = puVar1;
        if (*puVar5 == param_2) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE",param_2);
          return 0x102;
        }
        puVar1 = *(ushort **)(puVar5 + 6);
      } while (*(ushort **)(puVar5 + 6) != (ushort *)0x0);
      *__ptr = (short)param_2;
      if (param_2 == 0) {
        uVar4 = 1;
      }
      else {
        if (param_2 != 0x10) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        uVar4 = 3;
      }
      *(undefined1 *)((int)__ptr + 3) = uVar4;
      *(undefined1 *)(__ptr + 1) = 0x18;
      __ptr[2] = 0xffff;
      __ptr[3] = (short)param_3;
      __ptr[4] = (short)((uint)param_3 >> 0x10);
      __ptr[5] = 7;
      *(undefined4 *)(__ptr + 6) = 0;
      *(undefined2 **)(puVar5 + 6) = __ptr;
      return 0;
    }
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC6;
  }
  esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",puVar3,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
  return 0x102;
}

