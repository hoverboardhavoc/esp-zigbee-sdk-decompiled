/*
 * Last changed at upstream commit 6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * https://github.com/espressif/esp-zigbee-sdk/commit/6a9e3c6fdc96f7e7c0611d7b4a7e17141165ca31
 * Upstream date: 2023-04-06 16:02:34 +0800
 * Upstream subject: example: support single C6 gateway example and other API support(a1884f9)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_level_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_level_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  undefined2 *__ptr;
  int iVar1;
  undefined4 uVar2;
  int aiStack_24 [4];
  
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_24[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,8,param_2,aiStack_24);
  if (aiStack_24[0] != 0) {
    free(__ptr);
    return aiStack_24[0];
  }
  *__ptr = (short)param_2;
  if (param_2 == 0xf) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x18;
  }
  else if (param_2 < 0x10) {
    if (param_2 == 3) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else if (param_2 < 4) {
      if (param_2 == 1) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
      }
      else if (param_2 == 2) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
      else {
        if (param_2 != 0) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x20;
      }
    }
    else if (param_2 == 5) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else if (param_2 == 6) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else {
      if (param_2 != 4) {
_L0:
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 0x15;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
  }
  else if (param_2 == 0x13) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x21;
  }
  else if (param_2 < 0x14) {
    if (param_2 == 0x11) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x20;
    }
    else if (param_2 == 0x12) {
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
    else {
      if (param_2 != 0x10) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = 0x21;
    }
  }
  else if (param_2 == 0x4000) {
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x20;
  }
  else if (param_2 == 0xefff) {
    *(undefined1 *)((int)__ptr + 3) = 0x40;
    *(undefined1 *)(__ptr + 1) = 0;
  }
  else {
    if (param_2 != 0x14) goto _L0;
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x20;
  }
  __ptr[2] = 0xffff;
  __ptr[3] = (short)param_3;
  __ptr[4] = (short)((uint)param_3 >> 0x10);
  __ptr[5] = 8;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar1 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar1 + 0xc) = __ptr;
  }
  return 0;
}

