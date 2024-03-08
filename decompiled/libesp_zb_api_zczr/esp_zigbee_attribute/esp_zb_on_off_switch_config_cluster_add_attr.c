/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  ushort *puVar3;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
    uVar2 = 0x102;
  }
  else {
    puVar1 = *(ushort **)(param_1 + 0xc);
    if ((*(ushort **)(param_1 + 0xc))[5] == 7) {
      do {
        puVar3 = puVar1;
        if (puVar3 == (ushort *)0x0) break;
        if (*puVar3 == param_2) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE",param_2);
          return 0x102;
        }
        puVar1 = *(ushort **)(puVar3 + 6);
      } while (*(ushort **)(puVar3 + 6) != (ushort *)0x0);
      *__ptr = (short)param_2;
      if (param_2 == 0) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x18;
      }
      else {
        if (param_2 != 0x10) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x18;
      }
      __ptr[2] = 0xffff;
      __ptr[3] = (short)param_3;
      __ptr[4] = (short)((uint)param_3 >> 0x10);
      __ptr[5] = 7;
      *(undefined4 *)(__ptr + 6) = 0;
      if (puVar3 == (ushort *)0x0) {
        *(undefined2 **)(param_1 + 0xc) = __ptr;
        uVar2 = 0;
      }
      else {
        *(undefined2 **)(puVar3 + 6) = __ptr;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC6,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
      uVar2 = 0x102;
    }
  }
  return uVar2;
}

