/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> reportable_change_is_present
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool reportable_change_is_present(uint16_t min_interval,uint16_t max_interval,uint8_t type)

{
  undefined2 in_register_0000202a;
  int iVar1;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  
  iVar1 = zcl_attr_type_is_analog(CONCAT31(in_register_00002031,type));
  if (iVar1 != 0) {
    if ((CONCAT22(in_register_0000202e,max_interval) == 0) &&
       (CONCAT22(in_register_0000202a,min_interval) == 0xffff)) {
      iVar1 = 0;
    }
    else if (CONCAT22(in_register_0000202e,max_interval) == 0xffff) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return SUB41(iVar1,0);
}

