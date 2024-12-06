/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_attribute.o -> esp_zb_groups_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010256) */
/* WARNING: Removing unreachable block (ram,0x0001025c) */
/* WARNING: Removing unreachable block (ram,0x0001028a) */

undefined4 esp_zb_groups_cluster_add_attr(short *param_1,int param_2,void *param_3)

{
  undefined2 uVar1;
  short *psVar2;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar3;
  int iVar4;
  short *psVar5;
  
  if (param_2 != 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC5,uVar3,0x10000);
    return 0x102;
  }
  if ((param_1 == (short *)0x0) || (*(int *)(param_1 + 6) == 0)) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
  }
  else {
    psVar5 = param_1;
    if (*(short *)(*(int *)(param_1 + 6) + 10) == 4) {
      do {
        psVar2 = *(short **)(psVar5 + 6);
        if (psVar2 == (short *)0x0) {
          __ptr = (undefined2 *)malloc(0x10);
          if (__ptr == (undefined2 *)0x0) {
            return 0x102;
          }
          __size = esp_zb_zcl_get_attribute_size(0x18,param_3);
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
          iVar4 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = 1;
          *(undefined1 *)(__ptr + 1) = 0x18;
          uVar1 = *(undefined2 *)(iVar4 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = 0;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[2] = 0xffff;
          __ptr[5] = uVar1;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(psVar5 + 6) = __ptr;
          return 0;
        }
        psVar5 = psVar2;
      } while ((*psVar2 != 0) || (psVar2[2] != -1));
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC3,uVar3,0x10000,0);
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,*(undefined2 *)(*(int *)(param_1 + 6) + 10),4);
    }
  }
  return 0x102;
}

