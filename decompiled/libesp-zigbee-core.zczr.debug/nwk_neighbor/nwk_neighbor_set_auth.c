/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_set_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_set_auth(int param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0xc) & 3;
  if (uVar2 == 2) {
    iVar1 = 1;
  }
  else {
    iVar1 = 2;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffffc3f | iVar1 << 6;
  if (uVar2 == 2) {
    iVar1 = core_globals_get();
    nwk_neighbor_zed_set_timeout(param_1,*(undefined1 *)(iVar1 + 0xa29));
    nwk_neighbor_table_store_child(param_1);
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(iVar1 + 0xa25);
    iVar1 = core_globals_get();
    *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(iVar1 + 0xa25);
  }
  return;
}

