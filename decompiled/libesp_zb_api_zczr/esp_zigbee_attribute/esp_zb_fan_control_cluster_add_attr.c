/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_fan_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001024e) */
/* WARNING: Removing unreachable block (ram,0x00010254) */
/* WARNING: Removing unreachable block (ram,0x00010268) */
/* WARNING: Removing unreachable block (ram,0x00010270) */
/* WARNING: Removing unreachable block (ram,0x00010278) */

undefined4 esp_zb_fan_control_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  int iVar6;
  void *__dest;
  int iVar7;
  
  if (1 < param_2) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC6,uVar3,0x10000);
    return 0x102;
  }
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    return 0x102;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar4 = param_1;
  if (sVar1 == 0x202) {
    while (puVar5 = *(ushort **)(puVar4 + 6), puVar5 != (ushort *)0x0) {
      puVar4 = puVar5;
      if (*puVar5 == param_2) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar3,0x10000,param_2);
        return 0x102;
      }
    }
    iVar7 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,sVar1);
    iVar7 = 0x102;
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    return 0x102;
  }
  __size = esp_zb_zcl_get_attribute_size(0x30,param_3);
  if (__size != 0xffff) {
    __dest = (void *)0x0;
    if (__size != 0) {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) goto _L0;
      memcpy(__dest,param_3,__size);
    }
    __ptr[2] = 0xffff;
    iVar6 = *(int *)(param_1 + 6);
    *(undefined1 *)((int)__ptr + 3) = 3;
    *(undefined1 *)(__ptr + 1) = 0x30;
    uVar2 = *(undefined2 *)(iVar6 + 10);
    __ptr[3] = (short)__dest;
    *__ptr = (short)param_2;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[5] = uVar2;
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined2 **)(puVar4 + 6) = __ptr;
    if (iVar7 == 0) {
      return 0;
    }
  }
_L0:
  free(__ptr);
  return 0x102;
}

