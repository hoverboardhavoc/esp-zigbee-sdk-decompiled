/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_confirm_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_confirm_key_indication(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(param_1 + 8) == '\x04') {
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xcf8) == '\x03') {
      nwk_pim_stop_fast_poll();
      if (*(byte *)(param_1 + 9) == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(byte *)(param_1 + 9) | 0x300;
      }
      zdo_secur_finish_state(uVar2);
    }
  }
  return;
}

