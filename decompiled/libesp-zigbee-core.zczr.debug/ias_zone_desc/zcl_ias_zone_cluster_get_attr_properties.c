/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone_desc.o -> zcl_ias_zone_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_ias_zone_cluster_get_attr_properties
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
      pcVar3 = "zcl_ias_zone_cluster_get_attr_properties";
      uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone_desc.c"
                            ,0x19);
      type = (uint8_t *)pcVar3;
      access = (uint8_t *)pcVar4;
    }
    if (uVar2 == 0x10) {
      *access = '\x03';
      *type = 0xf0;
      eVar1 = 0;
    }
    else if (uVar2 < 0x11) {
      if (uVar2 == 1) {
        *access = '\x01';
        *type = '1';
        eVar1 = 0;
      }
      else if (uVar2 == 2) {
        *access = '\x01';
        *type = '\x19';
        eVar1 = 0;
      }
      else if (uVar2 == 0) {
        *access = '\x01';
        *type = '0';
        eVar1 = 0;
      }
      else {
        eVar1 = 6;
      }
    }
    else if (uVar2 == 0x13) {
      *access = '\x03';
      *type = ' ';
      eVar1 = 0;
    }
    else if (uVar2 < 0x14) {
      if ((uVar2 - 0x11 & 0xffff) < 2) {
        *access = '\x01';
        *type = ' ';
        eVar1 = 0;
      }
      else {
        eVar1 = 6;
      }
    }
    else if (uVar2 == 0xeff0) {
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

