/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> tasklet.o -> tasklet_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void tasklet_post(tasklet_t *t)

{
  _Bool _Var1;
  undefined3 extraout_var;
  
  _Var1 = test_and_set_bit(1,&t->state);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    tasklet_post_common(t,&s_tasklet_chain);
  }
  return;
}

