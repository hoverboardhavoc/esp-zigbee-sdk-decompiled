/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> binary_input_desc.o -> zcl_binary_input_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_binary_input_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  
  uVar2 = CONCAT22(in_register_0000202e,attr_id);
  if (type == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else if (access == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else {
    if ((CONCAT22(in_register_0000202a,cluster_role) - 1U & 0xffff) < 2) {
      if (CONCAT22(in_register_0000202a,cluster_role) != 1) {
        return 6;
      }
    }
    else {
      pcVar4 = "cluster_role == 0x01U || cluster_role == 0x02U";
      pcVar3 = "zcl_binary_input_cluster_get_attr_properties";
      uVar2 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/binary_input_desc.c",0x19);
      type = (uint8_t *)pcVar3;
      access = (uint8_t *)pcVar4;
    }
    if (uVar2 == 0x55) {
      *access = '\x05';
      *type = '\x10';
      eVar1 = 0;
    }
    else {
      if (uVar2 < 0x56) {
        if (uVar2 == 0x51) {
          *access = '\x01';
          *type = '\x10';
          return 0;
        }
        if (uVar2 < 0x52) {
          if (((uVar2 != 0x1c) && (uVar2 != 0x2e)) && (uVar2 != 4)) {
            return 6;
          }
          *access = '\x01';
          *type = 'B';
          return 0;
        }
        if (uVar2 != 0x54) {
          return 6;
        }
      }
      else {
        if (uVar2 == 0x6f) {
          *access = '\x05';
          *type = '\x18';
          return 0;
        }
        if (uVar2 == 0x100) {
          *access = '\x01';
          *type = '#';
          return 0;
        }
        if (uVar2 != 0x67) {
          return 6;
        }
      }
      *access = '\x01';
      *type = '0';
      eVar1 = 0;
    }
  }
  return eVar1;
}

