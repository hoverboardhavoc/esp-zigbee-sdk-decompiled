/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_window_covering_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010238) */
/* WARNING: Removing unreachable block (ram,0x00010240) */
/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x0001029c) */
/* WARNING: Removing unreachable block (ram,0x000102a2) */

undefined4 esp_zb_window_covering_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  ushort *puVar4;
  ushort *puVar5;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar6;
  undefined *puVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  int iVar10;
  
  if (param_2 < 0x14) {
    if (param_2 < 0x10) {
      if (param_2 == 7) {
        uVar9 = 1;
        goto _L0;
      }
      if (7 < param_2) {
        if (1 < (param_2 - 8 & 0xffff)) goto _L0;
        uVar9 = 0x15;
        uVar8 = 0x20;
        goto _L0;
      }
      uVar9 = 1;
      uVar8 = 0x30;
      uVar3 = 1;
      if (param_2 == 0) goto _L0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    if (param_2 == 0x17) {
      uVar9 = 3;
_L0:
      uVar8 = 0x18;
      goto _L0;
    }
    if (0x17 < param_2) {
      if (1 < (param_2 - 0x18 & 0xffff)) {
_L0:
        uVar6 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC6,uVar6,0x10000);
        return 0x102;
      }
      uVar9 = 3;
      uVar8 = 0x41;
      goto _L0;
    }
    uVar3 = 3;
  }
  uVar9 = uVar3;
  uVar8 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar6 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar6,0x10000);
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1 + 6) + 10);
    puVar4 = param_1;
    if (uVar1 == 0x102) {
      do {
        puVar5 = *(ushort **)(puVar4 + 6);
        if (puVar5 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(uVar8,param_3);
          if (__size == 0xffff) {
_L0:
            free(__ptr);
            return 0x102;
          }
          __dest = (void *)0x0;
          if (__size != 0) {
            __dest = malloc(__size);
            if (__dest == (void *)0x0) goto _L0;
            memcpy(__dest,param_3,__size);
          }
          __ptr[2] = 0xffff;
          iVar10 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar9;
          *(undefined1 *)(__ptr + 1) = uVar8;
          uVar2 = *(undefined2 *)(iVar10 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar4 + 6) = __ptr;
          return 0;
        }
        puVar4 = puVar5;
      } while (*puVar5 != param_2);
      uVar6 = esp_log_timestamp();
      puVar7 = &_LC4;
    }
    else {
      uVar6 = esp_log_timestamp();
      puVar7 = &_LC2;
      param_2 = (uint)uVar1;
    }
    esp_log_write(1,0x10000,puVar7,uVar6,0x10000,param_2);
  }
  return 0x102;
}

