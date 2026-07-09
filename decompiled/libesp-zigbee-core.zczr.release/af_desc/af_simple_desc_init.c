/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool af_simple_desc_init(void)

{
  uint __nmemb;
  int iVar1;
  void *pvVar2;
  
  __nmemb = (uint)s_ep_num_on_dev;
  iVar1 = core_globals_get();
  pvVar2 = calloc(__nmemb,4);
  *(void **)(iVar1 + 0xc9c) = pvVar2;
  iVar1 = core_globals_get();
  return *(int *)(iVar1 + 0xc9c) == 0;
}

