/*
 * Last changed at upstream commit 161b24f200d3999849a30e5fddeac9123c04dbfe
 * https://github.com/espressif/esp-zigbee-sdk/commit/161b24f200d3999849a30e5fddeac9123c04dbfe
 * Upstream date: 2022-09-02 14:39:54 +0800
 * Upstream subject: Components: Separation of the zigbee_core_api header
 * Source: libesp_zb_api_zczr -> esp_zigbee_api_attribute.o -> esp_zb_scenes_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_scenes_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

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
  if ((*(ushort **)(param_1 + 0xc))[4] != 5) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC7,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
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
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x21;
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else {
      if (param_2 != 1) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
  }
  else if (param_2 == 3) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x10;
  }
  else {
    if (param_2 != 4) {
_L0:
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x18;
  }
  *(undefined4 *)(__ptr + 2) = param_3;
  __ptr[4] = 5;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar3 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar3 + 6) = __ptr;
  }
  return 0;
}

