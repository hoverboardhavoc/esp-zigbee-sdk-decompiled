/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_intrp.o -> nwk_handle_intrp_data_sent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_handle_intrp_data_sent(int param_1,undefined1 param_2)

{
  int aiStack_24 [3];
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  aiStack_24[0] = param_1;
  zmsg_remove_header(2);
  uStack_18 = nwk_intrp_msg_transfer_ownership(aiStack_24);
  uStack_14 = param_2;
  nwk_intrp_data_confirm(&uStack_18);
  if (aiStack_24[0] != 0) {
    zmsg_free();
  }
  return;
}

