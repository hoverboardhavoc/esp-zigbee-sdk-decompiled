/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_endpoint.o -> esp_zb_ep_list_add_ep
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
    esp_log(1,"ESP_ZIGBEE_ENDPOINT","E (%lu) %s: %s(%d): Uninitialized endpoint linked list!\n",
            uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_ep",0x4f);
  }
  else {
    do {
      pbVar1 = *(byte **)(param_1 + 0x24);
      if (pbVar1 == (byte *)0x0) {
        __ptr = (undefined1 *)malloc(0x28);
        if (__ptr == (undefined1 *)0x0) {
          uVar2 = esp_log_timestamp();
          esp_log(1,"ESP_ZIGBEE_ENDPOINT","E (%lu) %s: %s(%d): No memory for endpoint list node\n",
                  uVar2,"ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_ep",0x5a);
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
    esp_log(1,"ESP_ZIGBEE_ENDPOINT","E (%lu) %s: %s(%d): Duplicated endpoint id:%d\n",uVar2,
            "ESP_ZIGBEE_ENDPOINT","esp_zb_ep_list_add_ep",0x56,param_3 & 0xff);
  }
  return 0x102;
}

