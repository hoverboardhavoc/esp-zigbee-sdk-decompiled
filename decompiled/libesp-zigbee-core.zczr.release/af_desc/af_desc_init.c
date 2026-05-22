/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_desc_init(void)

{
  uint __nmemb;
  void *pvVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  *(undefined4 *)(iVar2 + 0xca0) = 0;
  s_ep_num_on_dev = '@';
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xfff0;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xff0f | 0x10;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xf0ff | 0x100;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xfff | 0xc000;
  __nmemb = (uint)s_ep_num_on_dev;
  iVar2 = core_globals_get();
  pvVar1 = calloc(__nmemb,4);
  *(void **)(iVar2 + 0xc9c) = pvVar1;
  iVar2 = core_globals_get();
  return (uint)(*(int *)(iVar2 + 0xc9c) == 0);
}

