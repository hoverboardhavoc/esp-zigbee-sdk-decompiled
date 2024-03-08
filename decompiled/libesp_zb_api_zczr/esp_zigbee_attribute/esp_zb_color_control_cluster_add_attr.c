/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  undefined1 *puVar2;
  undefined2 *puVar3;
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
  if (param_2 == 0x4002) {
    *(undefined1 *)((int)__ptr + 3) = 0x11;
    *(undefined1 *)(__ptr + 1) = 0x20;
    puVar2 = (undefined1 *)malloc(1);
    *puVar2 = *(undefined1 *)param_3;
    __ptr[3] = (short)puVar2;
    __ptr[4] = (short)((uint)puVar2 >> 0x10);
  }
  else if (param_2 < 0x4003) {
    if (param_2 == 7) {
      *(undefined1 *)((int)__ptr + 3) = 0x15;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else if (param_2 < 8) {
      if (param_2 == 2) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
      else if (param_2 < 3) {
        if (param_2 == 0) {
          *(undefined1 *)((int)__ptr + 3) = 5;
          *(undefined1 *)(__ptr + 1) = 0x20;
          puVar2 = (undefined1 *)malloc(1);
          *puVar2 = *(undefined1 *)param_3;
          __ptr[3] = (short)puVar2;
          __ptr[4] = (short)((uint)puVar2 >> 0x10);
        }
        else {
          if (param_2 != 1) goto _L0;
          *(undefined1 *)((int)__ptr + 3) = 0x15;
          *(undefined1 *)(__ptr + 1) = 0x20;
          puVar2 = (undefined1 *)malloc(1);
          *puVar2 = *(undefined1 *)param_3;
          __ptr[3] = (short)puVar2;
          __ptr[4] = (short)((uint)puVar2 >> 0x10);
        }
      }
      else if (param_2 == 3) {
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
      else {
        if (param_2 != 4) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 0x15;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
    }
    else if (param_2 == 0x4000) {
      *(undefined1 *)((int)__ptr + 3) = 0x11;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else if (param_2 < 0x4001) {
      if (param_2 == 8) {
        *(undefined1 *)((int)__ptr + 3) = 1;
        *(undefined1 *)(__ptr + 1) = 0x30;
        puVar2 = (undefined1 *)malloc(1);
        *puVar2 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else {
        if (param_2 != 0xf) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 3;
        *(undefined1 *)(__ptr + 1) = 0x18;
        puVar2 = (undefined1 *)malloc(1);
        *puVar2 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x4001) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_L0,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
        free(__ptr);
        return 0x102;
      }
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x30;
      puVar2 = (undefined1 *)malloc(1);
      *puVar2 = *(undefined1 *)param_3;
      __ptr[3] = (short)puVar2;
      __ptr[4] = (short)((uint)puVar2 >> 0x10);
    }
  }
  else if (param_2 == 0x400a) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x19;
    puVar3 = (undefined2 *)malloc(2);
    *puVar3 = *param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
  }
  else if (param_2 < 0x400b) {
    if (param_2 == 0x4005) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else if (param_2 < 0x4006) {
      if (param_2 == 0x4003) {
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x20;
        puVar2 = (undefined1 *)malloc(1);
        *puVar2 = *(undefined1 *)param_3;
        __ptr[3] = (short)puVar2;
        __ptr[4] = (short)((uint)puVar2 >> 0x10);
      }
      else {
        if (param_2 != 0x4004) goto _L0;
        *(undefined1 *)((int)__ptr + 3) = 0x11;
        *(undefined1 *)(__ptr + 1) = 0x21;
        puVar3 = (undefined2 *)malloc(2);
        *puVar3 = *param_3;
        __ptr[3] = (short)puVar3;
        __ptr[4] = (short)((uint)puVar3 >> 0x10);
      }
    }
    else {
      if (param_2 != 0x4006) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
  }
  else if (param_2 == 0x400d) {
    *(undefined1 *)((int)__ptr + 3) = 1;
    *(undefined1 *)(__ptr + 1) = 0x21;
    puVar3 = (undefined2 *)malloc(2);
    *puVar3 = *param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
  }
  else if (param_2 < 0x400e) {
    if (param_2 == 0x400b) {
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
    else {
      if (param_2 != 0x400c) goto _L0;
      *(undefined1 *)((int)__ptr + 3) = 1;
      *(undefined1 *)(__ptr + 1) = 0x21;
      puVar3 = (undefined2 *)malloc(2);
      *puVar3 = *param_3;
      __ptr[3] = (short)puVar3;
      __ptr[4] = (short)((uint)puVar3 >> 0x10);
    }
  }
  else {
    if (param_2 != 0x4010) goto _L0;
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x21;
    puVar3 = (undefined2 *)malloc(2);
    *puVar3 = *param_3;
    __ptr[3] = (short)puVar3;
    __ptr[4] = (short)((uint)puVar3 >> 0x10);
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

