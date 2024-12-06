/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_level_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001028a) */

undefined4 esp_zb_level_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  ushort *puVar2;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar3;
  size_t sVar4;
  byte bVar5;
  int iVar6;
  ushort *puVar7;
  
  if (param_2 < 7) {
    if (param_2 < 5) {
      if (param_2 != 4) {
        bVar5 = 1;
        if (param_2 < 2) {
          if (param_2 != 0) goto _L0;
          bVar5 = 0x15;
        }
        else {
          bVar5 = 1;
        }
_L0:
        sVar4 = 0x20;
        goto _L0;
      }
      bVar5 = 0x15;
    }
    else {
      bVar5 = 1;
    }
  }
  else {
    if (0x13 < param_2) {
      if (param_2 == 0xefff) {
        bVar5 = 0x40;
        sVar4 = 0x12;
        goto _L0;
      }
      if ((0xefff < param_2) || ((param_2 != 0x14 && (param_2 != 0x4000)))) {
_L0:
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC5,uVar3,0x10000);
        return 0x102;
      }
_L0:
      bVar5 = 3;
      goto _L0;
    }
    if (param_2 < 0x12) {
      if (param_2 == 0xf) {
        bVar5 = 3;
        sVar4 = 0x18;
        goto _L0;
      }
      if (param_2 < 0xf) goto _L0;
      if (param_2 != 0x10) goto _L0;
    }
    bVar5 = 3;
  }
_L0:
  sVar4 = 0x21;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
  }
  else {
    puVar7 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 8) {
      do {
        puVar2 = *(ushort **)(puVar7 + 6);
        if (puVar2 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar5 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar4,param_3);
          }
          else {
            __size = sVar4;
            if (param_3 == (void *)0x0) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x67);
              goto _L0;
            }
          }
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
          iVar6 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar5;
          *(char *)(__ptr + 1) = (char)sVar4;
          uVar1 = *(undefined2 *)(iVar6 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar7 + 6) = __ptr;
          return 0;
        }
        puVar7 = puVar2;
      } while ((*puVar2 != param_2) || (puVar2[2] != 0xffff));
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar3,0x10000,param_2);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),8);
    }
  }
  return 0x102;
}

