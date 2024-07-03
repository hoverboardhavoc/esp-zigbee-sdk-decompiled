/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010202) */
/* WARNING: Removing unreachable block (ram,0x00010208) */

undefined4
esp_zb_custom_cluster_add_custom_attr
          (ushort *param_1,uint param_2,size_t param_3,uint param_4,void *param_5)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *__ptr;
  ushort *puVar3;
  size_t __size;
  int extraout_a1;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  void *__dest;
  int iVar7;
  
  iVar7 = 0x8000;
  if (param_1 == (ushort *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar2,0x10000);
    return 0x102;
  }
  uVar5 = (uint)*(ushort *)(*(int *)(param_1 + 6) + 10);
  puVar3 = param_1;
  while( true ) {
    if ((iVar7 == 0x8000) && (-1 < (short)uVar5)) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar2,0x10000);
      iVar7 = 0x102;
      puVar3 = param_1;
    }
    else {
      while (puVar4 = *(ushort **)(puVar3 + 6), puVar4 != (ushort *)0x0) {
        puVar3 = puVar4;
        if (*puVar4 == param_2) {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC4,uVar2,0x10000,param_2);
          return 0x102;
        }
      }
      iVar7 = 0;
    }
    __ptr = (undefined2 *)malloc(0x10);
    if (__ptr == (undefined2 *)0x0) {
      return 0x102;
    }
    uVar5 = param_4 & 0x40;
    if (uVar5 == 0) break;
    __size = param_3;
    if (param_5 != (void *)0x0) goto _L0;
    puVar3 = (ushort *)
             zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                       ,0x6b);
    iVar7 = extraout_a1;
  }
  __size = esp_zb_zcl_get_attribute_size(param_3,param_5);
  if (__size == 0xffff) goto _L0;
_L0:
  __dest = (void *)0x0;
  if (__size != 0) {
    __dest = malloc(__size);
    if (__dest == (void *)0x0) goto _L0;
    memcpy(__dest,param_5,__size);
  }
  __ptr[2] = 0xffff;
  iVar6 = *(int *)(param_1 + 6);
  *(char *)((int)__ptr + 3) = (char)param_4;
  *(char *)(__ptr + 1) = (char)param_3;
  uVar1 = *(undefined2 *)(iVar6 + 10);
  __ptr[3] = (short)__dest;
  *__ptr = (short)param_2;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = uVar1;
  *(undefined4 *)(__ptr + 6) = 0;
  *(undefined2 **)(puVar3 + 6) = __ptr;
  if (iVar7 == 0) {
    return 0;
  }
_L0:
  free(__ptr);
  return 0x102;
}

