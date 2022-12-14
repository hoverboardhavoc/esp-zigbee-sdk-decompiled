/*
 * Last changed at upstream commit dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * https://github.com/espressif/esp-zigbee-sdk/commit/dfdf370f9265e944dde2de8bee7a248c7515f1ef
 * Upstream date: 2022-12-14 19:24:05 +0800
 * Upstream subject: examples:Add ota application example(986c075)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_custom_cluster_add_custom_attr
          (int param_1,uint param_2,undefined1 param_3,undefined1 param_4,undefined4 param_5)

{
  ushort uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  ushort *puVar5;
  
  puVar3 = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
    uVar4 = 0x102;
  }
  else {
    uVar1 = (*(ushort **)(param_1 + 0xc))[5];
    puVar2 = *(ushort **)(param_1 + 0xc);
    if (uVar1 < 0xfc00) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC16,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
      uVar4 = 0x102;
    }
    else {
      do {
        puVar5 = puVar2;
        if (puVar5 == (ushort *)0x0) break;
        if (*puVar5 == param_2) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC3,uVar4,"ESP_ZIGBEE_ATTRIBUTE",param_2);
          return 0x102;
        }
        puVar2 = *(ushort **)(puVar5 + 6);
      } while (*(ushort **)(puVar5 + 6) != (ushort *)0x0);
      *puVar3 = (short)param_2;
      *(undefined1 *)(puVar3 + 1) = param_3;
      *(undefined1 *)((int)puVar3 + 3) = param_4;
      puVar3[2] = 0xffff;
      puVar3[3] = (short)param_5;
      puVar3[4] = (short)((uint)param_5 >> 0x10);
      puVar3[5] = uVar1;
      *(undefined4 *)(puVar3 + 6) = 0;
      if (puVar5 == (ushort *)0x0) {
        *(undefined2 **)(param_1 + 0xc) = puVar3;
        uVar4 = 0;
      }
      else {
        *(undefined2 **)(puVar5 + 6) = puVar3;
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

