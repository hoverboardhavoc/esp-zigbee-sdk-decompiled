/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_commissioning_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_commissioning_cluster_add_attr(int param_1,uint param_2,undefined4 param_3)

{
  undefined2 *__ptr;
  int iVar1;
  size_t __size;
  void *pvVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  int iVar6;
  int aiStack_34 [3];
  
  if (param_2 == 0x13) {
    uVar5 = 0x10;
    uVar4 = 0x13;
  }
  else if (param_2 < 0x14) {
    if (param_2 == 5) {
      uVar5 = 0x20;
      uVar4 = 5;
    }
    else if (param_2 < 6) {
      if (param_2 == 2) {
        uVar5 = 0x21;
        uVar4 = 2;
      }
      else if (param_2 < 3) {
        if (param_2 == 0) {
          uVar5 = 0x21;
          uVar4 = 0;
        }
        else {
          uVar5 = 0xf0;
          uVar4 = 1;
        }
      }
      else if (param_2 == 3) {
        uVar5 = 0x1b;
        uVar4 = 3;
      }
      else {
        uVar5 = 0x20;
        uVar4 = 4;
      }
    }
    else if (param_2 == 0x11) {
      uVar5 = 0xf1;
      uVar4 = 0x11;
    }
    else if (param_2 == 0x12) {
      uVar5 = 0xf1;
      uVar4 = 0x12;
    }
    else if (param_2 == 6) {
      uVar5 = 0x30;
      uVar4 = 6;
    }
    else {
      if (param_2 != 0x10) goto _L0;
      uVar5 = 0xf0;
      uVar4 = 0x10;
    }
  }
  else if (param_2 == 0x20) {
    uVar5 = 0x20;
    uVar4 = 0x20;
  }
  else if (param_2 < 0x21) {
    if (param_2 == 0x16) {
      uVar5 = 0x30;
      uVar4 = 0x16;
    }
    else if (param_2 < 0x17) {
      if (param_2 == 0x14) {
        uVar5 = 0xf1;
        uVar4 = 0x14;
      }
      else {
        uVar5 = 0x20;
        uVar4 = 0x15;
      }
    }
    else {
      if (param_2 != 0x17) goto _L0;
      uVar5 = 0x21;
      uVar4 = 0x17;
    }
  }
  else if (param_2 == 0x41) {
    uVar5 = 0x20;
    uVar4 = 0x41;
  }
  else if (param_2 < 0x42) {
    if (param_2 == 0x21) {
      uVar5 = 0x21;
      uVar4 = 0x21;
    }
    else {
      if (param_2 != 0x40) goto _L0;
      uVar5 = 0x10;
      uVar4 = 0x40;
    }
  }
  else {
    if (param_2 != 0x42) {
_L0:
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar3,"ESP_ZIGBEE_ATTRIBUTE");
      return 0x102;
    }
    uVar5 = 0x20;
    uVar4 = 0x42;
  }
  __ptr = (undefined2 *)malloc(0x10);
  aiStack_34[0] = 0;
  iVar1 = esp_zb_attr_list_get_tail(param_1,0x15,uVar4,aiStack_34);
  iVar6 = aiStack_34[0];
  if (aiStack_34[0] == 0) {
    *__ptr = uVar4;
    __size = esp_zb_zcl_get_attribute_size(uVar5,param_3);
    if (__size == 0xffff) {
      iVar6 = 0x102;
    }
    else {
      pvVar2 = malloc(__size);
      __ptr[3] = (short)pvVar2;
      __ptr[4] = (short)((uint)pvVar2 >> 0x10);
      esp_zb_zcl_put_attribute_value(uVar5,param_3,__size);
      *(undefined1 *)((int)__ptr + 3) = 3;
      *(undefined1 *)(__ptr + 1) = uVar5;
      __ptr[2] = 0xffff;
      __ptr[5] = 0x15;
      *(undefined4 *)(__ptr + 6) = 0;
      if (iVar1 == 0) {
        *(undefined2 **)(param_1 + 0xc) = __ptr;
      }
      else {
        *(undefined2 **)(iVar1 + 0xc) = __ptr;
      }
    }
  }
  else {
    free(__ptr);
  }
  return iVar6;
}

