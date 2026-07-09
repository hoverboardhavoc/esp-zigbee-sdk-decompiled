/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_update_attr(int param_1,void *param_2)

{
  void *__ptr;
  int iVar1;
  size_t __size;
  size_t sVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 2;
    if (param_2 != (void *)0x0) {
      iVar1 = ezb_zcl_cluster_get_attr_desc(param_1 + -0xc,0);
      uVar3 = 5;
      if (iVar1 != 0) {
        uVar3 = ezb_zcl_attr_desc_get_type();
        __ptr = *(void **)(iVar1 + 8);
        __size = ezb_zcl_get_attr_value_size(param_2);
        sVar2 = ezb_zcl_get_attr_value_size(uVar3,__ptr);
        if (__size != sVar2) {
          __ptr = realloc(__ptr,__size);
          uVar3 = 1;
          if (__ptr == (void *)0x0) goto _L295;
        }
        memcpy(__ptr,param_2,__size);
        uVar3 = 0;
        *(void **)(iVar1 + 8) = __ptr;
      }
    }
  }
_L295:
  esp_zigbee_err_to_esp(uVar3);
  return;
}

