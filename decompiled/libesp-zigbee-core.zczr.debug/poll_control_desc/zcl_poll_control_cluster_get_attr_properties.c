/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control_desc.o -> zcl_poll_control_cluster_get_attr_properties
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_poll_control_cluster_get_attr_properties
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
    pcVar2 = "zcl_poll_control_cluster_get_attr_properties";
    uVar1 = __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/poll_control_desc.c",0x19);
    type = (uint8_t *)pcVar2;
    access = (uint8_t *)pcVar3;
  }
  if (uVar1 == 3) {
    *access = '\x03';
    *type = '!';
    return 0;
  }
  if (uVar1 < 4) {
    if (uVar1 != 1) {
      if (uVar1 != 2) {
        if (uVar1 == 0) {
          *access = '\x03';
          *type = '#';
          return 0;
        }
        return 6;
      }
      goto _L0;
    }
  }
  else {
    if (uVar1 == 6) {
_L0:
      *access = '\x01';
      *type = '!';
      return 0;
    }
    if (6 < uVar1) {
      if (uVar1 == 0xeff0) {
        *access = '@';
        *type = '\0';
        return 0;
      }
      return 6;
    }
    if (1 < (uVar1 - 4 & 0xffff)) {
      return 6;
    }
  }
  *access = '\x01';
  *type = '#';
  return 0;
}

