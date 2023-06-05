/*
 * Last changed at upstream commit 503c5e49627f84174ce142bf784c3f01532fb5c9
 * https://github.com/espressif/esp-zigbee-sdk/commit/503c5e49627f84174ce142bf784c3f01532fb5c9
 * Upstream date: 2023-06-05 10:37:46 +0800
 * Upstream subject: esp-zigbee-sdk: optimize the zigbee cluster implementation(0f0acd4)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_color_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_color_control_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  undefined2 *__ptr;
  int iVar1;
  undefined2 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int aiStack_24 [2];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0x300,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0x4001) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x30;
    puVar3 = (undefined1 *)malloc(1);
    *puVar3 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
  }
  else if (param_2 < 0x4002) {
    if (param_2 == 7) {
      *(undefined1 *)((int)__ptr + 3) = 0x15;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else if (param_2 < 8) {
      if (param_2 == 3) {
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else if (param_2 < 4) {
        if (param_2 == 0) {
          *(undefined1 *)((int)__ptr + 3) = 5;
          *(undefined1 *)(__ptr + 1) = 0x20;
          puVar3 = (undefined1 *)malloc(1);
          *puVar3 = *(undefined1 *)param_3;
          __ptr[3] = (short)puVar3;
          __ptr[4] = (short)((uint)puVar3 >> 0x10);
        }
        else {
          if (param_2 != 1) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 0x15;
          *(undefined1 *)(__ptr + 1) = 0x20;
          puVar3 = (undefined1 *)malloc(1);
          *puVar3 = *(undefined1 *)param_3;
          __ptr[3] = (short)puVar3;
          __ptr[4] = (short)((uint)puVar3 >> 0x10);
        }
      }
      else {
        if (param_2 != 4) {
_L0:
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar2 = (undefined2 *)malloc(2);
        *puVar2 = *param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
    }
    else if (param_2 == 0xf) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x18;
      puVar3 = (undefined1 *)malloc(1);
      *puVar3 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else if (param_2 == 0x4000) {
      *(undefined1 *)((int)__ptr + 3) = 0x11;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else {
      if (param_2 != 8) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
      puVar3 = (undefined1 *)malloc(1);
      *puVar3 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
  }
  else if (param_2 == 0x4006) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x21;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else if (param_2 < 0x4007) {
    if (param_2 == 0x4004) {
      *(undefined1 *)((int)__ptr + 3) = 0x11;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
    else if (param_2 < 0x4005) {
      if (param_2 == 0x4002) {
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x20;
        puVar3 = (undefined1 *)malloc(1);
        *puVar3 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
      else {
        if (param_2 != 0x4003) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x20;
        puVar3 = (undefined1 *)malloc(1);
        *puVar3 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x4005) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar2 = (undefined2 *)malloc(2);
      *puVar2 = *param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
  }
  else if (param_2 == 0x400b) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x21;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else if (param_2 == 0x400c) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x21;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else {
    if (param_2 != 0x400a) goto _L0;
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x19;
    puVar2 = (undefined2 *)malloc(2);
    *puVar2 = *param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  __ptr[2] = 0xffff;
  __ptr[5] = 0x300;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

