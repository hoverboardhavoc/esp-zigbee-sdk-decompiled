/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ota_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_ota_cluster_add_attr(int param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  int iVar2;
  undefined2 *__ptr;
  int iVar3;
  undefined4 *__dest;
  undefined4 uVar4;
  void *pvVar5;
  undefined2 uVar6;
  int iStack_24;
  
  __ptr = (undefined2 *)malloc(0x10);
  iStack_24 = 0;
  iVar3 = esp_zb_attr_list_get_tail(param_1,0x19,param_2,&iStack_24);
  iVar2 = iStack_24;
  if (iStack_24 != 0) {
    free(__ptr);
    return iVar2;
  }
  *__ptr = (short)param_2;
  if (param_2 == 8) goto _L0;
  if (8 < param_2) {
    if (param_2 == 0xfff0) {
      __ptr[1] = 0x4010;
      __dest = (undefined4 *)malloc(0x10);
      bVar1 = *(byte *)(param_3 + 2);
      pvVar5 = malloc((uint)bVar1 << 3);
      *__dest = param_3;
      __dest[1] = param_3 + 1;
      *(byte *)(__dest + 2) = bVar1;
      __dest[3] = pvVar5;
      goto _L0;
    }
    if (param_2 < 0xfff1) {
      if (param_2 != 0xb) {
        if (param_2 < 0xc) {
          if (param_2 != 9) goto _L0;
          goto _L0;
        }
        if (param_2 != 0xc) {
_L0:
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar4,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
      }
_L0:
      uVar6 = 0x130;
    }
    else {
      if (param_2 == 0xfff2) goto _L0;
      if (param_2 != 0xfff3) {
        if (param_2 != 0xfff1) goto _L0;
        __ptr[1] = 0x4010;
        __dest = (undefined4 *)malloc(0x10);
        uVar6 = *(undefined2 *)param_3;
        *__dest = 0;
        *(undefined2 *)(__dest + 1) = uVar6;
        *(undefined2 *)((int)__dest + 6) = 1;
        uVar6 = *(undefined2 *)((int)param_3 + 2);
        *(undefined1 *)((int)__dest + 0xb) = 0;
        *(undefined1 *)(__dest + 3) = 0;
        *(undefined2 *)(__dest + 2) = uVar6;
        *(undefined1 *)((int)__dest + 10) = *(undefined1 *)(param_3 + 1);
        goto _L0;
      }
      uVar6 = 0x120;
    }
    __ptr[1] = uVar6;
    __dest = (undefined4 *)malloc(1);
    *(undefined1 *)__dest = *(undefined1 *)param_3;
    goto _L0;
  }
  if (param_2 != 4) {
    if (4 < param_2) {
      if (param_2 == 6) goto _L0;
_L0:
      __ptr[1] = 0x121;
      __dest = (undefined4 *)malloc(2);
      *(undefined2 *)__dest = *(undefined2 *)param_3;
      goto _L0;
    }
    if (param_2 != 2) {
      if (param_2 == 3) goto _L0;
      if (param_2 == 0) {
        __ptr[1] = 0x1f0;
        __dest = (undefined4 *)malloc(8);
        memcpy(__dest,param_3,8);
        goto _L0;
      }
    }
  }
_L0:
  __ptr[1] = 0x123;
  __dest = (undefined4 *)malloc(4);
  *__dest = *param_3;
_L0:
  __ptr[3] = (short)__dest;
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = 0x19;
  *(undefined4 *)(__ptr + 6) = 0;
  if (iVar3 == 0) {
    *(undefined2 **)(param_1 + 0xc) = __ptr;
  }
  else {
    *(undefined2 **)(iVar3 + 0xc) = __ptr;
  }
  return 0;
}

