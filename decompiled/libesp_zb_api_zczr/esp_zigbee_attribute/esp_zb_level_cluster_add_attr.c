/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_level_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x00010238) */
/* WARNING: Removing unreachable block (ram,0x00010240) */

undefined4 esp_zb_level_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar5;
  undefined *puVar6;
  size_t sVar7;
  byte bVar8;
  int iVar9;
  
  if (param_2 < 7) {
    if (param_2 < 5) {
      if (param_2 != 4) {
        bVar8 = 1;
        if (param_2 < 2) {
          if (param_2 != 0) goto _L0;
          bVar8 = 0x15;
        }
        else {
          bVar8 = 1;
        }
_L0:
        sVar7 = 0x20;
        goto _L0;
      }
      bVar8 = 0x15;
    }
    else {
      bVar8 = 1;
    }
  }
  else {
    if (0x13 < param_2) {
      if (param_2 == 0xefff) {
        bVar8 = 0x40;
        sVar7 = 0x12;
        goto _L0;
      }
      if (0xefff < param_2) {
_L0:
        uVar5 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC6,uVar5,0x10000);
        return 0x102;
      }
      if (param_2 != 0x14) {
        bVar8 = 3;
        sVar7 = 0x20;
        if (param_2 == 0x4000) goto _L0;
        goto _L0;
      }
_L0:
      bVar8 = 3;
      goto _L0;
    }
    if (param_2 < 0x12) {
      if (param_2 == 0xf) {
        bVar8 = 3;
        sVar7 = 0x18;
        goto _L0;
      }
      if (param_2 < 0xf) goto _L0;
      if (param_2 != 0x10) goto _L0;
    }
    bVar8 = 3;
  }
_L0:
  sVar7 = 0x21;
_L0:
  if (param_1 == (ushort *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar5,0x10000);
  }
  else {
    uVar1 = *(ushort *)(*(int *)(param_1 + 6) + 10);
    puVar3 = param_1;
    if (uVar1 == 8) {
      do {
        puVar4 = *(ushort **)(puVar3 + 6);
        if (puVar4 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar8 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar7,param_3);
            if (__size == 0xffff) goto _L0;
          }
          else {
            __size = sVar7;
            if (param_3 == (void *)0x0) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x6c);
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
            memcpy(__dest,param_3,__size);
          }
          __ptr[2] = 0xffff;
          iVar9 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar8;
          *(char *)(__ptr + 1) = (char)sVar7;
          uVar2 = *(undefined2 *)(iVar9 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar3 + 6) = __ptr;
          return 0;
        }
        puVar3 = puVar4;
      } while (*puVar4 != param_2);
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC4;
    }
    else {
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC2;
      param_2 = (uint)uVar1;
    }
    esp_log_write(1,0x10000,puVar6,uVar5,0x10000,param_2);
  }
  return 0x102;
}

