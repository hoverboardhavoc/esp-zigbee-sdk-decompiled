/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_level_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010268) */

undefined4 esp_zb_level_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar4;
  size_t sVar5;
  byte bVar6;
  int iVar7;
  
  if (param_2 < 7) {
    if (param_2 < 5) {
      if (param_2 != 4) {
        bVar6 = 1;
        if (param_2 < 2) {
          if (param_2 != 0) goto _L0;
          bVar6 = 0x15;
        }
_L0:
        sVar5 = 0x20;
        goto _L0;
      }
      bVar6 = 0x15;
    }
    else {
      bVar6 = 1;
    }
  }
  else {
    if (0x13 < param_2) {
      if (param_2 == 0xefff) {
        bVar6 = 0x40;
        sVar5 = 0x12;
        goto _L0;
      }
      if ((0xefff < param_2) || ((param_2 != 0x14 && (param_2 != 0x4000)))) {
_L0:
        uVar4 = esp_log_timestamp();
        esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar4,0x10000);
        return 0x102;
      }
_L0:
      bVar6 = 3;
      goto _L0;
    }
    if (param_2 < 0x12) {
      if (param_2 == 0xf) {
        bVar6 = 3;
        sVar5 = 0x18;
        goto _L0;
      }
      if (param_2 < 0xf) goto _L0;
      if (param_2 != 0x10) goto _L0;
    }
    bVar6 = 3;
  }
_L0:
  sVar5 = 0x21;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar4,0x10000);
  }
  else {
    puVar2 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 8) {
      do {
        puVar3 = *(ushort **)(puVar2 + 6);
        if (puVar3 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((bVar6 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(sVar5,param_3);
          }
          else {
            __size = sVar5;
            if ((param_3 == (void *)0x0) && (sVar5 != 0)) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x68);
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
          iVar7 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar6;
          *(char *)(__ptr + 1) = (char)sVar5;
          uVar1 = *(undefined2 *)(iVar7 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar2 + 6) = __ptr;
          return 0;
        }
        puVar2 = puVar3;
      } while ((*puVar3 != param_2) || (puVar3[2] != 0xffff));
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar4
              ,0x10000,param_2);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar4,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),8);
    }
  }
  return 0x102;
}

