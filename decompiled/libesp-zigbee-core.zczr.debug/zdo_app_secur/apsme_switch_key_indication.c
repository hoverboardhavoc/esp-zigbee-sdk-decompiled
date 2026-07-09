/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_switch_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void apsme_switch_key_indication(int param_1)

{
  int iVar1;
  
  iVar1 = nwk_secur_switch_key(*(undefined1 *)(param_1 + 8));
  if (iVar1 != 0) {
    log_write(1,"zdo_app_secur.c","Failed to switch key (seq:%d): 0x%x",*(undefined1 *)(param_1 + 8)
              ,iVar1);
  }
  return;
}

