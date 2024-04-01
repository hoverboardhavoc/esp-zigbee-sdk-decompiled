/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_binary_input_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_binary_input_cluster_add_attr(int param_1,uint param_2,char *param_3)

{
  ushort *puVar1;
  undefined2 *__ptr;
  undefined4 uVar2;
  size_t sVar3;
  char *__dest;
  undefined *puVar4;
  undefined2 uVar5;
  ushort *puVar6;
  
  __ptr = (undefined2 *)malloc(0x10);
  if (param_1 == 0) {
    uVar2 = esp_log_timestamp();
    puVar4 = &_LC1;
_L0:
    esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",puVar4,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
    return 0x102;
  }
  puVar1 = *(ushort **)(param_1 + 0xc);
  if ((*(ushort **)(param_1 + 0xc))[5] != 0xf) {
    uVar2 = esp_log_timestamp();
    puVar4 = &_LC7;
    goto _L0;
  }
  do {
    puVar6 = puVar1;
    if (*puVar6 == param_2) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC4,uVar2,"ESP_ZIGBEE_ATTRIBUTE",param_2);
      return 0x102;
    }
    puVar1 = *(ushort **)(puVar6 + 6);
  } while (*(ushort **)(puVar6 + 6) != (ushort *)0x0);
  *__ptr = (short)param_2;
  if (param_2 == 0x54) {
_L0:
    uVar5 = 0x118;
  }
  else {
    if (param_2 < 0x55) {
      if (param_2 != 0x2e) {
        if (0x2e < param_2) {
          if (param_2 != 0x51) goto _L0;
          uVar5 = 0x110;
          goto _L0;
        }
        if ((param_2 != 4) && (param_2 != 0x1c)) {
_L0:
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"ESP_ZIGBEE_ATTRIBUTE",&_LC5,uVar2,"ESP_ZIGBEE_ATTRIBUTE");
          free(__ptr);
          return 0x102;
        }
      }
      __ptr[1] = 0x142;
      sVar3 = strlen(param_3);
      __dest = (char *)malloc(sVar3 + 1);
      strcpy(__dest,param_3);
      goto _L0;
    }
    if (param_2 == 0x6f) {
      uVar5 = 0x518;
    }
    else {
      if (0x6f < param_2) {
        if (param_2 != 0x100) goto _L0;
        __ptr[1] = 0x123;
        __dest = (char *)malloc(4);
        *(undefined4 *)__dest = *(undefined4 *)param_3;
        goto _L0;
      }
      if (param_2 != 0x55) {
        if (param_2 != 0x67) goto _L0;
        goto _L0;
      }
      uVar5 = 0x510;
    }
  }
_L0:
  __ptr[1] = uVar5;
  __dest = (char *)malloc(1);
  *__dest = *param_3;
_L0:
  __ptr[3] = (short)__dest;
  __ptr[2] = 0xffff;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = 0xf;
  *(undefined4 *)(__ptr + 6) = 0;
  *(undefined2 **)(puVar6 + 6) = __ptr;
  return 0;
}

