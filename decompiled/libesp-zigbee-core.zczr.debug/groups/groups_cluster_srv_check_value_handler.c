/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
groups_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  undefined2 in_register_0000202a;
  undefined3 extraout_var;
  
  if (CONCAT22(in_register_0000202a,attr_id) == 0) {
                    /* WARNING: Load size is inaccurate */
    eVar2 = *value;
    if (eVar2 != '\0') {
      _Var1 = groups_group_name_is_supported();
      if (CONCAT31(extraout_var,_Var1) == 0) {
        eVar2 = 0x86;
      }
      else {
        eVar2 = '\0';
      }
    }
  }
  else {
    eVar2 = '\0';
  }
  return eVar2;
}

