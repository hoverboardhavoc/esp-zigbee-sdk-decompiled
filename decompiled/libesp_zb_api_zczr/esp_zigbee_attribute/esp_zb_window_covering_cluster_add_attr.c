/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_window_covering_cluster_add_attr
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

undefined4 esp_zb_window_covering_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  undefined2 *__ptr;
  size_t __size;
  undefined4 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  void *__dest;
  int iVar10;
  
  if (param_2 < 0x14) {
    if (param_2 < 0x10) {
      if (param_2 == 7) {
        uVar6 = 1;
        goto _L0;
      }
      if (param_2 < 8) {
        uVar6 = 1;
        uVar5 = 0x30;
        uVar3 = 1;
        if (param_2 != 0) goto _L0;
      }
      else {
        if (1 < (param_2 - 8 & 0xffff)) goto _L0;
        uVar6 = 0x15;
        uVar5 = 0x20;
      }
    }
    else {
      uVar3 = 1;
_L0:
      uVar6 = uVar3;
      uVar5 = 0x21;
    }
  }
  else {
    if (param_2 != 0x17) {
      if (0x17 < param_2) {
        if (1 < (param_2 - 0x18 & 0xffff)) {
_L0:
          uVar4 = esp_log_timestamp();
          esp_log_write(1,0x10000,&_LC6,uVar4,0x10000);
          return 0x102;
        }
        uVar6 = 3;
        uVar5 = 0x41;
        goto _L0;
      }
      uVar3 = 3;
      goto _L0;
    }
    uVar6 = 3;
_L0:
    uVar5 = 0x18;
  }
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000);
    return 0x102;
  }
  sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
  puVar7 = param_1;
  if (sVar1 == 0x102) {
    while (puVar8 = *(ushort **)(puVar7 + 6), puVar8 != (ushort *)0x0) {
      puVar7 = puVar8;
      if (*puVar8 == param_2) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC4,uVar4,0x10000,param_2);
        return 0x102;
      }
    }
    iVar10 = 0;
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC2,uVar4,0x10000,sVar1);
    iVar10 = 0x102;
  }
  __ptr = (undefined2 *)malloc(0x10);
  if (__ptr == (undefined2 *)0x0) {
    return 0x102;
  }
  __size = esp_zb_zcl_get_attribute_size(uVar5,param_3);
  if (__size != 0xffff) {
    __dest = (void *)0x0;
    if (__size != 0) {
      __dest = malloc(__size);
      if (__dest == (void *)0x0) goto _L0;
      memcpy(__dest,param_3,__size);
    }
    __ptr[2] = 0xffff;
    iVar9 = *(int *)(param_1 + 6);
    *(undefined1 *)((int)__ptr + 3) = uVar6;
    *(undefined1 *)(__ptr + 1) = uVar5;
    uVar2 = *(undefined2 *)(iVar9 + 10);
    __ptr[3] = (short)__dest;
    *__ptr = (short)param_2;
    __ptr[4] = (short)((uint)__dest >> 0x10);
    __ptr[5] = uVar2;
    *(undefined4 *)(__ptr + 6) = 0;
    *(undefined2 **)(puVar7 + 6) = __ptr;
    if (iVar10 == 0) {
      return 0;
    }
  }
_L0:
  free(__ptr);
  return 0x102;
}

