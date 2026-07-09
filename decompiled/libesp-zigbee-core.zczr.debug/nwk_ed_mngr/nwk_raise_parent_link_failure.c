/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_raise_parent_link_failure
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_raise_parent_link_failure(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined4 uStack_14;
  
  uStack_14 = 9;
  uVar2 = nwk_get_parent_shortaddr();
  uVar1 = uStack_14;
  uStack_14._3_1_ = SUB41(uVar1,3);
  uStack_14._0_3_ = CONCAT12((char)((ushort)uVar2 >> 8),CONCAT11((char)uVar2,(undefined1)uStack_14))
  ;
  nwk_handle_network_status_local(&uStack_14);
  return;
}

