/*
 * Last changed at upstream commit d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * https://github.com/espressif/esp-zigbee-sdk/commit/d9ff37b72907da6c3761d958aa9b6c92bf55c912
 * Upstream date: 2024-10-12 11:34:09 +0800
 * Upstream subject: esp-zigbee-lib:(a9edc7b2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_attribute.o -> esp_zb_ias_wd_cluster_add_attr
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

undefined4 esp_zb_ias_wd_cluster_add_attr(short *param_1,int param_2,void *param_3)

{
  short sVar1;
  undefined2 uVar2;
  short *psVar3;
  short *psVar4;
  undefined2 *__ptr;
  size_t __size;
  void *__dest;
  undefined4 uVar5;
  undefined *puVar6;
  short sVar7;
  int iVar8;
  
  if (param_2 != 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC6,uVar5,0x10000);
    return 0x102;
  }
  if (param_1 == (short *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar5,0x10000);
  }
  else {
    sVar1 = *(short *)(*(int *)(param_1 + 6) + 10);
    sVar7 = 0;
    psVar3 = param_1;
    if (sVar1 == 0x502) {
      do {
        psVar4 = *(short **)(psVar3 + 6);
        if (psVar4 == (short *)0x0) {
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
          __ptr[2] = 0xffff;
          iVar8 = *(int *)(param_1 + 6);
          *(undefined1 *)((int)__ptr + 3) = 3;
          *(undefined1 *)(__ptr + 1) = 0x21;
          uVar2 = *(undefined2 *)(iVar8 + 10);
          __ptr[3] = (short)__dest;
          *__ptr = 0;
          __ptr[4] = (short)((uint)__dest >> 0x10);
          __ptr[5] = uVar2;
          *(undefined4 *)(__ptr + 6) = 0;
          *(undefined2 **)(psVar3 + 6) = __ptr;
          return 0;
        }
        psVar3 = psVar4;
      } while (*psVar4 != 0);
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC4;
    }
    else {
      uVar5 = esp_log_timestamp();
      puVar6 = &_LC2;
      sVar7 = sVar1;
    }
    esp_log_write(1,0x10000,puVar6,uVar5,0x10000,sVar7);
  }
  return 0x102;
}

