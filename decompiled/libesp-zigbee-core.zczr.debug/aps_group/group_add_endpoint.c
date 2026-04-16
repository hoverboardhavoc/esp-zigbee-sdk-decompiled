/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> group_add_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool group_add_endpoint(aps_group_t *group,uint8_t endpoint)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 in_register_0000202d;
  
  _Var1 = test_and_set_bitmap(CONCAT31(in_register_0000202d,endpoint),group->ep_in_grp);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    aps_group_table_store_group(group);
  }
  return _Var1;
}

