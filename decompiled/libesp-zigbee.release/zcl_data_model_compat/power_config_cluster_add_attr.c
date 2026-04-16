/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_data_model_compat.o -> power_config_cluster_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t power_config_cluster_add_attr
                    (esp_zb_attribute_list_t *attr_list,uint16_t attr_id,void *value_p)

{
  int iVar1;
  esp_err_t eVar2;
  undefined2 in_register_0000202e;
  
  if (attr_list == (esp_zb_attribute_list_t *)0x0) {
    iVar1 = 2;
  }
  else {
    if (*(char *)((int)&attr_list[-3].attr_list + 2) == '\0') {
      *(undefined1 *)((int)&attr_list[-3].attr_list + 2) = 2;
      iVar1 = ezb_zcl_power_config_cluster_desc_add_attr
                        (attr_list + -3,CONCAT22(in_register_0000202e,attr_id));
      if (iVar1 == 0) goto _L0;
      *(undefined1 *)((int)&attr_list[-3].attr_list + 2) = 1;
    }
    iVar1 = ezb_zcl_power_config_cluster_desc_add_attr
                      (attr_list + -3,CONCAT22(in_register_0000202e,attr_id),value_p);
  }
_L0:
  eVar2 = esp_zigbee_err_to_esp(iVar1);
  return eVar2;
}

