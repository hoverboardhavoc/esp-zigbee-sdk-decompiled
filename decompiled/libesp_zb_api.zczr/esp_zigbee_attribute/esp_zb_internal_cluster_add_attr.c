/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_internal_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_zb_internal_cluster_add_attr
          (ushort *param_1,uint param_2,uint param_3,size_t param_4,byte param_5,void *param_6,
          uint param_7)

{
  undefined2 uVar1;
  ushort *puVar2;
  ushort *puVar3;
  undefined4 uVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  int iVar5;
  byte bVar6;
  
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar4,0x10000);
  }
  else {
    puVar2 = param_1;
    if (*(ushort *)(*(int *)(param_1 + 6) + 10) == param_2) {
      do {
        puVar3 = *(ushort **)(puVar2 + 6);
        if (puVar3 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          if ((param_5 & 0x40) == 0) {
_L0:
            __size = esp_zb_zcl_get_attribute_size(param_4,param_6);
          }
          else {
            __size = param_4;
            if ((param_6 == (void *)0x0) && (param_4 != 0)) {
              zb_assert("/builds/thread_zigbee/esp-zboss/components/esp_zb_sdk/src/esp_zigbee_attribute.c"
                        ,0x68);
              goto _L0;
            }
          }
          bVar6 = param_5 & 0xdf;
          if (param_7 != 0xffff) {
            bVar6 = param_5 | 0x20;
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
            memcpy(__dest,param_6,__size);
          }
          iVar5 = *(int *)(param_1 + 6);
          *(byte *)((int)__ptr + 3) = bVar6;
          *(char *)(__ptr + 1) = (char)param_4;
          uVar1 = *(undefined2 *)(iVar5 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_3;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = (short)param_7;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar2 + 6) = __ptr;
          return 0;
        }
        puVar2 = puVar3;
      } while ((*puVar3 != param_3) || (puVar3[2] != param_7));
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar4
              ,0x10000,param_3);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar4,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),param_2);
    }
  }
  return 0x102;
}

