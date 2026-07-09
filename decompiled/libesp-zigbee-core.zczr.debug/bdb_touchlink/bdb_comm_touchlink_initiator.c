/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> bdb_comm_touchlink_initiator
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bdb_comm_touchlink_initiator(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = aps_secur_is_centralized();
  if (iVar1 == 0) {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 1;
    uVar2 = bdb_comm_get_primary_channel_set();
    uVar3 = bdb_comm_get_secondary_channel_set();
    touchlink_commissioning_set_channel_mask(uVar3 | uVar2);
    touchlink_initiator_start_commissioning(touchlink_initiator_commissioning_handler);
  }
  else {
    iVar1 = core_globals_get();
    *(undefined1 *)(iVar1 + 0xd4c) = 9;
    bdb_comm_perform_next_step();
  }
  return;
}

