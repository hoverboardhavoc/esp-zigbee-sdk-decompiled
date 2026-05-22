/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> binary_output_desc.o -> zcl_binary_output_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_binary_output_cluster_get_attr_properties
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
      pcVar3 = "zcl_binary_output_cluster_get_attr_properties";
      uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/binary_output_desc.c"
                            ,0x19);
      type = (uint8_t *)pcVar3;
      access = (uint8_t *)pcVar4;
    }
    if (uVar2 == 0x57) {
      *access = '\x03';
      *type = 'H';
      eVar1 = 0;
    }
    else {
      if (uVar2 < 0x58) {
        if (uVar2 != 0x51) {
          if (uVar2 < 0x52) {
            if (0x43 < uVar2) {
              return 6;
            }
            if (uVar2 < 0x42) {
              if (((uVar2 != 0x1c) && (uVar2 != 0x2e)) && (uVar2 != 4)) {
                return 6;
              }
              *access = '\x03';
              *type = 'B';
              return 0;
            }
            *access = '\x03';
            *type = '#';
            return 0;
          }
          if (uVar2 == 0x54) {
            *access = '\x01';
            *type = '0';
            return 0;
          }
          if (uVar2 == 0x55) {
            *access = '\a';
            *type = '\x10';
            return 0;
          }
          return 6;
        }
      }
      else {
        if (uVar2 == 0x6f) {
          *access = '\x05';
          *type = '\x18';
          return 0;
        }
        if (0x6f < uVar2) {
          if (uVar2 == 0x100) {
            *access = '\x01';
            *type = '#';
            return 0;
          }
          return 6;
        }
        if (uVar2 == 0x67) {
          *access = '\x03';
          *type = '0';
          return 0;
        }
        if (uVar2 != 0x68) {
          return 6;
        }
      }
      *access = '\x03';
      *type = '\x10';
      eVar1 = 0;
    }
  }
  return eVar1;
}

