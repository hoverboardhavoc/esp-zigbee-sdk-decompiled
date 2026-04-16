/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_desc.o -> zcl_ota_upgrade_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_ota_upgrade_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar4 = CONCAT22(in_register_0000202e,attr_id);
  if (type == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else if (access == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else {
    if ((CONCAT22(in_register_0000202a,cluster_role) - 1U & 0xffff) < 2) {
      if (CONCAT22(in_register_0000202a,cluster_role) != 1) {
        if (0xc < uVar4) {
          if (uVar4 == 0xeff0) {
            *access = '@';
            *type = '\0';
            return 0;
          }
          return 6;
        }
        if (attr_id == 0) {
          if (uVar4 == 0) {
            *access = '\x01';
            *type = 0xf0;
            return 0;
          }
          return 6;
        }
        uVar4 = 1 << (attr_id & 0x1f);
        if ((uVar4 & 0x3a8) != 0) {
          *access = '\x01';
          *type = '!';
          return 0;
        }
        if ((uVar4 & 0x416) == 0) {
          if ((uVar4 >> 6 & 0x61) == 0) {
            return 6;
          }
          *access = '\x01';
          *type = '0';
          return 0;
        }
        *access = '\x01';
        *type = '#';
        return 0;
      }
    }
    else {
      pcVar3 = "cluster_role == 0x01U || cluster_role == 0x02U";
      pcVar2 = "zcl_ota_upgrade_cluster_get_attr_properties";
      uVar4 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_desc.c",0x19);
      type = (uint8_t *)pcVar2;
      access = (uint8_t *)pcVar3;
    }
    if (uVar4 == 0xeff0) {
      *access = '@';
      *type = ' ';
      eVar1 = 0;
    }
    else if (uVar4 == 0xeff1) {
      *access = '@';
      *type = '\0';
      eVar1 = 0;
    }
    else {
      eVar1 = 6;
    }
  }
  return eVar1;
}

