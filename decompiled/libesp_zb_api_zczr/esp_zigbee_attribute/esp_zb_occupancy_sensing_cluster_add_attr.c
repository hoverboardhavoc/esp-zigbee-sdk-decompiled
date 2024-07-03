/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_occupancy_sensing_cluster_add_attr
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

undefined4 esp_zb_occupancy_sensing_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  void *__dest;
  int iVar10;
  
  if (param_2 == 2) {
    uVar5 = 1;
_L0:
    uVar4 = 0x18;
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      uVar5 = 5;
      goto _L0;
    }
    uVar5 = 1;
    uVar4 = 0x30;
  }
  else if (param_2 == 0x12) {
_L0:
    uVar5 = 3;
    uVar4 = 0x20;
  }
  else {
    if (param_2 < 0x13) {
      if (param_2 != 0x10) {
        uVar5 = 3;
        uVar4 = 0x29;
        if (param_2 != 0x11) goto _L0;
        goto _L0;
      }
    }
    else {
      if (0x31 < param_2) {
        uVar8 = 0x32;
_L577:
        if (param_2 != uVar8) {
_L0:
          uVar3 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC6,uVar3,0x10000);
          return 0x102;
        }
        goto _L0;
      }
      if (param_2 < 0x30) {
        if (0x21 < param_2) {
          uVar8 = 0x22;
          goto _L577;
        }
        if (param_2 < 0x20) goto _L0;
      }
    }
    uVar5 = 3;
    uVar4 = 0x21;
  }
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    return 0x102;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar6 = param_1;
  if (sVar1 == 0x406) {
    while (puVar7 = *(ushort **)(puVar6 + 6), puVar7 != (ushort *)0x0) {
      puVar6 = puVar7;
      if (*puVar7 == param_2) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar3,0x10000,param_2);
        return 0x102;
      }
    }
    iVar10 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,sVar1);
    iVar10 = 0x102;
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    return 0x102;
  }
  __size = esp_zb_zcl_get_attribute_size(uVar4,param_3);
  if (__size != 0xffff) {
    __dest = (void *)0x0;
    if (__size != 0) {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) goto _L0;
      memcpy(__dest,param_3,__size);
    }
    __ptr[2] = 0xffff;
    iVar9 = *(int *)(param_1 + 6);
    *(undefined1 *)((int)__ptr + 3) = uVar5;
    *(undefined1 *)(__ptr + 1) = uVar4;
    uVar2 = *(undefined2 *)(iVar9 + 10);
    __ptr[3] = (short)__dest;
    *__ptr = (short)param_2;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[5] = uVar2;
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined2 **)(puVar6 + 6) = __ptr;
    if (iVar10 == 0) {
      return 0;
    }
  }
_L0:
  free(__ptr);
  return 0x102;
}

