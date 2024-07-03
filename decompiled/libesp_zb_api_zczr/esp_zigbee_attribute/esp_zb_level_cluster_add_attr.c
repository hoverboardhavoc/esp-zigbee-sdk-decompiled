/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_level_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_level_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *__ptr;
  ushort *puVar3;
  size_t __size;
  undefined4 uVar4;
  int extraout_a1;
  size_t sVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort uVar8;
  int iVar9;
  void *__dest;
  int iVar10;
  
  if (param_2 < 7) {
    if (param_2 < 5) {
      if (param_2 != 4) {
        uVar6 = 1;
        if (param_2 < 2) {
          if (param_2 != 0) goto _L0;
          uVar6 = 0x15;
        }
        else {
          uVar6 = 1;
        }
_L0:
        sVar5 = 0x20;
        goto _L0;
      }
      uVar6 = 0x15;
    }
    else {
      uVar6 = 1;
    }
  }
  else {
    if (0x13 < param_2) {
      if (param_2 == 0xefff) {
        uVar6 = 0x40;
        sVar5 = 0x12;
        goto _L0;
      }
      if (0xefff < param_2) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC6,uVar4,0x10000);
        return 0x102;
      }
      if (param_2 != 0x14) {
        uVar6 = 3;
        sVar5 = 0x20;
        if (param_2 == 0x4000) goto _L0;
        goto _L0;
      }
_L0:
      uVar6 = 3;
      goto _L0;
    }
    if (param_2 < 0x12) {
      if (param_2 == 0xf) {
        uVar6 = 3;
        sVar5 = 0x18;
        goto _L0;
      }
      if (param_2 < 0xf) goto _L0;
      if (param_2 != 0x10) goto _L0;
    }
    uVar6 = 3;
  }
_L0:
  sVar5 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000);
    return 0x102;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar3 = param_1;
  if (sVar1 == 8) goto _L0;
  uVar4 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC2,uVar4,0x10000,sVar1);
_L0:
  iVar10 = 0x102;
  puVar3 = param_1;
  do {
    __ptr = (undefined2 *)malloc(0x10);
    if (__ptr == (undefined2 *)0x0) {
      return 0x102;
    }
    uVar8 = uVar6 & 0x40;
    if (uVar8 == 0) {
      __size = esp_zb_zcl_get_attribute_size(sVar5,param_3);
      if (__size == 0xffff) goto _L0;
_L0:
      __dest = (void *)0x0;
      if (__size != 0) {
        __dest = malloc(__size);
        if (__dest == (void *)0x0) goto _L0;
        memcpy(__dest,param_3,__size);
      }
      __ptr[2] = 0xffff;
      iVar9 = *(int *)(param_1 + 6);
      *(char *)((int)__ptr + 3) = (char)uVar6;
      *(char *)(__ptr + 1) = (char)sVar5;
      uVar2 = *(undefined2 *)(iVar9 + 10);
      __ptr[3] = (short)__dest;
      *__ptr = (short)param_2;
      __ptr[4] = (short)((uint)__dest >> 0x10);
      __ptr[5] = uVar2;
      *(undefined4 *)(__ptr + 6) = 0;
      *(undefined2 **)(puVar3 + 6) = __ptr;
      if (iVar10 == 0) {
        return 0;
      }
_L0:
      free(__ptr);
      return 0x102;
    }
    __size = sVar5;
    if (param_3 != (void *)0x0) goto _L0;
    puVar3 = (ushort *)
             zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                       ,0x6b);
    if ((extraout_a1 == 0x8000) && (-1 < (short)uVar8)) break;
_L0:
    while (puVar7 = *(ushort **)(puVar3 + 6), puVar7 != (ushort *)0x0) {
      puVar3 = puVar7;
      if (*puVar7 == param_2) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar4,0x10000,param_2);
        return 0x102;
      }
    }
    iVar10 = 0;
  } while( true );
  uVar4 = esp_log_timestamp();
  esp_log_write(1,0x10000,&_LC3,uVar4,0x10000);
  goto _L0;
}

