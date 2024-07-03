/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ep_list_add_ep(byte *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined1 *__ptr;
  undefined1 *puVar3;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  
  if (param_1 == (byte *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC2,uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_ep",
                  0x4f);
  }
  else {
    do {
      pbVar1 = *(byte **)(param_1 + 0x24);
      if (pbVar1 == (byte *)0x0) {
        __ptr = (undefined1 *)malloc(0x28);
        if (__ptr == (undefined1 *)0x0) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC4,uVar2,"ESP_ZIGBEE_ENDPOINT",
                        "esp_zb_ep_list_add_ep",0x5a);
          return 0x101;
        }
        puVar3 = (undefined1 *)malloc(6);
        if (puVar3 != (undefined1 *)0x0) {
          memset(__ptr,0,0x28);
          uStack_28 = (undefined1)param_3;
          uStack_27 = (undefined1)(param_3 >> 8);
          uStack_26 = (undefined1)(param_3 >> 0x10);
          uStack_25 = (undefined1)(param_3 >> 0x18);
          uStack_24 = (undefined1)param_4;
          uStack_23 = (undefined1)((uint)param_4 >> 8);
          *puVar3 = uStack_28;
          puVar3[1] = uStack_27;
          puVar3[2] = uStack_26;
          puVar3[3] = uStack_25;
          puVar3[4] = uStack_24;
          puVar3[5] = uStack_23;
          *__ptr = uStack_28;
          __ptr[1] = uStack_27;
          __ptr[2] = uStack_26;
          *(undefined1 **)(__ptr + 0xc) = puVar3;
          __ptr[0x11] = (char)param_2;
          __ptr[0x12] = (char)((uint)param_2 >> 8);
          __ptr[0x13] = (char)((uint)param_2 >> 0x10);
          __ptr[0x14] = (char)((uint)param_2 >> 0x18);
          *(undefined1 **)(param_1 + 0x24) = __ptr;
          return 0;
        }
        free(__ptr);
        return 0x101;
      }
      param_1 = pbVar1;
    } while ((uint)*pbVar1 != (param_3 & 0xff));
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ENDPOINT",&_LC3,uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_ep",
                  0x56,param_3 & 0xff);
  }
  return 0x102;
}

