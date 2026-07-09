/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_bcast
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_fwd_handle_bcast(int param_1,undefined4 param_2)

{
  ushort uVar1;
  uint uVar2;
  
  core_globals_get();
  uVar2 = nwk_is_device_in_bcast_group(*(undefined2 *)(param_1 + 4));
  if ((uVar2 != 0) && (uVar2 = nwk_btt_add_if_absent(param_1,param_2), uVar2 != 0)) {
    uVar1 = *(ushort *)(param_1 + 6);
    uVar2 = nwk_get_short_address();
    uVar2 = (uint)(uVar1 != uVar2);
  }
  return uVar2;
}

