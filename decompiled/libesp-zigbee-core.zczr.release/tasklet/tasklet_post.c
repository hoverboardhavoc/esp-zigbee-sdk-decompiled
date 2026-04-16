/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> tasklet.o -> tasklet_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tasklet_post(tasklet_t *t)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = __atomic_fetch_or_4(&t->state,2,5);
  if (((uVar1 & 2) == 0) && (iVar2 = list_push_head_ll(&s_tasklet_chain,t), iVar2 != 0)) {
    ezb_tasklet_signal_pending();
    return;
  }
  return;
}

