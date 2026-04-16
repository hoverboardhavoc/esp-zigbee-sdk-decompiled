/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_simple_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_simple_desc_init(void)

{
  uint __nmemb;
  int iVar1;
  void *pvVar2;
  
  __nmemb = (uint)s_ep_num_on_dev;
  iVar1 = core_globals_get();
  pvVar2 = calloc(__nmemb,4);
  *(void **)(iVar1 + 0xd00) = pvVar2;
  iVar1 = core_globals_get();
  return (uint)(*(int *)(iVar1 + 0xd00) == 0);
}

