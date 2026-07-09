/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> tasklet.o -> tasklet_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void tasklet_post(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = __atomic_fetch_or_4(param_1 + 4,2,5);
  if (((uVar1 & 2) == 0) && (iVar2 = list_push_head_ll(&s_tasklet_chain,param_1), iVar2 != 0)) {
    ezb_tasklet_signal_pending();
    return;
  }
  return;
}

