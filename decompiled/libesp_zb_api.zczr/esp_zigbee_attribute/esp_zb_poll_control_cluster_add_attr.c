/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_poll_control_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001028a) */

undefined4 esp_zb_poll_control_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

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
  
  if (param_2 < 6) {
    bVar5 = 3;
    if (3 < param_2) {
_L0:
      bVar5 = 1;
_L0:
      sVar4 = 0x23;
      goto _L0;
    }
    if (param_2 == 2) goto _L0;
    if (param_2 != 3) {
      if (param_2 != 0) goto _L0;
      goto _L0;
    }
    bVar5 = 3;
  }
  else {
    if (param_2 == 0xeffe) {
      bVar5 = 0x40;
      sVar4 = 4;
      goto _L0;
    }
    if (param_2 == 0xefff) {
      bVar5 = 0x40;
      sVar4 = 3;
      goto _L0;
    }
    if (param_2 != 6) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC5,uVar3,0x10000);
      return 0x102;
    }
_L0:
    bVar5 = 1;
  }
  sVar4 = 0x21;
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
  }
  else {
    puVar7 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0x20) {
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
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0x20);
    }
  }
  return 0x102;
}

