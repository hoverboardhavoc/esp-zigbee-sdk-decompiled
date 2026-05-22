/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> time_desc.o -> zcl_time_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_time_cluster_get_attr_properties
                    (uint16_t cluster_role,uint16_t attr_id,uint8_t *type,uint8_t *access)

{
  undefined2 in_register_0000202a;
  undefined2 in_register_0000202e;
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = CONCAT22(in_register_0000202e,attr_id);
  if (type == (uint8_t *)0x0) {
    return 2;
  }
  if (access == (uint8_t *)0x0) {
    return 2;
  }
  if ((CONCAT22(in_register_0000202a,cluster_role) - 1U & 0xffff) < 2) {
    if (CONCAT22(in_register_0000202a,cluster_role) != 1) {
      return 6;
    }
  }
  else {
    pcVar3 = "cluster_role == 0x01U || cluster_role == 0x02U";
    pcVar2 = "zcl_time_cluster_get_attr_properties";
    uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/time_desc.c",
                          0x16);
    type = (uint8_t *)pcVar2;
    access = (uint8_t *)pcVar3;
  }
  if (uVar1 < 8) {
    if (5 < uVar1) {
      *access = '\x01';
      *type = '#';
      return 0;
    }
    if (uVar1 != 2) {
      if (uVar1 < 3) {
        if (uVar1 != 0) {
          if (uVar1 == 1) {
            *access = '\x03';
            *type = '\x18';
            return 0;
          }
          return 6;
        }
        goto _L0;
      }
      if (uVar1 < 5) {
        if (2 < uVar1) {
          *access = '\x03';
          *type = '#';
          return 0;
        }
        return 6;
      }
      if (uVar1 != 5) {
        return 6;
      }
    }
    *access = '\x03';
    *type = '+';
  }
  else {
    if (uVar1 != 9) {
      if (uVar1 == 0xeffe) {
        *access = '@';
        *type = '\0';
        return 0;
      }
      if (uVar1 == 8) {
        *access = '\x01';
        *type = 0xe2;
        return 0;
      }
      return 6;
    }
_L0:
    *access = '\x03';
    *type = 0xe2;
  }
  return 0;
}

