/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_cluster_update_attr(int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  size_t __size;
  size_t sVar3;
  void *__ptr;
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else if (param_2 == (void *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = ezb_zcl_cluster_get_attr_desc(param_1 + -0xc,0);
    if (iVar1 == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = ezb_zcl_attr_desc_get_type();
      __ptr = *(void **)(iVar1 + 8);
      __size = ezb_zcl_get_attr_value_size(param_2);
      sVar3 = ezb_zcl_get_attr_value_size(uVar2,__ptr);
      if ((__size == sVar3) || (__ptr = realloc(__ptr,__size), __ptr != (void *)0x0)) {
        memcpy(__ptr,param_2,__size);
        *(void **)(iVar1 + 8) = __ptr;
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  esp_zigbee_err_to_esp(uVar2);
  return;
}

