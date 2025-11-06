/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_ias_wd_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010230) */
/* WARNING: Removing unreachable block (ram,0x00010236) */
/* WARNING: Removing unreachable block (ram,0x0001023a) */
/* WARNING: Removing unreachable block (ram,0x00010268) */

undefined4 esp_zb_ias_wd_cluster_add_attr(short *param_1,int param_2,void *param_3)

{
  undefined2 uVar1;
  short *psVar2;
  short *psVar3;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar4;
  int iVar5;
  
  if (param_2 != 0) {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: incorrect/unsupported attribute_id!\n",uVar4,0x10000);
    return 0x102;
  }
  if ((param_1 == (short *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Uninitialized attribute linked list!\n",uVar4,0x10000);
  }
  else {
    psVar2 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 0x502) {
      do {
        psVar3 = *(short **)(psVar2 + 6);
        if (psVar3 == (short *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(0x21,param_3);
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
          iVar5 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x21;
          uVar1 = *(undefined2 *)(iVar5 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = 0;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(psVar2 + 6) = __ptr;
          return 0;
        }
        psVar2 = psVar3;
      } while ((*psVar3 != 0) || (psVar3[2] != -1));
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: The requested add attribute ID:0x%x is already existed\n",uVar4
              ,0x10000,0);
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: Wrong cluster(0x%04x) to add attribute, expect 0x%04x\n",uVar4,
              0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),0x502);
    }
  }
  return 0x102;
}

