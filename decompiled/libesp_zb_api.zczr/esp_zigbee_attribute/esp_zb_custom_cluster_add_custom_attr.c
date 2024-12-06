/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_custom_cluster_add_custom_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001028a) */

undefined4
esp_zb_custom_cluster_add_custom_attr
          (ushort *param_1,uint param_2,size_t param_3,byte param_4,void *param_5)

{
  undefined2 uVar1;
  short sVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  int iVar5;
  ushort *puVar6;
  
  if (param_1 == (ushort *)0x0) {
    return 0x102;
  }
  sVar2 = *(short *)(*(int *)(param_1 + 6) + 10);
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar4,0x10000);
  }
  else {
    puVar6 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == sVar2) {
      do {
        puVar3 = *(ushort **)(puVar6 + 6);
        if (puVar3 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((param_4 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(param_3,param_5);
          }
          else {
            __size = param_3;
            if (param_5 == (void *)0x0) {
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
            memcpy(__dest,param_5,__size);
          }
          iVar5 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = param_4 & 0xdf;
          *(char *)(__ptr + 1) = (char)param_3;
          uVar1 = *(undefined2 *)(iVar5 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar6 + 6) = __ptr;
          return 0;
        }
        puVar6 = puVar3;
      } while ((*puVar3 != param_2) || (puVar3[2] != 0xffff));
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar4,0x10000,param_2);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar4,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),sVar2)
      ;
    }
  }
  return 0x102;
}

