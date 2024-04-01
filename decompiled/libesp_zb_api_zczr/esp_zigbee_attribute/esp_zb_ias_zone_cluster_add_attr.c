/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ias_zone_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_ias_zone_cluster_add_attr(int param_1,uint param_2,undefined2 *param_3)

{
  ushort *puVar1;
  undefined2 *__ptr;
  undefined4 uVar2;
  undefined2 *__dest;
  undefined *puVar3;
  size_t __n;
  undefined2 uVar4;
  ushort *puVar5;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC1;
_L0:
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",puVar3,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  puVar1 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[5] != 0x500) {
    uVar2 = esp_log_timestamp();
    puVar3 = &_LC8;
    goto _L0;
  }
  do {
    puVar5 = puVar1;
    if (*puVar5 == param_2) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE",param_2);
      return 0x102;
    }
    puVar1 = *(ushort **)(puVar5 + 6);
  } while (*(ushort **)(puVar5 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 0x12) {
_L0:
    uVar4 = 0x120;
  }
  else {
    if (param_2 < 0x13) {
      if (param_2 == 2) {
        uVar4 = 0x119;
      }
      else {
        if (2 < param_2) {
          if (param_2 == 0x10) {
            __ptr[1] = 0x3f0;
            __dest = (undefined2 *)malloc(8);
            __n = 8;
_L0:
            memcpy(__dest,param_3,__n);
            goto _L0;
          }
          if (param_2 != 0x11) goto _L0;
          goto _L0;
        }
        uVar4 = 0x131;
        if (param_2 == 0) {
          uVar4 = 0x130;
          goto _L0;
        }
      }
_L0:
      __ptr[1] = uVar4;
      __dest = (undefined2 *)malloc(2);
      *__dest = *param_3;
      goto _L0;
    }
    if (param_2 != 0xe001) {
      if (param_2 < 0xe002) {
        if (param_2 == 0x13) {
          uVar4 = 800;
          goto _L0;
        }
        if (param_2 == 0xe000) goto _L0;
      }
      else {
        if (param_2 == 0xe002) {
          uVar4 = 0x4002;
          goto _L0;
        }
        if (param_2 == 0xeffe) {
          __ptr[1] = 0x4000;
          if (param_3 == (undefined2 *)0x0) {
            uVar2 = esp_log_timestamp();
            puVar3 = &_LC9;
            goto _L0;
          }
          *(undefined1 *)(__ptr + 1) = 0xc;
          __dest = (undefined2 *)malloc(0xc);
          __n = 0xc;
          goto _L0;
        }
      }
_L0:
      uVar2 = esp_log_timestamp();
      puVar3 = &_LC5;
_L0:
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",puVar3,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
      free(__ptr);
      return 0x102;
    }
_L0:
    uVar4 = 0x4001;
  }
_L0:
  __ptr[1] = uVar4;
  __dest = (undefined2 *)malloc(1);
  *(undefined1 *)__dest = *(undefined1 *)param_3;
_L0:
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[3] = (short)__dest;
  __ptr[5] = 0x500;
  *(undefined4 *)(__ptr + 6) = 0;
  *(undefined2 **)(puVar5 + 6) = __ptr;
  return 0;
}

