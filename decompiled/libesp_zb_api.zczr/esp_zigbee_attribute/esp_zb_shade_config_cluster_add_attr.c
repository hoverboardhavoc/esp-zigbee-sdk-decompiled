/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_shade_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x00010236) */
/* WARNING: Removing unreachable block (ram,0x0001023a) */
/* WARNING: Removing unreachable block (ram,0x00010268) */

undefined4 esp_zb_shade_config_cluster_add_attr(ushort *param_1,uint param_2,void *param_3)

{
  undefined2 uVar1;
  undefined1 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  int iVar8;
  
  if (param_2 == 2) {
    uVar7 = 3;
    uVar6 = 0x18;
  }
  else {
    if (param_2 < 3) {
      uVar7 = 1;
      uVar6 = 0x20;
      uVar2 = 1;
      if (param_2 != 0) goto _L0;
    }
    else {
      if (param_2 != 0x10) {
        if (param_2 != 0x11) {
          uVar5 = esp_log_timestamp();
          esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar5,0x10000);
          return 0x102;
        }
        uVar7 = 3;
        uVar6 = 0x30;
        goto _L0;
      }
      uVar2 = 3;
    }
    uVar7 = uVar2;
    uVar6 = 0x21;
  }
_L0:
  if ((param_1 == (ushort *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar5 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar5,0x10000);
  }
  else {
    puVar3 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0x100) {
      do {
        puVar4 = *(ushort **)(puVar3 + 6);
        if (puVar4 == (ushort *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(uVar6,param_3);
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
          iVar8 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = uVar7;
          *(undefined1 *)(__ptr + 1) = uVar6;
          uVar1 = *(undefined2 *)(iVar8 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = (short)param_2;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(puVar3 + 6) = __ptr;
          return 0;
        }
        puVar3 = puVar4;
      } while ((*puVar4 != param_2) || (puVar4[2] != 0xffff));
      uVar5 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar5
              ,0x10000,param_2);
    }
    else {
      uVar5 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar5,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0x100);
    }
  }
  return 0x102;
}

