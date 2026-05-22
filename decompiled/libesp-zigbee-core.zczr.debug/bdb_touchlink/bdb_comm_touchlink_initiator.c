/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> bdb_touchlink.o -> bdb_comm_touchlink_initiator
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

