/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> bdb_comm_touchlink_target
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bdb_comm_touchlink_target(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = aps_secur_is_centralized();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xda0) = 1;
    uVar2 = bdb_comm_get_primary_channel_set();
    uVar3 = bdb_comm_get_secondary_channel_set();
    touchlink_commissioning_set_channel_mask(uVar3 | uVar2);
    touchlink_target_start_commissioning(touchlink_target_commissioning_handler);
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xda0) = 9;
    bdb_comm_perform_next_step();
  }
  return;
}

