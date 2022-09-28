/*
 * Last changed at upstream commit edae603135f5169e47a3eae722f314ece18018a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/edae603135f5169e47a3eae722f314ece18018a0
 * Upstream date: 2022-09-28 15:45:52 +0800
 * Upstream subject: Components: Update sdk_lib for support more devices/cluster
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_shade_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_shade_config_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  ushort *puVar1;
  undefined2 *__ptr;
  undefined4 uVar2;
  ushort *puVar3;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  puVar1 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[4] != 0x100) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  do {
    puVar3 = puVar1;
    if (puVar3 == (ushort *)0x0) break;
    if (*puVar3 == param_2) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC3,uVar2,"ESP_ZIGBEE_ATTRIBUTE",param_2);
      return 0x102;
    }
    puVar1 = *(ushort **)(puVar3 + 6);
  } while (*(ushort **)(puVar3 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 2) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x18;
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else {
      if (param_2 != 1) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
  }
  else if (param_2 == 0x10) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x21;
  }
  else {
    if (param_2 != 0x11) {
_L0:
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x30;
  }
  *(undefined4 *)(__ptr + 2) = param_3;
  __ptr[4] = 0x100;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar3 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar3 + 6) = __ptr;
  }
  return 0;
}

