/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_deinit(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  zmsg_queue_deinit(&s_nwk_fwd);
  zmsg_tmque_deinit(&s_nwk_fwd);
  puVar2 = &s_nwk_fwd;
  do {
    puVar1 = puVar2 + 0x10;
    puVar2 = puVar2 + 2;
    mm_free(*puVar1);
  } while (puVar2 != (undefined4 *)&DAT_000116b8);
  return;
}

