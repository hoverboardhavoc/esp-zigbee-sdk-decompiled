/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ias_zone_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ushort *puVar8;
  ushort *puVar9;
  undefined2 *__ptr;
  undefined2 *puVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar12 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC1,uVar12,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  puVar8 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[5] != 0x500) {
    uVar12 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC8,uVar12,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  do {
    puVar9 = puVar8;
    if (puVar9 == (ushort *)0x0) break;
    if (*puVar9 == param_2) {
      uVar12 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar12,"ESP_ZIGBEE_ATTRIBUTE",param_2);
      return 0x102;
    }
    puVar8 = *(ushort **)(puVar9 + 6);
  } while (*(ushort **)(puVar9 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 0x10) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0xf0;
    puVar11 = (undefined1 *)malloc(8);
    uVar1 = *(undefined1 *)((int)param_3 + 1);
    uVar2 = *(undefined1 *)(param_3 + 1);
    uVar3 = *(undefined1 *)((int)param_3 + 3);
    uVar4 = *(undefined1 *)(param_3 + 2);
    uVar5 = *(undefined1 *)((int)param_3 + 5);
    uVar6 = *(undefined1 *)(param_3 + 3);
    uVar7 = *(undefined1 *)((int)param_3 + 7);
    *puVar11 = *(undefined1 *)param_3;
    puVar11[1] = uVar1;
    puVar11[2] = uVar2;
    puVar11[3] = uVar3;
    puVar11[4] = uVar4;
    puVar11[5] = uVar5;
    puVar11[6] = uVar6;
    puVar11[7] = uVar7;
    __ptr[3] = (short)puVar11;
    __ptr[4] = (short)((uint)puVar11 >> 0x10);
  }
  else if (param_2 < 0x11) {
    if (param_2 == 1) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x31;
      puVar10 = (undefined2 *)malloc(2);
      *puVar10 = *param_3;
      __ptr[3] = (short)puVar10;
      __ptr[4] = (short)((uint)puVar10 >> 0x10);
    }
    else if (param_2 == 2) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x19;
      puVar10 = (undefined2 *)malloc(2);
      *puVar10 = *param_3;
      __ptr[3] = (short)puVar10;
      __ptr[4] = (short)((uint)puVar10 >> 0x10);
    }
    else {
      if (param_2 != 0) {
_L0:
        uVar12 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar12,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
      puVar11 = (undefined1 *)malloc(1);
      *puVar11 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar11;
      __ptr[4] = (short)((uint)puVar11 >> 0x10);
    }
  }
  else if (param_2 == 0x12) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar11 = (undefined1 *)malloc(1);
    *puVar11 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar11;
    __ptr[4] = (short)((uint)puVar11 >> 0x10);
  }
  else if (param_2 == 0x13) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar11 = (undefined1 *)malloc(1);
    *puVar11 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar11;
    __ptr[4] = (short)((uint)puVar11 >> 0x10);
  }
  else {
    if (param_2 != 0x11) goto _L0;
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar11 = (undefined1 *)malloc(1);
    *puVar11 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar11;
    __ptr[4] = (short)((uint)puVar11 >> 0x10);
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0x500;
  *(undefined4 *)(__ptr + 6) = 0;
  if (puVar9 == (ushort *)0x0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(puVar9 + 6) = __ptr;
  }
  return 0;
}

