/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_cluster_update_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_cluster_update_attr
                    (esp_zb_attribute_list_t *attr_list,uint16_t attr_id,void *value_p)

{
  int iVar1;
  undefined4 uVar2;
  size_t __size;
  size_t sVar3;
  esp_err_t eVar4;
  undefined2 in_register_0000202e;
  void *__ptr;
  
  if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    uVar2 = 2;
  }
  else if (value_p == (void *)0x0) {
    uVar2 = 2;
  }
  else {
    iVar1 = ezb_zcl_cluster_get_attr_desc(attr_list + -3,CONCAT22(in_register_0000202e,attr_id),0);
    if (iVar1 == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = ezb_zcl_attr_desc_get_type();
      __ptr = *(void **)(iVar1 + 8);
      __size = ezb_zcl_get_attr_value_size(value_p);
      sVar3 = ezb_zcl_get_attr_value_size(uVar2,__ptr);
      if ((__size == sVar3) || (__ptr = realloc(__ptr,__size), __ptr != (void *)0x0)) {
        memcpy(__ptr,value_p,__size);
        *(void **)(iVar1 + 8) = __ptr;
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  eVar4 = esp_zigbee_err_to_esp(uVar2);
  return eVar4;
}

