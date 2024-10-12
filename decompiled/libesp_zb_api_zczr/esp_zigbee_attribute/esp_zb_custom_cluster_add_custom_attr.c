/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000101fc) */
/* WARNING: Removing unreachable block (ram,0x00010202) */

undefined4
esp_zb_custom_cluster_add_custom_attr
          (ushort *param_1,uint param_2,size_t param_3,byte param_4,void *param_5)

{
  undefined2 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined *puVar5;
  int iVar6;
  
  if (param_1 == (ushort *)0x0) {
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC1;
_L28:
    esp_log_write(1,0x10000,puVar5,uVar4,0x10000);
    return 0x102;
  }
  puVar2 = param_1;
  if (-1 < *(short *)(*(int *)(param_1 + 6) + 10)) {
    uVar4 = esp_log_timestamp();
    puVar5 = &_LC3;
    goto _L28;
  }
  while (puVar3 = *(ushort **)(puVar2 + 6), puVar3 != (ushort *)0x0) {
    puVar2 = puVar3;
    if (*puVar3 == param_2) {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC4,uVar4,0x10000,param_2);
      return 0x102;
    }
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    return 0x102;
  }
  if ((param_4 & 0x40) == 0) {
_L0:
    __size = esp_zb_zcl_get_attribute_size(param_3,param_5);
    if (__size == 0xffff) goto _L0;
  }
  else {
    __size = param_3;
    if (param_5 == (void *)0x0) {
      zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c",
                0x6c);
      goto _L0;
    }
  }
  __dest = (void *)0x0;
  if (__size != 0) {
    __dest = malloc(__size);
    if (__dest == (void *)0x0) {
_L0:
      free(__ptr);
      return 0x102;
    }
    memcpy(__dest,param_5,__size);
  }
  __ptr[2] = 0xffff;
  iVar6 = *(int *)(param_1 + 6);
  *(byte *)((int)__ptr + 3) = param_4;
  *(char *)(__ptr + 1) = (char)param_3;
  uVar1 = *(undefined2 *)(iVar6 + 10);
  __ptr[3] = (short)__dest;
  *__ptr = (short)param_2;
  __ptr[4] = (short)((uint)__dest >> 0x10);
  __ptr[5] = uVar1;
  *(undefined4 *)(__ptr + 6) = 0;
  *(undefined2 **)(puVar2 + 6) = __ptr;
  return 0;
}

